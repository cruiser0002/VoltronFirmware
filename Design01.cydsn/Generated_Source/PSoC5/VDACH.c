/*******************************************************************************
* File Name: VDACH.c  
* Version 1.90
*
* Description:
*  This file provides the source code to the API for the 8-bit Voltage DAC 
*  (VDAC8) User Module.
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "VDACH.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 VDACH_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 VDACH_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static VDACH_backupStruct VDACH_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: VDACH_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void VDACH_Init(void) 
{
    VDACH_CR0 = (VDACH_MODE_V );

    /* Set default data source */
    #if(VDACH_DEFAULT_DATA_SRC != 0 )
        VDACH_CR1 = (VDACH_DEFAULT_CNTL | VDACH_DACBUS_ENABLE) ;
    #else
        VDACH_CR1 = (VDACH_DEFAULT_CNTL | VDACH_DACBUS_DISABLE) ;
    #endif /* (VDACH_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(VDACH_DEFAULT_STRB != 0)
        VDACH_Strobe |= VDACH_STRB_EN ;
    #endif/* (VDACH_DEFAULT_STRB != 0) */

    /* Set default range */
    VDACH_SetRange(VDACH_DEFAULT_RANGE); 

    /* Set default speed */
    VDACH_SetSpeed(VDACH_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: VDACH_Enable
********************************************************************************
* Summary:
*  Enable the VDAC8
* 
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void VDACH_Enable(void) 
{
    VDACH_PWRMGR |= VDACH_ACT_PWR_EN;
    VDACH_STBY_PWRMGR |= VDACH_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(VDACH_restoreVal == 1u) 
        {
             VDACH_CR0 = VDACH_backup.data_value;
             VDACH_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: VDACH_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  Power: Sets power level between off (0) and (3) high power
*
* Return:
*  void 
*
* Global variables:
*  VDACH_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void VDACH_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(VDACH_initVar == 0u)
    { 
        VDACH_Init();
        VDACH_initVar = 1u;
    }

    /* Enable power to DAC */
    VDACH_Enable();

    /* Set default value */
    VDACH_SetValue(VDACH_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: VDACH_Stop
********************************************************************************
*
* Summary:
*  Powers down DAC to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void VDACH_Stop(void) 
{
    /* Disble power to DAC */
    VDACH_PWRMGR &= (uint8)(~VDACH_ACT_PWR_EN);
    VDACH_STBY_PWRMGR &= (uint8)(~VDACH_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        VDACH_backup.data_value = VDACH_CR0;
        VDACH_CR0 = VDACH_CUR_MODE_OUT_OFF;
        VDACH_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: VDACH_SetSpeed
********************************************************************************
*
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void VDACH_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    VDACH_CR0 &= (uint8)(~VDACH_HS_MASK);
    VDACH_CR0 |=  (speed & VDACH_HS_MASK);
}


/*******************************************************************************
* Function Name: VDACH_SetRange
********************************************************************************
*
* Summary:
*  Set one of three current ranges.
*
* Parameters:
*  Range: Sets one of Three valid ranges.
*
* Return:
*  void 
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void VDACH_SetRange(uint8 range) 
{
    VDACH_CR0 &= (uint8)(~VDACH_RANGE_MASK);      /* Clear existing mode */
    VDACH_CR0 |= (range & VDACH_RANGE_MASK);      /*  Set Range  */
    VDACH_DacTrim();
}


/*******************************************************************************
* Function Name: VDACH_SetValue
********************************************************************************
*
* Summary:
*  Set 8-bit DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  void 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void VDACH_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 VDACH_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    VDACH_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        VDACH_Data = value;
        CyExitCriticalSection(VDACH_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: VDACH_DacTrim
********************************************************************************
*
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  range:  1V or 4V range.  See constants.
*
* Return:
*  void
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void VDACH_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((VDACH_CR0 & VDACH_RANGE_MASK) >> 2) + VDACH_TRIM_M7_1V_RNG_OFFSET;
    VDACH_TR = CY_GET_XTND_REG8((uint8 *)(VDACH_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
