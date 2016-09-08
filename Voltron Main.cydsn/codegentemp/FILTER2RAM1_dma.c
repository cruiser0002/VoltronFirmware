/***************************************************************************
* File Name: FILTER2RAM1_dma.c  
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
#include <FILTER2RAM1_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* FILTER2RAM1__DRQ_CTL_REG
* 
* 
* FILTER2RAM1__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* FILTER2RAM1__NUMBEROF_TDS
* 
* Priority of this channel.
* FILTER2RAM1__PRIORITY
* 
* True if FILTER2RAM1_TERMIN_SEL is used.
* FILTER2RAM1__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* FILTER2RAM1__TERMIN_SEL
* 
* 
* True if FILTER2RAM1_TERMOUT0_SEL is used.
* FILTER2RAM1__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* FILTER2RAM1__TERMOUT0_SEL
* 
* 
* True if FILTER2RAM1_TERMOUT1_SEL is used.
* FILTER2RAM1__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* FILTER2RAM1__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of FILTER2RAM1 dma channel */
uint8 FILTER2RAM1_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 FILTER2RAM1_DmaInitalize
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
uint8 FILTER2RAM1_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    FILTER2RAM1_DmaHandle = (uint8)FILTER2RAM1__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(FILTER2RAM1_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)FILTER2RAM1__TERMOUT0_SEL,
                                  (uint8)FILTER2RAM1__TERMOUT1_SEL,
                                  (uint8)FILTER2RAM1__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(FILTER2RAM1_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(FILTER2RAM1_DmaHandle, (uint8)FILTER2RAM1__PRIORITY);
    
    return FILTER2RAM1_DmaHandle;
}

/*********************************************************************
* Function Name: void FILTER2RAM1_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with FILTER2RAM1.
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
void FILTER2RAM1_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(FILTER2RAM1_DmaHandle);
}

