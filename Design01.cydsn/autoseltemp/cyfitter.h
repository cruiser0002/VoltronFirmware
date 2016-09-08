#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* I2C_I2C_Prim */
#define I2C_I2C_Prim__ADR CYREG_I2C_ADR
#define I2C_I2C_Prim__CFG CYREG_I2C_CFG
#define I2C_I2C_Prim__CLK_DIV1 CYREG_I2C_CLK_DIV1
#define I2C_I2C_Prim__CLK_DIV2 CYREG_I2C_CLK_DIV2
#define I2C_I2C_Prim__CSR CYREG_I2C_CSR
#define I2C_I2C_Prim__D CYREG_I2C_D
#define I2C_I2C_Prim__MCSR CYREG_I2C_MCSR
#define I2C_I2C_Prim__PM_ACT_CFG CYREG_PM_ACT_CFG5
#define I2C_I2C_Prim__PM_ACT_MSK 0x04u
#define I2C_I2C_Prim__PM_STBY_CFG CYREG_PM_STBY_CFG5
#define I2C_I2C_Prim__PM_STBY_MSK 0x04u
#define I2C_I2C_Prim__TMOUT_CFG0 CYREG_I2C_TMOUT_CFG0
#define I2C_I2C_Prim__TMOUT_CFG1 CYREG_I2C_TMOUT_CFG1
#define I2C_I2C_Prim__TMOUT_CSR CYREG_I2C_TMOUT_CSR
#define I2C_I2C_Prim__TMOUT_SR CYREG_I2C_TMOUT_SR
#define I2C_I2C_Prim__XCFG CYREG_I2C_XCFG

/* I2C_isr */
#define I2C_isr__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define I2C_isr__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define I2C_isr__INTC_MASK 0x8000u
#define I2C_isr__INTC_NUMBER 15u
#define I2C_isr__INTC_PRIOR_NUM 7u
#define I2C_isr__INTC_PRIOR_REG CYREG_NVIC_PRI_15
#define I2C_isr__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define I2C_isr__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* IDACH_viDAC8 */
#define IDACH_viDAC8__CR0 CYREG_DAC2_CR0
#define IDACH_viDAC8__CR1 CYREG_DAC2_CR1
#define IDACH_viDAC8__D CYREG_DAC2_D
#define IDACH_viDAC8__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define IDACH_viDAC8__PM_ACT_MSK 0x04u
#define IDACH_viDAC8__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define IDACH_viDAC8__PM_STBY_MSK 0x04u
#define IDACH_viDAC8__STROBE CYREG_DAC2_STROBE
#define IDACH_viDAC8__SW0 CYREG_DAC2_SW0
#define IDACH_viDAC8__SW2 CYREG_DAC2_SW2
#define IDACH_viDAC8__SW3 CYREG_DAC2_SW3
#define IDACH_viDAC8__SW4 CYREG_DAC2_SW4
#define IDACH_viDAC8__TR CYREG_DAC2_TR
#define IDACH_viDAC8__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC2_M1
#define IDACH_viDAC8__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC2_M2
#define IDACH_viDAC8__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC2_M3
#define IDACH_viDAC8__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC2_M4
#define IDACH_viDAC8__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC2_M5
#define IDACH_viDAC8__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC2_M6
#define IDACH_viDAC8__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC2_M7
#define IDACH_viDAC8__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC2_M8
#define IDACH_viDAC8__TST CYREG_DAC2_TST

/* IDACL_viDAC8 */
#define IDACL_viDAC8__CR0 CYREG_DAC0_CR0
#define IDACL_viDAC8__CR1 CYREG_DAC0_CR1
#define IDACL_viDAC8__D CYREG_DAC0_D
#define IDACL_viDAC8__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define IDACL_viDAC8__PM_ACT_MSK 0x01u
#define IDACL_viDAC8__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define IDACL_viDAC8__PM_STBY_MSK 0x01u
#define IDACL_viDAC8__STROBE CYREG_DAC0_STROBE
#define IDACL_viDAC8__SW0 CYREG_DAC0_SW0
#define IDACL_viDAC8__SW2 CYREG_DAC0_SW2
#define IDACL_viDAC8__SW3 CYREG_DAC0_SW3
#define IDACL_viDAC8__SW4 CYREG_DAC0_SW4
#define IDACL_viDAC8__TR CYREG_DAC0_TR
#define IDACL_viDAC8__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC0_M1
#define IDACL_viDAC8__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC0_M2
#define IDACL_viDAC8__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC0_M3
#define IDACL_viDAC8__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC0_M4
#define IDACL_viDAC8__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC0_M5
#define IDACL_viDAC8__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC0_M6
#define IDACL_viDAC8__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC0_M7
#define IDACL_viDAC8__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC0_M8
#define IDACL_viDAC8__TST CYREG_DAC0_TST

/* Pin_1 */
#define Pin_1__0__INTTYPE CYREG_PICU12_INTTYPE0
#define Pin_1__0__MASK 0x01u
#define Pin_1__0__PC CYREG_PRT12_PC0
#define Pin_1__0__PORT 12u
#define Pin_1__0__SHIFT 0u
#define Pin_1__1__INTTYPE CYREG_PICU12_INTTYPE1
#define Pin_1__1__MASK 0x02u
#define Pin_1__1__PC CYREG_PRT12_PC1
#define Pin_1__1__PORT 12u
#define Pin_1__1__SHIFT 1u
#define Pin_1__AG CYREG_PRT12_AG
#define Pin_1__BIE CYREG_PRT12_BIE
#define Pin_1__BIT_MASK CYREG_PRT12_BIT_MASK
#define Pin_1__BYP CYREG_PRT12_BYP
#define Pin_1__DM0 CYREG_PRT12_DM0
#define Pin_1__DM1 CYREG_PRT12_DM1
#define Pin_1__DM2 CYREG_PRT12_DM2
#define Pin_1__DR CYREG_PRT12_DR
#define Pin_1__INP_DIS CYREG_PRT12_INP_DIS
#define Pin_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define Pin_1__MASK 0x03u
#define Pin_1__PORT 12u
#define Pin_1__PRT CYREG_PRT12_PRT
#define Pin_1__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define Pin_1__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define Pin_1__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define Pin_1__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define Pin_1__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define Pin_1__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define Pin_1__PS CYREG_PRT12_PS
#define Pin_1__scl__INTTYPE CYREG_PICU12_INTTYPE0
#define Pin_1__scl__MASK 0x01u
#define Pin_1__scl__PC CYREG_PRT12_PC0
#define Pin_1__scl__PORT 12u
#define Pin_1__scl__SHIFT 0u
#define Pin_1__sda__INTTYPE CYREG_PICU12_INTTYPE1
#define Pin_1__sda__MASK 0x02u
#define Pin_1__sda__PC CYREG_PRT12_PC1
#define Pin_1__sda__PORT 12u
#define Pin_1__sda__SHIFT 1u
#define Pin_1__SHIFT 0u
#define Pin_1__SIO_CFG CYREG_PRT12_SIO_CFG
#define Pin_1__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define Pin_1__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define Pin_1__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define Pin_1__SLW CYREG_PRT12_SLW

/* Pin_2 */
#define Pin_2__0__INTTYPE CYREG_PICU2_INTTYPE1
#define Pin_2__0__MASK 0x02u
#define Pin_2__0__PC CYREG_PRT2_PC1
#define Pin_2__0__PORT 2u
#define Pin_2__0__SHIFT 1u
#define Pin_2__AG CYREG_PRT2_AG
#define Pin_2__AMUX CYREG_PRT2_AMUX
#define Pin_2__BIE CYREG_PRT2_BIE
#define Pin_2__BIT_MASK CYREG_PRT2_BIT_MASK
#define Pin_2__BYP CYREG_PRT2_BYP
#define Pin_2__CTL CYREG_PRT2_CTL
#define Pin_2__DM0 CYREG_PRT2_DM0
#define Pin_2__DM1 CYREG_PRT2_DM1
#define Pin_2__DM2 CYREG_PRT2_DM2
#define Pin_2__DR CYREG_PRT2_DR
#define Pin_2__INP_DIS CYREG_PRT2_INP_DIS
#define Pin_2__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Pin_2__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Pin_2__LCD_EN CYREG_PRT2_LCD_EN
#define Pin_2__MASK 0x02u
#define Pin_2__PORT 2u
#define Pin_2__PRT CYREG_PRT2_PRT
#define Pin_2__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Pin_2__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Pin_2__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Pin_2__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Pin_2__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Pin_2__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Pin_2__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Pin_2__PS CYREG_PRT2_PS
#define Pin_2__SHIFT 1u
#define Pin_2__SLW CYREG_PRT2_SLW

/* Pin_3 */
#define Pin_3__0__INTTYPE CYREG_PICU2_INTTYPE2
#define Pin_3__0__MASK 0x04u
#define Pin_3__0__PC CYREG_PRT2_PC2
#define Pin_3__0__PORT 2u
#define Pin_3__0__SHIFT 2u
#define Pin_3__AG CYREG_PRT2_AG
#define Pin_3__AMUX CYREG_PRT2_AMUX
#define Pin_3__BIE CYREG_PRT2_BIE
#define Pin_3__BIT_MASK CYREG_PRT2_BIT_MASK
#define Pin_3__BYP CYREG_PRT2_BYP
#define Pin_3__CTL CYREG_PRT2_CTL
#define Pin_3__DM0 CYREG_PRT2_DM0
#define Pin_3__DM1 CYREG_PRT2_DM1
#define Pin_3__DM2 CYREG_PRT2_DM2
#define Pin_3__DR CYREG_PRT2_DR
#define Pin_3__INP_DIS CYREG_PRT2_INP_DIS
#define Pin_3__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Pin_3__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Pin_3__LCD_EN CYREG_PRT2_LCD_EN
#define Pin_3__MASK 0x04u
#define Pin_3__PORT 2u
#define Pin_3__PRT CYREG_PRT2_PRT
#define Pin_3__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Pin_3__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Pin_3__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Pin_3__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Pin_3__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Pin_3__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Pin_3__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Pin_3__PS CYREG_PRT2_PS
#define Pin_3__SHIFT 2u
#define Pin_3__SLW CYREG_PRT2_SLW

/* TIA_1_SC */
#define TIA_1_SC__BST CYREG_SC0_BST
#define TIA_1_SC__CLK CYREG_SC0_CLK
#define TIA_1_SC__CMPINV CYREG_SC_CMPINV
#define TIA_1_SC__CMPINV_MASK 0x01u
#define TIA_1_SC__CPTR CYREG_SC_CPTR
#define TIA_1_SC__CPTR_MASK 0x01u
#define TIA_1_SC__CR0 CYREG_SC0_CR0
#define TIA_1_SC__CR1 CYREG_SC0_CR1
#define TIA_1_SC__CR2 CYREG_SC0_CR2
#define TIA_1_SC__MSK CYREG_SC_MSK
#define TIA_1_SC__MSK_MASK 0x01u
#define TIA_1_SC__PM_ACT_CFG CYREG_PM_ACT_CFG9
#define TIA_1_SC__PM_ACT_MSK 0x01u
#define TIA_1_SC__PM_STBY_CFG CYREG_PM_STBY_CFG9
#define TIA_1_SC__PM_STBY_MSK 0x01u
#define TIA_1_SC__SR CYREG_SC_SR
#define TIA_1_SC__SR_MASK 0x01u
#define TIA_1_SC__SW0 CYREG_SC0_SW0
#define TIA_1_SC__SW10 CYREG_SC0_SW10
#define TIA_1_SC__SW2 CYREG_SC0_SW2
#define TIA_1_SC__SW3 CYREG_SC0_SW3
#define TIA_1_SC__SW4 CYREG_SC0_SW4
#define TIA_1_SC__SW6 CYREG_SC0_SW6
#define TIA_1_SC__SW7 CYREG_SC0_SW7
#define TIA_1_SC__SW8 CYREG_SC0_SW8
#define TIA_1_SC__WRK1 CYREG_SC_WRK1
#define TIA_1_SC__WRK1_MASK 0x01u

/* TIA_2_SC */
#define TIA_2_SC__BST CYREG_SC2_BST
#define TIA_2_SC__CLK CYREG_SC2_CLK
#define TIA_2_SC__CMPINV CYREG_SC_CMPINV
#define TIA_2_SC__CMPINV_MASK 0x04u
#define TIA_2_SC__CPTR CYREG_SC_CPTR
#define TIA_2_SC__CPTR_MASK 0x04u
#define TIA_2_SC__CR0 CYREG_SC2_CR0
#define TIA_2_SC__CR1 CYREG_SC2_CR1
#define TIA_2_SC__CR2 CYREG_SC2_CR2
#define TIA_2_SC__MSK CYREG_SC_MSK
#define TIA_2_SC__MSK_MASK 0x04u
#define TIA_2_SC__PM_ACT_CFG CYREG_PM_ACT_CFG9
#define TIA_2_SC__PM_ACT_MSK 0x04u
#define TIA_2_SC__PM_STBY_CFG CYREG_PM_STBY_CFG9
#define TIA_2_SC__PM_STBY_MSK 0x04u
#define TIA_2_SC__SR CYREG_SC_SR
#define TIA_2_SC__SR_MASK 0x04u
#define TIA_2_SC__SW0 CYREG_SC2_SW0
#define TIA_2_SC__SW10 CYREG_SC2_SW10
#define TIA_2_SC__SW2 CYREG_SC2_SW2
#define TIA_2_SC__SW3 CYREG_SC2_SW3
#define TIA_2_SC__SW4 CYREG_SC2_SW4
#define TIA_2_SC__SW6 CYREG_SC2_SW6
#define TIA_2_SC__SW7 CYREG_SC2_SW7
#define TIA_2_SC__SW8 CYREG_SC2_SW8
#define TIA_2_SC__WRK1 CYREG_SC_WRK1
#define TIA_2_SC__WRK1_MASK 0x04u

/* VDACH_viDAC8 */
#define VDACH_viDAC8__CR0 CYREG_DAC3_CR0
#define VDACH_viDAC8__CR1 CYREG_DAC3_CR1
#define VDACH_viDAC8__D CYREG_DAC3_D
#define VDACH_viDAC8__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define VDACH_viDAC8__PM_ACT_MSK 0x08u
#define VDACH_viDAC8__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define VDACH_viDAC8__PM_STBY_MSK 0x08u
#define VDACH_viDAC8__STROBE CYREG_DAC3_STROBE
#define VDACH_viDAC8__SW0 CYREG_DAC3_SW0
#define VDACH_viDAC8__SW2 CYREG_DAC3_SW2
#define VDACH_viDAC8__SW3 CYREG_DAC3_SW3
#define VDACH_viDAC8__SW4 CYREG_DAC3_SW4
#define VDACH_viDAC8__TR CYREG_DAC3_TR
#define VDACH_viDAC8__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC3_M1
#define VDACH_viDAC8__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC3_M2
#define VDACH_viDAC8__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC3_M3
#define VDACH_viDAC8__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC3_M4
#define VDACH_viDAC8__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC3_M5
#define VDACH_viDAC8__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC3_M6
#define VDACH_viDAC8__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC3_M7
#define VDACH_viDAC8__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC3_M8
#define VDACH_viDAC8__TST CYREG_DAC3_TST

/* VDACL_viDAC8 */
#define VDACL_viDAC8__CR0 CYREG_DAC1_CR0
#define VDACL_viDAC8__CR1 CYREG_DAC1_CR1
#define VDACL_viDAC8__D CYREG_DAC1_D
#define VDACL_viDAC8__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define VDACL_viDAC8__PM_ACT_MSK 0x02u
#define VDACL_viDAC8__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define VDACL_viDAC8__PM_STBY_MSK 0x02u
#define VDACL_viDAC8__STROBE CYREG_DAC1_STROBE
#define VDACL_viDAC8__SW0 CYREG_DAC1_SW0
#define VDACL_viDAC8__SW2 CYREG_DAC1_SW2
#define VDACL_viDAC8__SW3 CYREG_DAC1_SW3
#define VDACL_viDAC8__SW4 CYREG_DAC1_SW4
#define VDACL_viDAC8__TR CYREG_DAC1_TR
#define VDACL_viDAC8__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC1_M1
#define VDACL_viDAC8__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC1_M2
#define VDACL_viDAC8__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC1_M3
#define VDACL_viDAC8__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC1_M4
#define VDACL_viDAC8__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC1_M5
#define VDACL_viDAC8__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC1_M6
#define VDACL_viDAC8__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC1_M7
#define VDACL_viDAC8__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC1_M8
#define VDACL_viDAC8__TST CYREG_DAC1_TST

/* Filter_DFB */
#define Filter_DFB__ACU_SRAM_DATA CYREG_DFB0_ACU_SRAM_DATA_MBASE
#define Filter_DFB__COHER CYREG_DFB0_COHER
#define Filter_DFB__CR CYREG_DFB0_CR
#define Filter_DFB__CSA_SRAM_DATA CYREG_DFB0_CSA_SRAM_DATA_MBASE
#define Filter_DFB__CSB_SRAM_DATA CYREG_DFB0_CSB_SRAM_DATA_MBASE
#define Filter_DFB__DALIGN CYREG_DFB0_DALIGN
#define Filter_DFB__DMA_CTRL CYREG_DFB0_DMA_CTRL
#define Filter_DFB__DPA_SRAM_DATA CYREG_DFB0_DPA_SRAM_DATA_MBASE
#define Filter_DFB__DPB_SRAM_DATA CYREG_DFB0_DPB_SRAM_DATA_MBASE
#define Filter_DFB__DSI_CTRL CYREG_DFB0_DSI_CTRL
#define Filter_DFB__FSM_SRAM_DATA CYREG_DFB0_FSM_SRAM_DATA_MBASE
#define Filter_DFB__HOLDA CYREG_DFB0_HOLDA
#define Filter_DFB__HOLDAH CYREG_DFB0_HOLDAH
#define Filter_DFB__HOLDAM CYREG_DFB0_HOLDAM
#define Filter_DFB__HOLDAS CYREG_DFB0_HOLDAS
#define Filter_DFB__HOLDB CYREG_DFB0_HOLDB
#define Filter_DFB__HOLDBH CYREG_DFB0_HOLDBH
#define Filter_DFB__HOLDBM CYREG_DFB0_HOLDBM
#define Filter_DFB__HOLDBS CYREG_DFB0_HOLDBS
#define Filter_DFB__INT_CTRL CYREG_DFB0_INT_CTRL
#define Filter_DFB__PM_ACT_CFG CYREG_PM_ACT_CFG6
#define Filter_DFB__PM_ACT_MSK 0x10u
#define Filter_DFB__PM_STBY_CFG CYREG_PM_STBY_CFG6
#define Filter_DFB__PM_STBY_MSK 0x10u
#define Filter_DFB__RAM_DIR CYREG_DFB0_RAM_DIR
#define Filter_DFB__RAM_EN CYREG_DFB0_RAM_EN
#define Filter_DFB__SEMA CYREG_DFB0_SEMA
#define Filter_DFB__SR CYREG_DFB0_SR
#define Filter_DFB__STAGEA CYREG_DFB0_STAGEA
#define Filter_DFB__STAGEAH CYREG_DFB0_STAGEAH
#define Filter_DFB__STAGEAM CYREG_DFB0_STAGEAM
#define Filter_DFB__STAGEB CYREG_DFB0_STAGEB
#define Filter_DFB__STAGEBH CYREG_DFB0_STAGEBH
#define Filter_DFB__STAGEBM CYREG_DFB0_STAGEBM

/* Pin_PD1 */
#define Pin_PD1__0__INTTYPE CYREG_PICU3_INTTYPE0
#define Pin_PD1__0__MASK 0x01u
#define Pin_PD1__0__PC CYREG_PRT3_PC0
#define Pin_PD1__0__PORT 3u
#define Pin_PD1__0__SHIFT 0u
#define Pin_PD1__AG CYREG_PRT3_AG
#define Pin_PD1__AMUX CYREG_PRT3_AMUX
#define Pin_PD1__BIE CYREG_PRT3_BIE
#define Pin_PD1__BIT_MASK CYREG_PRT3_BIT_MASK
#define Pin_PD1__BYP CYREG_PRT3_BYP
#define Pin_PD1__CTL CYREG_PRT3_CTL
#define Pin_PD1__DM0 CYREG_PRT3_DM0
#define Pin_PD1__DM1 CYREG_PRT3_DM1
#define Pin_PD1__DM2 CYREG_PRT3_DM2
#define Pin_PD1__DR CYREG_PRT3_DR
#define Pin_PD1__INP_DIS CYREG_PRT3_INP_DIS
#define Pin_PD1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Pin_PD1__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Pin_PD1__LCD_EN CYREG_PRT3_LCD_EN
#define Pin_PD1__MASK 0x01u
#define Pin_PD1__PORT 3u
#define Pin_PD1__PRT CYREG_PRT3_PRT
#define Pin_PD1__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Pin_PD1__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Pin_PD1__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Pin_PD1__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Pin_PD1__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Pin_PD1__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Pin_PD1__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Pin_PD1__PS CYREG_PRT3_PS
#define Pin_PD1__SHIFT 0u
#define Pin_PD1__SLW CYREG_PRT3_SLW

/* Pin_PD2 */
#define Pin_PD2__0__INTTYPE CYREG_PICU0_INTTYPE3
#define Pin_PD2__0__MASK 0x08u
#define Pin_PD2__0__PC CYREG_PRT0_PC3
#define Pin_PD2__0__PORT 0u
#define Pin_PD2__0__SHIFT 3u
#define Pin_PD2__AG CYREG_PRT0_AG
#define Pin_PD2__AMUX CYREG_PRT0_AMUX
#define Pin_PD2__BIE CYREG_PRT0_BIE
#define Pin_PD2__BIT_MASK CYREG_PRT0_BIT_MASK
#define Pin_PD2__BYP CYREG_PRT0_BYP
#define Pin_PD2__CTL CYREG_PRT0_CTL
#define Pin_PD2__DM0 CYREG_PRT0_DM0
#define Pin_PD2__DM1 CYREG_PRT0_DM1
#define Pin_PD2__DM2 CYREG_PRT0_DM2
#define Pin_PD2__DR CYREG_PRT0_DR
#define Pin_PD2__INP_DIS CYREG_PRT0_INP_DIS
#define Pin_PD2__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define Pin_PD2__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define Pin_PD2__LCD_EN CYREG_PRT0_LCD_EN
#define Pin_PD2__MASK 0x08u
#define Pin_PD2__PORT 0u
#define Pin_PD2__PRT CYREG_PRT0_PRT
#define Pin_PD2__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define Pin_PD2__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define Pin_PD2__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define Pin_PD2__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define Pin_PD2__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define Pin_PD2__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define Pin_PD2__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define Pin_PD2__PS CYREG_PRT0_PS
#define Pin_PD2__SHIFT 3u
#define Pin_PD2__SLW CYREG_PRT0_SLW

/* Pin_TIA1 */
#define Pin_TIA1__0__INTTYPE CYREG_PICU3_INTTYPE7
#define Pin_TIA1__0__MASK 0x80u
#define Pin_TIA1__0__PC CYREG_PRT3_PC7
#define Pin_TIA1__0__PORT 3u
#define Pin_TIA1__0__SHIFT 7u
#define Pin_TIA1__AG CYREG_PRT3_AG
#define Pin_TIA1__AMUX CYREG_PRT3_AMUX
#define Pin_TIA1__BIE CYREG_PRT3_BIE
#define Pin_TIA1__BIT_MASK CYREG_PRT3_BIT_MASK
#define Pin_TIA1__BYP CYREG_PRT3_BYP
#define Pin_TIA1__CTL CYREG_PRT3_CTL
#define Pin_TIA1__DM0 CYREG_PRT3_DM0
#define Pin_TIA1__DM1 CYREG_PRT3_DM1
#define Pin_TIA1__DM2 CYREG_PRT3_DM2
#define Pin_TIA1__DR CYREG_PRT3_DR
#define Pin_TIA1__INP_DIS CYREG_PRT3_INP_DIS
#define Pin_TIA1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Pin_TIA1__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Pin_TIA1__LCD_EN CYREG_PRT3_LCD_EN
#define Pin_TIA1__MASK 0x80u
#define Pin_TIA1__PORT 3u
#define Pin_TIA1__PRT CYREG_PRT3_PRT
#define Pin_TIA1__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Pin_TIA1__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Pin_TIA1__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Pin_TIA1__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Pin_TIA1__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Pin_TIA1__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Pin_TIA1__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Pin_TIA1__PS CYREG_PRT3_PS
#define Pin_TIA1__SHIFT 7u
#define Pin_TIA1__SLW CYREG_PRT3_SLW

/* Pin_TIA2 */
#define Pin_TIA2__0__INTTYPE CYREG_PICU0_INTTYPE5
#define Pin_TIA2__0__MASK 0x20u
#define Pin_TIA2__0__PC CYREG_PRT0_PC5
#define Pin_TIA2__0__PORT 0u
#define Pin_TIA2__0__SHIFT 5u
#define Pin_TIA2__AG CYREG_PRT0_AG
#define Pin_TIA2__AMUX CYREG_PRT0_AMUX
#define Pin_TIA2__BIE CYREG_PRT0_BIE
#define Pin_TIA2__BIT_MASK CYREG_PRT0_BIT_MASK
#define Pin_TIA2__BYP CYREG_PRT0_BYP
#define Pin_TIA2__CTL CYREG_PRT0_CTL
#define Pin_TIA2__DM0 CYREG_PRT0_DM0
#define Pin_TIA2__DM1 CYREG_PRT0_DM1
#define Pin_TIA2__DM2 CYREG_PRT0_DM2
#define Pin_TIA2__DR CYREG_PRT0_DR
#define Pin_TIA2__INP_DIS CYREG_PRT0_INP_DIS
#define Pin_TIA2__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define Pin_TIA2__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define Pin_TIA2__LCD_EN CYREG_PRT0_LCD_EN
#define Pin_TIA2__MASK 0x20u
#define Pin_TIA2__PORT 0u
#define Pin_TIA2__PRT CYREG_PRT0_PRT
#define Pin_TIA2__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define Pin_TIA2__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define Pin_TIA2__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define Pin_TIA2__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define Pin_TIA2__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define Pin_TIA2__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define Pin_TIA2__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define Pin_TIA2__PS CYREG_PRT0_PS
#define Pin_TIA2__SHIFT 5u
#define Pin_TIA2__SLW CYREG_PRT0_SLW

/* ADC_SAR_1_ADC_SAR */
#define ADC_SAR_1_ADC_SAR__CLK CYREG_SAR1_CLK
#define ADC_SAR_1_ADC_SAR__CSR0 CYREG_SAR1_CSR0
#define ADC_SAR_1_ADC_SAR__CSR1 CYREG_SAR1_CSR1
#define ADC_SAR_1_ADC_SAR__CSR2 CYREG_SAR1_CSR2
#define ADC_SAR_1_ADC_SAR__CSR3 CYREG_SAR1_CSR3
#define ADC_SAR_1_ADC_SAR__CSR4 CYREG_SAR1_CSR4
#define ADC_SAR_1_ADC_SAR__CSR5 CYREG_SAR1_CSR5
#define ADC_SAR_1_ADC_SAR__CSR6 CYREG_SAR1_CSR6
#define ADC_SAR_1_ADC_SAR__PM_ACT_CFG CYREG_PM_ACT_CFG11
#define ADC_SAR_1_ADC_SAR__PM_ACT_MSK 0x02u
#define ADC_SAR_1_ADC_SAR__PM_STBY_CFG CYREG_PM_STBY_CFG11
#define ADC_SAR_1_ADC_SAR__PM_STBY_MSK 0x02u
#define ADC_SAR_1_ADC_SAR__SW0 CYREG_SAR1_SW0
#define ADC_SAR_1_ADC_SAR__SW2 CYREG_SAR1_SW2
#define ADC_SAR_1_ADC_SAR__SW3 CYREG_SAR1_SW3
#define ADC_SAR_1_ADC_SAR__SW4 CYREG_SAR1_SW4
#define ADC_SAR_1_ADC_SAR__SW6 CYREG_SAR1_SW6
#define ADC_SAR_1_ADC_SAR__TR0 CYREG_SAR1_TR0
#define ADC_SAR_1_ADC_SAR__WRK0 CYREG_SAR1_WRK0
#define ADC_SAR_1_ADC_SAR__WRK1 CYREG_SAR1_WRK1

/* ADC_SAR_1_Bypass */
#define ADC_SAR_1_Bypass__0__INTTYPE CYREG_PICU0_INTTYPE2
#define ADC_SAR_1_Bypass__0__MASK 0x04u
#define ADC_SAR_1_Bypass__0__PC CYREG_PRT0_PC2
#define ADC_SAR_1_Bypass__0__PORT 0u
#define ADC_SAR_1_Bypass__0__SHIFT 2u
#define ADC_SAR_1_Bypass__AG CYREG_PRT0_AG
#define ADC_SAR_1_Bypass__AMUX CYREG_PRT0_AMUX
#define ADC_SAR_1_Bypass__BIE CYREG_PRT0_BIE
#define ADC_SAR_1_Bypass__BIT_MASK CYREG_PRT0_BIT_MASK
#define ADC_SAR_1_Bypass__BYP CYREG_PRT0_BYP
#define ADC_SAR_1_Bypass__CTL CYREG_PRT0_CTL
#define ADC_SAR_1_Bypass__DM0 CYREG_PRT0_DM0
#define ADC_SAR_1_Bypass__DM1 CYREG_PRT0_DM1
#define ADC_SAR_1_Bypass__DM2 CYREG_PRT0_DM2
#define ADC_SAR_1_Bypass__DR CYREG_PRT0_DR
#define ADC_SAR_1_Bypass__INP_DIS CYREG_PRT0_INP_DIS
#define ADC_SAR_1_Bypass__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define ADC_SAR_1_Bypass__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define ADC_SAR_1_Bypass__LCD_EN CYREG_PRT0_LCD_EN
#define ADC_SAR_1_Bypass__MASK 0x04u
#define ADC_SAR_1_Bypass__PORT 0u
#define ADC_SAR_1_Bypass__PRT CYREG_PRT0_PRT
#define ADC_SAR_1_Bypass__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define ADC_SAR_1_Bypass__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define ADC_SAR_1_Bypass__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define ADC_SAR_1_Bypass__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define ADC_SAR_1_Bypass__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define ADC_SAR_1_Bypass__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define ADC_SAR_1_Bypass__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define ADC_SAR_1_Bypass__PS CYREG_PRT0_PS
#define ADC_SAR_1_Bypass__SHIFT 2u
#define ADC_SAR_1_Bypass__SLW CYREG_PRT0_SLW

/* ADC_SAR_1_IRQ */
#define ADC_SAR_1_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define ADC_SAR_1_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define ADC_SAR_1_IRQ__INTC_MASK 0x02u
#define ADC_SAR_1_IRQ__INTC_NUMBER 1u
#define ADC_SAR_1_IRQ__INTC_PRIOR_NUM 7u
#define ADC_SAR_1_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_1
#define ADC_SAR_1_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define ADC_SAR_1_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* ADC_SAR_1_theACLK */
#define ADC_SAR_1_theACLK__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define ADC_SAR_1_theACLK__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define ADC_SAR_1_theACLK__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define ADC_SAR_1_theACLK__CFG2_SRC_SEL_MASK 0x07u
#define ADC_SAR_1_theACLK__INDEX 0x00u
#define ADC_SAR_1_theACLK__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define ADC_SAR_1_theACLK__PM_ACT_MSK 0x01u
#define ADC_SAR_1_theACLK__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define ADC_SAR_1_theACLK__PM_STBY_MSK 0x01u

/* Pin_IDACH */
#define Pin_IDACH__0__INTTYPE CYREG_PICU0_INTTYPE7
#define Pin_IDACH__0__MASK 0x80u
#define Pin_IDACH__0__PC CYREG_PRT0_PC7
#define Pin_IDACH__0__PORT 0u
#define Pin_IDACH__0__SHIFT 7u
#define Pin_IDACH__AG CYREG_PRT0_AG
#define Pin_IDACH__AMUX CYREG_PRT0_AMUX
#define Pin_IDACH__BIE CYREG_PRT0_BIE
#define Pin_IDACH__BIT_MASK CYREG_PRT0_BIT_MASK
#define Pin_IDACH__BYP CYREG_PRT0_BYP
#define Pin_IDACH__CTL CYREG_PRT0_CTL
#define Pin_IDACH__DM0 CYREG_PRT0_DM0
#define Pin_IDACH__DM1 CYREG_PRT0_DM1
#define Pin_IDACH__DM2 CYREG_PRT0_DM2
#define Pin_IDACH__DR CYREG_PRT0_DR
#define Pin_IDACH__INP_DIS CYREG_PRT0_INP_DIS
#define Pin_IDACH__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define Pin_IDACH__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define Pin_IDACH__LCD_EN CYREG_PRT0_LCD_EN
#define Pin_IDACH__MASK 0x80u
#define Pin_IDACH__PORT 0u
#define Pin_IDACH__PRT CYREG_PRT0_PRT
#define Pin_IDACH__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define Pin_IDACH__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define Pin_IDACH__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define Pin_IDACH__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define Pin_IDACH__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define Pin_IDACH__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define Pin_IDACH__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define Pin_IDACH__PS CYREG_PRT0_PS
#define Pin_IDACH__SHIFT 7u
#define Pin_IDACH__SLW CYREG_PRT0_SLW

/* Pin_IDACL */
#define Pin_IDACL__0__INTTYPE CYREG_PICU0_INTTYPE6
#define Pin_IDACL__0__MASK 0x40u
#define Pin_IDACL__0__PC CYREG_PRT0_PC6
#define Pin_IDACL__0__PORT 0u
#define Pin_IDACL__0__SHIFT 6u
#define Pin_IDACL__AG CYREG_PRT0_AG
#define Pin_IDACL__AMUX CYREG_PRT0_AMUX
#define Pin_IDACL__BIE CYREG_PRT0_BIE
#define Pin_IDACL__BIT_MASK CYREG_PRT0_BIT_MASK
#define Pin_IDACL__BYP CYREG_PRT0_BYP
#define Pin_IDACL__CTL CYREG_PRT0_CTL
#define Pin_IDACL__DM0 CYREG_PRT0_DM0
#define Pin_IDACL__DM1 CYREG_PRT0_DM1
#define Pin_IDACL__DM2 CYREG_PRT0_DM2
#define Pin_IDACL__DR CYREG_PRT0_DR
#define Pin_IDACL__INP_DIS CYREG_PRT0_INP_DIS
#define Pin_IDACL__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define Pin_IDACL__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define Pin_IDACL__LCD_EN CYREG_PRT0_LCD_EN
#define Pin_IDACL__MASK 0x40u
#define Pin_IDACL__PORT 0u
#define Pin_IDACL__PRT CYREG_PRT0_PRT
#define Pin_IDACL__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define Pin_IDACL__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define Pin_IDACL__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define Pin_IDACL__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define Pin_IDACL__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define Pin_IDACL__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define Pin_IDACL__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define Pin_IDACL__PS CYREG_PRT0_PS
#define Pin_IDACL__SHIFT 6u
#define Pin_IDACL__SLW CYREG_PRT0_SLW

/* Pin_VDACH */
#define Pin_VDACH__0__INTTYPE CYREG_PICU1_INTTYPE4
#define Pin_VDACH__0__MASK 0x10u
#define Pin_VDACH__0__PC CYREG_PRT1_PC4
#define Pin_VDACH__0__PORT 1u
#define Pin_VDACH__0__SHIFT 4u
#define Pin_VDACH__AG CYREG_PRT1_AG
#define Pin_VDACH__AMUX CYREG_PRT1_AMUX
#define Pin_VDACH__BIE CYREG_PRT1_BIE
#define Pin_VDACH__BIT_MASK CYREG_PRT1_BIT_MASK
#define Pin_VDACH__BYP CYREG_PRT1_BYP
#define Pin_VDACH__CTL CYREG_PRT1_CTL
#define Pin_VDACH__DM0 CYREG_PRT1_DM0
#define Pin_VDACH__DM1 CYREG_PRT1_DM1
#define Pin_VDACH__DM2 CYREG_PRT1_DM2
#define Pin_VDACH__DR CYREG_PRT1_DR
#define Pin_VDACH__INP_DIS CYREG_PRT1_INP_DIS
#define Pin_VDACH__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define Pin_VDACH__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Pin_VDACH__LCD_EN CYREG_PRT1_LCD_EN
#define Pin_VDACH__MASK 0x10u
#define Pin_VDACH__PORT 1u
#define Pin_VDACH__PRT CYREG_PRT1_PRT
#define Pin_VDACH__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Pin_VDACH__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Pin_VDACH__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Pin_VDACH__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Pin_VDACH__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Pin_VDACH__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Pin_VDACH__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Pin_VDACH__PS CYREG_PRT1_PS
#define Pin_VDACH__SHIFT 4u
#define Pin_VDACH__SLW CYREG_PRT1_SLW

/* Pin_VDACL */
#define Pin_VDACL__0__INTTYPE CYREG_PICU1_INTTYPE5
#define Pin_VDACL__0__MASK 0x20u
#define Pin_VDACL__0__PC CYREG_PRT1_PC5
#define Pin_VDACL__0__PORT 1u
#define Pin_VDACL__0__SHIFT 5u
#define Pin_VDACL__AG CYREG_PRT1_AG
#define Pin_VDACL__AMUX CYREG_PRT1_AMUX
#define Pin_VDACL__BIE CYREG_PRT1_BIE
#define Pin_VDACL__BIT_MASK CYREG_PRT1_BIT_MASK
#define Pin_VDACL__BYP CYREG_PRT1_BYP
#define Pin_VDACL__CTL CYREG_PRT1_CTL
#define Pin_VDACL__DM0 CYREG_PRT1_DM0
#define Pin_VDACL__DM1 CYREG_PRT1_DM1
#define Pin_VDACL__DM2 CYREG_PRT1_DM2
#define Pin_VDACL__DR CYREG_PRT1_DR
#define Pin_VDACL__INP_DIS CYREG_PRT1_INP_DIS
#define Pin_VDACL__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define Pin_VDACL__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define Pin_VDACL__LCD_EN CYREG_PRT1_LCD_EN
#define Pin_VDACL__MASK 0x20u
#define Pin_VDACL__PORT 1u
#define Pin_VDACL__PRT CYREG_PRT1_PRT
#define Pin_VDACL__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define Pin_VDACL__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define Pin_VDACL__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define Pin_VDACL__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define Pin_VDACL__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define Pin_VDACL__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define Pin_VDACL__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define Pin_VDACL__PS CYREG_PRT1_PS
#define Pin_VDACL__SHIFT 5u
#define Pin_VDACL__SLW CYREG_PRT1_SLW

/* DMA_ADC2RAM */
#define DMA_ADC2RAM__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define DMA_ADC2RAM__DRQ_NUMBER 1u
#define DMA_ADC2RAM__NUMBEROF_TDS 0u
#define DMA_ADC2RAM__PRIORITY 2u
#define DMA_ADC2RAM__TERMIN_EN 0u
#define DMA_ADC2RAM__TERMIN_SEL 0u
#define DMA_ADC2RAM__TERMOUT0_EN 1u
#define DMA_ADC2RAM__TERMOUT0_SEL 1u
#define DMA_ADC2RAM__TERMOUT1_EN 0u
#define DMA_ADC2RAM__TERMOUT1_SEL 0u

/* DMA_RAM2DAC */
#define DMA_RAM2DAC__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define DMA_RAM2DAC__DRQ_NUMBER 2u
#define DMA_RAM2DAC__NUMBEROF_TDS 0u
#define DMA_RAM2DAC__PRIORITY 2u
#define DMA_RAM2DAC__TERMIN_EN 0u
#define DMA_RAM2DAC__TERMIN_SEL 0u
#define DMA_RAM2DAC__TERMOUT0_EN 0u
#define DMA_RAM2DAC__TERMOUT0_SEL 0u
#define DMA_RAM2DAC__TERMOUT1_EN 0u
#define DMA_RAM2DAC__TERMOUT1_SEL 0u

/* DMA_ADC2FILT */
#define DMA_ADC2FILT__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define DMA_ADC2FILT__DRQ_NUMBER 0u
#define DMA_ADC2FILT__NUMBEROF_TDS 0u
#define DMA_ADC2FILT__PRIORITY 2u
#define DMA_ADC2FILT__TERMIN_EN 0u
#define DMA_ADC2FILT__TERMIN_SEL 0u
#define DMA_ADC2FILT__TERMOUT0_EN 0u
#define DMA_ADC2FILT__TERMOUT0_SEL 0u
#define DMA_ADC2FILT__TERMOUT1_EN 0u
#define DMA_ADC2FILT__TERMOUT1_SEL 0u

/* DMA_FILT2RAM */
#define DMA_FILT2RAM__DRQ_CTL CYREG_IDMUX_DRQ_CTL2
#define DMA_FILT2RAM__DRQ_NUMBER 8u
#define DMA_FILT2RAM__NUMBEROF_TDS 0u
#define DMA_FILT2RAM__PRIORITY 2u
#define DMA_FILT2RAM__TERMIN_EN 0u
#define DMA_FILT2RAM__TERMIN_SEL 0u
#define DMA_FILT2RAM__TERMOUT0_EN 1u
#define DMA_FILT2RAM__TERMOUT0_SEL 8u
#define DMA_FILT2RAM__TERMOUT1_EN 0u
#define DMA_FILT2RAM__TERMOUT1_SEL 0u

/* DMA_RAM2FILT */
#define DMA_RAM2FILT__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define DMA_RAM2FILT__DRQ_NUMBER 3u
#define DMA_RAM2FILT__NUMBEROF_TDS 0u
#define DMA_RAM2FILT__PRIORITY 2u
#define DMA_RAM2FILT__TERMIN_EN 0u
#define DMA_RAM2FILT__TERMIN_SEL 0u
#define DMA_RAM2FILT__TERMOUT0_EN 1u
#define DMA_RAM2FILT__TERMOUT0_SEL 3u
#define DMA_RAM2FILT__TERMOUT1_EN 0u
#define DMA_RAM2FILT__TERMOUT1_SEL 0u

/* Pin_Status_1 */
#define Pin_Status_1__0__INTTYPE CYREG_PICU2_INTTYPE0
#define Pin_Status_1__0__MASK 0x01u
#define Pin_Status_1__0__PC CYREG_PRT2_PC0
#define Pin_Status_1__0__PORT 2u
#define Pin_Status_1__0__SHIFT 0u
#define Pin_Status_1__AG CYREG_PRT2_AG
#define Pin_Status_1__AMUX CYREG_PRT2_AMUX
#define Pin_Status_1__BIE CYREG_PRT2_BIE
#define Pin_Status_1__BIT_MASK CYREG_PRT2_BIT_MASK
#define Pin_Status_1__BYP CYREG_PRT2_BYP
#define Pin_Status_1__CTL CYREG_PRT2_CTL
#define Pin_Status_1__DM0 CYREG_PRT2_DM0
#define Pin_Status_1__DM1 CYREG_PRT2_DM1
#define Pin_Status_1__DM2 CYREG_PRT2_DM2
#define Pin_Status_1__DR CYREG_PRT2_DR
#define Pin_Status_1__INP_DIS CYREG_PRT2_INP_DIS
#define Pin_Status_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Pin_Status_1__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Pin_Status_1__LCD_EN CYREG_PRT2_LCD_EN
#define Pin_Status_1__MASK 0x01u
#define Pin_Status_1__PORT 2u
#define Pin_Status_1__PRT CYREG_PRT2_PRT
#define Pin_Status_1__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Pin_Status_1__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Pin_Status_1__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Pin_Status_1__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Pin_Status_1__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Pin_Status_1__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Pin_Status_1__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Pin_Status_1__PS CYREG_PRT2_PS
#define Pin_Status_1__SHIFT 0u
#define Pin_Status_1__SLW CYREG_PRT2_SLW

/* ISR_DMA_FILT2RAM */
#define ISR_DMA_FILT2RAM__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define ISR_DMA_FILT2RAM__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define ISR_DMA_FILT2RAM__INTC_MASK 0x01u
#define ISR_DMA_FILT2RAM__INTC_NUMBER 0u
#define ISR_DMA_FILT2RAM__INTC_PRIOR_NUM 7u
#define ISR_DMA_FILT2RAM__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define ISR_DMA_FILT2RAM__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define ISR_DMA_FILT2RAM__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "Design01"
#define CY_VERSION "PSoC Creator  3.3 CP3"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 19u
#define CYDEV_CHIP_DIE_PSOC4A 11u
#define CYDEV_CHIP_DIE_PSOC5LP 18u
#define CYDEV_CHIP_DIE_TMA4 2u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 11u
#define CYDEV_CHIP_MEMBER_4C 16u
#define CYDEV_CHIP_MEMBER_4D 7u
#define CYDEV_CHIP_MEMBER_4E 4u
#define CYDEV_CHIP_MEMBER_4F 12u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 10u
#define CYDEV_CHIP_MEMBER_4I 15u
#define CYDEV_CHIP_MEMBER_4J 8u
#define CYDEV_CHIP_MEMBER_4K 9u
#define CYDEV_CHIP_MEMBER_4L 14u
#define CYDEV_CHIP_MEMBER_4M 13u
#define CYDEV_CHIP_MEMBER_4N 6u
#define CYDEV_CHIP_MEMBER_4O 5u
#define CYDEV_CHIP_MEMBER_4U 3u
#define CYDEV_CHIP_MEMBER_5A 18u
#define CYDEV_CHIP_MEMBER_5B 17u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4C_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00008003u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x0000010Fu
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */