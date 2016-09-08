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

/* Number of FIR filter taps are: 25 */

const uint8 CYCODE Filter_ChannelAFirCoefficients[Filter_FIR_A_SIZE] = 
{
 0x4Fu, 0x8Au, 0x00u, 0x00u, /* Tap(0), 0.00422084331512451 */

 0xAEu, 0xC9u, 0x00u, 0x00u, /* Tap(1), 0.00615477561950684 */

 0x83u, 0x44u, 0x01u, 0x00u, /* Tap(2), 0.00990331172943115 */

 0xD9u, 0xFBu, 0x01u, 0x00u, /* Tap(3), 0.0154982805252075 */

 0x84u, 0xEAu, 0x02u, 0x00u, /* Tap(4), 0.0227818489074707 */

 0x43u, 0x05u, 0x04u, 0x00u, /* Tap(5), 0.0314105749130249 */

 0x80u, 0x3Bu, 0x05u, 0x00u, /* Tap(6), 0.0408782958984375 */

 0xB6u, 0x78u, 0x06u, 0x00u, /* Tap(7), 0.0505588054656982 */

 0x47u, 0xA6u, 0x07u, 0x00u, /* Tap(8), 0.0597618818283081 */

 0x98u, 0xADu, 0x08u, 0x00u, /* Tap(9), 0.0677976608276367 */

 0x3Fu, 0x7Au, 0x09u, 0x00u, /* Tap(10), 0.0740431547164917 */

 0x03u, 0xFCu, 0x09u, 0x00u, /* Tap(11), 0.0780032873153687 */

 0x78u, 0x28u, 0x0Au, 0x00u, /* Tap(12), 0.0793600082397461 */

 0x03u, 0xFCu, 0x09u, 0x00u, /* Tap(13), 0.0780032873153687 */

 0x3Fu, 0x7Au, 0x09u, 0x00u, /* Tap(14), 0.0740431547164917 */

 0x98u, 0xADu, 0x08u, 0x00u, /* Tap(15), 0.0677976608276367 */

 0x47u, 0xA6u, 0x07u, 0x00u, /* Tap(16), 0.0597618818283081 */

 0xB6u, 0x78u, 0x06u, 0x00u, /* Tap(17), 0.0505588054656982 */

 0x80u, 0x3Bu, 0x05u, 0x00u, /* Tap(18), 0.0408782958984375 */

 0x43u, 0x05u, 0x04u, 0x00u, /* Tap(19), 0.0314105749130249 */

 0x84u, 0xEAu, 0x02u, 0x00u, /* Tap(20), 0.0227818489074707 */

 0xD9u, 0xFBu, 0x01u, 0x00u, /* Tap(21), 0.0154982805252075 */

 0x83u, 0x44u, 0x01u, 0x00u, /* Tap(22), 0.00990331172943115 */

 0xAEu, 0xC9u, 0x00u, 0x00u, /* Tap(23), 0.00615477561950684 */

 0x4Fu, 0x8Au, 0x00u, 0x00u, /* Tap(24), 0.00422084331512451 */
};


/*******************************************************************************
* ChannelB filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelBFirCoefficients Filter_ChannelBFirCoefficients

/* Number of FIR filter taps are: 25 */

const uint8 CYCODE Filter_ChannelBFirCoefficients[Filter_FIR_B_SIZE] = 
{
 0x4Fu, 0x8Au, 0x00u, 0x00u, /* Tap(0), 0.00422084331512451 */

 0xAEu, 0xC9u, 0x00u, 0x00u, /* Tap(1), 0.00615477561950684 */

 0x83u, 0x44u, 0x01u, 0x00u, /* Tap(2), 0.00990331172943115 */

 0xD9u, 0xFBu, 0x01u, 0x00u, /* Tap(3), 0.0154982805252075 */

 0x84u, 0xEAu, 0x02u, 0x00u, /* Tap(4), 0.0227818489074707 */

 0x43u, 0x05u, 0x04u, 0x00u, /* Tap(5), 0.0314105749130249 */

 0x80u, 0x3Bu, 0x05u, 0x00u, /* Tap(6), 0.0408782958984375 */

 0xB6u, 0x78u, 0x06u, 0x00u, /* Tap(7), 0.0505588054656982 */

 0x47u, 0xA6u, 0x07u, 0x00u, /* Tap(8), 0.0597618818283081 */

 0x98u, 0xADu, 0x08u, 0x00u, /* Tap(9), 0.0677976608276367 */

 0x3Fu, 0x7Au, 0x09u, 0x00u, /* Tap(10), 0.0740431547164917 */

 0x03u, 0xFCu, 0x09u, 0x00u, /* Tap(11), 0.0780032873153687 */

 0x78u, 0x28u, 0x0Au, 0x00u, /* Tap(12), 0.0793600082397461 */

 0x03u, 0xFCu, 0x09u, 0x00u, /* Tap(13), 0.0780032873153687 */

 0x3Fu, 0x7Au, 0x09u, 0x00u, /* Tap(14), 0.0740431547164917 */

 0x98u, 0xADu, 0x08u, 0x00u, /* Tap(15), 0.0677976608276367 */

 0x47u, 0xA6u, 0x07u, 0x00u, /* Tap(16), 0.0597618818283081 */

 0xB6u, 0x78u, 0x06u, 0x00u, /* Tap(17), 0.0505588054656982 */

 0x80u, 0x3Bu, 0x05u, 0x00u, /* Tap(18), 0.0408782958984375 */

 0x43u, 0x05u, 0x04u, 0x00u, /* Tap(19), 0.0314105749130249 */

 0x84u, 0xEAu, 0x02u, 0x00u, /* Tap(20), 0.0227818489074707 */

 0xD9u, 0xFBu, 0x01u, 0x00u, /* Tap(21), 0.0154982805252075 */

 0x83u, 0x44u, 0x01u, 0x00u, /* Tap(22), 0.00990331172943115 */

 0xAEu, 0xC9u, 0x00u, 0x00u, /* Tap(23), 0.00615477561950684 */

 0x4Fu, 0x8Au, 0x00u, 0x00u, /* Tap(24), 0.00422084331512451 */
};

