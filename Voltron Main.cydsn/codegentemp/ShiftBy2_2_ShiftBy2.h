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

#if !defined (ShiftBy2_2_SHIFTBY2_H) 
    #define ShiftBy2_2_SHIFTBY2_H 
     
    #include "cytypes.h" 
    
    #define ShiftBy2_2_INPUT_PTR ShiftBy2_2_DP_A0_PTR 
    #define ShiftBy2_2_OUTPUT_PTR ShiftBy2_2_DP_A1_PTR
     
    void ShiftBy2_2_SetInput(uint16); 
    uint16 ShiftBy2_2_GetInput(); 
    uint16 ShiftBy2_2_GetOutput(void); 
 
#endif


