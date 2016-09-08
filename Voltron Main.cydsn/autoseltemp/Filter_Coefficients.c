#include "Filter.h"
#include "Filter_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelAFirCoefficients Filter_ChannelAFirCoefficients

/* Number of FIR filter taps are: 16 */

const uint8 CYCODE Filter_ChannelAFirCoefficients[Filter_FIR_A_SIZE] = 
{
 0x4Eu, 0x4Du, 0x00u, 0x00u, /* Tap(0), 0.00235915184020996 */

 0x93u, 0x8Eu, 0x00u, 0x00u, /* Tap(1), 0.00435101985931396 */

 0xDDu, 0x08u, 0x01u, 0x00u, /* Tap(2), 0.00808298587799072 */

 0x9Au, 0xABu, 0x01u, 0x00u, /* Tap(3), 0.0130493640899658 */

 0x9Fu, 0x5Eu, 0x02u, 0x00u, /* Tap(4), 0.0185126066207886 */

 0x25u, 0x06u, 0x03u, 0x00u, /* Tap(5), 0.0236250162124634 */

 0x8Bu, 0x87u, 0x03u, 0x00u, /* Tap(6), 0.0275739431381226 */

 0xF6u, 0xCDu, 0x03u, 0x00u, /* Tap(7), 0.0297229290008545 */

 0xF6u, 0xCDu, 0x03u, 0x00u, /* Tap(8), 0.0297229290008545 */

 0x8Bu, 0x87u, 0x03u, 0x00u, /* Tap(9), 0.0275739431381226 */

 0x25u, 0x06u, 0x03u, 0x00u, /* Tap(10), 0.0236250162124634 */

 0x9Fu, 0x5Eu, 0x02u, 0x00u, /* Tap(11), 0.0185126066207886 */

 0x9Au, 0xABu, 0x01u, 0x00u, /* Tap(12), 0.0130493640899658 */

 0xDDu, 0x08u, 0x01u, 0x00u, /* Tap(13), 0.00808298587799072 */

 0x93u, 0x8Eu, 0x00u, 0x00u, /* Tap(14), 0.00435101985931396 */

 0x4Eu, 0x4Du, 0x00u, 0x00u, /* Tap(15), 0.00235915184020996 */
};


/*******************************************************************************
* ChannelB filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelBFirCoefficients Filter_ChannelBFirCoefficients

/* Number of FIR filter taps are: 16 */

const uint8 CYCODE Filter_ChannelBFirCoefficients[Filter_FIR_B_SIZE] = 
{
 0x2Bu, 0x54u, 0x00u, 0x00u, /* Tap(0), 0.00256860256195068 */

 0x36u, 0xD9u, 0xFFu, 0x00u, /* Tap(1), -0.00118374824523926 */

 0xB0u, 0x23u, 0xFEu, 0x00u, /* Tap(2), -0.0145359039306641 */

 0x29u, 0x62u, 0xFCu, 0x00u, /* Tap(3), -0.0282543897628784 */

 0x09u, 0xDBu, 0xFEu, 0x00u, /* Tap(4), -0.00894057750701904 */

 0xE2u, 0x28u, 0x09u, 0x00u, /* Tap(5), 0.0715601444244385 */

 0xA5u, 0xBDu, 0x18u, 0x00u, /* Tap(6), 0.193287491798401 */

 0x94u, 0xAAu, 0x24u, 0x00u, /* Tap(7), 0.286455631256104 */

 0x94u, 0xAAu, 0x24u, 0x00u, /* Tap(8), 0.286455631256104 */

 0xA5u, 0xBDu, 0x18u, 0x00u, /* Tap(9), 0.193287491798401 */

 0xE2u, 0x28u, 0x09u, 0x00u, /* Tap(10), 0.0715601444244385 */

 0x09u, 0xDBu, 0xFEu, 0x00u, /* Tap(11), -0.00894057750701904 */

 0x29u, 0x62u, 0xFCu, 0x00u, /* Tap(12), -0.0282543897628784 */

 0xB0u, 0x23u, 0xFEu, 0x00u, /* Tap(13), -0.0145359039306641 */

 0x36u, 0xD9u, 0xFFu, 0x00u, /* Tap(14), -0.00118374824523926 */

 0x2Bu, 0x54u, 0x00u, 0x00u, /* Tap(15), 0.00256860256195068 */
};

