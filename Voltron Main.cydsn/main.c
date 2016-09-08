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
#include <project.h>
#include <math.h>

//I2C
uint8 i2cbuf[4] = {0,0,0,0};


//DMA variables
uint32 sarmem1[1] = {0};
uint32 sarmem2[1] = {0};
uint8 RAM2FILTER1_Chan;

void start_resources()
{
    I2C_Start();
    
    I2C_SetBuffer1(4, 4, i2cbuf);
    
    PWM1_Start();
    PWM2_Start();
    
    VDAC1_Start();
    VDAC2_Start();
    VDAC3_Start();
    VDAC4_Start();
    VDAC1_SetValue(127);
    VDAC2_SetValue(127);
    VDAC3_SetValue(127);
    VDAC4_SetValue(127);
    
    SAR1_Start();
    SAR2_Start();
    SAR1_StartConvert();
    SAR2_StartConvert();
    
    Filter_Start();
    //Filter_SetDalign(Filter_STAGEA_DALIGN, Filter_ENABLED);
    //Filter_SetDalign(Filter_HOLDA_DALIGN, Filter_ENABLED);
    //Filter_SetDalign(Filter_STAGEA_DALIGN, Filter_ENABLED);
    //Filter_SetCoherency(Filter_CHANNEL_A, Filter_KEY_MID);
    
    
}

CY_ISR(shift_sar1_handler) 
{
    //sarmem1[0] = sarmem1[0] << 16;
    Filter_Write16(Filter_CHANNEL_A, sarmem1[0]);
    //CyDmaChSetRequest(RAM2FILTER1_Chan, CPU_REQ);
}

CY_ISR(shift_sar2_handler) 
{
    //sarmem2[0] = sarmem2[0] << 0;
    Filter_Write16(Filter_CHANNEL_B, sarmem2[0]);
}

void start_interrupts()
{
    isr_shift_sar1_StartEx(shift_sar1_handler);
    isr_shift_sar2_StartEx(shift_sar2_handler);
}

void DMA_SAR2RAM1_config()
{
    /* Defines for SAR2RAM1 */
    #define SAR2RAM1_BYTES_PER_BURST 2
    #define SAR2RAM1_REQUEST_PER_BURST 1
    #define SAR2RAM1_SRC_BASE (CYDEV_PERIPH_BASE)
    #define SAR2RAM1_DST_BASE (CYDEV_SRAM_BASE)

    /* Variable declarations for SAR2RAM1 */
    /* Move these variable declarations to the top of the function */
    uint8 SAR2RAM1_Chan;
    uint8 SAR2RAM1_TD[1];

    /* DMA Configuration for SAR2RAM1 */
    SAR2RAM1_Chan = SAR2RAM1_DmaInitialize(SAR2RAM1_BYTES_PER_BURST, SAR2RAM1_REQUEST_PER_BURST, 
        HI16(SAR2RAM1_SRC_BASE), HI16(SAR2RAM1_DST_BASE));
    SAR2RAM1_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(SAR2RAM1_TD[0], 2, SAR2RAM1_TD[0], SAR2RAM1__TD_TERMOUT_EN);
    CyDmaTdSetAddress(SAR2RAM1_TD[0], LO16((uint32)SAR1_SAR_WRK0_PTR), LO16((uint32)sarmem1));
    CyDmaChSetInitialTd(SAR2RAM1_Chan, SAR2RAM1_TD[0]);
    CyDmaChEnable(SAR2RAM1_Chan, 1);

}

void DMA_SAR2RAM2_config()
{
    /* Defines for SAR2RAM2 */
    #define SAR2RAM2_BYTES_PER_BURST 2
    #define SAR2RAM2_REQUEST_PER_BURST 1
    #define SAR2RAM2_SRC_BASE (CYDEV_PERIPH_BASE)
    #define SAR2RAM2_DST_BASE (CYDEV_SRAM_BASE)

    /* Variable declarations for SAR2RAM2 */
    /* Move these variable declarations to the top of the function */
    uint8 SAR2RAM2_Chan;
    uint8 SAR2RAM2_TD[1];

    /* DMA Configuration for SAR2RAM2 */
    SAR2RAM2_Chan = SAR2RAM2_DmaInitialize(SAR2RAM2_BYTES_PER_BURST, SAR2RAM2_REQUEST_PER_BURST, 
        HI16(SAR2RAM2_SRC_BASE), HI16(SAR2RAM2_DST_BASE));
    SAR2RAM2_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(SAR2RAM2_TD[0], 2, SAR2RAM2_TD[0], SAR2RAM2__TD_TERMOUT_EN);
    CyDmaTdSetAddress(SAR2RAM2_TD[0], LO16((uint32)SAR2_SAR_WRK0_PTR), LO16((uint32)sarmem2));
    CyDmaChSetInitialTd(SAR2RAM2_Chan, SAR2RAM2_TD[0]);
    CyDmaChEnable(SAR2RAM2_Chan, 1);

}

void DMA_SAR2FILTER1_config()
{
    /* Defines for SAR2FILTER1 */
    #define SAR2FILTER1_BYTES_PER_BURST 2
    #define SAR2FILTER1_REQUEST_PER_BURST 1
    #define SAR2FILTER1_SRC_BASE (CYDEV_PERIPH_BASE)
    #define SAR2FILTER1_DST_BASE (CYDEV_PERIPH_BASE)

    /* Variable declarations for SAR2FILTER1 */
    /* Move these variable declarations to the top of the function */
    uint8 SAR2FILTER1_Chan;
    uint8 SAR2FILTER1_TD[1];

    /* DMA Configuration for SAR2FILTER1 */
    SAR2FILTER1_Chan = SAR2FILTER1_DmaInitialize(SAR2FILTER1_BYTES_PER_BURST, SAR2FILTER1_REQUEST_PER_BURST, 
        HI16(SAR2FILTER1_SRC_BASE), HI16(SAR2FILTER1_DST_BASE));
    SAR2FILTER1_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(SAR2FILTER1_TD[0], 2, SAR2FILTER1_TD[0], SAR2FILTER1__TD_TERMOUT_EN); // | TD_INC_SRC_ADR | TD_INC_DST_ADR
    CyDmaTdSetAddress(SAR2FILTER1_TD[0], LO16((uint32)SAR1_SAR_WRK0_PTR), LO16((uint32)Filter_STAGEA_PTR));
    CyDmaChSetInitialTd(SAR2FILTER1_Chan, SAR2FILTER1_TD[0]);
    CyDmaChEnable(SAR2FILTER1_Chan, 1);

}


void DMA_SAR2FILTER2_config()
{


}

void DMA_RAM2FILTER1_config()
{ 
    /* Defines for RAM2FILTER1 */
    #define RAM2FILTER1_BYTES_PER_BURST 2
    #define RAM2FILTER1_REQUEST_PER_BURST 1
    #define RAM2FILTER1_SRC_BASE (CYDEV_SRAM_BASE)
    #define RAM2FILTER1_DST_BASE (CYDEV_PERIPH_BASE)

    /* Variable declarations for RAM2FILTER1 */
    /* Move these variable declarations to the top of the function */
    //uint8 RAM2FILTER1_Chan;
    uint8 RAM2FILTER1_TD[1];

    /* DMA Configuration for RAM2FILTER1 */
    RAM2FILTER1_Chan = RAM2FILTER1_DmaInitialize(RAM2FILTER1_BYTES_PER_BURST, RAM2FILTER1_REQUEST_PER_BURST, 
        HI16(RAM2FILTER1_SRC_BASE), HI16(RAM2FILTER1_DST_BASE));
    RAM2FILTER1_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(RAM2FILTER1_TD[0], 2, RAM2FILTER1_TD[0], RAM2FILTER1__TD_TERMOUT_EN | TD_INC_SRC_ADR | TD_INC_DST_ADR);
    CyDmaTdSetAddress(RAM2FILTER1_TD[0], LO16((uint32)sarmem1), LO16((uint32)Filter_STAGEA_PTR));
    CyDmaChSetInitialTd(RAM2FILTER1_Chan, RAM2FILTER1_TD[0]);
    CyDmaChEnable(RAM2FILTER1_Chan, 1);

}

void start_DMAs()
{
    DMA_SAR2RAM1_config();
    DMA_SAR2RAM2_config();
    //DMA_RAM2FILTER1_config();
    //DMA_SAR2FILTER1_config();
    //DMA_SAR2FILTER2_config();
}


int main()
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    start_resources();
    start_DMAs();
    start_interrupts();
    
    int sarvalue1 = 0;
    int sarvalue2 = 0;

    long filtervalue1 = 0;
    long filtervalue2 = 0;
    
    for(;;)
    {
//        if(SAR1_IsEndConversion(SAR1_WAIT_FOR_RESULT))
//        {
//            sarmem1[0] = SAR1_GetResult16();
//            sarmem1[0] = sarmem1[0] << 0;
//            
//            Filter_Write16(Filter_CHANNEL_A, sarmem1[0]);
//        }
//        
//        if(SAR2_IsEndConversion(SAR2_WAIT_FOR_RESULT))
//        {
//            sarmem2[0] = SAR2_GetResult16();
//            sarmem2[0] = sarmem2[0] << 0;
//            
//            Filter_Write16(Filter_CHANNEL_B, sarmem2[0]);
//        }
        
        
        
        filtervalue1 = Filter_Read16(Filter_CHANNEL_A);
        filtervalue2 = Filter_Read16(Filter_CHANNEL_B);
        
//        i2cbuf[0] = filtervalue1 >> 16;
//        i2cbuf[1] = filtervalue1 >> 8;
//        i2cbuf[2] = filtervalue1;
//        i2cbuf[3] = filtervalue1;
        
        
        i2cbuf[0] = sarmem1[0] >> 8;
        i2cbuf[1] = sarmem1[0];
        i2cbuf[2] = sarmem2[0] >> 8;
        i2cbuf[3] = sarmem2[0];
        
        CyDelay(1);
    }
}

