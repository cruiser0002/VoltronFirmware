/*******************************************************************************
* File Name: Pin_I2C.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pin_I2C_ALIASES_H) /* Pins Pin_I2C_ALIASES_H */
#define CY_PINS_Pin_I2C_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Pin_I2C_0			(Pin_I2C__0__PC)
#define Pin_I2C_0_INTR	((uint16)((uint16)0x0001u << Pin_I2C__0__SHIFT))

#define Pin_I2C_1			(Pin_I2C__1__PC)
#define Pin_I2C_1_INTR	((uint16)((uint16)0x0001u << Pin_I2C__1__SHIFT))

#define Pin_I2C_INTR_ALL	 ((uint16)(Pin_I2C_0_INTR| Pin_I2C_1_INTR))
#define Pin_I2C_scl			(Pin_I2C__scl__PC)
#define Pin_I2C_scl_INTR	((uint16)((uint16)0x0001u << Pin_I2C__0__SHIFT))

#define Pin_I2C_sda			(Pin_I2C__sda__PC)
#define Pin_I2C_sda_INTR	((uint16)((uint16)0x0001u << Pin_I2C__1__SHIFT))

#endif /* End Pins Pin_I2C_ALIASES_H */


/* [] END OF FILE */
