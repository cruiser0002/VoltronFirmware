/*******************************************************************************
* File Name: IDACH.c
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


#include "IDACH.h"

static IDACH_backupStruct IDACH_backup;


/*******************************************************************************
* Function Name: IDACH_SaveConfig
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
void IDACH_SaveConfig(void) 
{
    if (!((IDACH_CR1 & IDACH_SRC_MASK) == IDACH_SRC_UDB))
    {
        IDACH_backup.data_value = IDACH_Data;
    }
}


/*******************************************************************************
* Function Name: IDACH_RestoreConfig
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
void IDACH_RestoreConfig(void) 
{
    if (!((IDACH_CR1 & IDACH_SRC_MASK) == IDACH_SRC_UDB))
    {
        if((IDACH_Strobe & IDACH_STRB_MASK) == IDACH_STRB_EN)
        {
            IDACH_Strobe &= (uint8)(~IDACH_STRB_MASK);
            IDACH_Data = IDACH_backup.data_value;
            IDACH_Strobe |= IDACH_STRB_EN;
        }
        else
        {
            IDACH_Data = IDACH_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: IDACH_Sleep
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
*  IDACH_backup.enableState: Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void IDACH_Sleep(void) 
{
    if(IDACH_ACT_PWR_EN == (IDACH_PWRMGR & IDACH_ACT_PWR_EN))
    {
        /* IDAC8 is enabled */
        IDACH_backup.enableState = 1u;
    }
    else
    {
        /* IDAC8 is disabled */
        IDACH_backup.enableState = 0u;
    }

    IDACH_Stop();
    IDACH_SaveConfig();
}


/*******************************************************************************
* Function Name: IDACH_Wakeup
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
*  IDACH_backup.enableState: Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void IDACH_Wakeup(void) 
{
    IDACH_RestoreConfig();
    
    if(IDACH_backup.enableState == 1u)
    {
        /* Enable IDAC8's operation */
        IDACH_Enable();
        
        /* Set the data register */
        IDACH_SetValue(IDACH_Data);
    } /* Do nothing if IDAC8 was disabled before */    
}


/* [] END OF FILE */
