/*******************************************************************************
* File Name: IDACL1.c
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


#include "IDACL1.h"

static IDACL1_backupStruct IDACL1_backup;


/*******************************************************************************
* Function Name: IDACL1_SaveConfig
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
void IDACL1_SaveConfig(void) 
{
    if (!((IDACL1_CR1 & IDACL1_SRC_MASK) == IDACL1_SRC_UDB))
    {
        IDACL1_backup.data_value = IDACL1_Data;
    }
}


/*******************************************************************************
* Function Name: IDACL1_RestoreConfig
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
void IDACL1_RestoreConfig(void) 
{
    if (!((IDACL1_CR1 & IDACL1_SRC_MASK) == IDACL1_SRC_UDB))
    {
        if((IDACL1_Strobe & IDACL1_STRB_MASK) == IDACL1_STRB_EN)
        {
            IDACL1_Strobe &= (uint8)(~IDACL1_STRB_MASK);
            IDACL1_Data = IDACL1_backup.data_value;
            IDACL1_Strobe |= IDACL1_STRB_EN;
        }
        else
        {
            IDACL1_Data = IDACL1_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: IDACL1_Sleep
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
*  IDACL1_backup.enableState: Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void IDACL1_Sleep(void) 
{
    if(IDACL1_ACT_PWR_EN == (IDACL1_PWRMGR & IDACL1_ACT_PWR_EN))
    {
        /* IDAC8 is enabled */
        IDACL1_backup.enableState = 1u;
    }
    else
    {
        /* IDAC8 is disabled */
        IDACL1_backup.enableState = 0u;
    }

    IDACL1_Stop();
    IDACL1_SaveConfig();
}


/*******************************************************************************
* Function Name: IDACL1_Wakeup
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
*  IDACL1_backup.enableState: Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void IDACL1_Wakeup(void) 
{
    IDACL1_RestoreConfig();
    
    if(IDACL1_backup.enableState == 1u)
    {
        /* Enable IDAC8's operation */
        IDACL1_Enable();
        
        /* Set the data register */
        IDACL1_SetValue(IDACL1_Data);
    } /* Do nothing if IDAC8 was disabled before */    
}


/* [] END OF FILE */
