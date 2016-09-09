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
#include <project.h>

uint32 buffer[128];
uint32 adcmem[2] = {0,0};
uint8 i2cbuf[4] = {0,0,0,0};

void DMA_RAM2VDAC_Config() {
    /* Defines for DMA_RAM2DAC */
    #define DMA_RAM2DAC_BYTES_PER_BURST 2
    #define DMA_RAM2DAC_REQUEST_PER_BURST 1
    #define DMA_RAM2DAC_SRC_BASE (CYDEV_SRAM_BASE)
    #define DMA_RAM2DAC_DST_BASE (CYDEV_PERIPH_BASE)

    /* Variable declarations for DMA_RAM2DAC */
    /* Move these variable declarations to the top of the function */
    uint8 DMA_RAM2DAC_Chan;
    uint8 DMA_RAM2DAC_TD[2];

    /* DMA Configuration for DMA_RAM2DAC */
    DMA_RAM2DAC_Chan = DMA_RAM2DAC_DmaInitialize(DMA_RAM2DAC_BYTES_PER_BURST, DMA_RAM2DAC_REQUEST_PER_BURST, 
        HI16(DMA_RAM2DAC_SRC_BASE), HI16(DMA_RAM2DAC_DST_BASE));
    DMA_RAM2DAC_TD[0] = CyDmaTdAllocate();
    DMA_RAM2DAC_TD[1] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_RAM2DAC_TD[0], 2, DMA_RAM2DAC_TD[1], TD_AUTO_EXEC_NEXT);
    CyDmaTdSetConfiguration(DMA_RAM2DAC_TD[1], 1, DMA_RAM2DAC_TD[0], DMA_RAM2DAC__TD_TERMOUT_EN);
    CyDmaTdSetAddress(DMA_RAM2DAC_TD[0], LO16((uint32)&buffer[63]), LO16((uint32)VDACH_Data_PTR));
    CyDmaTdSetAddress(DMA_RAM2DAC_TD[1], LO16((uint32)&buffer[63]), LO16((uint32)VDACL_Data_PTR));
    CyDmaChSetInitialTd(DMA_RAM2DAC_Chan, DMA_RAM2DAC_TD[0]);
    CyDmaChEnable(DMA_RAM2DAC_Chan, 1);
}

//void DMA_FILT2RAM_Config() {
//    /* Defines for DMA_FILT2RAM */
//    #define DMA_FILT2RAM_BYTES_PER_BURST 4
//    #define DMA_FILT2RAM_REQUEST_PER_BURST 1
//    #define DMA_FILT2RAM_SRC_BASE (CYDEV_PERIPH_BASE)
//    #define DMA_FILT2RAM_DST_BASE (CYDEV_SRAM_BASE)
//
//    /* Variable declarations for DMA_FILT2RAM */
//    /* Move these variable declarations to the top of the function */
//    uint8 DMA_FILT2RAM_Chan;
//    uint8 DMA_FILT2RAM_TD[1];
//
//    /* DMA Configuration for DMA_FILT2RAM */
//    DMA_FILT2RAM_Chan = DMA_FILT2RAM_DmaInitialize(DMA_FILT2RAM_BYTES_PER_BURST, DMA_FILT2RAM_REQUEST_PER_BURST, 
//        HI16(DMA_FILT2RAM_SRC_BASE), HI16(DMA_FILT2RAM_DST_BASE));
//    DMA_FILT2RAM_TD[0] = CyDmaTdAllocate();
//    CyDmaTdSetConfiguration(DMA_FILT2RAM_TD[0], 256, DMA_FILT2RAM_TD[0], DMA_FILT2RAM__TD_TERMOUT_EN | TD_INC_DST_ADR);
//    CyDmaTdSetAddress(DMA_FILT2RAM_TD[0], LO16((uint32)Filter_HOLDA_PTR), LO16((uint32)buffer));
//    CyDmaChSetInitialTd(DMA_FILT2RAM_Chan, DMA_FILT2RAM_TD[0]);
//    CyDmaChEnable(DMA_FILT2RAM_Chan, 1);
//}

CY_ISR( isr_1_routine ) {
    i2cbuf[0] = 0;
    i2cbuf[1] = buffer[24] >> 16;
    i2cbuf[2] = buffer[24] >> 8;
    i2cbuf[3] = buffer[24];
    VDACH_SetValue(buffer[127] >> 12);
    VDACL_SetValue(buffer[127] >> 4);
    Pin_Status_1_Write(!Pin_Status_1_Read());
    
}

void DMA_ADC2FILT_Config() {
    /* Defines for DMA_ADC2FILT */
    #define DMA_ADC2FILT_BYTES_PER_BURST 2
    #define DMA_ADC2FILT_REQUEST_PER_BURST 1
    #define DMA_ADC2FILT_SRC_BASE (CYDEV_PERIPH_BASE)
    #define DMA_ADC2FILT_DST_BASE (CYDEV_PERIPH_BASE)

    /* Variable declarations for DMA_ADC2FILT */
    /* Move these variable declarations to the top of the function */
    uint8 DMA_ADC2FILT_Chan;
    uint8 DMA_ADC2FILT_TD[1];

    /* DMA Configuration for DMA_ADC2FILT */
    DMA_ADC2FILT_Chan = DMA_ADC2FILT_DmaInitialize(DMA_ADC2FILT_BYTES_PER_BURST, DMA_ADC2FILT_REQUEST_PER_BURST, 
        HI16(DMA_ADC2FILT_SRC_BASE), HI16(DMA_ADC2FILT_DST_BASE));
    DMA_ADC2FILT_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_ADC2FILT_TD[0], 2, DMA_ADC2FILT_TD[0], DMA_ADC2FILT__TD_TERMOUT_EN | TD_INC_SRC_ADR | TD_INC_DST_ADR);
    CyDmaTdSetAddress(DMA_ADC2FILT_TD[0], LO16((uint32)ADC_SAR_1_SAR_WRK0_PTR), LO16((uint32)Filter_STAGEA_PTR));
    CyDmaChSetInitialTd(DMA_ADC2FILT_Chan, DMA_ADC2FILT_TD[0]);
    CyDmaChEnable(DMA_ADC2FILT_Chan, 1);
  
}

void DMA_ADC2RAM_Config() {
    /* Defines for DMA_ADC2RAM */
    #define DMA_ADC2RAM_BYTES_PER_BURST 2
    #define DMA_ADC2RAM_REQUEST_PER_BURST 1
    #define DMA_ADC2RAM_SRC_BASE (CYDEV_PERIPH_BASE)
    #define DMA_ADC2RAM_DST_BASE (CYDEV_SRAM_BASE)

    /* Variable declarations for DMA_ADC2RAM */
    /* Move these variable declarations to the top of the function */
    uint8 DMA_ADC2RAM_Chan;
    uint8 DMA_ADC2RAM_TD[1];

    /* DMA Configuration for DMA_ADC2RAM */
    DMA_ADC2RAM_Chan = DMA_ADC2RAM_DmaInitialize(DMA_ADC2RAM_BYTES_PER_BURST, DMA_ADC2RAM_REQUEST_PER_BURST, 
        HI16(DMA_ADC2RAM_SRC_BASE), HI16(DMA_ADC2RAM_DST_BASE));
    DMA_ADC2RAM_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_ADC2RAM_TD[0], 2, DMA_ADC2RAM_TD[0], DMA_ADC2RAM__TD_TERMOUT_EN | TD_INC_DST_ADR);
    CyDmaTdSetAddress(DMA_ADC2RAM_TD[0], LO16((uint32)ADC_SAR_1_SAR_WRK0_PTR), LO16((uint32)adcmem));
    CyDmaChSetInitialTd(DMA_ADC2RAM_Chan, DMA_ADC2RAM_TD[0]);
    CyDmaChEnable(DMA_ADC2RAM_Chan, 1);

}

void DMA_RAM2FILT_Config() {
    /* Defines for DMA_RAM2FILT */
    #define DMA_RAM2FILT_BYTES_PER_BURST 2
    #define DMA_RAM2FILT_REQUEST_PER_BURST 1
    #define DMA_RAM2FILT_SRC_BASE (CYDEV_SRAM_BASE)
    #define DMA_RAM2FILT_DST_BASE (CYDEV_PERIPH_BASE)

    /* Variable declarations for DMA_RAM2FILT */
    /* Move these variable declarations to the top of the function */
    uint8 DMA_RAM2FILT_Chan;
    uint8 DMA_RAM2FILT_TD[1];

    /* DMA Configuration for DMA_RAM2FILT */
    DMA_RAM2FILT_Chan = DMA_RAM2FILT_DmaInitialize(DMA_RAM2FILT_BYTES_PER_BURST, DMA_RAM2FILT_REQUEST_PER_BURST, 
        HI16(DMA_RAM2FILT_SRC_BASE), HI16(DMA_RAM2FILT_DST_BASE));
    DMA_RAM2FILT_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_RAM2FILT_TD[0], 2, DMA_RAM2FILT_TD[0], DMA_RAM2FILT__TD_TERMOUT_EN | TD_INC_SRC_ADR | TD_INC_DST_ADR);
    CyDmaTdSetAddress(DMA_RAM2FILT_TD[0], LO16((uint32)adcmem) + 4, LO16((uint32)Filter_STAGEA_PTR));
    CyDmaChSetInitialTd(DMA_RAM2FILT_Chan, DMA_RAM2FILT_TD[0]);
    CyDmaChEnable(DMA_RAM2FILT_Chan, 1);


}

int main() {
    CyGlobalIntEnable; /* Enable global interrupts. */

    I2C_Start();
    //TIA_1_Start();
    //TIA_2_Start();
    
    ADC_SAR_1_Start();
    ADC_SAR_1_StartConvert();
    
    Filter_Start();
    Filter_SetDalign(Filter_STAGEA_DALIGN, Filter_ENABLED);
    //Filter_SetDalign(Filter_HOLDA_DALIGN, Filter_ENABLED);
    //Filter_SetCoherency(Filter_CHANNEL_A, Filter_KEY_MID);
    Filter_SetCoherencyEx(Filter_STAGEA_COHER, Filter_KEY_MID);
    Filter_SetCoherencyEx(Filter_HOLDA_COHER, Filter_KEY_HIGH);
    
    //IDACH_Start();
    //IDACL_Start();
    
    VDACH_Start();
    VDACL_Start();
    
    
    DMA_ADC2FILT_Config();
//    DMA_ADC2RAM_Config();
//    DMA_RAM2FILT_Config();
    
    DMA_FILT2RAM_Config();
    ISR_DMA_FILT2RAM_StartEx(isr_1_routine);
    
    //DMA_RAM2VDAC_Config();
    
    
    i2cbuf[0] = 0;
    i2cbuf[1] = 0;
    i2cbuf[2] = 0;
    i2cbuf[3] = 0;
    
    I2C_SetBuffer1(4, 4, i2cbuf);
    
    int adcvalue = 0;
    long filtervalue = 0;
    
    for(;;)
    {
        if(ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT)){
//            adcvalue = ADC_SAR_1_GetResult16();
//            i2cbuf[0] = adcvalue >> 8;
//            i2cbuf[1] = adcvalue;
//            i2cbuf[2] = 0;
//            i2cbuf[3] = 0;
//            Filter_Write16(Filter_CHANNEL_A, adcvalue << 4);
//            filtervalue = Filter_Read24(Filter_CHANNEL_A);
//            i2cbuf[0] = filtervalue >> 24;
//            i2cbuf[1] = filtervalue >> 16;
//            i2cbuf[2] = filtervalue >> 8;
//            i2cbuf[3] = filtervalue;
            
//            i2cbuf[0] = buffer[0] >> 24;
//            i2cbuf[1] = buffer[0] >> 16;
//            i2cbuf[2] = buffer[0] >> 8;
//            i2cbuf[3] = buffer[0];
        }
//        filtervalue = Filter_Read24(Filter_CHANNEL_A);
        
//        filtervalue = buffer[0];
//        i2cbuf[0] = filtervalue >> 24;
//        i2cbuf[1] = filtervalue >> 16;
//        i2cbuf[2] = filtervalue >> 8;
//        i2cbuf[3] = filtervalue;
        
//        VDACH_SetValue(filtervalue >> 8);
//        VDACL_SetValue(filtervalue);
//        
//        CyDelay(1);
//        adcvalue = adcmem[0];
//        i2cbuf[0] = 0;
//        i2cbuf[1] = 0;
//        i2cbuf[2] = adcvalue >> 8;
//        i2cbuf[3] = adcvalue;
        
//        VDACH_SetValue(adcvalue >> 8);
//        VDACL_SetValue(adcvalue);
//        CyDelay(1);
        
    }
}


