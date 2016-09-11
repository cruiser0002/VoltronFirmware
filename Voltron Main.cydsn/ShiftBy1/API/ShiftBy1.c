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
#include "`$INSTANCE_NAME`_ShiftBy1.h" 
#include "`$INSTANCE_NAME`_defs.h" 
 
void `$INSTANCE_NAME`_SetInput(uint8 val) 
{ 
    /* Datapath_1 is the instance name from the UDB Editor */ 
    CY_SET_REG8(`$INSTANCE_NAME`_Datapath_1_A0_PTR,val);  
} 
 
uint8 `$INSTANCE_NAME`_GetInput() 
{ 
    return CY_GET_REG8(`$INSTANCE_NAME`_Datapath_1_A0_PTR); 
} 
 
uint8 `$INSTANCE_NAME`_GetOutput(void) 
{ 
    return CY_GET_REG8(`$INSTANCE_NAME`_Datapath_1_A1_PTR); 
} 
