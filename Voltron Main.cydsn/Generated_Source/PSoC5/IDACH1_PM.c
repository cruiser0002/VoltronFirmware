/*******************************************************************************
* File Name: IDACH1.c
* Version 2.0
*
* Description:
*  This file provides the power management source code to API for the
*  IDAC8.
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


#include "IDACH1.h"

static IDACH1_backupStruct IDACH1_backup;


/*******************************************************************************
* Function Name: IDACH1_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void IDACH1_SaveConfig(void) 
{
    if (!((IDACH1_CR1 & IDACH1_SRC_MASK) == IDACH1_SRC_UDB))
    {
        IDACH1_backup.data_value = IDACH1_Data;
    }
}


/*******************************************************************************
* Function Name: IDACH1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void IDACH1_RestoreConfig(void) 
{
    if (!((IDACH1_CR1 & IDACH1_SRC_MASK) == IDACH1_SRC_UDB))
    {
        if((IDACH1_Strobe & IDACH1_STRB_MASK) == IDACH1_STRB_EN)
        {
            IDACH1_Strobe &= (uint8)(~IDACH1_STRB_MASK);
            IDACH1_Data = IDACH1_backup.data_value;
            IDACH1_Strobe |= IDACH1_STRB_EN;
        }
        else
        {
            IDACH1_Data = IDACH1_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: IDACH1_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
* Global variables:
*  IDACH1_backup.enableState: Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void IDACH1_Sleep(void) 
{
    if(IDACH1_ACT_PWR_EN == (IDACH1_PWRMGR & IDACH1_ACT_PWR_EN))
    {
        /* IDAC8 is enabled */
        IDACH1_backup.enableState = 1u;
    }
    else
    {
        /* IDAC8 is disabled */
        IDACH1_backup.enableState = 0u;
    }

    IDACH1_Stop();
    IDACH1_SaveConfig();
}


/*******************************************************************************
* Function Name: IDACH1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  IDACH1_backup.enableState: Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void IDACH1_Wakeup(void) 
{
    IDACH1_RestoreConfig();
    
    if(IDACH1_backup.enableState == 1u)
    {
        /* Enable IDAC8's operation */
        IDACH1_Enable();
        
        /* Set the data register */
        IDACH1_SetValue(IDACH1_Data);
    } /* Do nothing if IDAC8 was disabled before */    
}


/* [] END OF FILE */
