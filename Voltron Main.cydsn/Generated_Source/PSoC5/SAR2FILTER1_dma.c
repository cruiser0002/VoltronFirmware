/***************************************************************************
* File Name: SAR2FILTER1_dma.c  
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
#include <SAR2FILTER1_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* SAR2FILTER1__DRQ_CTL_REG
* 
* 
* SAR2FILTER1__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* SAR2FILTER1__NUMBEROF_TDS
* 
* Priority of this channel.
* SAR2FILTER1__PRIORITY
* 
* True if SAR2FILTER1_TERMIN_SEL is used.
* SAR2FILTER1__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* SAR2FILTER1__TERMIN_SEL
* 
* 
* True if SAR2FILTER1_TERMOUT0_SEL is used.
* SAR2FILTER1__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* SAR2FILTER1__TERMOUT0_SEL
* 
* 
* True if SAR2FILTER1_TERMOUT1_SEL is used.
* SAR2FILTER1__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* SAR2FILTER1__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of SAR2FILTER1 dma channel */
uint8 SAR2FILTER1_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 SAR2FILTER1_DmaInitalize
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
uint8 SAR2FILTER1_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    SAR2FILTER1_DmaHandle = (uint8)SAR2FILTER1__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(SAR2FILTER1_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)SAR2FILTER1__TERMOUT0_SEL,
                                  (uint8)SAR2FILTER1__TERMOUT1_SEL,
                                  (uint8)SAR2FILTER1__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(SAR2FILTER1_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(SAR2FILTER1_DmaHandle, (uint8)SAR2FILTER1__PRIORITY);
    
    return SAR2FILTER1_DmaHandle;
}

/*********************************************************************
* Function Name: void SAR2FILTER1_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with SAR2FILTER1.
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
void SAR2FILTER1_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(SAR2FILTER1_DmaHandle);
}

