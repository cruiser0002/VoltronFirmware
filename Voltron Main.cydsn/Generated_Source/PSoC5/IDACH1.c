/*******************************************************************************
* File Name: IDACH1.c
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
#include "IDACH1.h"   

#if (CY_PSOC5A)
    #include <CyLib.h>
#endif /* CY_PSOC5A */


uint8 IDACH1_initVar = 0u;


#if (CY_PSOC5A)
    static IDACH1_LOWPOWER_BACKUP_STRUCT  IDACH1_lowPowerBackup;
#endif /* CY_PSOC5A */

/* Variable to decide whether or not to restore control register in Enable()
   API. This valid only for PSoC5A */
#if (CY_PSOC5A)
    static uint8 IDACH1_restoreReg = 0u;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: IDACH1_Init
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
void IDACH1_Init(void) 
{
    IDACH1_CR0 = (IDACH1_MODE_I | IDACH1_DEFAULT_RANGE );

    /* Set default data source */
    #if(IDACH1_DEFAULT_DATA_SRC != 0u )    
        IDACH1_CR1 = (IDACH1_DEFAULT_CNTL | IDACH1_DACBUS_ENABLE);
    #else
        IDACH1_CR1 = (IDACH1_DEFAULT_CNTL | IDACH1_DACBUS_DISABLE);
    #endif /* (IDACH1_DEFAULT_DATA_SRC != 0u ) */
    
    /*Controls polarity from UDB Control*/
    #if(IDACH1_DEFAULT_POLARITY == IDACH1_HARDWARE_CONTROLLED)
        IDACH1_CR1 |= IDACH1_IDIR_SRC_UDB;
    #else
        IDACH1_CR1 |= IDACH1_DEFAULT_POLARITY;
    #endif/* (IDACH1_DEFAULT_POLARITY == IDACH1_HARDWARE_CONTROLLED) */
    /*Controls Current Source from UDB Control*/
    #if(IDACH1_HARDWARE_ENABLE != 0u ) 
        IDACH1_CR1 |= IDACH1_IDIR_CTL_UDB;
    #endif /* (IDACH1_HARDWARE_ENABLE != 0u ) */ 
    
    /* Set default strobe mode */
    #if(IDACH1_DEFAULT_STRB != 0u)
        IDACH1_Strobe |= IDACH1_STRB_EN;
    #endif /* (IDACH1_DEFAULT_STRB != 0u) */
    
    /* Set default speed */
    IDACH1_SetSpeed(IDACH1_DEFAULT_SPEED);
    
    /* Set proper DAC trim */
    IDACH1_DacTrim();
    
}


/*******************************************************************************
* Function Name: IDACH1_Enable
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
void IDACH1_Enable(void) 
{
    IDACH1_PWRMGR |= IDACH1_ACT_PWR_EN;
    IDACH1_STBY_PWRMGR |= IDACH1_STBY_PWR_EN;

    /* This is to restore the value of register CR0 which is saved 
      in prior to the modification in stop() API */
    #if (CY_PSOC5A)
        if(IDACH1_restoreReg == 1u)
        {
            IDACH1_CR0 = IDACH1_lowPowerBackup.DACCR0Reg;

            /* Clear the flag */
            IDACH1_restoreReg = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACH1_Start
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
*  IDACH1_initVar: Is modified when this function is called for 
*   the first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void IDACH1_Start(void) 
{
    /* Hardware initiazation only needs to occur the first time */
    if ( IDACH1_initVar == 0u)  
    {
        IDACH1_Init();
        
        IDACH1_initVar = 1u;
    }
   
    /* Enable power to DAC */
    IDACH1_Enable();

    /* Set default value */
    IDACH1_SetValue(IDACH1_DEFAULT_DATA);

}


/*******************************************************************************
* Function Name: IDACH1_Stop
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
void IDACH1_Stop(void) 
{
    /* Disble power to DAC */
    IDACH1_PWRMGR &= (uint8)(~IDACH1_ACT_PWR_EN);
    IDACH1_STBY_PWRMGR &= (uint8)(~IDACH1_STBY_PWR_EN);
    
    #if (CY_PSOC5A)
    
        /* Set the global variable  */
        IDACH1_restoreReg = 1u;

        /* Save the control register and then Clear it. */
        IDACH1_lowPowerBackup.DACCR0Reg = IDACH1_CR0;
        IDACH1_CR0 = (IDACH1_MODE_I | IDACH1_RANGE_3 | IDACH1_HS_HIGHSPEED);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACH1_SetSpeed
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
void IDACH1_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    IDACH1_CR0 &= (uint8)(~IDACH1_HS_MASK);
    IDACH1_CR0 |=  ( speed & IDACH1_HS_MASK);
}


/*******************************************************************************
* Function Name: IDACH1_SetPolarity
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
#if(IDACH1_DEFAULT_POLARITY != IDACH1_HARDWARE_CONTROLLED)
    void IDACH1_SetPolarity(uint8 polarity) 
    {
        IDACH1_CR1 &= (uint8)(~IDACH1_IDIR_MASK);                /* clear polarity bit */
        IDACH1_CR1 |= (polarity & IDACH1_IDIR_MASK);             /* set new value */
    
        IDACH1_DacTrim();
    }
#endif/*(IDACH1_DEFAULT_POLARITY != IDACH1_HARDWARE_CONTROLLED)*/


/*******************************************************************************
* Function Name: IDACH1_SetRange
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
void IDACH1_SetRange(uint8 range) 
{
    IDACH1_CR0 &= (uint8)(~IDACH1_RANGE_MASK);       /* Clear existing mode */
    IDACH1_CR0 |= ( range & IDACH1_RANGE_MASK );     /*  Set Range  */
    IDACH1_DacTrim();
}


/*******************************************************************************
* Function Name: IDACH1_SetValue
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
void IDACH1_SetValue(uint8 value) 
{

    #if (CY_PSOC5A)
        uint8 IDACH1_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    IDACH1_Data = value;         /*  Set Value  */
    
    /* PSOC5A silicons require a double write */
    #if (CY_PSOC5A)
        IDACH1_Data = value;
        CyExitCriticalSection(IDACH1_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACH1_DacTrim
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
void IDACH1_DacTrim(void) 
{
    uint8 mode;

    mode = ((IDACH1_CR0 & IDACH1_RANGE_MASK) >> 1u);
    
    if((IDACH1_IDIR_MASK & IDACH1_CR1) == IDACH1_IDIR_SINK)
    {
        mode++;
    }

    IDACH1_TR = CY_GET_XTND_REG8((uint8 *)(IDACH1_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
