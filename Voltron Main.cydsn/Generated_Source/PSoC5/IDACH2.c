/*******************************************************************************
* File Name: IDACH2.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the 8-bit Current 
*  DAC (IDAC8) User Module.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "IDACH2.h"   

#if (CY_PSOC5A)
    #include <CyLib.h>
#endif /* CY_PSOC5A */


uint8 IDACH2_initVar = 0u;


#if (CY_PSOC5A)
    static IDACH2_LOWPOWER_BACKUP_STRUCT  IDACH2_lowPowerBackup;
#endif /* CY_PSOC5A */

/* Variable to decide whether or not to restore control register in Enable()
   API. This valid only for PSoC5A */
#if (CY_PSOC5A)
    static uint8 IDACH2_restoreReg = 0u;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: IDACH2_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void IDACH2_Init(void) 
{
    IDACH2_CR0 = (IDACH2_MODE_I | IDACH2_DEFAULT_RANGE );

    /* Set default data source */
    #if(IDACH2_DEFAULT_DATA_SRC != 0u )    
        IDACH2_CR1 = (IDACH2_DEFAULT_CNTL | IDACH2_DACBUS_ENABLE);
    #else
        IDACH2_CR1 = (IDACH2_DEFAULT_CNTL | IDACH2_DACBUS_DISABLE);
    #endif /* (IDACH2_DEFAULT_DATA_SRC != 0u ) */
    
    /*Controls polarity from UDB Control*/
    #if(IDACH2_DEFAULT_POLARITY == IDACH2_HARDWARE_CONTROLLED)
        IDACH2_CR1 |= IDACH2_IDIR_SRC_UDB;
    #else
        IDACH2_CR1 |= IDACH2_DEFAULT_POLARITY;
    #endif/* (IDACH2_DEFAULT_POLARITY == IDACH2_HARDWARE_CONTROLLED) */
    /*Controls Current Source from UDB Control*/
    #if(IDACH2_HARDWARE_ENABLE != 0u ) 
        IDACH2_CR1 |= IDACH2_IDIR_CTL_UDB;
    #endif /* (IDACH2_HARDWARE_ENABLE != 0u ) */ 
    
    /* Set default strobe mode */
    #if(IDACH2_DEFAULT_STRB != 0u)
        IDACH2_Strobe |= IDACH2_STRB_EN;
    #endif /* (IDACH2_DEFAULT_STRB != 0u) */
    
    /* Set default speed */
    IDACH2_SetSpeed(IDACH2_DEFAULT_SPEED);
    
    /* Set proper DAC trim */
    IDACH2_DacTrim();
    
}


/*******************************************************************************
* Function Name: IDACH2_Enable
********************************************************************************
* Summary:
*  Enable the IDAC8
* 
* Parameters:
*  void:
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void IDACH2_Enable(void) 
{
    IDACH2_PWRMGR |= IDACH2_ACT_PWR_EN;
    IDACH2_STBY_PWRMGR |= IDACH2_STBY_PWR_EN;

    /* This is to restore the value of register CR0 which is saved 
      in prior to the modification in stop() API */
    #if (CY_PSOC5A)
        if(IDACH2_restoreReg == 1u)
        {
            IDACH2_CR0 = IDACH2_lowPowerBackup.DACCR0Reg;

            /* Clear the flag */
            IDACH2_restoreReg = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACH2_Start
********************************************************************************
* Summary:
*  Set power level then turn on IDAC8.
*
* Parameters:  
*  power: Sets power level between off (0) and (3) high power
*
* Return:
*  (void)
*
* Global variables:
*  IDACH2_initVar: Is modified when this function is called for 
*   the first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void IDACH2_Start(void) 
{
    /* Hardware initiazation only needs to occur the first time */
    if ( IDACH2_initVar == 0u)  
    {
        IDACH2_Init();
        
        IDACH2_initVar = 1u;
    }
   
    /* Enable power to DAC */
    IDACH2_Enable();

    /* Set default value */
    IDACH2_SetValue(IDACH2_DEFAULT_DATA);

}


/*******************************************************************************
* Function Name: IDACH2_Stop
********************************************************************************
* Summary:
*  Powers down IDAC8 to lowest power state.
*
* Parameters:
*  (void)
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void IDACH2_Stop(void) 
{
    /* Disble power to DAC */
    IDACH2_PWRMGR &= (uint8)(~IDACH2_ACT_PWR_EN);
    IDACH2_STBY_PWRMGR &= (uint8)(~IDACH2_STBY_PWR_EN);
    
    #if (CY_PSOC5A)
    
        /* Set the global variable  */
        IDACH2_restoreReg = 1u;

        /* Save the control register and then Clear it. */
        IDACH2_lowPowerBackup.DACCR0Reg = IDACH2_CR0;
        IDACH2_CR0 = (IDACH2_MODE_I | IDACH2_RANGE_3 | IDACH2_HS_HIGHSPEED);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACH2_SetSpeed
********************************************************************************
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void IDACH2_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    IDACH2_CR0 &= (uint8)(~IDACH2_HS_MASK);
    IDACH2_CR0 |=  ( speed & IDACH2_HS_MASK);
}


/*******************************************************************************
* Function Name: IDACH2_SetPolarity
********************************************************************************
* Summary:
*  Sets IDAC to Sink or Source current.
*  
* Parameters:
*  Polarity: Sets the IDAC to Sink or Source 
*  0x00 - Source
*  0x04 - Sink
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
#if(IDACH2_DEFAULT_POLARITY != IDACH2_HARDWARE_CONTROLLED)
    void IDACH2_SetPolarity(uint8 polarity) 
    {
        IDACH2_CR1 &= (uint8)(~IDACH2_IDIR_MASK);                /* clear polarity bit */
        IDACH2_CR1 |= (polarity & IDACH2_IDIR_MASK);             /* set new value */
    
        IDACH2_DacTrim();
    }
#endif/*(IDACH2_DEFAULT_POLARITY != IDACH2_HARDWARE_CONTROLLED)*/


/*******************************************************************************
* Function Name: IDACH2_SetRange
********************************************************************************
* Summary:
*  Set current range
*
* Parameters:
*  Range: Sets on of four valid ranges.
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void IDACH2_SetRange(uint8 range) 
{
    IDACH2_CR0 &= (uint8)(~IDACH2_RANGE_MASK);       /* Clear existing mode */
    IDACH2_CR0 |= ( range & IDACH2_RANGE_MASK );     /*  Set Range  */
    IDACH2_DacTrim();
}


/*******************************************************************************
* Function Name: IDACH2_SetValue
********************************************************************************
* Summary:
*  Set DAC value
*
* Parameters:
*  value: Sets DAC value between 0 and 255.
*
* Return:
*  (void)
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void IDACH2_SetValue(uint8 value) 
{

    #if (CY_PSOC5A)
        uint8 IDACH2_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    IDACH2_Data = value;         /*  Set Value  */
    
    /* PSOC5A silicons require a double write */
    #if (CY_PSOC5A)
        IDACH2_Data = value;
        CyExitCriticalSection(IDACH2_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACH2_DacTrim
********************************************************************************
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  None
*
* Return:
*  (void) 
*
* Theory:
*  Trim values for the IDAC blocks are stored in the "Customer Table" area in 
*  Row 1 of the Hidden Flash.  There are 8 bytes of trim data for each 
*  IDAC block.
*  The values are:
*       I Gain offset, min range, Sourcing
*       I Gain offset, min range, Sinking
*       I Gain offset, med range, Sourcing
*       I Gain offset, med range, Sinking
*       I Gain offset, max range, Sourcing
*       I Gain offset, max range, Sinking
*       V Gain offset, 1V range
*       V Gain offset, 4V range
*
* Side Effects:
*
*******************************************************************************/
void IDACH2_DacTrim(void) 
{
    uint8 mode;

    mode = ((IDACH2_CR0 & IDACH2_RANGE_MASK) >> 1u);
    
    if((IDACH2_IDIR_MASK & IDACH2_CR1) == IDACH2_IDIR_SINK)
    {
        mode++;
    }

    IDACH2_TR = CY_GET_XTND_REG8((uint8 *)(IDACH2_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
