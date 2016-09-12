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

#if !defined (`$INSTANCE_NAME`_SHIFTBY2_H) 
    #define `$INSTANCE_NAME`_SHIFTBY2_H 
     
    #include "cytypes.h" 
    
    #define `$INSTANCE_NAME`_INPUT_PTR `$INSTANCE_NAME`_DP_A0_PTR 
    #define `$INSTANCE_NAME`_OUTPUT_PTR `$INSTANCE_NAME`_DP_A1_PTR
     
    void `$INSTANCE_NAME`_SetInput(uint16); 
    uint16 `$INSTANCE_NAME`_GetInput(); 
    uint16 `$INSTANCE_NAME`_GetOutput(void); 
 
#endif


