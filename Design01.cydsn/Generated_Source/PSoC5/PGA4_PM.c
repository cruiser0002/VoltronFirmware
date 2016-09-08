/*******************************************************************************
* File Name: PGA4.c
* Version 2.0
*
* Description:
*  This file provides the power manager source code to the API for the 
*  inverting PGA component.
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

#include "PGA4.h"

static PGA4_BACKUP_STRUCT  PGA4_backup;


/*******************************************************************************  
* Function Name: PGA4_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the user configuration registers.
* 
* Parameters:
*  void
* 
* Return:
*  void
*
*******************************************************************************/
void PGA4_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************
* Function Name: PGA4_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations.
* 
* Parameters:
*  void.
* 
* Return:
*  void
*
*******************************************************************************/
void PGA4_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************
* Function Name: PGA4_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PGA4_backup:  The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void PGA4_Sleep(void) 
{
    /* Save PGA_Inv enable state */
    if((PGA4_PM_ACT_CFG_REG & PGA4_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        PGA4_backup.enableState = 1u;
        /* Stop the configuration */
        PGA4_Stop();
    }
    else
    {
        /* Component is disabled */
        PGA4_backup.enableState = 0u;
    }
    /* Save the configurations */
    PGA4_SaveConfig();
}


/*******************************************************************************
* Function Name: PGA4_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  void
*
* Global variables:
*  PGA4_backup:  The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void PGA4_Wakeup(void) 
{
    /* Restore the register configurations */
    PGA4_RestoreConfig();
    
    /* Enable's the component operation */
    if(PGA4_backup.enableState == 1u)
    {
        PGA4_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
