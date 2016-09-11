/***************************************************************************
* File Name: SPI2SHIFT_dma.c  
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
#include <SPI2SHIFT_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* SPI2SHIFT__DRQ_CTL_REG
* 
* 
* SPI2SHIFT__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* SPI2SHIFT__NUMBEROF_TDS
* 
* Priority of this channel.
* SPI2SHIFT__PRIORITY
* 
* True if SPI2SHIFT_TERMIN_SEL is used.
* SPI2SHIFT__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* SPI2SHIFT__TERMIN_SEL
* 
* 
* True if SPI2SHIFT_TERMOUT0_SEL is used.
* SPI2SHIFT__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* SPI2SHIFT__TERMOUT0_SEL
* 
* 
* True if SPI2SHIFT_TERMOUT1_SEL is used.
* SPI2SHIFT__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* SPI2SHIFT__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of SPI2SHIFT dma channel */
uint8 SPI2SHIFT_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 SPI2SHIFT_DmaInitalize
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
uint8 SPI2SHIFT_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    SPI2SHIFT_DmaHandle = (uint8)SPI2SHIFT__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(SPI2SHIFT_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)SPI2SHIFT__TERMOUT0_SEL,
                                  (uint8)SPI2SHIFT__TERMOUT1_SEL,
                                  (uint8)SPI2SHIFT__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(SPI2SHIFT_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(SPI2SHIFT_DmaHandle, (uint8)SPI2SHIFT__PRIORITY);
    
    return SPI2SHIFT_DmaHandle;
}

/*********************************************************************
* Function Name: void SPI2SHIFT_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with SPI2SHIFT.
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
void SPI2SHIFT_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(SPI2SHIFT_DmaHandle);
}

