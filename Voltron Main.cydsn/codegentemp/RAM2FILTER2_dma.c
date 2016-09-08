/***************************************************************************
* File Name: RAM2FILTER2_dma.c  
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
#include <RAM2FILTER2_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* RAM2FILTER2__DRQ_CTL_REG
* 
* 
* RAM2FILTER2__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* RAM2FILTER2__NUMBEROF_TDS
* 
* Priority of this channel.
* RAM2FILTER2__PRIORITY
* 
* True if RAM2FILTER2_TERMIN_SEL is used.
* RAM2FILTER2__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* RAM2FILTER2__TERMIN_SEL
* 
* 
* True if RAM2FILTER2_TERMOUT0_SEL is used.
* RAM2FILTER2__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* RAM2FILTER2__TERMOUT0_SEL
* 
* 
* True if RAM2FILTER2_TERMOUT1_SEL is used.
* RAM2FILTER2__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* RAM2FILTER2__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of RAM2FILTER2 dma channel */
uint8 RAM2FILTER2_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 RAM2FILTER2_DmaInitalize
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
uint8 RAM2FILTER2_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    RAM2FILTER2_DmaHandle = (uint8)RAM2FILTER2__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(RAM2FILTER2_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)RAM2FILTER2__TERMOUT0_SEL,
                                  (uint8)RAM2FILTER2__TERMOUT1_SEL,
                                  (uint8)RAM2FILTER2__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(RAM2FILTER2_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(RAM2FILTER2_DmaHandle, (uint8)RAM2FILTER2__PRIORITY);
    
    return RAM2FILTER2_DmaHandle;
}

/*********************************************************************
* Function Name: void RAM2FILTER2_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with RAM2FILTER2.
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
void RAM2FILTER2_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(RAM2FILTER2_DmaHandle);
}

