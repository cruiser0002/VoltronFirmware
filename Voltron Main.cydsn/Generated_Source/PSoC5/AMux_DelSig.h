/*******************************************************************************
* File Name: AMux_DelSig.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_AMux_DelSig_H)
#define CY_AMUX_AMux_DelSig_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void AMux_DelSig_Start(void) ;
#define AMux_DelSig_Init() AMux_DelSig_Start()
void AMux_DelSig_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void AMux_DelSig_Stop(void); */
/* void AMux_DelSig_Select(uint8 channel); */
/* void AMux_DelSig_Connect(uint8 channel); */
/* void AMux_DelSig_Disconnect(uint8 channel); */
/* void AMux_DelSig_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define AMux_DelSig_CHANNELS  4u
#define AMux_DelSig_MUXTYPE   2
#define AMux_DelSig_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define AMux_DelSig_NULL_CHANNEL 0xFFu
#define AMux_DelSig_MUX_SINGLE   1
#define AMux_DelSig_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if AMux_DelSig_MUXTYPE == AMux_DelSig_MUX_SINGLE
# if !AMux_DelSig_ATMOSTONE
#  define AMux_DelSig_Connect(channel) AMux_DelSig_Set(channel)
# endif
# define AMux_DelSig_Disconnect(channel) AMux_DelSig_Unset(channel)
#else
# if !AMux_DelSig_ATMOSTONE
void AMux_DelSig_Connect(uint8 channel) ;
# endif
void AMux_DelSig_Disconnect(uint8 channel) ;
#endif

#if AMux_DelSig_ATMOSTONE
# define AMux_DelSig_Stop() AMux_DelSig_DisconnectAll()
# define AMux_DelSig_Select(channel) AMux_DelSig_FastSelect(channel)
void AMux_DelSig_DisconnectAll(void) ;
#else
# define AMux_DelSig_Stop() AMux_DelSig_Start()
void AMux_DelSig_Select(uint8 channel) ;
# define AMux_DelSig_DisconnectAll() AMux_DelSig_Start()
#endif

#endif /* CY_AMUX_AMux_DelSig_H */


/* [] END OF FILE */
