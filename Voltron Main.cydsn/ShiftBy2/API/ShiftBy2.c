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
#include "`$INSTANCE_NAME`_ShiftBy2.h" 
#include "`$INSTANCE_NAME`_defs.h" 
 
void `$INSTANCE_NAME`_SetInput(uint16 val) 
{ 
    /* Datapath_1 is the instance name from the UDB Editor */ 
    CY_SET_REG16(`$INSTANCE_NAME`_Datapath_1_A0_PTR,val);  
} 
 
uint16 `$INSTANCE_NAME`_GetInput() 
{ 
    return CY_GET_REG16(`$INSTANCE_NAME`_Datapath_1_A0_PTR); 
} 
 
uint16 `$INSTANCE_NAME`_GetOutput(void) 
{ 
    return CY_GET_REG16(`$INSTANCE_NAME`_Datapath_1_A1_PTR); 
} 
