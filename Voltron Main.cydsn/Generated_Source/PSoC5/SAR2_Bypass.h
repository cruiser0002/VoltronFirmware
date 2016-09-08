/*******************************************************************************
* File Name: SAR2_Bypass.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SAR2_Bypass_H) /* Pins SAR2_Bypass_H */
#define CY_PINS_SAR2_Bypass_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SAR2_Bypass_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SAR2_Bypass__PORT == 15 && ((SAR2_Bypass__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SAR2_Bypass_Write(uint8 value) ;
void    SAR2_Bypass_SetDriveMode(uint8 mode) ;
uint8   SAR2_Bypass_ReadDataReg(void) ;
uint8   SAR2_Bypass_Read(void) ;
uint8   SAR2_Bypass_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SAR2_Bypass_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SAR2_Bypass_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SAR2_Bypass_DM_RES_UP          PIN_DM_RES_UP
#define SAR2_Bypass_DM_RES_DWN         PIN_DM_RES_DWN
#define SAR2_Bypass_DM_OD_LO           PIN_DM_OD_LO
#define SAR2_Bypass_DM_OD_HI           PIN_DM_OD_HI
#define SAR2_Bypass_DM_STRONG          PIN_DM_STRONG
#define SAR2_Bypass_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SAR2_Bypass_MASK               SAR2_Bypass__MASK
#define SAR2_Bypass_SHIFT              SAR2_Bypass__SHIFT
#define SAR2_Bypass_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SAR2_Bypass_PS                     (* (reg8 *) SAR2_Bypass__PS)
/* Data Register */
#define SAR2_Bypass_DR                     (* (reg8 *) SAR2_Bypass__DR)
/* Port Number */
#define SAR2_Bypass_PRT_NUM                (* (reg8 *) SAR2_Bypass__PRT) 
/* Connect to Analog Globals */                                                  
#define SAR2_Bypass_AG                     (* (reg8 *) SAR2_Bypass__AG)                       
/* Analog MUX bux enable */
#define SAR2_Bypass_AMUX                   (* (reg8 *) SAR2_Bypass__AMUX) 
/* Bidirectional Enable */                                                        
#define SAR2_Bypass_BIE                    (* (reg8 *) SAR2_Bypass__BIE)
/* Bit-mask for Aliased Register Access */
#define SAR2_Bypass_BIT_MASK               (* (reg8 *) SAR2_Bypass__BIT_MASK)
/* Bypass Enable */
#define SAR2_Bypass_BYP                    (* (reg8 *) SAR2_Bypass__BYP)
/* Port wide control signals */                                                   
#define SAR2_Bypass_CTL                    (* (reg8 *) SAR2_Bypass__CTL)
/* Drive Modes */
#define SAR2_Bypass_DM0                    (* (reg8 *) SAR2_Bypass__DM0) 
#define SAR2_Bypass_DM1                    (* (reg8 *) SAR2_Bypass__DM1)
#define SAR2_Bypass_DM2                    (* (reg8 *) SAR2_Bypass__DM2) 
/* Input Buffer Disable Override */
#define SAR2_Bypass_INP_DIS                (* (reg8 *) SAR2_Bypass__INP_DIS)
/* LCD Common or Segment Drive */
#define SAR2_Bypass_LCD_COM_SEG            (* (reg8 *) SAR2_Bypass__LCD_COM_SEG)
/* Enable Segment LCD */
#define SAR2_Bypass_LCD_EN                 (* (reg8 *) SAR2_Bypass__LCD_EN)
/* Slew Rate Control */
#define SAR2_Bypass_SLW                    (* (reg8 *) SAR2_Bypass__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SAR2_Bypass_PRTDSI__CAPS_SEL       (* (reg8 *) SAR2_Bypass__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SAR2_Bypass_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SAR2_Bypass__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SAR2_Bypass_PRTDSI__OE_SEL0        (* (reg8 *) SAR2_Bypass__PRTDSI__OE_SEL0) 
#define SAR2_Bypass_PRTDSI__OE_SEL1        (* (reg8 *) SAR2_Bypass__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SAR2_Bypass_PRTDSI__OUT_SEL0       (* (reg8 *) SAR2_Bypass__PRTDSI__OUT_SEL0) 
#define SAR2_Bypass_PRTDSI__OUT_SEL1       (* (reg8 *) SAR2_Bypass__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SAR2_Bypass_PRTDSI__SYNC_OUT       (* (reg8 *) SAR2_Bypass__PRTDSI__SYNC_OUT) 


#if defined(SAR2_Bypass__INTSTAT)  /* Interrupt Registers */

    #define SAR2_Bypass_INTSTAT                (* (reg8 *) SAR2_Bypass__INTSTAT)
    #define SAR2_Bypass_SNAP                   (* (reg8 *) SAR2_Bypass__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SAR2_Bypass_H */


/* [] END OF FILE */
