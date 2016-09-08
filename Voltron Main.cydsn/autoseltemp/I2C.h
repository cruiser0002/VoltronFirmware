/*******************************************************************************
* File Name: I2C.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_I2C_H) /* Pins I2C_H */
#define CY_PINS_I2C_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "I2C_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 I2C__PORT == 15 && ((I2C__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    I2C_Write(uint8 value);
void    I2C_SetDriveMode(uint8 mode);
uint8   I2C_ReadDataReg(void);
uint8   I2C_Read(void);
void    I2C_SetInterruptMode(uint16 position, uint16 mode);
uint8   I2C_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the I2C_SetDriveMode() function.
     *  @{
     */
        #define I2C_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define I2C_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define I2C_DM_RES_UP          PIN_DM_RES_UP
        #define I2C_DM_RES_DWN         PIN_DM_RES_DWN
        #define I2C_DM_OD_LO           PIN_DM_OD_LO
        #define I2C_DM_OD_HI           PIN_DM_OD_HI
        #define I2C_DM_STRONG          PIN_DM_STRONG
        #define I2C_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define I2C_MASK               I2C__MASK
#define I2C_SHIFT              I2C__SHIFT
#define I2C_WIDTH              2u

/* Interrupt constants */
#if defined(I2C__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in I2C_SetInterruptMode() function.
     *  @{
     */
        #define I2C_INTR_NONE      (uint16)(0x0000u)
        #define I2C_INTR_RISING    (uint16)(0x0001u)
        #define I2C_INTR_FALLING   (uint16)(0x0002u)
        #define I2C_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define I2C_INTR_MASK      (0x01u) 
#endif /* (I2C__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define I2C_PS                     (* (reg8 *) I2C__PS)
/* Data Register */
#define I2C_DR                     (* (reg8 *) I2C__DR)
/* Port Number */
#define I2C_PRT_NUM                (* (reg8 *) I2C__PRT) 
/* Connect to Analog Globals */                                                  
#define I2C_AG                     (* (reg8 *) I2C__AG)                       
/* Analog MUX bux enable */
#define I2C_AMUX                   (* (reg8 *) I2C__AMUX) 
/* Bidirectional Enable */                                                        
#define I2C_BIE                    (* (reg8 *) I2C__BIE)
/* Bit-mask for Aliased Register Access */
#define I2C_BIT_MASK               (* (reg8 *) I2C__BIT_MASK)
/* Bypass Enable */
#define I2C_BYP                    (* (reg8 *) I2C__BYP)
/* Port wide control signals */                                                   
#define I2C_CTL                    (* (reg8 *) I2C__CTL)
/* Drive Modes */
#define I2C_DM0                    (* (reg8 *) I2C__DM0) 
#define I2C_DM1                    (* (reg8 *) I2C__DM1)
#define I2C_DM2                    (* (reg8 *) I2C__DM2) 
/* Input Buffer Disable Override */
#define I2C_INP_DIS                (* (reg8 *) I2C__INP_DIS)
/* LCD Common or Segment Drive */
#define I2C_LCD_COM_SEG            (* (reg8 *) I2C__LCD_COM_SEG)
/* Enable Segment LCD */
#define I2C_LCD_EN                 (* (reg8 *) I2C__LCD_EN)
/* Slew Rate Control */
#define I2C_SLW                    (* (reg8 *) I2C__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define I2C_PRTDSI__CAPS_SEL       (* (reg8 *) I2C__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define I2C_PRTDSI__DBL_SYNC_IN    (* (reg8 *) I2C__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define I2C_PRTDSI__OE_SEL0        (* (reg8 *) I2C__PRTDSI__OE_SEL0) 
#define I2C_PRTDSI__OE_SEL1        (* (reg8 *) I2C__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define I2C_PRTDSI__OUT_SEL0       (* (reg8 *) I2C__PRTDSI__OUT_SEL0) 
#define I2C_PRTDSI__OUT_SEL1       (* (reg8 *) I2C__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define I2C_PRTDSI__SYNC_OUT       (* (reg8 *) I2C__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(I2C__SIO_CFG)
    #define I2C_SIO_HYST_EN        (* (reg8 *) I2C__SIO_HYST_EN)
    #define I2C_SIO_REG_HIFREQ     (* (reg8 *) I2C__SIO_REG_HIFREQ)
    #define I2C_SIO_CFG            (* (reg8 *) I2C__SIO_CFG)
    #define I2C_SIO_DIFF           (* (reg8 *) I2C__SIO_DIFF)
#endif /* (I2C__SIO_CFG) */

/* Interrupt Registers */
#if defined(I2C__INTSTAT)
    #define I2C_INTSTAT            (* (reg8 *) I2C__INTSTAT)
    #define I2C_SNAP               (* (reg8 *) I2C__SNAP)
    
	#define I2C_0_INTTYPE_REG 		(* (reg8 *) I2C__0__INTTYPE)
	#define I2C_1_INTTYPE_REG 		(* (reg8 *) I2C__1__INTTYPE)
#endif /* (I2C__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_I2C_H */


/* [] END OF FILE */
