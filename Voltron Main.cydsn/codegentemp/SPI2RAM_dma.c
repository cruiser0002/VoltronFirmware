/***************************************************************************
* File Name: SPI2RAM_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <SPI2RAM_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* SPI2RAM__DRQ_CTL_REG
* 
* 
* SPI2RAM__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* SPI2RAM__NUMBEROF_TDS
* 
* Priority of this channel.
* SPI2RAM__PRIORITY
* 
* True if SPI2RAM_TERMIN_SEL is used.
* SPI2RAM__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* SPI2RAM__TERMIN_SEL
* 
* 
* True if SPI2RAM_TERMOUT0_SEL is used.
* SPI2RAM__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* SPI2RAM__TERMOUT0_SEL
* 
* 
* True if SPI2RAM_TERMOUT1_SEL is used.
* SPI2RAM__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* SPI2RAM__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of SPI2RAM dma channel */
uint8 SPI2RAM_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 SPI2RAM_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 SPI2RAM_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    SPI2RAM_DmaHandle = (uint8)SPI2RAM__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(SPI2RAM_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)SPI2RAM__TERMOUT0_SEL,
                                  (uint8)SPI2RAM__TERMOUT1_SEL,
                                  (uint8)SPI2RAM__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(SPI2RAM_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(SPI2RAM_DmaHandle, (uint8)SPI2RAM__PRIORITY);
    
    return SPI2RAM_DmaHandle;
}

/*********************************************************************
* Function Name: void SPI2RAM_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with SPI2RAM.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void SPI2RAM_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(SPI2RAM_DmaHandle);
}

