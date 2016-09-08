/*******************************************************************************
* File Name: IDACL.c
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


#include "IDACL.h"

static IDACL_backupStruct IDACL_backup;


/*******************************************************************************
* Function Name: IDACL_SaveConfig
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
void IDACL_SaveConfig(void) 
{
    if (!((IDACL_CR1 & IDACL_SRC_MASK) == IDACL_SRC_UDB))
    {
        IDACL_backup.data_value = IDACL_Data;
    }
}


/*******************************************************************************
* Function Name: IDACL_RestoreConfig
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
void IDACL_RestoreConfig(void) 
{
    if (!((IDACL_CR1 & IDACL_SRC_MASK) == IDACL_SRC_UDB))
    {
        if((IDACL_Strobe & IDACL_STRB_MASK) == IDACL_STRB_EN)
        {
            IDACL_Strobe &= (uint8)(~IDACL_STRB_MASK);
            IDACL_Data = IDACL_backup.data_value;
            IDACL_Strobe |= IDACL_STRB_EN;
        }
        else
        {
            IDACL_Data = IDACL_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: IDACL_Sleep
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
*  IDACL_backup.enableState: Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void IDACL_Sleep(void) 
{
    if(IDACL_ACT_PWR_EN == (IDACL_PWRMGR & IDACL_ACT_PWR_EN))
    {
        /* IDAC8 is enabled */
        IDACL_backup.enableState = 1u;
    }
    else
    {
        /* IDAC8 is disabled */
        IDACL_backup.enableState = 0u;
    }

    IDACL_Stop();
    IDACL_SaveConfig();
}


/*******************************************************************************
* Function Name: IDACL_Wakeup
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
*  IDACL_backup.enableState: Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void IDACL_Wakeup(void) 
{
    IDACL_RestoreConfig();
    
    if(IDACL_backup.enableState == 1u)
    {
        /* Enable IDAC8's operation */
        IDACL_Enable();
        
        /* Set the data register */
        IDACL_SetValue(IDACL_Data);
    } /* Do nothing if IDAC8 was disabled before */    
}


/* [] END OF FILE */
