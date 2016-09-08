/*******************************************************************************
* File Name: VDACL.c  
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
#include "VDACL.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 VDACL_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 VDACL_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static VDACL_backupStruct VDACL_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: VDACL_Init
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
void VDACL_Init(void) 
{
    VDACL_CR0 = (VDACL_MODE_V );

    /* Set default data source */
    #if(VDACL_DEFAULT_DATA_SRC != 0 )
        VDACL_CR1 = (VDACL_DEFAULT_CNTL | VDACL_DACBUS_ENABLE) ;
    #else
        VDACL_CR1 = (VDACL_DEFAULT_CNTL | VDACL_DACBUS_DISABLE) ;
    #endif /* (VDACL_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(VDACL_DEFAULT_STRB != 0)
        VDACL_Strobe |= VDACL_STRB_EN ;
    #endif/* (VDACL_DEFAULT_STRB != 0) */

    /* Set default range */
    VDACL_SetRange(VDACL_DEFAULT_RANGE); 

    /* Set default speed */
    VDACL_SetSpeed(VDACL_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: VDACL_Enable
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
void VDACL_Enable(void) 
{
    VDACL_PWRMGR |= VDACL_ACT_PWR_EN;
    VDACL_STBY_PWRMGR |= VDACL_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(VDACL_restoreVal == 1u) 
        {
             VDACL_CR0 = VDACL_backup.data_value;
             VDACL_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: VDACL_Start
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
*  VDACL_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void VDACL_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(VDACL_initVar == 0u)
    { 
        VDACL_Init();
        VDACL_initVar = 1u;
    }

    /* Enable power to DAC */
    VDACL_Enable();

    /* Set default value */
    VDACL_SetValue(VDACL_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: VDACL_Stop
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
void VDACL_Stop(void) 
{
    /* Disble power to DAC */
    VDACL_PWRMGR &= (uint8)(~VDACL_ACT_PWR_EN);
    VDACL_STBY_PWRMGR &= (uint8)(~VDACL_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        VDACL_backup.data_value = VDACL_CR0;
        VDACL_CR0 = VDACL_CUR_MODE_OUT_OFF;
        VDACL_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: VDACL_SetSpeed
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
void VDACL_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    VDACL_CR0 &= (uint8)(~VDACL_HS_MASK);
    VDACL_CR0 |=  (speed & VDACL_HS_MASK);
}


/*******************************************************************************
* Function Name: VDACL_SetRange
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
void VDACL_SetRange(uint8 range) 
{
    VDACL_CR0 &= (uint8)(~VDACL_RANGE_MASK);      /* Clear existing mode */
    VDACL_CR0 |= (range & VDACL_RANGE_MASK);      /*  Set Range  */
    VDACL_DacTrim();
}


/*******************************************************************************
* Function Name: VDACL_SetValue
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
void VDACL_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 VDACL_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    VDACL_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        VDACL_Data = value;
        CyExitCriticalSection(VDACL_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: VDACL_DacTrim
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
void VDACL_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((VDACL_CR0 & VDACL_RANGE_MASK) >> 2) + VDACL_TRIM_M7_1V_RNG_OFFSET;
    VDACL_TR = CY_GET_XTND_REG8((uint8 *)(VDACL_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
