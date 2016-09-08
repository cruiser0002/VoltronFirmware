/*******************************************************************************
* File Name: IDACH.c
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
#include "IDACH.h"   

#if (CY_PSOC5A)
    #include <CyLib.h>
#endif /* CY_PSOC5A */


uint8 IDACH_initVar = 0u;


#if (CY_PSOC5A)
    static IDACH_LOWPOWER_BACKUP_STRUCT  IDACH_lowPowerBackup;
#endif /* CY_PSOC5A */

/* Variable to decide whether or not to restore control register in Enable()
   API. This valid only for PSoC5A */
#if (CY_PSOC5A)
    static uint8 IDACH_restoreReg = 0u;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: IDACH_Init
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
void IDACH_Init(void) 
{
    IDACH_CR0 = (IDACH_MODE_I | IDACH_DEFAULT_RANGE );

    /* Set default data source */
    #if(IDACH_DEFAULT_DATA_SRC != 0u )    
        IDACH_CR1 = (IDACH_DEFAULT_CNTL | IDACH_DACBUS_ENABLE);
    #else
        IDACH_CR1 = (IDACH_DEFAULT_CNTL | IDACH_DACBUS_DISABLE);
    #endif /* (IDACH_DEFAULT_DATA_SRC != 0u ) */
    
    /*Controls polarity from UDB Control*/
    #if(IDACH_DEFAULT_POLARITY == IDACH_HARDWARE_CONTROLLED)
        IDACH_CR1 |= IDACH_IDIR_SRC_UDB;
    #else
        IDACH_CR1 |= IDACH_DEFAULT_POLARITY;
    #endif/* (IDACH_DEFAULT_POLARITY == IDACH_HARDWARE_CONTROLLED) */
    /*Controls Current Source from UDB Control*/
    #if(IDACH_HARDWARE_ENABLE != 0u ) 
        IDACH_CR1 |= IDACH_IDIR_CTL_UDB;
    #endif /* (IDACH_HARDWARE_ENABLE != 0u ) */ 
    
    /* Set default strobe mode */
    #if(IDACH_DEFAULT_STRB != 0u)
        IDACH_Strobe |= IDACH_STRB_EN;
    #endif /* (IDACH_DEFAULT_STRB != 0u) */
    
    /* Set default speed */
    IDACH_SetSpeed(IDACH_DEFAULT_SPEED);
    
    /* Set proper DAC trim */
    IDACH_DacTrim();
    
}


/*******************************************************************************
* Function Name: IDACH_Enable
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
void IDACH_Enable(void) 
{
    IDACH_PWRMGR |= IDACH_ACT_PWR_EN;
    IDACH_STBY_PWRMGR |= IDACH_STBY_PWR_EN;

    /* This is to restore the value of register CR0 which is saved 
      in prior to the modification in stop() API */
    #if (CY_PSOC5A)
        if(IDACH_restoreReg == 1u)
        {
            IDACH_CR0 = IDACH_lowPowerBackup.DACCR0Reg;

            /* Clear the flag */
            IDACH_restoreReg = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACH_Start
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
*  IDACH_initVar: Is modified when this function is called for 
*   the first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void IDACH_Start(void) 
{
    /* Hardware initiazation only needs to occur the first time */
    if ( IDACH_initVar == 0u)  
    {
        IDACH_Init();
        
        IDACH_initVar = 1u;
    }
   
    /* Enable power to DAC */
    IDACH_Enable();

    /* Set default value */
    IDACH_SetValue(IDACH_DEFAULT_DATA);

}


/*******************************************************************************
* Function Name: IDACH_Stop
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
void IDACH_Stop(void) 
{
    /* Disble power to DAC */
    IDACH_PWRMGR &= (uint8)(~IDACH_ACT_PWR_EN);
    IDACH_STBY_PWRMGR &= (uint8)(~IDACH_STBY_PWR_EN);
    
    #if (CY_PSOC5A)
    
        /* Set the global variable  */
        IDACH_restoreReg = 1u;

        /* Save the control register and then Clear it. */
        IDACH_lowPowerBackup.DACCR0Reg = IDACH_CR0;
        IDACH_CR0 = (IDACH_MODE_I | IDACH_RANGE_3 | IDACH_HS_HIGHSPEED);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACH_SetSpeed
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
void IDACH_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    IDACH_CR0 &= (uint8)(~IDACH_HS_MASK);
    IDACH_CR0 |=  ( speed & IDACH_HS_MASK);
}


/*******************************************************************************
* Function Name: IDACH_SetPolarity
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
#if(IDACH_DEFAULT_POLARITY != IDACH_HARDWARE_CONTROLLED)
    void IDACH_SetPolarity(uint8 polarity) 
    {
        IDACH_CR1 &= (uint8)(~IDACH_IDIR_MASK);                /* clear polarity bit */
        IDACH_CR1 |= (polarity & IDACH_IDIR_MASK);             /* set new value */
    
        IDACH_DacTrim();
    }
#endif/*(IDACH_DEFAULT_POLARITY != IDACH_HARDWARE_CONTROLLED)*/


/*******************************************************************************
* Function Name: IDACH_SetRange
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
void IDACH_SetRange(uint8 range) 
{
    IDACH_CR0 &= (uint8)(~IDACH_RANGE_MASK);       /* Clear existing mode */
    IDACH_CR0 |= ( range & IDACH_RANGE_MASK );     /*  Set Range  */
    IDACH_DacTrim();
}


/*******************************************************************************
* Function Name: IDACH_SetValue
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
void IDACH_SetValue(uint8 value) 
{

    #if (CY_PSOC5A)
        uint8 IDACH_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    IDACH_Data = value;         /*  Set Value  */
    
    /* PSOC5A silicons require a double write */
    #if (CY_PSOC5A)
        IDACH_Data = value;
        CyExitCriticalSection(IDACH_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACH_DacTrim
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
void IDACH_DacTrim(void) 
{
    uint8 mode;

    mode = ((IDACH_CR0 & IDACH_RANGE_MASK) >> 1u);
    
    if((IDACH_IDIR_MASK & IDACH_CR1) == IDACH_IDIR_SINK)
    {
        mode++;
    }

    IDACH_TR = CY_GET_XTND_REG8((uint8 *)(IDACH_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
