/*******************************************************************************
* File Name: SAR1_PM.c
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

#include "SAR1.h"


/***************************************
* Local data allocation
***************************************/

static SAR1_BACKUP_STRUCT  SAR1_backup =
{
    SAR1_DISABLED
};


/*******************************************************************************
* Function Name: SAR1_SaveConfig
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
void SAR1_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: SAR1_RestoreConfig
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
void SAR1_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: SAR1_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The SAR1_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SAR1_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void SAR1_Sleep(void)
{
    if((SAR1_PWRMGR_SAR_REG  & SAR1_ACT_PWR_SAR_EN) != 0u)
    {
        if((SAR1_SAR_CSR0_REG & SAR1_SAR_SOF_START_CONV) != 0u)
        {
            SAR1_backup.enableState = SAR1_ENABLED | SAR1_STARTED;
        }
        else
        {
            SAR1_backup.enableState = SAR1_ENABLED;
        }
        SAR1_Stop();
    }
    else
    {
        SAR1_backup.enableState = SAR1_DISABLED;
    }
}


/*******************************************************************************
* Function Name: SAR1_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  SAR1_Sleep() was called. If the component was enabled before the
*  SAR1_Sleep() function was called, the
*  SAR1_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SAR1_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void SAR1_Wakeup(void)
{
    if(SAR1_backup.enableState != SAR1_DISABLED)
    {
        SAR1_Enable();
        #if(SAR1_DEFAULT_CONV_MODE != SAR1__HARDWARE_TRIGGER)
            if((SAR1_backup.enableState & SAR1_STARTED) != 0u)
            {
                SAR1_StartConvert();
            }
        #endif /* End SAR1_DEFAULT_CONV_MODE != SAR1__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
