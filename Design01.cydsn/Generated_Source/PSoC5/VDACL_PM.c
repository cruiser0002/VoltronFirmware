/*******************************************************************************
* File Name: VDACL_PM.c  
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

#include "VDACL.h"

static VDACL_backupStruct VDACL_backup;


/*******************************************************************************
* Function Name: VDACL_SaveConfig
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
void VDACL_SaveConfig(void) 
{
    if (!((VDACL_CR1 & VDACL_SRC_MASK) == VDACL_SRC_UDB))
    {
        VDACL_backup.data_value = VDACL_Data;
    }
}


/*******************************************************************************
* Function Name: VDACL_RestoreConfig
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
void VDACL_RestoreConfig(void) 
{
    if (!((VDACL_CR1 & VDACL_SRC_MASK) == VDACL_SRC_UDB))
    {
        if((VDACL_Strobe & VDACL_STRB_MASK) == VDACL_STRB_EN)
        {
            VDACL_Strobe &= (uint8)(~VDACL_STRB_MASK);
            VDACL_Data = VDACL_backup.data_value;
            VDACL_Strobe |= VDACL_STRB_EN;
        }
        else
        {
            VDACL_Data = VDACL_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: VDACL_Sleep
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
*  VDACL_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void VDACL_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(VDACL_ACT_PWR_EN == (VDACL_PWRMGR & VDACL_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        VDACL_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        VDACL_backup.enableState = 0u;
    }
    
    VDACL_Stop();
    VDACL_SaveConfig();
}


/*******************************************************************************
* Function Name: VDACL_Wakeup
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
*  VDACL_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VDACL_Wakeup(void) 
{
    VDACL_RestoreConfig();
    
    if(VDACL_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        VDACL_Enable();

        /* Restore the data register */
        VDACL_SetValue(VDACL_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
