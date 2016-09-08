/*******************************************************************************
* File Name: DelSig_PM.c
* Version 3.20
*
* Description:
*  This file provides the power manager source code to the API for the
*  Delta-Sigma ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "DelSig.h"

static DelSig_BACKUP_STRUCT DelSig_backup =
{
    DelSig_DISABLED,
    DelSig_CFG1_DEC_CR
};


/*******************************************************************************
* Function Name: DelSig_SaveConfig
********************************************************************************
*
* Summary:
*  Save the register configuration which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  DelSig_backup:  This global structure variable is used to store
*  configuration registers which are non retention whenever user wants to go
*  sleep mode by calling Sleep() API.
*
*******************************************************************************/
void DelSig_SaveConfig(void) 
{
    DelSig_backup.deccr = DelSig_DEC_CR_REG;
}


/*******************************************************************************
* Function Name: DelSig_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  DelSig_backup:  This global structure variable is used to restore
*  configuration registers which are non retention whenever user wants to switch
*  to active power mode by calling Wakeup() API.
*
*******************************************************************************/
void DelSig_RestoreConfig(void) 
{
    DelSig_DEC_CR_REG = DelSig_backup.deccr;
}


/*******************************************************************************
* Function Name: DelSig_Sleep
********************************************************************************
*
* Summary:
*  Stops the operation of the block and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  DelSig_backup:  The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void DelSig_Sleep(void) 
{
    /* Save ADC enable state */
    if((DelSig_ACT_PWR_DEC_EN == (DelSig_PWRMGR_DEC_REG & DelSig_ACT_PWR_DEC_EN)) &&
       (DelSig_ACT_PWR_DSM_EN == (DelSig_PWRMGR_DSM_REG & DelSig_ACT_PWR_DSM_EN)))
    {
        /* Component is enabled */
        DelSig_backup.enableState = DelSig_ENABLED;
        if((DelSig_DEC_CR_REG & DelSig_DEC_START_CONV) != 0u)
        {   
            /* Conversion is started */
            DelSig_backup.enableState |= DelSig_STARTED;
        }
		
        /* Stop the configuration */
        DelSig_Stop();
    }
    else
    {
        /* Component is disabled */
        DelSig_backup.enableState = DelSig_DISABLED;
    }

    /* Save the user configuration */
    DelSig_SaveConfig();
}


/*******************************************************************************
* Function Name: DelSig_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and enables the power to the block.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  DelSig_backup:  The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void DelSig_Wakeup(void) 
{
    /* Restore the configuration */
    DelSig_RestoreConfig();

    /* Enables the component operation */
    if(DelSig_backup.enableState != DelSig_DISABLED)
    {
        DelSig_Enable();
        if((DelSig_backup.enableState & DelSig_STARTED) != 0u)
        {
            DelSig_StartConvert();
        }
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
