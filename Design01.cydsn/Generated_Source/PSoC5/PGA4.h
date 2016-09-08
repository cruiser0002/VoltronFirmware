/*******************************************************************************
* File Name: PGA4.c
* Version 2.0
*
* Description:
*  This file contains the function prototypes and constants used in
*  the PGA_Inv User Module.
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

#if !defined(CY_PGA_Inv_PGA4_H) 
#define CY_PGA_Inv_PGA4_H 

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PGA_Inv_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


#if(!CY_PSOC5A)
    #if(CYDEV_VARIABLE_VDDA == 1)
        #if (!defined(CY_LIB_SC_BST_CLK_EN))
            #error Component PGA_Inv_v2_0 requires cy_boot v3.30 or later
        #endif /* (!defined(CY_LIB_SC_BST_CLK_EN)) */
    #endif /* CYDEV_VARIABLE_VDDA == 1 */
#endif /* (!CY_PSOC5A) */

/***************************************
*   Data Struct Definition
***************************************/

/* Low power API Support */
typedef struct
{
    uint8   enableState;
    uint8   scCR0Reg;
    uint8   scCR1Reg;
    uint8   scCR2Reg;
}   PGA4_BACKUP_STRUCT;


/* component init state */
extern uint8 PGA4_initVar;


/***************************************
*        Function Prototypes 
***************************************/

void PGA4_Start(void)                 ;
void PGA4_Stop(void)                  ;
void PGA4_SetPower(uint8 power)       ;
void PGA4_SetGain(uint8 gain)         ;
void PGA4_Sleep(void)                 ;
void PGA4_Wakeup(void)                ;
void PGA4_SaveConfig(void)            ;
void PGA4_RestoreConfig(void)         ;
void PGA4_Init(void)                  ;
void PGA4_Enable(void)                ;


/***************************************
*           API Constants        
***************************************/

/* Power constants for SetPower function */
#define PGA4_MINPOWER                 (0x00u)
#define PGA4_LOWPOWER                 (0x01u)
#define PGA4_MEDPOWER                 (0x02u)
#define PGA4_HIGHPOWER                (0x03u)

/* Constants for SetGain function */
#define PGA4_GAIN_01                  (0x00u)
#define PGA4_GAIN_03                  (0x01u)
#define PGA4_GAIN_07                  (0x02u)
#define PGA4_GAIN_15                  (0x03u)
#define PGA4_GAIN_22                  (0x04u)
#define PGA4_GAIN_24                  (0x05u)
#define PGA4_GAIN_31                  (0x06u)
#define PGA4_GAIN_47                  (0x07u)
#define PGA4_GAIN_49                  (0x08u)
#define PGA4_GAIN_MAX                 (0x08u)


/***************************************
*       Initialization Values
***************************************/

#define PGA4_DEFAULT_GAIN             (0u)
#define PGA4_DEFAULT_POWER            (3u)


/***************************************
*              Registers
***************************************/

#define PGA4_CR0_REG                  (* (reg8 *) PGA4_SC__CR0 )
#define PGA4_CR0_PTR                  (  (reg8 *) PGA4_SC__CR0 )
#define PGA4_CR1_REG                  (* (reg8 *) PGA4_SC__CR1 )
#define PGA4_CR1_PTR                  (  (reg8 *) PGA4_SC__CR1 )
#define PGA4_CR2_REG                  (* (reg8 *) PGA4_SC__CR2 )
#define PGA4_CR2_PTR                  (  (reg8 *) PGA4_SC__CR2 )
  /* Power manager */
#define PGA4_PM_ACT_CFG_REG           (* (reg8 *) PGA4_SC__PM_ACT_CFG )
#define PGA4_PM_ACT_CFG_PTR           (  (reg8 *) PGA4_SC__PM_ACT_CFG )
  /* Power manager */
#define PGA4_PM_STBY_CFG_REG          (* (reg8 *) PGA4_SC__PM_STBY_CFG )
#define PGA4_PM_STBY_CFG_PTR          (  (reg8 *) PGA4_SC__PM_STBY_CFG )

/* Switched Capacitor Routing Register */
#define PGA4_SW0_REG                  (* (reg8 *) PGA4_SC__SW0 )
#define PGA4_SW0_PTR                  (  (reg8 *) PGA4_SC__SW0 )
#define PGA4_SW2_REG                  (* (reg8 *) PGA4_SC__SW2 )
#define PGA4_SW2_PTR                  (  (reg8 *) PGA4_SC__SW2 )
#define PGA4_SW3_REG                  (* (reg8 *) PGA4_SC__SW3 )
#define PGA4_SW3_PTR                  (  (reg8 *) PGA4_SC__SW3 )
#define PGA4_SW4_REG                  (* (reg8 *) PGA4_SC__SW4 )
#define PGA4_SW4_PTR                  (  (reg8 *) PGA4_SC__SW4 )
#define PGA4_SW6_REG                  (* (reg8 *) PGA4_SC__SW6 )
#define PGA4_SW6_PTR                  (  (reg8 *) PGA4_SC__SW6 )
#define PGA4_SW7_REG                  (* (reg8 *) PGA4_SC__SW7 )
#define PGA4_SW7_PTR                  (  (reg8 *) PGA4_SC__SW7 )
#define PGA4_SW8_REG                  (* (reg8 *) PGA4_SC__SW8 )
#define PGA4_SW8_PTR                  (  (reg8 *) PGA4_SC__SW8 )
#define PGA4_SW10_REG                 (* (reg8 *) PGA4_SC__SW10 )
#define PGA4_SW10_PTR                 (  (reg8 *) PGA4_SC__SW10 )

/* Switched Capacitor Clock Selection Register */
#define PGA4_CLK_REG                  (* (reg8 *) PGA4_SC__CLK )
#define PGA4_CLK_PTR                  (  (reg8 *) PGA4_SC__CLK )

/* Switched Capacitor Boost Clock Selection Register */
#define PGA4_BSTCLK_REG               (* (reg8 *) PGA4_SC__BST )
#define PGA4_BSTCLK_PTR               (  (reg8 *) PGA4_SC__BST )

 /* Pump clock selectin register */
#define PGA4_PUMP_CR1_REG             (* (reg8 *) CYDEV_ANAIF_CFG_PUMP_CR1)
#define PGA4_PUMP_CR1_PTR             (  (reg8 *) CYDEV_ANAIF_CFG_PUMP_CR1)

/* Pump Register for SC block */
#define PGA4_SC_MISC_REG              (* (reg8 *) CYDEV_ANAIF_RT_SC_MISC)
#define PGA4_SC_MISC_PTR              (  (reg8 *) CYDEV_ANAIF_RT_SC_MISC)

/* PM_ACT_CFG (Active Power Mode CFG Register) mask */ 
#define PGA4_ACT_PWR_EN               PGA4_SC__PM_ACT_MSK
#define PGA4_STBY_PWR_EN              PGA4_SC__PM_STBY_MSK


/***************************************
*           Register Constants
***************************************/

/* CR0 SC/CT Control Register 0 definitions */
#define PGA4_MODE_PGA                 (0x0Cu)

/* CR1 SC/CT Control Register 1 definitions */

/* Bit Field  SC_COMP_ENUM */
#define PGA4_COMP_MASK                (0x0Cu)
#define PGA4_COMP_3P0PF               (0x00u)
#define PGA4_COMP_3P6PF               (0x04u)
#define PGA4_COMP_4P35PF              (0x08u)
#define PGA4_COMP_5P1PF               (0x0Cu)

/* Bit Field  SC_DIV2_ENUM */
#define PGA4_DIV2_MASK                (0x10u)
#define PGA4_DIV2_DISABLE             (0x00u)
#define PGA4_DIV2_ENABLE              (0x10u)

/* Bit Field  SC_DRIVE_ENUM */
#define PGA4_DRIVE_MASK               (0x03u)
#define PGA4_DRIVE_280UA              (0x00u)
#define PGA4_DRIVE_420UA              (0x01u)
#define PGA4_DRIVE_530UA              (0x02u)
#define PGA4_DRIVE_650UA              (0x03u)

/* Bit Field  SC_PGA_MODE_ENUM */
#define PGA4_PGA_MODE_MASK            (0x20u)
#define PGA4_PGA_INV                  (0x00u)
#define PGA4_PGA_NINV                 (0x20u)

/* CR2 SC/CT Control Register 2 definitions */

/* Bit Field  SC_BIAS_CONTROL_ENUM */
#define PGA4_BIAS_MASK                (0x01u)
#define PGA4_BIAS_NORMAL              (0x00u)
#define PGA4_BIAS_LOW                 (0x01u)

/* Bit Field  SC_PGA_GNDVREF_ENUM */
#define PGA4_GNDVREF_MASK             (0x80u)
#define PGA4_GNDVREF_DI               (0x00u)
#define PGA4_GNDVREF_E                (0x80u)

/* Bit Field  SC_R20_40B_ENUM */
#define PGA4_R20_40B_MASK             (0x02u)
#define PGA4_R20_40B_40K              (0x00u)
#define PGA4_R20_40B_20K              (0x02u)

/* Bit Field  SC_REDC_ENUM */
#define PGA4_REDC_MASK                (0x0Cu)
#define PGA4_REDC_00                  (0x00u)
#define PGA4_REDC_01                  (0x04u)
#define PGA4_REDC_10                  (0x08u)
#define PGA4_REDC_11                  (0x0Cu)

/* Bit Field  SC_RVAL_ENUM */
#define PGA4_RVAL_MASK                (0x70u)
#define PGA4_RVAL_20K                 (0x00u)
#define PGA4_RVAL_30K                 (0x10u)
#define PGA4_RVAL_40K                 (0x20u)
#define PGA4_RVAL_60K                 (0x30u)
#define PGA4_RVAL_120K                (0x40u)
#define PGA4_RVAL_250K                (0x50u)
#define PGA4_RVAL_500K                (0x60u)
#define PGA4_RVAL_1000K               (0x70u)

/* SC_MISC constants */
#define PGA4_PUMP_FORCE               (0x20u)
#define PGA4_PUMP_AUTO                (0x10u)
#define PGA4_DIFF_PGA_1_3             (0x02u)
#define PGA4_DIFF_PGA_0_2             (0x01u)

/* Bit Field  PGA_INVERTING_GAIN_ENUM */
#define PGA4_PGA_INV_GAIN_MASK        (0x72u)
#define PGA4_PGA_INV_GAIN_00          (0x00u)
#define PGA4_PGA_INV_GAIN_01          (0x10u)
#define PGA4_PGA_INV_GAIN_03          (0x20u)
#define PGA4_PGA_INV_GAIN_07          (0x30u)
#define PGA4_PGA_INV_GAIN_15          (0x40u)
#define PGA4_PGA_INV_GAIN_22          (0x50u)
#define PGA4_PGA_INV_GAIN_24          (0x70u)
#define PGA4_PGA_INV_GAIN_31          (0x52u)
#define PGA4_PGA_INV_GAIN_47          (0x62u)
#define PGA4_PGA_INV_GAIN_49          (0x72u)

/* ANIF.PUMP.CR1 Constants */
#define PGA4_PUMP_CR1_SC_CLKSEL       (0x80u)

#define PGA4_SC_REG_CLR               (0x00u)

/* Boost Clock Enable */
#define PGA4_BST_CLK_EN               (0x08u)
#define PGA4_BST_CLK_INDEX_MASK       (0x07u)
#define PGA4_PM_ACT_CFG_MASK          (0x0Fu)

/* Constants for VDDA Threshold */
#define PGA4_CYDEV_VDDA_MV             (CYDEV_VDDA_MV)
#define PGA4_MINIMUM_VDDA_THRESHOLD_MV (2700u)

/*******************************************************************************
* Following code are OBSOLETE and must not be used starting from PGA_inv 2.0
*******************************************************************************/
#define PGA4_BST_REG            (PGA4_BSTCLK_REG)
#define PGA4_BST_PTR            (PGA4_BSTCLK_PTR)

#endif /* CY_PGA_Inv_PGA4_H */


/* [] END OF FILE */
