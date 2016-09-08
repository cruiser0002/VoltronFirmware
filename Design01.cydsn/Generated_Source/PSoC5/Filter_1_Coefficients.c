#include "Filter_1.h"
#include "Filter_1_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelAFirCoefficients Filter_1_ChannelAFirCoefficients

/* Number of FIR filter taps are: 15 */

const uint8 CYCODE Filter_1_ChannelAFirCoefficients[Filter_1_FIR_A_SIZE] = 
{
 0x94u, 0x14u, 0x00u, 0x00u, /* Tap(0), 0.000627994537353516 */

 0xF4u, 0x64u, 0x00u, 0x00u, /* Tap(1), 0.00308084487915039 */

 0x58u, 0x2Au, 0x01u, 0x00u, /* Tap(2), 0.00910472869873047 */

 0x3Eu, 0x86u, 0x02u, 0x00u, /* Tap(3), 0.0197217464447021 */

 0x76u, 0x64u, 0x04u, 0x00u, /* Tap(4), 0.034315824508667 */

 0x2Eu, 0x64u, 0x06u, 0x00u, /* Tap(5), 0.0499322414398193 */

 0x06u, 0xF2u, 0x07u, 0x00u, /* Tap(6), 0.0620734691619873 */

 0x88u, 0x88u, 0x08u, 0x00u, /* Tap(7), 0.0666666030883789 */

 0x06u, 0xF2u, 0x07u, 0x00u, /* Tap(8), 0.0620734691619873 */

 0x2Eu, 0x64u, 0x06u, 0x00u, /* Tap(9), 0.0499322414398193 */

 0x76u, 0x64u, 0x04u, 0x00u, /* Tap(10), 0.034315824508667 */

 0x3Eu, 0x86u, 0x02u, 0x00u, /* Tap(11), 0.0197217464447021 */

 0x58u, 0x2Au, 0x01u, 0x00u, /* Tap(12), 0.00910472869873047 */

 0xF4u, 0x64u, 0x00u, 0x00u, /* Tap(13), 0.00308084487915039 */

 0x94u, 0x14u, 0x00u, 0x00u, /* Tap(14), 0.000627994537353516 */
};

