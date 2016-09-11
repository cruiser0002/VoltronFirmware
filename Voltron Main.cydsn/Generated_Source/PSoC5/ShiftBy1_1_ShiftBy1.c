/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "cytypes.h" 
#include "ShiftBy1_1_ShiftBy1.h" 
#include "ShiftBy1_1_defs.h" 
 
void ShiftBy1_1_SetInput(uint8 val) 
{ 
    /* Datapath_1 is the instance name from the UDB Editor */ 
    CY_SET_REG8(ShiftBy1_1_Datapath_1_A0_PTR,val);  
} 
 
uint8 ShiftBy1_1_GetInput() 
{ 
    return CY_GET_REG8(ShiftBy1_1_Datapath_1_A0_PTR); 
} 
 
uint8 ShiftBy1_1_GetOutput(void) 
{ 
    return CY_GET_REG8(ShiftBy1_1_Datapath_1_A1_PTR); 
} 
