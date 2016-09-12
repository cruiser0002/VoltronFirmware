/* ========================================
 *
 * Jay Lin
 * Copyright ALCH3MY, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF ALCH3MY.
 *
 * ========================================
*/

#include "cytypes.h" 
#include "ShiftBy2_1_ShiftBy2.h" 
#include "ShiftBy2_1_defs.h" 
 
void ShiftBy2_1_SetInput(uint16 val) 
{ 
    /* Datapath_1 is the instance name from the UDB Editor */ 
    CY_SET_REG16(ShiftBy2_1_DP_A0_PTR,val);  
} 
 
uint16 ShiftBy2_1_GetInput() 
{ 
    return CY_GET_REG16(ShiftBy2_1_DP_A0_PTR); 
} 
 
uint16 ShiftBy2_1_GetOutput(void) 
{ 
    return CY_GET_REG16(ShiftBy2_1_DP_A1_PTR); 
} 
