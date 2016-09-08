/*******************************************************************************
* File Name: IDACH2.c
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


#include "IDACH2.h"

static IDACH2_backupStruct IDACH2_backup;


/*******************************************************************************
* Function Name: IDACH2_SaveConfig
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
void IDACH2_SaveConfig(void) 
{
    if (!((IDACH2_CR1 & IDACH2_SRC_MASK) == IDACH2_SRC_UDB))
    {
        IDACH2_backup.data_value = IDACH2_Data;
    }
}


/*******************************************************************************
* Function Name: IDACH2_RestoreConfig
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
void IDACH2_RestoreConfig(void) 
{
    if (!((IDACH2_CR1 & IDACH2_SRC_MASK) == IDACH2_SRC_UDB))
    {
        if((IDACH2_Strobe & IDACH2_STRB_MASK) == IDACH2_STRB_EN)
        {
            IDACH2_Strobe &= (uint8)(~IDACH2_STRB_MASK);
            IDACH2_Data = IDACH2_backup.data_value;
            IDACH2_Strobe |= IDACH2_STRB_EN;
        }
        else
        {
            IDACH2_Data = IDACH2_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: IDACH2_Sleep
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
*  IDACH2_backup.enableState: Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void IDACH2_Sleep(void) 
{
    if(IDACH2_ACT_PWR_EN == (IDACH2_PWRMGR & IDACH2_ACT_PWR_EN))
    {
        /* IDAC8 is enabled */
        IDACH2_backup.enableState = 1u;
    }
    else
    {
        /* IDAC8 is disabled */
        IDACH2_backup.enableState = 0u;
    }

    IDACH2_Stop();
    IDACH2_SaveConfig();
}


/*******************************************************************************
* Function Name: IDACH2_Wakeup
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
*  IDACH2_backup.enableState: Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void IDACH2_Wakeup(void) 
{
    IDACH2_RestoreConfig();
    
    if(IDACH2_backup.enableState == 1u)
    {
        /* Enable IDAC8's operation */
        IDACH2_Enable();
        
        /* Set the data register */
        IDACH2_SetValue(IDACH2_Data);
    } /* Do nothing if IDAC8 was disabled before */    
}


/* [] END OF FILE */
