/*******************************************************************************
* File Name: SamplingClock.h
* Version 2.20
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

#if !defined(CY_CLOCK_SamplingClock_H)
#define CY_CLOCK_SamplingClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void SamplingClock_Start(void) ;
void SamplingClock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void SamplingClock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void SamplingClock_StandbyPower(uint8 state) ;
void SamplingClock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 SamplingClock_GetDividerRegister(void) ;
void SamplingClock_SetModeRegister(uint8 modeBitMask) ;
void SamplingClock_ClearModeRegister(uint8 modeBitMask) ;
uint8 SamplingClock_GetModeRegister(void) ;
void SamplingClock_SetSourceRegister(uint8 clkSource) ;
uint8 SamplingClock_GetSourceRegister(void) ;
#if defined(SamplingClock__CFG3)
void SamplingClock_SetPhaseRegister(uint8 clkPhase) ;
uint8 SamplingClock_GetPhaseRegister(void) ;
#endif /* defined(SamplingClock__CFG3) */

#define SamplingClock_Enable()                       SamplingClock_Start()
#define SamplingClock_Disable()                      SamplingClock_Stop()
#define SamplingClock_SetDivider(clkDivider)         SamplingClock_SetDividerRegister(clkDivider, 1u)
#define SamplingClock_SetDividerValue(clkDivider)    SamplingClock_SetDividerRegister((clkDivider) - 1u, 1u)
#define SamplingClock_SetMode(clkMode)               SamplingClock_SetModeRegister(clkMode)
#define SamplingClock_SetSource(clkSource)           SamplingClock_SetSourceRegister(clkSource)
#if defined(SamplingClock__CFG3)
#define SamplingClock_SetPhase(clkPhase)             SamplingClock_SetPhaseRegister(clkPhase)
#define SamplingClock_SetPhaseValue(clkPhase)        SamplingClock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(SamplingClock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define SamplingClock_CLKEN              (* (reg8 *) SamplingClock__PM_ACT_CFG)
#define SamplingClock_CLKEN_PTR          ((reg8 *) SamplingClock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SamplingClock_CLKSTBY            (* (reg8 *) SamplingClock__PM_STBY_CFG)
#define SamplingClock_CLKSTBY_PTR        ((reg8 *) SamplingClock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SamplingClock_DIV_LSB            (* (reg8 *) SamplingClock__CFG0)
#define SamplingClock_DIV_LSB_PTR        ((reg8 *) SamplingClock__CFG0)
#define SamplingClock_DIV_PTR            ((reg16 *) SamplingClock__CFG0)

/* Clock MSB divider configuration register. */
#define SamplingClock_DIV_MSB            (* (reg8 *) SamplingClock__CFG1)
#define SamplingClock_DIV_MSB_PTR        ((reg8 *) SamplingClock__CFG1)

/* Mode and source configuration register */
#define SamplingClock_MOD_SRC            (* (reg8 *) SamplingClock__CFG2)
#define SamplingClock_MOD_SRC_PTR        ((reg8 *) SamplingClock__CFG2)

#if defined(SamplingClock__CFG3)
/* Analog clock phase configuration register */
#define SamplingClock_PHASE              (* (reg8 *) SamplingClock__CFG3)
#define SamplingClock_PHASE_PTR          ((reg8 *) SamplingClock__CFG3)
#endif /* defined(SamplingClock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SamplingClock_CLKEN_MASK         SamplingClock__PM_ACT_MSK
#define SamplingClock_CLKSTBY_MASK       SamplingClock__PM_STBY_MSK

/* CFG2 field masks */
#define SamplingClock_SRC_SEL_MSK        SamplingClock__CFG2_SRC_SEL_MASK
#define SamplingClock_MODE_MASK          (~(SamplingClock_SRC_SEL_MSK))

#if defined(SamplingClock__CFG3)
/* CFG3 phase mask */
#define SamplingClock_PHASE_MASK         SamplingClock__CFG3_PHASE_DLY_MASK
#endif /* defined(SamplingClock__CFG3) */

#endif /* CY_CLOCK_SamplingClock_H */


/* [] END OF FILE */
