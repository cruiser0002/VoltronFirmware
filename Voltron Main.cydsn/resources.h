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

#ifndef RESOURCE_H
    #define RESOURCE_H
    
    #include <project.h>

    #define DECIMATION 25
    //I2C
    extern uint8 i2cbuf[4];

    //SPI
    extern uint32 spimem[1];

    //SAR variables
    extern uint32 sarmem1[1];
    extern uint32 sarmem2[1];

    //4^N samples for decimation
    extern uint16 filtermem1[DECIMATION];
    extern uint16 filtermem2[DECIMATION];

    void start_resources();

    //CY_ISR(filter_ready1_handler);
    //
    //CY_ISR(filter_ready2_handler);
    //
    //CY_ISR(spi_rx_handler);

    void start_interrupts();

    void DMA_SAR2FILTER1_config();

    void DMA_SAR2FILTER2_config();

    void DMA_FILTER2RAM1_config();

    void DMA_FILTER2RAM2_config();

    void DMA_SPI2RAM_config();

    void DMA_SAR2SHIFT1_config();

    void DMA_SAR2SHIFT2_config();

    void DMA_SHIFT2FILTER1_config();

    void DMA_SHIFT2FILTER2_config();

    void start_DMAs();

#endif

