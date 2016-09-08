/*******************************************************************************
* File Name: VDAC4.c  
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
#include "VDAC4.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 VDAC4_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 VDAC4_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static VDAC4_backupStruct VDAC4_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: VDAC4_Init
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
void VDAC4_Init(void) 
{
    VDAC4_CR0 = (VDAC4_MODE_V );

    /* Set default data source */
    #if(VDAC4_DEFAULT_DATA_SRC != 0 )
        VDAC4_CR1 = (VDAC4_DEFAULT_CNTL | VDAC4_DACBUS_ENABLE) ;
    #else
        VDAC4_CR1 = (VDAC4_DEFAULT_CNTL | VDAC4_DACBUS_DISABLE) ;
    #endif /* (VDAC4_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(VDAC4_DEFAULT_STRB != 0)
        VDAC4_Strobe |= VDAC4_STRB_EN ;
    #endif/* (VDAC4_DEFAULT_STRB != 0) */

    /* Set default range */
    VDAC4_SetRange(VDAC4_DEFAULT_RANGE); 

    /* Set default speed */
    VDAC4_SetSpeed(VDAC4_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: VDAC4_Enable
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
void VDAC4_Enable(void) 
{
    VDAC4_PWRMGR |= VDAC4_ACT_PWR_EN;
    VDAC4_STBY_PWRMGR |= VDAC4_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(VDAC4_restoreVal == 1u) 
        {
             VDAC4_CR0 = VDAC4_backup.data_value;
             VDAC4_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: VDAC4_Start
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
*  VDAC4_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void VDAC4_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(VDAC4_initVar == 0u)
    { 
        VDAC4_Init();
        VDAC4_initVar = 1u;
    }

    /* Enable power to DAC */
    VDAC4_Enable();

    /* Set default value */
    VDAC4_SetValue(VDAC4_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: VDAC4_Stop
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
void VDAC4_Stop(void) 
{
    /* Disble power to DAC */
    VDAC4_PWRMGR &= (uint8)(~VDAC4_ACT_PWR_EN);
    VDAC4_STBY_PWRMGR &= (uint8)(~VDAC4_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        VDAC4_backup.data_value = VDAC4_CR0;
        VDAC4_CR0 = VDAC4_CUR_MODE_OUT_OFF;
        VDAC4_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: VDAC4_SetSpeed
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
void VDAC4_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    VDAC4_CR0 &= (uint8)(~VDAC4_HS_MASK);
    VDAC4_CR0 |=  (speed & VDAC4_HS_MASK);
}


/*******************************************************************************
* Function Name: VDAC4_SetRange
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
void VDAC4_SetRange(uint8 range) 
{
    VDAC4_CR0 &= (uint8)(~VDAC4_RANGE_MASK);      /* Clear existing mode */
    VDAC4_CR0 |= (range & VDAC4_RANGE_MASK);      /*  Set Range  */
    VDAC4_DacTrim();
}


/*******************************************************************************
* Function Name: VDAC4_SetValue
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
void VDAC4_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 VDAC4_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    VDAC4_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        VDAC4_Data = value;
        CyExitCriticalSection(VDAC4_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: VDAC4_DacTrim
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
void VDAC4_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((VDAC4_CR0 & VDAC4_RANGE_MASK) >> 2) + VDAC4_TRIM_M7_1V_RNG_OFFSET;
    VDAC4_TR = CY_GET_XTND_REG8((uint8 *)(VDAC4_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
