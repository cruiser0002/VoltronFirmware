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
#include "ShiftBy2_2_ShiftBy2.h" 
#include "ShiftBy2_2_defs.h" 
 
void ShiftBy2_2_SetInput(uint16 val) 
{ 
    /* Datapath_1 is the instance name from the UDB Editor */ 
    CY_SET_REG16(ShiftBy2_2_Datapath_1_A0_PTR,val);  
} 
 
uint16 ShiftBy2_2_GetInput() 
{ 
    return CY_GET_REG16(ShiftBy2_2_Datapath_1_A0_PTR); 
} 
 
uint16 ShiftBy2_2_GetOutput(void) 
{ 
    return CY_GET_REG16(ShiftBy2_2_Datapath_1_A1_PTR); 
} 
