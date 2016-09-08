/*******************************************************************************
* File Name: SAR2_PM.c
* Version 3.0
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SAR2.h"


/***************************************
* Local data allocation
***************************************/

static SAR2_BACKUP_STRUCT  SAR2_backup =
{
    SAR2_DISABLED
};


/*******************************************************************************
* Function Name: SAR2_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SAR2_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: SAR2_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SAR2_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: SAR2_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The SAR2_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SAR2_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void SAR2_Sleep(void)
{
    if((SAR2_PWRMGR_SAR_REG  & SAR2_ACT_PWR_SAR_EN) != 0u)
    {
        if((SAR2_SAR_CSR0_REG & SAR2_SAR_SOF_START_CONV) != 0u)
        {
            SAR2_backup.enableState = SAR2_ENABLED | SAR2_STARTED;
        }
        else
        {
            SAR2_backup.enableState = SAR2_ENABLED;
        }
        SAR2_Stop();
    }
    else
    {
        SAR2_backup.enableState = SAR2_DISABLED;
    }
}


/*******************************************************************************
* Function Name: SAR2_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  SAR2_Sleep() was called. If the component was enabled before the
*  SAR2_Sleep() function was called, the
*  SAR2_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SAR2_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void SAR2_Wakeup(void)
{
    if(SAR2_backup.enableState != SAR2_DISABLED)
    {
        SAR2_Enable();
        #if(SAR2_DEFAULT_CONV_MODE != SAR2__HARDWARE_TRIGGER)
            if((SAR2_backup.enableState & SAR2_STARTED) != 0u)
            {
                SAR2_StartConvert();
            }
        #endif /* End SAR2_DEFAULT_CONV_MODE != SAR2__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
