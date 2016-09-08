/***************************************************************************
* File Name: FILTER2RAM2_dma.c  
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
#include <FILTER2RAM2_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* FILTER2RAM2__DRQ_CTL_REG
* 
* 
* FILTER2RAM2__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* FILTER2RAM2__NUMBEROF_TDS
* 
* Priority of this channel.
* FILTER2RAM2__PRIORITY
* 
* True if FILTER2RAM2_TERMIN_SEL is used.
* FILTER2RAM2__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* FILTER2RAM2__TERMIN_SEL
* 
* 
* True if FILTER2RAM2_TERMOUT0_SEL is used.
* FILTER2RAM2__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* FILTER2RAM2__TERMOUT0_SEL
* 
* 
* True if FILTER2RAM2_TERMOUT1_SEL is used.
* FILTER2RAM2__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* FILTER2RAM2__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of FILTER2RAM2 dma channel */
uint8 FILTER2RAM2_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 FILTER2RAM2_DmaInitalize
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
uint8 FILTER2RAM2_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    FILTER2RAM2_DmaHandle = (uint8)FILTER2RAM2__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(FILTER2RAM2_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)FILTER2RAM2__TERMOUT0_SEL,
                                  (uint8)FILTER2RAM2__TERMOUT1_SEL,
                                  (uint8)FILTER2RAM2__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(FILTER2RAM2_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(FILTER2RAM2_DmaHandle, (uint8)FILTER2RAM2__PRIORITY);
    
    return FILTER2RAM2_DmaHandle;
}

/*********************************************************************
* Function Name: void FILTER2RAM2_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with FILTER2RAM2.
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
void FILTER2RAM2_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(FILTER2RAM2_DmaHandle);
}

