/***************************************************************************
* File Name: SAR2SHIFT2_dma.c  
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
#include <SAR2SHIFT2_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* SAR2SHIFT2__DRQ_CTL_REG
* 
* 
* SAR2SHIFT2__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* SAR2SHIFT2__NUMBEROF_TDS
* 
* Priority of this channel.
* SAR2SHIFT2__PRIORITY
* 
* True if SAR2SHIFT2_TERMIN_SEL is used.
* SAR2SHIFT2__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* SAR2SHIFT2__TERMIN_SEL
* 
* 
* True if SAR2SHIFT2_TERMOUT0_SEL is used.
* SAR2SHIFT2__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* SAR2SHIFT2__TERMOUT0_SEL
* 
* 
* True if SAR2SHIFT2_TERMOUT1_SEL is used.
* SAR2SHIFT2__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* SAR2SHIFT2__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of SAR2SHIFT2 dma channel */
uint8 SAR2SHIFT2_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 SAR2SHIFT2_DmaInitalize
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
uint8 SAR2SHIFT2_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    SAR2SHIFT2_DmaHandle = (uint8)SAR2SHIFT2__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(SAR2SHIFT2_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)SAR2SHIFT2__TERMOUT0_SEL,
                                  (uint8)SAR2SHIFT2__TERMOUT1_SEL,
                                  (uint8)SAR2SHIFT2__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(SAR2SHIFT2_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(SAR2SHIFT2_DmaHandle, (uint8)SAR2SHIFT2__PRIORITY);
    
    return SAR2SHIFT2_DmaHandle;
}

/*********************************************************************
* Function Name: void SAR2SHIFT2_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with SAR2SHIFT2.
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
void SAR2SHIFT2_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(SAR2SHIFT2_DmaHandle);
}

