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

#if !defined (ShiftBy1_1_SHIFTBY1_H) 
    #define ShiftBy1_1_SHIFTBY1_H 
     
    #include "cytypes.h" 
    
    #define ShiftBy1_1_INPUT_PTR ((reg16 *) ShiftBy1_1_Datapath_1_u0__16BIT_A0_REG) 
    #define ShiftBy1_1_OUTPUT_PTR ((reg16 *) ShiftBy1_1_Datapath_1_u0__16BIT_A1_REG) 

    void ShiftBy1_1_SetInput(uint8); 
    uint8 ShiftBy1_1_GetInput(); 
    uint8 ShiftBy1_1_GetOutput(void); 
 
#endif 

//#define ShiftBy1_1_Datapath_1_u0__16BIT_A0_REG CYREG_B0_UDB11_12_A0
//#define ShiftBy1_1_Datapath_1_u0__16BIT_A1_REG CYREG_B0_UDB11_12_A1
//#define ShiftBy1_1_Datapath_1_u0__16BIT_D0_REG CYREG_B0_UDB11_12_D0
//#define ShiftBy1_1_Datapath_1_u0__16BIT_D1_REG CYREG_B0_UDB11_12_D1
//#define ShiftBy1_1_Datapath_1_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
//#define ShiftBy1_1_Datapath_1_u0__16BIT_F0_REG CYREG_B0_UDB11_12_F0
//#define ShiftBy1_1_Datapath_1_u0__16BIT_F1_REG CYREG_B0_UDB11_12_F1
//#define ShiftBy1_1_Datapath_1_u0__A0_A1_REG CYREG_B0_UDB11_A0_A1
//#define ShiftBy1_1_Datapath_1_u0__A0_REG CYREG_B0_UDB11_A0
//#define ShiftBy1_1_Datapath_1_u0__A1_REG CYREG_B0_UDB11_A1
//#define ShiftBy1_1_Datapath_1_u0__D0_D1_REG CYREG_B0_UDB11_D0_D1
//#define ShiftBy1_1_Datapath_1_u0__D0_REG CYREG_B0_UDB11_D0
//#define ShiftBy1_1_Datapath_1_u0__D1_REG CYREG_B0_UDB11_D1
//#define ShiftBy1_1_Datapath_1_u0__DP_AUX_CTL_REG CYREG_B0_UDB11_ACTL
//#define ShiftBy1_1_Datapath_1_u0__F0_F1_REG CYREG_B0_UDB11_F0_F1
//#define ShiftBy1_1_Datapath_1_u0__F0_REG CYREG_B0_UDB11_F0
//#define ShiftBy1_1_Datapath_1_u0__F1_REG CYREG_B0_UDB11_F1