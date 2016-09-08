/*******************************************************************************
* File Name: VDACH.h  
* Version 1.90
*
*  Description:
*    This file contains the function prototypes and constants used in
*    the 8-bit Voltage DAC (vDAC8) User Module.
*
*   Note:
*     
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_VDAC8_VDACH_H) 
#define CY_VDAC8_VDACH_H

#include "cytypes.h"
#include "cyfitter.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component VDAC8_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/***************************************
*       Type defines
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState; 
    uint8 data_value;
}VDACH_backupStruct;

/* component init state */
extern uint8 VDACH_initVar;


/***************************************
*        Function Prototypes 
***************************************/

void VDACH_Start(void)           ;
void VDACH_Stop(void)            ;
void VDACH_SetSpeed(uint8 speed) ;
void VDACH_SetRange(uint8 range) ;
void VDACH_SetValue(uint8 value) ;
void VDACH_DacTrim(void)         ;
void VDACH_Init(void)            ;
void VDACH_Enable(void)          ;
void VDACH_SaveConfig(void)      ;
void VDACH_RestoreConfig(void)   ;
void VDACH_Sleep(void)           ;
void VDACH_Wakeup(void)          ;


/***************************************
*            API Constants
***************************************/

/* SetRange constants */

#define VDACH_RANGE_1V       0x00u
#define VDACH_RANGE_4V       0x04u


/* Power setting for Start API  */
#define VDACH_LOWSPEED       0x00u
#define VDACH_HIGHSPEED      0x02u


/***************************************
*  Initialization Parameter Constants
***************************************/

 /* Default DAC range */
#define VDACH_DEFAULT_RANGE    0u
 /* Default DAC speed */
#define VDACH_DEFAULT_SPEED    0u
 /* Default Control */
#define VDACH_DEFAULT_CNTL      0x00u
/* Default Strobe mode */
#define VDACH_DEFAULT_STRB     0u
 /* Initial DAC value */
#define VDACH_DEFAULT_DATA     100u
 /* Default Data Source */
#define VDACH_DEFAULT_DATA_SRC 0u


/***************************************
*              Registers        
***************************************/
#define VDACH_CR0_REG            (* (reg8 *) VDACH_viDAC8__CR0 )
#define VDACH_CR0_PTR            (  (reg8 *) VDACH_viDAC8__CR0 )
#define VDACH_CR1_REG            (* (reg8 *) VDACH_viDAC8__CR1 )
#define VDACH_CR1_PTR            (  (reg8 *) VDACH_viDAC8__CR1 )
#define VDACH_Data_REG           (* (reg8 *) VDACH_viDAC8__D )
#define VDACH_Data_PTR           (  (reg8 *) VDACH_viDAC8__D )
#define VDACH_Strobe_REG         (* (reg8 *) VDACH_viDAC8__STROBE )
#define VDACH_Strobe_PTR         (  (reg8 *) VDACH_viDAC8__STROBE )
#define VDACH_SW0_REG            (* (reg8 *) VDACH_viDAC8__SW0 )
#define VDACH_SW0_PTR            (  (reg8 *) VDACH_viDAC8__SW0 )
#define VDACH_SW2_REG            (* (reg8 *) VDACH_viDAC8__SW2 )
#define VDACH_SW2_PTR            (  (reg8 *) VDACH_viDAC8__SW2 )
#define VDACH_SW3_REG            (* (reg8 *) VDACH_viDAC8__SW3 )
#define VDACH_SW3_PTR            (  (reg8 *) VDACH_viDAC8__SW3 )
#define VDACH_SW4_REG            (* (reg8 *) VDACH_viDAC8__SW4 )
#define VDACH_SW4_PTR            (  (reg8 *) VDACH_viDAC8__SW4 )
#define VDACH_TR_REG             (* (reg8 *) VDACH_viDAC8__TR )
#define VDACH_TR_PTR             (  (reg8 *) VDACH_viDAC8__TR )
/* Power manager */
#define VDACH_PWRMGR_REG         (* (reg8 *) VDACH_viDAC8__PM_ACT_CFG )
#define VDACH_PWRMGR_PTR         (  (reg8 *) VDACH_viDAC8__PM_ACT_CFG )
  /* Standby Power manager */
#define VDACH_STBY_PWRMGR_REG    (* (reg8 *) VDACH_viDAC8__PM_STBY_CFG )
#define VDACH_STBY_PWRMGR_PTR    (  (reg8 *) VDACH_viDAC8__PM_STBY_CFG )

/***************************************
*  Registers definitions
* for backward capability        
***************************************/
#define VDACH_CR0         (* (reg8 *) VDACH_viDAC8__CR0 )
#define VDACH_CR1         (* (reg8 *) VDACH_viDAC8__CR1 )
#define VDACH_Data        (* (reg8 *) VDACH_viDAC8__D )
#define VDACH_Data_PTR    (  (reg8 *) VDACH_viDAC8__D )
#define VDACH_Strobe      (* (reg8 *) VDACH_viDAC8__STROBE )
#define VDACH_SW0         (* (reg8 *) VDACH_viDAC8__SW0 )
#define VDACH_SW2         (* (reg8 *) VDACH_viDAC8__SW2 )
#define VDACH_SW3         (* (reg8 *) VDACH_viDAC8__SW3 )
#define VDACH_SW4         (* (reg8 *) VDACH_viDAC8__SW4 )
#define VDACH_TR          (* (reg8 *) VDACH_viDAC8__TR )
/* Power manager */
#define VDACH_PWRMGR      (* (reg8 *) VDACH_viDAC8__PM_ACT_CFG )
  /* Standby Power manager */
#define VDACH_STBY_PWRMGR (* (reg8 *) VDACH_viDAC8__PM_STBY_CFG )


/***************************************
*         Register Constants       
***************************************/

/* CR0 vDac Control Register 0 definitions */

/* Bit Field  DAC_HS_MODE                  */
#define VDACH_HS_MASK        0x02u
#define VDACH_HS_LOWPOWER    0x00u
#define VDACH_HS_HIGHSPEED   0x02u

/* Bit Field  DAC_MODE                  */
#define VDACH_MODE_MASK      0x10u
#define VDACH_MODE_V         0x00u
#define VDACH_MODE_I         0x10u

/* Bit Field  DAC_RANGE                  */
#define VDACH_RANGE_MASK     0x0Cu
#define VDACH_RANGE_0        0x00u
#define VDACH_RANGE_1        0x04u

/* CR1 iDac Control Register 1 definitions */

/* Bit Field  DAC_MX_DATA                  */
#define VDACH_SRC_MASK       0x20u
#define VDACH_SRC_REG        0x00u
#define VDACH_SRC_UDB        0x20u

/* This bit enable reset from UDB array      */
#define VDACH_RESET_MASK     0x10u
#define VDACH_RESET_ENABLE   0x10u
#define VDACH_RESET_DISABLE  0x00u

/* This bit enables data from DAC bus      */
#define VDACH_DACBUS_MASK     0x20u
#define VDACH_DACBUS_ENABLE   0x20u
#define VDACH_DACBUS_DISABLE  0x00u

/* DAC STROBE Strobe Control Register definitions */

/* Bit Field  DAC_MX_STROBE                  */
#define VDACH_STRB_MASK     0x08u
#define VDACH_STRB_EN       0x08u
#define VDACH_STRB_DIS      0x00u

/* PM_ACT_CFG (Active Power Mode CFG Register)     */ 
#define VDACH_ACT_PWR_EN   VDACH_viDAC8__PM_ACT_MSK
  /* Standby Power enable mask */
#define VDACH_STBY_PWR_EN  VDACH_viDAC8__PM_STBY_MSK


/*******************************************************************************
*              Trim    
* Note - VDAC trim values are stored in the "Customer Table" area in * Row 1 of
*the Hidden Flash.  There are 8 bytes of trim data for each VDAC block.
* The values are:
*       I Gain offset, min range, Sourcing
*       I Gain offset, min range, Sinking
*       I Gain offset, med range, Sourcing
*       I Gain offset, med range, Sinking
*       I Gain offset, max range, Sourcing
*       I Gain offset, max range, Sinking
*       V Gain offset, 1V range
*       V Gain offset, 4V range
*
* The data set for the 4 VDACs are arranged using a left side/right side
* approach:
*   Left 0, Left 1, Right 0, Right 1.
* When mapped to the VDAC0 thru VDAC3 as:
*   VDAC 0, VDAC 2, VDAC 1, VDAC 3
*******************************************************************************/
#define VDACH_TRIM_M7_1V_RNG_OFFSET  0x06u
#define VDACH_TRIM_M8_4V_RNG_OFFSET  0x07u
/*Constatnt to set DAC in current mode and turnoff output */
#define VDACH_CUR_MODE_OUT_OFF       0x1Eu 
#define VDACH_DAC_TRIM_BASE          (VDACH_viDAC8__TRIM__M1)

#endif /* CY_VDAC8_VDACH_H  */


/* [] END OF FILE */


