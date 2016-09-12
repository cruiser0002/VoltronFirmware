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

#if !defined (ShiftBy2_1_SHIFTBY2_H) 
    #define ShiftBy2_1_SHIFTBY2_H 
     
    #include "cytypes.h" 
    
    #define ShiftBy2_1_INPUT_PTR ShiftBy2_1_DP_A0_PTR 
    #define ShiftBy2_1_OUTPUT_PTR ShiftBy2_1_DP_A1_PTR
     
    void ShiftBy2_1_SetInput(uint16); 
    uint16 ShiftBy2_1_GetInput(); 
    uint16 ShiftBy2_1_GetOutput(void); 
 
#endif


