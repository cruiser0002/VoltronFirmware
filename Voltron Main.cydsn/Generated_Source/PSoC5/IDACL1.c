/*******************************************************************************
* File Name: IDACL1.c
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
#include "IDACL1.h"   

#if (CY_PSOC5A)
    #include <CyLib.h>
#endif /* CY_PSOC5A */


uint8 IDACL1_initVar = 0u;


#if (CY_PSOC5A)
    static IDACL1_LOWPOWER_BACKUP_STRUCT  IDACL1_lowPowerBackup;
#endif /* CY_PSOC5A */

/* Variable to decide whether or not to restore control register in Enable()
   API. This valid only for PSoC5A */
#if (CY_PSOC5A)
    static uint8 IDACL1_restoreReg = 0u;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: IDACL1_Init
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
void IDACL1_Init(void) 
{
    IDACL1_CR0 = (IDACL1_MODE_I | IDACL1_DEFAULT_RANGE );

    /* Set default data source */
    #if(IDACL1_DEFAULT_DATA_SRC != 0u )    
        IDACL1_CR1 = (IDACL1_DEFAULT_CNTL | IDACL1_DACBUS_ENABLE);
    #else
        IDACL1_CR1 = (IDACL1_DEFAULT_CNTL | IDACL1_DACBUS_DISABLE);
    #endif /* (IDACL1_DEFAULT_DATA_SRC != 0u ) */
    
    /*Controls polarity from UDB Control*/
    #if(IDACL1_DEFAULT_POLARITY == IDACL1_HARDWARE_CONTROLLED)
        IDACL1_CR1 |= IDACL1_IDIR_SRC_UDB;
    #else
        IDACL1_CR1 |= IDACL1_DEFAULT_POLARITY;
    #endif/* (IDACL1_DEFAULT_POLARITY == IDACL1_HARDWARE_CONTROLLED) */
    /*Controls Current Source from UDB Control*/
    #if(IDACL1_HARDWARE_ENABLE != 0u ) 
        IDACL1_CR1 |= IDACL1_IDIR_CTL_UDB;
    #endif /* (IDACL1_HARDWARE_ENABLE != 0u ) */ 
    
    /* Set default strobe mode */
    #if(IDACL1_DEFAULT_STRB != 0u)
        IDACL1_Strobe |= IDACL1_STRB_EN;
    #endif /* (IDACL1_DEFAULT_STRB != 0u) */
    
    /* Set default speed */
    IDACL1_SetSpeed(IDACL1_DEFAULT_SPEED);
    
    /* Set proper DAC trim */
    IDACL1_DacTrim();
    
}


/*******************************************************************************
* Function Name: IDACL1_Enable
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
void IDACL1_Enable(void) 
{
    IDACL1_PWRMGR |= IDACL1_ACT_PWR_EN;
    IDACL1_STBY_PWRMGR |= IDACL1_STBY_PWR_EN;

    /* This is to restore the value of register CR0 which is saved 
      in prior to the modification in stop() API */
    #if (CY_PSOC5A)
        if(IDACL1_restoreReg == 1u)
        {
            IDACL1_CR0 = IDACL1_lowPowerBackup.DACCR0Reg;

            /* Clear the flag */
            IDACL1_restoreReg = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACL1_Start
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
*  IDACL1_initVar: Is modified when this function is called for 
*   the first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void IDACL1_Start(void) 
{
    /* Hardware initiazation only needs to occur the first time */
    if ( IDACL1_initVar == 0u)  
    {
        IDACL1_Init();
        
        IDACL1_initVar = 1u;
    }
   
    /* Enable power to DAC */
    IDACL1_Enable();

    /* Set default value */
    IDACL1_SetValue(IDACL1_DEFAULT_DATA);

}


/*******************************************************************************
* Function Name: IDACL1_Stop
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
void IDACL1_Stop(void) 
{
    /* Disble power to DAC */
    IDACL1_PWRMGR &= (uint8)(~IDACL1_ACT_PWR_EN);
    IDACL1_STBY_PWRMGR &= (uint8)(~IDACL1_STBY_PWR_EN);
    
    #if (CY_PSOC5A)
    
        /* Set the global variable  */
        IDACL1_restoreReg = 1u;

        /* Save the control register and then Clear it. */
        IDACL1_lowPowerBackup.DACCR0Reg = IDACL1_CR0;
        IDACL1_CR0 = (IDACL1_MODE_I | IDACL1_RANGE_3 | IDACL1_HS_HIGHSPEED);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACL1_SetSpeed
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
void IDACL1_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    IDACL1_CR0 &= (uint8)(~IDACL1_HS_MASK);
    IDACL1_CR0 |=  ( speed & IDACL1_HS_MASK);
}


/*******************************************************************************
* Function Name: IDACL1_SetPolarity
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
#if(IDACL1_DEFAULT_POLARITY != IDACL1_HARDWARE_CONTROLLED)
    void IDACL1_SetPolarity(uint8 polarity) 
    {
        IDACL1_CR1 &= (uint8)(~IDACL1_IDIR_MASK);                /* clear polarity bit */
        IDACL1_CR1 |= (polarity & IDACL1_IDIR_MASK);             /* set new value */
    
        IDACL1_DacTrim();
    }
#endif/*(IDACL1_DEFAULT_POLARITY != IDACL1_HARDWARE_CONTROLLED)*/


/*******************************************************************************
* Function Name: IDACL1_SetRange
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
void IDACL1_SetRange(uint8 range) 
{
    IDACL1_CR0 &= (uint8)(~IDACL1_RANGE_MASK);       /* Clear existing mode */
    IDACL1_CR0 |= ( range & IDACL1_RANGE_MASK );     /*  Set Range  */
    IDACL1_DacTrim();
}


/*******************************************************************************
* Function Name: IDACL1_SetValue
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
void IDACL1_SetValue(uint8 value) 
{

    #if (CY_PSOC5A)
        uint8 IDACL1_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    IDACL1_Data = value;         /*  Set Value  */
    
    /* PSOC5A silicons require a double write */
    #if (CY_PSOC5A)
        IDACL1_Data = value;
        CyExitCriticalSection(IDACL1_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACL1_DacTrim
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
void IDACL1_DacTrim(void) 
{
    uint8 mode;

    mode = ((IDACL1_CR0 & IDACL1_RANGE_MASK) >> 1u);
    
    if((IDACL1_IDIR_MASK & IDACL1_CR1) == IDACL1_IDIR_SINK)
    {
        mode++;
    }

    IDACL1_TR = CY_GET_XTND_REG8((uint8 *)(IDACL1_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
