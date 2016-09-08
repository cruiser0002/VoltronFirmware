/*******************************************************************************
* File Name: IDACL.c
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
#include "IDACL.h"   

#if (CY_PSOC5A)
    #include <CyLib.h>
#endif /* CY_PSOC5A */


uint8 IDACL_initVar = 0u;


#if (CY_PSOC5A)
    static IDACL_LOWPOWER_BACKUP_STRUCT  IDACL_lowPowerBackup;
#endif /* CY_PSOC5A */

/* Variable to decide whether or not to restore control register in Enable()
   API. This valid only for PSoC5A */
#if (CY_PSOC5A)
    static uint8 IDACL_restoreReg = 0u;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: IDACL_Init
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
void IDACL_Init(void) 
{
    IDACL_CR0 = (IDACL_MODE_I | IDACL_DEFAULT_RANGE );

    /* Set default data source */
    #if(IDACL_DEFAULT_DATA_SRC != 0u )    
        IDACL_CR1 = (IDACL_DEFAULT_CNTL | IDACL_DACBUS_ENABLE);
    #else
        IDACL_CR1 = (IDACL_DEFAULT_CNTL | IDACL_DACBUS_DISABLE);
    #endif /* (IDACL_DEFAULT_DATA_SRC != 0u ) */
    
    /*Controls polarity from UDB Control*/
    #if(IDACL_DEFAULT_POLARITY == IDACL_HARDWARE_CONTROLLED)
        IDACL_CR1 |= IDACL_IDIR_SRC_UDB;
    #else
        IDACL_CR1 |= IDACL_DEFAULT_POLARITY;
    #endif/* (IDACL_DEFAULT_POLARITY == IDACL_HARDWARE_CONTROLLED) */
    /*Controls Current Source from UDB Control*/
    #if(IDACL_HARDWARE_ENABLE != 0u ) 
        IDACL_CR1 |= IDACL_IDIR_CTL_UDB;
    #endif /* (IDACL_HARDWARE_ENABLE != 0u ) */ 
    
    /* Set default strobe mode */
    #if(IDACL_DEFAULT_STRB != 0u)
        IDACL_Strobe |= IDACL_STRB_EN;
    #endif /* (IDACL_DEFAULT_STRB != 0u) */
    
    /* Set default speed */
    IDACL_SetSpeed(IDACL_DEFAULT_SPEED);
    
    /* Set proper DAC trim */
    IDACL_DacTrim();
    
}


/*******************************************************************************
* Function Name: IDACL_Enable
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
void IDACL_Enable(void) 
{
    IDACL_PWRMGR |= IDACL_ACT_PWR_EN;
    IDACL_STBY_PWRMGR |= IDACL_STBY_PWR_EN;

    /* This is to restore the value of register CR0 which is saved 
      in prior to the modification in stop() API */
    #if (CY_PSOC5A)
        if(IDACL_restoreReg == 1u)
        {
            IDACL_CR0 = IDACL_lowPowerBackup.DACCR0Reg;

            /* Clear the flag */
            IDACL_restoreReg = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACL_Start
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
*  IDACL_initVar: Is modified when this function is called for 
*   the first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void IDACL_Start(void) 
{
    /* Hardware initiazation only needs to occur the first time */
    if ( IDACL_initVar == 0u)  
    {
        IDACL_Init();
        
        IDACL_initVar = 1u;
    }
   
    /* Enable power to DAC */
    IDACL_Enable();

    /* Set default value */
    IDACL_SetValue(IDACL_DEFAULT_DATA);

}


/*******************************************************************************
* Function Name: IDACL_Stop
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
void IDACL_Stop(void) 
{
    /* Disble power to DAC */
    IDACL_PWRMGR &= (uint8)(~IDACL_ACT_PWR_EN);
    IDACL_STBY_PWRMGR &= (uint8)(~IDACL_STBY_PWR_EN);
    
    #if (CY_PSOC5A)
    
        /* Set the global variable  */
        IDACL_restoreReg = 1u;

        /* Save the control register and then Clear it. */
        IDACL_lowPowerBackup.DACCR0Reg = IDACL_CR0;
        IDACL_CR0 = (IDACL_MODE_I | IDACL_RANGE_3 | IDACL_HS_HIGHSPEED);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACL_SetSpeed
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
void IDACL_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    IDACL_CR0 &= (uint8)(~IDACL_HS_MASK);
    IDACL_CR0 |=  ( speed & IDACL_HS_MASK);
}


/*******************************************************************************
* Function Name: IDACL_SetPolarity
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
#if(IDACL_DEFAULT_POLARITY != IDACL_HARDWARE_CONTROLLED)
    void IDACL_SetPolarity(uint8 polarity) 
    {
        IDACL_CR1 &= (uint8)(~IDACL_IDIR_MASK);                /* clear polarity bit */
        IDACL_CR1 |= (polarity & IDACL_IDIR_MASK);             /* set new value */
    
        IDACL_DacTrim();
    }
#endif/*(IDACL_DEFAULT_POLARITY != IDACL_HARDWARE_CONTROLLED)*/


/*******************************************************************************
* Function Name: IDACL_SetRange
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
void IDACL_SetRange(uint8 range) 
{
    IDACL_CR0 &= (uint8)(~IDACL_RANGE_MASK);       /* Clear existing mode */
    IDACL_CR0 |= ( range & IDACL_RANGE_MASK );     /*  Set Range  */
    IDACL_DacTrim();
}


/*******************************************************************************
* Function Name: IDACL_SetValue
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
void IDACL_SetValue(uint8 value) 
{

    #if (CY_PSOC5A)
        uint8 IDACL_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    IDACL_Data = value;         /*  Set Value  */
    
    /* PSOC5A silicons require a double write */
    #if (CY_PSOC5A)
        IDACL_Data = value;
        CyExitCriticalSection(IDACL_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: IDACL_DacTrim
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
void IDACL_DacTrim(void) 
{
    uint8 mode;

    mode = ((IDACL_CR0 & IDACL_RANGE_MASK) >> 1u);
    
    if((IDACL_IDIR_MASK & IDACL_CR1) == IDACL_IDIR_SINK)
    {
        mode++;
    }

    IDACL_TR = CY_GET_XTND_REG8((uint8 *)(IDACL_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
