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

#define DECIMATION 25


void start_resources();

CY_ISR(filter_ready1_handler);

CY_ISR(filter_ready2_handler);

CY_ISR(spi_rx_handler);

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