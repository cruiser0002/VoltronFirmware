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


#include <resources.h>

uint8 i2cbuf[4];

//SPI
uint32 spimem[1];

//SAR variables
uint32 sarmem1[1];
uint32 sarmem2[1];

//4^N samples for decimation
uint16 filtermem1[DECIMATION];
uint16 filtermem2[DECIMATION];


void start_resources()
{
    I2C_Start();
    I2C_SetBuffer1(4, 4, i2cbuf);
    
    PWM1_Start();
    PWM2_Start();
    
    PWM1_WriteCompare(35);
    PWM2_WriteCompare(35);
    
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
    Filter_SetDalign(Filter_STAGEA_DALIGN, Filter_ENABLED);
    Filter_SetDalign(Filter_HOLDA_DALIGN, Filter_ENABLED);
    Filter_SetCoherency(Filter_CHANNEL_A, Filter_KEY_MID);
    
    Filter_SetDalign(Filter_STAGEB_DALIGN, Filter_ENABLED);
    Filter_SetDalign(Filter_HOLDB_DALIGN, Filter_ENABLED);
    Filter_SetCoherency(Filter_CHANNEL_B, Filter_KEY_MID);
    
    SPIS_Start();
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
    /* Defines for SAR2FILTER2 */
    #define SAR2FILTER2_BYTES_PER_BURST 2
    #define SAR2FILTER2_REQUEST_PER_BURST 1
    #define SAR2FILTER2_SRC_BASE (CYDEV_PERIPH_BASE)
    #define SAR2FILTER2_DST_BASE (CYDEV_PERIPH_BASE)

    /* Variable declarations for SAR2FILTER1 */
    /* Move these variable declarations to the top of the function */
    uint8 SAR2FILTER2_Chan;
    uint8 SAR2FILTER2_TD[1];

    /* DMA Configuration for SAR2FILTER1 */
    SAR2FILTER2_Chan = SAR2FILTER2_DmaInitialize(SAR2FILTER2_BYTES_PER_BURST, SAR2FILTER2_REQUEST_PER_BURST, 
        HI16(SAR2FILTER2_SRC_BASE), HI16(SAR2FILTER2_DST_BASE));
    SAR2FILTER2_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(SAR2FILTER2_TD[0], 2, SAR2FILTER2_TD[0], SAR2FILTER2__TD_TERMOUT_EN); // | TD_INC_SRC_ADR | TD_INC_DST_ADR
    CyDmaTdSetAddress(SAR2FILTER2_TD[0], LO16((uint32)SAR2_SAR_WRK0_PTR), LO16((uint32)Filter_STAGEB_PTR));
    CyDmaChSetInitialTd(SAR2FILTER2_Chan, SAR2FILTER2_TD[0]);
    CyDmaChEnable(SAR2FILTER2_Chan, 1);
}

void DMA_FILTER2RAM1_config()
{
    /* Defines for FILTER2RAM1 */
    #define FILTER2RAM1_BYTES_PER_BURST 2
    #define FILTER2RAM1_REQUEST_PER_BURST 1
    #define FILTER2RAM1_SRC_BASE (CYDEV_PERIPH_BASE)
    #define FILTER2RAM1_DST_BASE (CYDEV_SRAM_BASE)

    /* Variable declarations for FILTER2RAM1 */
    /* Move these variable declarations to the top of the function */
    uint8 FILTER2RAM1_Chan;
    uint8 FILTER2RAM1_TD[1];

    /* DMA Configuration for FILTER2RAM1 */
    FILTER2RAM1_Chan = FILTER2RAM1_DmaInitialize(FILTER2RAM1_BYTES_PER_BURST, FILTER2RAM1_REQUEST_PER_BURST, 
        HI16(FILTER2RAM1_SRC_BASE), HI16(FILTER2RAM1_DST_BASE));
    FILTER2RAM1_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(FILTER2RAM1_TD[0], DECIMATION*2, FILTER2RAM1_TD[0], FILTER2RAM1__TD_TERMOUT_EN | TD_INC_DST_ADR);
    CyDmaTdSetAddress(FILTER2RAM1_TD[0], LO16((uint32)Filter_HOLDA_PTR), LO16((uint32)filtermem1));
    CyDmaChSetInitialTd(FILTER2RAM1_Chan, FILTER2RAM1_TD[0]);
    CyDmaChEnable(FILTER2RAM1_Chan, 1);
}

void DMA_FILTER2RAM2_config()
{
    /* Defines for FILTER2RAM2 */
    #define FILTER2RAM2_BYTES_PER_BURST 2
    #define FILTER2RAM2_REQUEST_PER_BURST 1
    #define FILTER2RAM2_SRC_BASE (CYDEV_PERIPH_BASE)
    #define FILTER2RAM2_DST_BASE (CYDEV_SRAM_BASE)

    /* Variable declarations for FILTER2RAM1 */
    /* Move these variable declarations to the top of the function */
    uint8 FILTER2RAM2_Chan;
    uint8 FILTER2RAM2_TD[1];

    /* DMA Configuration for FILTER2RAM1 */
    FILTER2RAM2_Chan = FILTER2RAM2_DmaInitialize(FILTER2RAM2_BYTES_PER_BURST, FILTER2RAM2_REQUEST_PER_BURST, 
        HI16(FILTER2RAM2_SRC_BASE), HI16(FILTER2RAM2_DST_BASE));
    FILTER2RAM2_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(FILTER2RAM2_TD[0], DECIMATION*2, FILTER2RAM2_TD[0], FILTER2RAM2__TD_TERMOUT_EN | TD_INC_DST_ADR);
    CyDmaTdSetAddress(FILTER2RAM2_TD[0], LO16((uint32)Filter_HOLDB_PTR), LO16((uint32)filtermem2));
    CyDmaChSetInitialTd(FILTER2RAM2_Chan, FILTER2RAM2_TD[0]);
    CyDmaChEnable(FILTER2RAM2_Chan, 1);
}

void DMA_SPI2RAM_config()
{
    /* Defines for SPI2RAM */
    #define SPI2RAM_BYTES_PER_BURST 1
    #define SPI2RAM_REQUEST_PER_BURST 1
    #define SPI2RAM_SRC_BASE (CYDEV_PERIPH_BASE)
    #define SPI2RAM_DST_BASE (CYDEV_SRAM_BASE)
    
    uint8 SPI2RAM_Chan;
    uint8 SPI2RAM_TD[1];
    
    SPI2RAM_Chan = SPI2RAM_DmaInitialize(SPI2RAM_BYTES_PER_BURST, SPI2RAM_REQUEST_PER_BURST,
        HI16(SPI2RAM_SRC_BASE), HI16(SPI2RAM_DST_BASE));

    SPI2RAM_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(SPI2RAM_TD[0], 1, SPI2RAM_TD[0], SPI2RAM__TD_TERMOUT_EN);
    CyDmaTdSetAddress(SPI2RAM_TD[0], LO16((uint32)SPIS_RXDATA_PTR), LO16((uint32)spimem));
    CyDmaChSetInitialTd(SPI2RAM_Chan, SPI2RAM_TD[0]);
    CyDmaChEnable(SPI2RAM_Chan, 1);
}

void DMA_SAR2SHIFT1_config()
{
    /* Defines for SAR2SHIFT1 */
    #define SAR2SHIFT1_BYTES_PER_BURST 2
    #define SAR2SHIFT1_REQUEST_PER_BURST 1
    #define SAR2SHIFT1_SRC_BASE (CYDEV_PERIPH_BASE)
    #define SAR2SHIFT1_DST_BASE (CYDEV_PERIPH_BASE)

    /* Variable declarations for SAR2SHIFT1 */
    /* Move these variable declarations to the top of the function */
    uint8 SAR2SHIFT1_Chan;
    uint8 SAR2SHIFT1_TD[1];

    /* DMA Configuration for SAR2SHIFT1 */
    SAR2SHIFT1_Chan = SAR2SHIFT1_DmaInitialize(SAR2SHIFT1_BYTES_PER_BURST, SAR2SHIFT1_REQUEST_PER_BURST, 
        HI16(SAR2SHIFT1_SRC_BASE), HI16(SAR2SHIFT1_DST_BASE));
    SAR2SHIFT1_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(SAR2SHIFT1_TD[0], 2, SAR2SHIFT1_TD[0], SAR2SHIFT1__TD_TERMOUT_EN);
    CyDmaTdSetAddress(SAR2SHIFT1_TD[0], LO16((uint32)SAR1_SAR_WRK0_PTR), LO16((uint32)ShiftBy2_1_INPUT_PTR));
    CyDmaChSetInitialTd(SAR2SHIFT1_Chan, SAR2SHIFT1_TD[0]);
    CyDmaChEnable(SAR2SHIFT1_Chan, 1);
}

void DMA_SAR2SHIFT2_config()
{
    /* Defines for SAR2SHIFT2 */
    #define SAR2SHIFT2_BYTES_PER_BURST 2
    #define SAR2SHIFT2_REQUEST_PER_BURST 1
    #define SAR2SHIFT2_SRC_BASE (CYDEV_PERIPH_BASE)
    #define SAR2SHIFT2_DST_BASE (CYDEV_PERIPH_BASE)

    /* Variable declarations for SAR2SHIFT2 */
    /* Move these variable declarations to the top of the function */
    uint8 SAR2SHIFT2_Chan;
    uint8 SAR2SHIFT2_TD[1];

    /* DMA Configuration for SAR2SHIFT2 */
    SAR2SHIFT2_Chan = SAR2SHIFT2_DmaInitialize(SAR2SHIFT2_BYTES_PER_BURST, SAR2SHIFT2_REQUEST_PER_BURST, 
        HI16(SAR2SHIFT2_SRC_BASE), HI16(SAR2SHIFT2_DST_BASE));
    SAR2SHIFT2_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(SAR2SHIFT2_TD[0], 2, SAR2SHIFT2_TD[0], SAR2SHIFT2__TD_TERMOUT_EN);
    CyDmaTdSetAddress(SAR2SHIFT2_TD[0], LO16((uint32)SAR2_SAR_WRK0_PTR), LO16((uint32)ShiftBy2_2_INPUT_PTR));
    CyDmaChSetInitialTd(SAR2SHIFT2_Chan, SAR2SHIFT2_TD[0]);
    CyDmaChEnable(SAR2SHIFT2_Chan, 1);
}

void DMA_SHIFT2FILTER1_config()
{
    /* Defines for SHIFT2FILTER1 */
    #define SHIFT2FILTER1_BYTES_PER_BURST 2
    #define SHIFT2FILTER1_REQUEST_PER_BURST 1
    #define SHIFT2FILTER1_SRC_BASE (CYDEV_PERIPH_BASE)
    #define SHIFT2FILTER1_DST_BASE (CYDEV_PERIPH_BASE)

    /* Variable declarations for SHIFT2FILTER1 */
    /* Move these variable declarations to the top of the function */
    uint8 SHIFT2FILTER1_Chan;
    uint8 SHIFT2FILTER1_TD[1];

    /* DMA Configuration for SHIFT2FILTER1 */
    SHIFT2FILTER1_Chan = SHIFT2FILTER1_DmaInitialize(SHIFT2FILTER1_BYTES_PER_BURST, SHIFT2FILTER1_REQUEST_PER_BURST, 
        HI16(SHIFT2FILTER1_SRC_BASE), HI16(SHIFT2FILTER1_DST_BASE));
    SHIFT2FILTER1_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(SHIFT2FILTER1_TD[0], 2, SHIFT2FILTER1_TD[0], SHIFT2FILTER1__TD_TERMOUT_EN);
    CyDmaTdSetAddress(SHIFT2FILTER1_TD[0], LO16((uint32)ShiftBy2_1_OUTPUT_PTR), LO16((uint32)Filter_STAGEA_PTR));
    CyDmaChSetInitialTd(SHIFT2FILTER1_Chan, SHIFT2FILTER1_TD[0]);
    CyDmaChEnable(SHIFT2FILTER1_Chan, 1);

}

void DMA_SHIFT2FILTER2_config()
{
    /* Defines for SHIFT2FILTER2 */
    #define SHIFT2FILTER2_BYTES_PER_BURST 2
    #define SHIFT2FILTER2_REQUEST_PER_BURST 1
    #define SHIFT2FILTER2_SRC_BASE (CYDEV_PERIPH_BASE)
    #define SHIFT2FILTER2_DST_BASE (CYDEV_PERIPH_BASE)

    /* Variable declarations for SHIFT2FILTER2 */
    /* Move these variable declarations to the top of the function */
    uint8 SHIFT2FILTER2_Chan;
    uint8 SHIFT2FILTER2_TD[1];

    /* DMA Configuration for SHIFT2FILTER2 */
    SHIFT2FILTER2_Chan = SHIFT2FILTER2_DmaInitialize(SHIFT2FILTER2_BYTES_PER_BURST, SHIFT2FILTER2_REQUEST_PER_BURST, 
        HI16(SHIFT2FILTER2_SRC_BASE), HI16(SHIFT2FILTER2_DST_BASE));
    SHIFT2FILTER2_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(SHIFT2FILTER2_TD[0], 2, SHIFT2FILTER2_TD[0], SHIFT2FILTER2__TD_TERMOUT_EN);
    CyDmaTdSetAddress(SHIFT2FILTER2_TD[0], LO16((uint32)ShiftBy2_2_OUTPUT_PTR), LO16((uint32)Filter_STAGEB_PTR));
    CyDmaChSetInitialTd(SHIFT2FILTER2_Chan, SHIFT2FILTER2_TD[0]);
    CyDmaChEnable(SHIFT2FILTER2_Chan, 1);
}

void start_DMAs()
{
//    DMA_SAR2FILTER1_config();
//    DMA_SAR2FILTER2_config();
    DMA_SAR2SHIFT1_config();
    DMA_SAR2SHIFT2_config();
    DMA_SHIFT2FILTER1_config();
    DMA_SHIFT2FILTER2_config();
    DMA_FILTER2RAM1_config();
    DMA_FILTER2RAM2_config();

    DMA_SPI2RAM_config();

}


