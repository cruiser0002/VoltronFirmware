/*******************************************************************************
* File Name: IDACL2.c
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


#include "IDACL2.h"

static IDACL2_backupStruct IDACL2_backup;


/*******************************************************************************
* Function Name: IDACL2_SaveConfig
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
void IDACL2_SaveConfig(void) 
{
    if (!((IDACL2_CR1 & IDACL2_SRC_MASK) == IDACL2_SRC_UDB))
    {
        IDACL2_backup.data_value = IDACL2_Data;
    }
}


/*******************************************************************************
* Function Name: IDACL2_RestoreConfig
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
void IDACL2_RestoreConfig(void) 
{
    if (!((IDACL2_CR1 & IDACL2_SRC_MASK) == IDACL2_SRC_UDB))
    {
        if((IDACL2_Strobe & IDACL2_STRB_MASK) == IDACL2_STRB_EN)
        {
            IDACL2_Strobe &= (uint8)(~IDACL2_STRB_MASK);
            IDACL2_Data = IDACL2_backup.data_value;
            IDACL2_Strobe |= IDACL2_STRB_EN;
        }
        else
        {
            IDACL2_Data = IDACL2_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: IDACL2_Sleep
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
*  IDACL2_backup.enableState: Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void IDACL2_Sleep(void) 
{
    if(IDACL2_ACT_PWR_EN == (IDACL2_PWRMGR & IDACL2_ACT_PWR_EN))
    {
        /* IDAC8 is enabled */
        IDACL2_backup.enableState = 1u;
    }
    else
    {
        /* IDAC8 is disabled */
        IDACL2_backup.enableState = 0u;
    }

    IDACL2_Stop();
    IDACL2_SaveConfig();
}


/*******************************************************************************
* Function Name: IDACL2_Wakeup
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
*  IDACL2_backup.enableState: Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void IDACL2_Wakeup(void) 
{
    IDACL2_RestoreConfig();
    
    if(IDACL2_backup.enableState == 1u)
    {
        /* Enable IDAC8's operation */
        IDACL2_Enable();
        
        /* Set the data register */
        IDACL2_SetValue(IDACL2_Data);
    } /* Do nothing if IDAC8 was disabled before */    
}


/* [] END OF FILE */
