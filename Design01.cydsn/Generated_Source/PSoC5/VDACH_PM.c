/*******************************************************************************
* File Name: VDACH_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
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

#include "VDACH.h"

static VDACH_backupStruct VDACH_backup;


/*******************************************************************************
* Function Name: VDACH_SaveConfig
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
void VDACH_SaveConfig(void) 
{
    if (!((VDACH_CR1 & VDACH_SRC_MASK) == VDACH_SRC_UDB))
    {
        VDACH_backup.data_value = VDACH_Data;
    }
}


/*******************************************************************************
* Function Name: VDACH_RestoreConfig
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
void VDACH_RestoreConfig(void) 
{
    if (!((VDACH_CR1 & VDACH_SRC_MASK) == VDACH_SRC_UDB))
    {
        if((VDACH_Strobe & VDACH_STRB_MASK) == VDACH_STRB_EN)
        {
            VDACH_Strobe &= (uint8)(~VDACH_STRB_MASK);
            VDACH_Data = VDACH_backup.data_value;
            VDACH_Strobe |= VDACH_STRB_EN;
        }
        else
        {
            VDACH_Data = VDACH_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: VDACH_Sleep
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
*  VDACH_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void VDACH_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(VDACH_ACT_PWR_EN == (VDACH_PWRMGR & VDACH_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        VDACH_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        VDACH_backup.enableState = 0u;
    }
    
    VDACH_Stop();
    VDACH_SaveConfig();
}


/*******************************************************************************
* Function Name: VDACH_Wakeup
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
*  VDACH_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VDACH_Wakeup(void) 
{
    VDACH_RestoreConfig();
    
    if(VDACH_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        VDACH_Enable();

        /* Restore the data register */
        VDACH_SetValue(VDACH_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
