/*******************************************************************************
* File Name: ShiftBy2_1_defs.h
* 
* PSoC Creator  3.3 CP3
*
* Description:
* It contains defines for UDB editor content and should not be modified.
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2016 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_SHIFTBY2_1_DEFS_H
#define INCLUDED_SHIFTBY2_1_DEFS_H
#include "cydevice.h"
#include "cydevice_trm.h"
#include "cytypes.h"
#include "cyfitter.h"

/* Note: Register pointers (denoted by a _PTR suffix) should be accessed
 * via the CY_GET_REGn and CY_SET_REGn macros (defined in cytypes.h),
 * where n is the width of the datapath with which they are associated.
 */

/******************** DP (Width: 16) Definitions ********************/

#if(CY_PSOC3) /* 8-bit address space */

    #define ShiftBy2_1_DP_A0_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__A0_REG)
    #define ShiftBy2_1_DP_A1_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__A1_REG)
    #define ShiftBy2_1_DP_D0_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__D0_REG)
    #define ShiftBy2_1_DP_D1_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__D1_REG)
    #define ShiftBy2_1_DP_F0_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__F0_REG)
    #define ShiftBy2_1_DP_F1_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__F1_REG)
    
    /* Note: To avoid corruption of a shared register, call the following registers from within
     * a critical section (See Component Author Guide for details).
     */
    
    /* Macros to clear DP FIFOs.*/
    #define ShiftBy2_1_DP_F0_CLEAR do { \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0x0101u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)));\
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0xfefeu & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)));\
        } while(0)
    #define ShiftBy2_1_DP_F1_CLEAR do { \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0x0202u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)));\
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0xfdfdu & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)));\
        } while(0)
    
    /* Macros to set FIFO level mode. See the TRM for details */
    #define ShiftBy2_1_DP_F0_SET_LEVEL_NORMAL \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0xfbfbu & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)))
    #define ShiftBy2_1_DP_F1_SET_LEVEL_NORMAL \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0xf7f7u & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)))
    #define ShiftBy2_1_DP_F0_SET_LEVEL_MID \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0x0404u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)))
    #define ShiftBy2_1_DP_F1_SET_LEVEL_MID \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0x0808u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)))
    
    /* Macros to set FIFO to single-buffer mode. */
    #define ShiftBy2_1_DP_F0_SINGLE_BUFFER_SET \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0x0101u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)))
    #define ShiftBy2_1_DP_F1_SINGLE_BUFFER_SET \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0x0202u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)))
    
    /* Macros to return the FIFO to normal mode. */
    #define ShiftBy2_1_DP_F0_SINGLE_BUFFER_UNSET \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0xfefeu & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)))
    #define ShiftBy2_1_DP_F1_SINGLE_BUFFER_UNSET \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG), 0xfdfdu & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__DP_AUX_CTL_REG)))
    
    /* End macros which should be called from within a critical section */
    
#else /* 16-bit address space */

    #define ShiftBy2_1_DP_A0_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__16BIT_A0_REG)
    #define ShiftBy2_1_DP_A1_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__16BIT_A1_REG)
    #define ShiftBy2_1_DP_D0_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__16BIT_D0_REG)
    #define ShiftBy2_1_DP_D1_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__16BIT_D1_REG)
    #define ShiftBy2_1_DP_F0_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__16BIT_F0_REG)
    #define ShiftBy2_1_DP_F1_PTR 	 ((reg16 *) ShiftBy2_1_DP_u0__16BIT_F1_REG)
    
    /* Note: To avoid corruption of a shared register, call the following registers from within
     * a critical section (See Component Author Guide for details).
     */
    
    /* Macros to clear DP FIFOs.*/
    #define ShiftBy2_1_DP_F0_CLEAR do { \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0x0101u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)));\
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0xfefeu & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)));\
        } while(0)
    #define ShiftBy2_1_DP_F1_CLEAR do { \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0x0202u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)));\
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0xfdfdu & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)));\
        } while(0)
    
    /* Macros to set FIFO level mode. See the TRM for details */
    #define ShiftBy2_1_DP_F0_SET_LEVEL_NORMAL \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0xfbfbu & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)))
    #define ShiftBy2_1_DP_F1_SET_LEVEL_NORMAL \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0xf7f7u & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)))
    #define ShiftBy2_1_DP_F0_SET_LEVEL_MID \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0x0404u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)))
    #define ShiftBy2_1_DP_F1_SET_LEVEL_MID \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0x0808u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)))
    
    /* Macros to set FIFO to single-buffer mode. */
    #define ShiftBy2_1_DP_F0_SINGLE_BUFFER_SET \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0x0101u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)))
    #define ShiftBy2_1_DP_F1_SINGLE_BUFFER_SET \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0x0202u | \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)))
    
    /* Macros to return the FIFO to normal mode. */
    #define ShiftBy2_1_DP_F0_SINGLE_BUFFER_UNSET \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0xfefeu & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)))
    #define ShiftBy2_1_DP_F1_SINGLE_BUFFER_UNSET \
        CY_SET_XTND_REG16(\
            ((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG), 0xfdfdu & \
            CY_GET_XTND_REG16(((reg16 *) ShiftBy2_1_DP_u0__16BIT_DP_AUX_CTL_REG)))
    
    /* End macros which should be called from within a critical section */
    
#endif

#endif /* INCLUDED_SHIFTBY2_1_DEFS_H */
