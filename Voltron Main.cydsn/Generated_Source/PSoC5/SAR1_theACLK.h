/*******************************************************************************
* File Name: SAR1_theACLK.h
* Version 2.10
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_SAR1_theACLK_H)
#define CY_CLOCK_SAR1_theACLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void SAR1_theACLK_Start(void) ;
void SAR1_theACLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void SAR1_theACLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void SAR1_theACLK_StandbyPower(uint8 state) ;
void SAR1_theACLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 SAR1_theACLK_GetDividerRegister(void) ;
void SAR1_theACLK_SetModeRegister(uint8 modeBitMask) ;
void SAR1_theACLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 SAR1_theACLK_GetModeRegister(void) ;
void SAR1_theACLK_SetSourceRegister(uint8 clkSource) ;
uint8 SAR1_theACLK_GetSourceRegister(void) ;
#if defined(SAR1_theACLK__CFG3)
void SAR1_theACLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 SAR1_theACLK_GetPhaseRegister(void) ;
#endif /* defined(SAR1_theACLK__CFG3) */

#define SAR1_theACLK_Enable()                       SAR1_theACLK_Start()
#define SAR1_theACLK_Disable()                      SAR1_theACLK_Stop()
#define SAR1_theACLK_SetDivider(clkDivider)         SAR1_theACLK_SetDividerRegister(clkDivider, 1u)
#define SAR1_theACLK_SetDividerValue(clkDivider)    SAR1_theACLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define SAR1_theACLK_SetMode(clkMode)               SAR1_theACLK_SetModeRegister(clkMode)
#define SAR1_theACLK_SetSource(clkSource)           SAR1_theACLK_SetSourceRegister(clkSource)
#if defined(SAR1_theACLK__CFG3)
#define SAR1_theACLK_SetPhase(clkPhase)             SAR1_theACLK_SetPhaseRegister(clkPhase)
#define SAR1_theACLK_SetPhaseValue(clkPhase)        SAR1_theACLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(SAR1_theACLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define SAR1_theACLK_CLKEN              (* (reg8 *) SAR1_theACLK__PM_ACT_CFG)
#define SAR1_theACLK_CLKEN_PTR          ((reg8 *) SAR1_theACLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SAR1_theACLK_CLKSTBY            (* (reg8 *) SAR1_theACLK__PM_STBY_CFG)
#define SAR1_theACLK_CLKSTBY_PTR        ((reg8 *) SAR1_theACLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SAR1_theACLK_DIV_LSB            (* (reg8 *) SAR1_theACLK__CFG0)
#define SAR1_theACLK_DIV_LSB_PTR        ((reg8 *) SAR1_theACLK__CFG0)
#define SAR1_theACLK_DIV_PTR            ((reg16 *) SAR1_theACLK__CFG0)

/* Clock MSB divider configuration register. */
#define SAR1_theACLK_DIV_MSB            (* (reg8 *) SAR1_theACLK__CFG1)
#define SAR1_theACLK_DIV_MSB_PTR        ((reg8 *) SAR1_theACLK__CFG1)

/* Mode and source configuration register */
#define SAR1_theACLK_MOD_SRC            (* (reg8 *) SAR1_theACLK__CFG2)
#define SAR1_theACLK_MOD_SRC_PTR        ((reg8 *) SAR1_theACLK__CFG2)

#if defined(SAR1_theACLK__CFG3)
/* Analog clock phase configuration register */
#define SAR1_theACLK_PHASE              (* (reg8 *) SAR1_theACLK__CFG3)
#define SAR1_theACLK_PHASE_PTR          ((reg8 *) SAR1_theACLK__CFG3)
#endif /* defined(SAR1_theACLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SAR1_theACLK_CLKEN_MASK         SAR1_theACLK__PM_ACT_MSK
#define SAR1_theACLK_CLKSTBY_MASK       SAR1_theACLK__PM_STBY_MSK

/* CFG2 field masks */
#define SAR1_theACLK_SRC_SEL_MSK        SAR1_theACLK__CFG2_SRC_SEL_MASK
#define SAR1_theACLK_MODE_MASK          (~(SAR1_theACLK_SRC_SEL_MSK))

#if defined(SAR1_theACLK__CFG3)
/* CFG3 phase mask */
#define SAR1_theACLK_PHASE_MASK         SAR1_theACLK__CFG3_PHASE_DLY_MASK
#endif /* defined(SAR1_theACLK__CFG3) */

#endif /* CY_CLOCK_SAR1_theACLK_H */


/* [] END OF FILE */
