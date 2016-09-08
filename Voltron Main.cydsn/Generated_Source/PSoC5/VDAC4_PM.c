/*******************************************************************************
* File Name: VDAC4_PM.c  
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

#include "VDAC4.h"

static VDAC4_backupStruct VDAC4_backup;


/*******************************************************************************
* Function Name: VDAC4_SaveConfig
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
void VDAC4_SaveConfig(void) 
{
    if (!((VDAC4_CR1 & VDAC4_SRC_MASK) == VDAC4_SRC_UDB))
    {
        VDAC4_backup.data_value = VDAC4_Data;
    }
}


/*******************************************************************************
* Function Name: VDAC4_RestoreConfig
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
void VDAC4_RestoreConfig(void) 
{
    if (!((VDAC4_CR1 & VDAC4_SRC_MASK) == VDAC4_SRC_UDB))
    {
        if((VDAC4_Strobe & VDAC4_STRB_MASK) == VDAC4_STRB_EN)
        {
            VDAC4_Strobe &= (uint8)(~VDAC4_STRB_MASK);
            VDAC4_Data = VDAC4_backup.data_value;
            VDAC4_Strobe |= VDAC4_STRB_EN;
        }
        else
        {
            VDAC4_Data = VDAC4_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: VDAC4_Sleep
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
*  VDAC4_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void VDAC4_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(VDAC4_ACT_PWR_EN == (VDAC4_PWRMGR & VDAC4_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        VDAC4_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        VDAC4_backup.enableState = 0u;
    }
    
    VDAC4_Stop();
    VDAC4_SaveConfig();
}


/*******************************************************************************
* Function Name: VDAC4_Wakeup
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
*  VDAC4_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VDAC4_Wakeup(void) 
{
    VDAC4_RestoreConfig();
    
    if(VDAC4_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        VDAC4_Enable();

        /* Restore the data register */
        VDAC4_SetValue(VDAC4_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
