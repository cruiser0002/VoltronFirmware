/* ========================================
 *
 * Jay Lin
 * Copyright ALCH3MY, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF ALCH3MY.
 *
 * ========================================
*/
#include <project.h>
#include <math.h>
#include <resources.h>


int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    start_resources();
    start_DMAs();
    start_interrupts();
    
    for(;;)
    {
//        i2cbuf[0] = filtermem1[0] >> 8;
//        i2cbuf[1] = filtermem1[0];
//        i2cbuf[2] = filtermem2[0] >> 8;
//        i2cbuf[3] = filtermem2[0];

        //VDAC1_SetValue(SPIS_ReadRxData());
        //VDAC4_SetValue(SPIS_ReadRxData());
        //SPIS_ClearRxBuffer();
        
        CyDelay(1);
    }
}

