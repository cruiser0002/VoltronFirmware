/*******************************************************************************
* File Name: IDACL2.c
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
#include "IDACL2.h"   

#if (CY_PSOC5A)
    #include <CyLib.h>
#endif /* CY_PSOC5A */


uint8 IDACL2_initVar = 0u;


#if (CY_PSOC5A)
    static IDACL2_LOWPOWER_BACKUP_STRUCT  IDACL2_lowPowerBackup;
#endif /* CY_PSOC5A */

/* Variable to decide whether or not to restore control register in Enable()
   API. This valid only for PSoC5A */
#if (CY_PSOC5A)
    static uint8 IDACL2_restoreReg = 0u;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: IDACL2_Init
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
void IDACL2_Init(void) 
{
    IDACL2_CR0 = (IDACL2_MODE_I | IDACL2_DEFAULT_RANGE );

    /* Set default data source */
    #if(IDACL2_DEFAULT_DATA_SRC != 0u )    
        IDACL2_CR1 = (IDACL2_DEFAULT_CNTL | IDACL2_DACBUS_ENABLE);
    #else
        IDACL2_CR1 = (IDACL2_DEFAULT_CNTL | IDACL2_DACBUS_DISABLE);
    #endif /* (IDACL2_DEFAULT_DATA_SRC != 0u ) */
    
    /*Controls polarity from UDB Control*/
    #if(IDACL2_DEFAULT_POLARITY == IDACL2_HARDWARE_CONTROLLED)
        IDACL2_CR1 |= IDACL2_IDIR_SRC_UDB;
    #else
        IDACL2_CR1 |= IDACL2_DEFAULT_POLARITY;
    #endif/* (IDACL2_DEFAULT_POLARITY == IDACL2_HARDWARE_CONTROLLED) */
    /*Controls Current Source from UDB Control*/
    #if(IDACL2_HARDWARE_ENABLE != 0u ) 
        IDACL2_CR1 |= IDACL2_IDIR_CTL_UDB;
    #endif /* (IDACL2_HARDWARE_ENABLE != 0u ) */ 
    
    /* Set default strobe mode */
    #if(IDACL2_DEFAULT_STRB != 0u)
        IDACL2_Strobe |= IDACL2_STRB_EN;
    #endif /* (IDACL2_DEFAULT_STRB != 0u) */
    
    /* Set default speed */
    IDACL2_SetSpeed(IDACL2_DEFAULT_SPEED);
    
    /* Set proper DAC trim */
    IDACL2_DacTrim();
    
}


/*******************************************************************************
* Function Name: IDACL2_Enable
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
void IDACL2_Enable(void) 
{
    IDACL2_PWRMGR |= IDACL2_ACT_PWR_EN;
    IDACL2_STBY_PWRMGR |= IDACL2_STBY_PWR_EN;

    /* This is to restore the value of register CR0 which is saved 
      in prior to the modification in stop() API */
    #if (CY_PSOC5A)
        if(IDACL2_restoreReg == 1u)
        {
            IDACL2_CR0 = IDACL2_lowPowerBackup.DACCR0Reg;

            /* Clear the flag */
            IDACL2_restoreReg = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACL2_Start
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
*  IDACL2_initVar: Is modified when this function is called for 
*   the first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void IDACL2_Start(void) 
{
    /* Hardware initiazation only needs to occur the first time */
    if ( IDACL2_initVar == 0u)  
    {
        IDACL2_Init();
        
        IDACL2_initVar = 1u;
    }
   
    /* Enable power to DAC */
    IDACL2_Enable();

    /* Set default value */
    IDACL2_SetValue(IDACL2_DEFAULT_DATA);

}


/*******************************************************************************
* Function Name: IDACL2_Stop
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
void IDACL2_Stop(void) 
{
    /* Disble power to DAC */
    IDACL2_PWRMGR &= (uint8)(~IDACL2_ACT_PWR_EN);
    IDACL2_STBY_PWRMGR &= (uint8)(~IDACL2_STBY_PWR_EN);
    
    #if (CY_PSOC5A)
    
        /* Set the global variable  */
        IDACL2_restoreReg = 1u;

        /* Save the control register and then Clear it. */
        IDACL2_lowPowerBackup.DACCR0Reg = IDACL2_CR0;
        IDACL2_CR0 = (IDACL2_MODE_I | IDACL2_RANGE_3 | IDACL2_HS_HIGHSPEED);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACL2_SetSpeed
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
void IDACL2_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    IDACL2_CR0 &= (uint8)(~IDACL2_HS_MASK);
    IDACL2_CR0 |=  ( speed & IDACL2_HS_MASK);
}


/*******************************************************************************
* Function Name: IDACL2_SetPolarity
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
#if(IDACL2_DEFAULT_POLARITY != IDACL2_HARDWARE_CONTROLLED)
    void IDACL2_SetPolarity(uint8 polarity) 
    {
        IDACL2_CR1 &= (uint8)(~IDACL2_IDIR_MASK);                /* clear polarity bit */
        IDACL2_CR1 |= (polarity & IDACL2_IDIR_MASK);             /* set new value */
    
        IDACL2_DacTrim();
    }
#endif/*(IDACL2_DEFAULT_POLARITY != IDACL2_HARDWARE_CONTROLLED)*/


/*******************************************************************************
* Function Name: IDACL2_SetRange
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
void IDACL2_SetRange(uint8 range) 
{
    IDACL2_CR0 &= (uint8)(~IDACL2_RANGE_MASK);       /* Clear existing mode */
    IDACL2_CR0 |= ( range & IDACL2_RANGE_MASK );     /*  Set Range  */
    IDACL2_DacTrim();
}


/*******************************************************************************
* Function Name: IDACL2_SetValue
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
void IDACL2_SetValue(uint8 value) 
{

    #if (CY_PSOC5A)
        uint8 IDACL2_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    IDACL2_Data = value;         /*  Set Value  */
    
    /* PSOC5A silicons require a double write */
    #if (CY_PSOC5A)
        IDACL2_Data = value;
        CyExitCriticalSection(IDACL2_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACL2_DacTrim
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
void IDACL2_DacTrim(void) 
{
    uint8 mode;

    mode = ((IDACL2_CR0 & IDACL2_RANGE_MASK) >> 1u);
    
    if((IDACL2_IDIR_MASK & IDACL2_CR1) == IDACL2_IDIR_SINK)
    {
        mode++;
    }

    IDACL2_TR = CY_GET_XTND_REG8((uint8 *)(IDACL2_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
