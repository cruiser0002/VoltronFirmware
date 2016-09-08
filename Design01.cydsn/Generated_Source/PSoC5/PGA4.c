/*******************************************************************************
* File Name: PGA4.c
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the inverting PGA 
*  Component.
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

#if (!CY_PSOC5A)
    #if (CYDEV_VARIABLE_VDDA == 1u)
        #include "CyScBoostClk.h"
    #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
#endif /* (!CY_PSOC5A) */

#if (CY_PSOC5A)
    static PGA4_BACKUP_STRUCT  PGA4_P5backup;
#endif /* (CY_PSOC5A) */

uint8 PGA4_initVar = 0u;



/*******************************************************************************   
* Function Name: PGA4_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  PGA4_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PGA4_Init(void) 
{
    /* Set PGA mode */
    PGA4_CR0_REG = PGA4_MODE_PGA;

    /* Set inverting PGA mode  and reference mode */
    PGA4_CR1_REG &= (uint8)(~PGA4_PGA_INV);

    /* Set gain and compensation */
    PGA4_SetGain(PGA4_DEFAULT_GAIN);

    /* Set power */
    PGA4_SetPower(PGA4_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: PGA4_Enable
********************************************************************************
*
* Summary:
*  Enables the inverting PGA block operation
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PGA4_Enable(void) 
{
    /* This is to restore the value of register CR1 and CR2 which is saved 
      in prior to the modifications in stop() API */
    #if (CY_PSOC5A)
        if(PGA4_P5backup.enableState == 1u)
        {
            PGA4_CR1_REG = PGA4_P5backup.scCR1Reg;
            PGA4_CR2_REG = PGA4_P5backup.scCR2Reg;
            PGA4_P5backup.enableState = 0u;
        }
    #endif /* CY_PSOC5A */
    
    /* Enable power to the Amp in Active mode */
    PGA4_PM_ACT_CFG_REG |= PGA4_ACT_PWR_EN;

    /* Enable power to the Amp in Alternative active mode  */
    PGA4_PM_STBY_CFG_REG |= PGA4_STBY_PWR_EN;
    
    PGA4_PUMP_CR1_REG |= PGA4_PUMP_CR1_SC_CLKSEL;
    
    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            if(CyScPumpEnabled == 1u)
            {
                PGA4_BSTCLK_REG &= (uint8)(~PGA4_BST_CLK_INDEX_MASK);
                PGA4_BSTCLK_REG |= PGA4_BST_CLK_EN | CyScBoostClk__INDEX;
                PGA4_SC_MISC_REG |= PGA4_PUMP_FORCE;
                CyScBoostClk_Start();
            }
            else
            {
                PGA4_BSTCLK_REG &= (uint8)(~PGA4_BST_CLK_EN);
                PGA4_SC_MISC_REG &= (uint8)(~PGA4_PUMP_FORCE);
            }
        #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
    #endif /* (!CY_PSOC5A) */
}


/*******************************************************************************
* Function Name: PGA4_Start
********************************************************************************
*
* Summary:
*  The start function initializes the inverting PGA with the default values,
*  and sets the power to the given level.A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*  This function modifies the global variable PGA4_initVar: which 
*  defines where component's configuration are taken from the customizer 
*  (equals 0) or parameters changed by API will be used instead (equals 1).
*
*******************************************************************************/
void PGA4_Start(void) 
{

    if(PGA4_initVar == 0u)
    {
        PGA4_initVar = 1u;
        PGA4_Init();
    }
    
    PGA4_Enable();
}


/*******************************************************************************
* Function Name: PGA4_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void 
*
*******************************************************************************/
void PGA4_Stop(void) 
{
    /* Disble power to the Amp in Active mode*/
    PGA4_PM_ACT_CFG_REG &= (uint8)(~PGA4_ACT_PWR_EN);

    /* Disble power to the Amp in Alternative active mode*/
    PGA4_PM_STBY_CFG_REG &= (uint8)(~PGA4_STBY_PWR_EN);

    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            PGA4_BSTCLK_REG &= (uint8)(~PGA4_BST_CLK_EN);
            /* Disable pumps only if there aren't any SC block in use */
            if ((PGA4_PM_ACT_CFG_REG & PGA4_PM_ACT_CFG_MASK) == 0u)
            {
                PGA4_SC_MISC_REG &= (uint8)(~PGA4_PUMP_FORCE);
                PGA4_PUMP_CR1_REG &= (uint8)(~PGA4_PUMP_CR1_SC_CLKSEL);
                CyScBoostClk_Stop();
            }
        #endif /* CYDEV_VARIABLE_VDDA == 1u */
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    
    /* This sets PGA in zero current mode and output routes are valid */
    #if (CY_PSOC5A)
        PGA4_P5backup.scCR1Reg = PGA4_CR1_REG;
        PGA4_P5backup.scCR2Reg = PGA4_CR2_REG;
        PGA4_CR1_REG = 0x00u;
        PGA4_CR2_REG = 0x00u;
        PGA4_P5backup.enableState = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: PGA4_SetPower
********************************************************************************
*
* Summary:
*  Set the power of the inverting PGA
*
* Parameters:
*  power:  Sets power level between (0) and (3) high power
*
* Return:
*  void 
*
*******************************************************************************/
void PGA4_SetPower(uint8 power) 
{
    uint8 tmpCR;

    tmpCR = PGA4_CR1_REG & (uint8)(~PGA4_DRIVE_MASK);
    tmpCR |= (power & PGA4_DRIVE_MASK);
    PGA4_CR1_REG = tmpCR;
}


/*******************************************************************************
* Function Name: PGA4_SetGain
********************************************************************************
*
* Summary:
*  This function sets values of the input and feedback resistors to set a 
*  specific gain of the amplifier.
*
* Parameters:
*  gain: Sets gain of amplifier.
*
* Return:
*  void
*
*******************************************************************************/
void PGA4_SetGain(uint8 gain) 
{
    /* Constant array for gain settings */
    const uint8 PGA4_GainArray[9] = { 
        (PGA4_PGA_INV_GAIN_01 | PGA4_BIAS_LOW), /* G=-1  */
        (PGA4_PGA_INV_GAIN_03 | PGA4_BIAS_LOW), /* G=-3  */
        (PGA4_PGA_INV_GAIN_07 | PGA4_BIAS_LOW), /* G=-7  */
        (PGA4_PGA_INV_GAIN_15 | PGA4_BIAS_LOW), /* G=-15 */
        (PGA4_PGA_INV_GAIN_22 | PGA4_BIAS_LOW), /* G=-22 */
        (PGA4_PGA_INV_GAIN_24 | PGA4_BIAS_LOW), /* G=-24 */
        (PGA4_PGA_INV_GAIN_31 | PGA4_BIAS_LOW), /* G=-31 */
        (PGA4_PGA_INV_GAIN_47 | PGA4_BIAS_LOW), /* G=-47 */
        (PGA4_PGA_INV_GAIN_49 | PGA4_BIAS_LOW)  /* G=-49 */
    };

    /* Constant array for gain compenstion settings */
    const uint8 PGA4_GainComp[9] = { 
        ( PGA4_COMP_4P35PF  | (uint8)( PGA4_REDC_00 >> 2 )), /* G=-1  */
        ( PGA4_COMP_4P35PF  | (uint8)( PGA4_REDC_01 >> 2 )), /* G=-3  */
        ( PGA4_COMP_3P0PF   | (uint8)( PGA4_REDC_01 >> 2 )), /* G=-7  */
        ( PGA4_COMP_3P0PF   | (uint8)( PGA4_REDC_01 >> 2 )), /* G=-15 */
        ( PGA4_COMP_3P6PF   | (uint8)( PGA4_REDC_01 >> 2 )), /* G=-22 */
        ( PGA4_COMP_3P0PF   | (uint8)( PGA4_REDC_10 >> 2 )), /* G=-24 */
        ( PGA4_COMP_3P6PF   | (uint8)( PGA4_REDC_11 >> 2 )), /* G=-31 */
        ( PGA4_COMP_3P6PF   | (uint8)( PGA4_REDC_00 >> 2 )), /* G=-47 */
        ( PGA4_COMP_3P6PF   | (uint8)( PGA4_REDC_00 >> 2 ))  /* G=-49 */
    };
    
    
    /* Only set new gain if it is a valid gain */
    if( gain <= PGA4_GAIN_MAX)
    {
        /* Clear resistors, redc, and bias */
        PGA4_CR2_REG &= (uint8)(~(PGA4_RVAL_MASK | PGA4_R20_40B_MASK | 
                                      PGA4_REDC_MASK | PGA4_BIAS_MASK ));

        /* Set gain value resistors, redc comp, and bias */
        PGA4_CR2_REG |= (PGA4_GainArray[gain] |
                                ( (uint8)(PGA4_GainComp[gain] << 2 ) & PGA4_REDC_MASK) );

        /* Clear sc_comp  */
        PGA4_CR1_REG &= (uint8)(~PGA4_COMP_MASK);

        /* Set sc_comp  */
        PGA4_CR1_REG |= ( PGA4_GainComp[gain] | PGA4_COMP_MASK );
    }
}


/* [] END OF FILE */
