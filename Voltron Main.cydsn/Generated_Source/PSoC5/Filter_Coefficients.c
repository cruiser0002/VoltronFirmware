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
 0x64u, 0x0Au, 0x00u, 0x00u, /* Tap(0), 0.000317096710205078 */

 0x38u, 0x2Du, 0x00u, 0x00u, /* Tap(1), 0.00137996673583984 */

 0xFEu, 0x77u, 0x00u, 0x00u, /* Tap(2), 0.0036618709564209 */

 0xBCu, 0x02u, 0x01u, 0x00u, /* Tap(3), 0.00789594650268555 */

 0xA2u, 0xDEu, 0x01u, 0x00u, /* Tap(4), 0.0146067142486572 */

 0x0Bu, 0x11u, 0x03u, 0x00u, /* Tap(5), 0.0239576101303101 */

 0x65u, 0x90u, 0x04u, 0x00u, /* Tap(6), 0.0356565713882446 */

 0xC6u, 0x43u, 0x06u, 0x00u, /* Tap(7), 0.0489432811737061 */

 0x61u, 0x05u, 0x08u, 0x00u, /* Tap(8), 0.0626641511917114 */

 0x9Fu, 0xA7u, 0x09u, 0x00u, /* Tap(9), 0.0754278898239136 */

 0xF8u, 0xFBu, 0x0Au, 0x00u, /* Tap(10), 0.0858144760131836 */

 0x57u, 0xDAu, 0x0Bu, 0x00u, /* Tap(11), 0.0926007032394409 */

 0xA6u, 0x27u, 0x0Cu, 0x00u, /* Tap(12), 0.0949599742889404 */

 0x57u, 0xDAu, 0x0Bu, 0x00u, /* Tap(13), 0.0926007032394409 */

 0xF8u, 0xFBu, 0x0Au, 0x00u, /* Tap(14), 0.0858144760131836 */

 0x9Fu, 0xA7u, 0x09u, 0x00u, /* Tap(15), 0.0754278898239136 */

 0x61u, 0x05u, 0x08u, 0x00u, /* Tap(16), 0.0626641511917114 */

 0xC6u, 0x43u, 0x06u, 0x00u, /* Tap(17), 0.0489432811737061 */

 0x65u, 0x90u, 0x04u, 0x00u, /* Tap(18), 0.0356565713882446 */

 0x0Bu, 0x11u, 0x03u, 0x00u, /* Tap(19), 0.0239576101303101 */

 0xA2u, 0xDEu, 0x01u, 0x00u, /* Tap(20), 0.0146067142486572 */

 0xBCu, 0x02u, 0x01u, 0x00u, /* Tap(21), 0.00789594650268555 */

 0xFEu, 0x77u, 0x00u, 0x00u, /* Tap(22), 0.0036618709564209 */

 0x38u, 0x2Du, 0x00u, 0x00u, /* Tap(23), 0.00137996673583984 */

 0x64u, 0x0Au, 0x00u, 0x00u, /* Tap(24), 0.000317096710205078 */
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
 0x64u, 0x0Au, 0x00u, 0x00u, /* Tap(0), 0.000317096710205078 */

 0x38u, 0x2Du, 0x00u, 0x00u, /* Tap(1), 0.00137996673583984 */

 0xFEu, 0x77u, 0x00u, 0x00u, /* Tap(2), 0.0036618709564209 */

 0xBCu, 0x02u, 0x01u, 0x00u, /* Tap(3), 0.00789594650268555 */

 0xA2u, 0xDEu, 0x01u, 0x00u, /* Tap(4), 0.0146067142486572 */

 0x0Bu, 0x11u, 0x03u, 0x00u, /* Tap(5), 0.0239576101303101 */

 0x65u, 0x90u, 0x04u, 0x00u, /* Tap(6), 0.0356565713882446 */

 0xC6u, 0x43u, 0x06u, 0x00u, /* Tap(7), 0.0489432811737061 */

 0x61u, 0x05u, 0x08u, 0x00u, /* Tap(8), 0.0626641511917114 */

 0x9Fu, 0xA7u, 0x09u, 0x00u, /* Tap(9), 0.0754278898239136 */

 0xF8u, 0xFBu, 0x0Au, 0x00u, /* Tap(10), 0.0858144760131836 */

 0x57u, 0xDAu, 0x0Bu, 0x00u, /* Tap(11), 0.0926007032394409 */

 0xA6u, 0x27u, 0x0Cu, 0x00u, /* Tap(12), 0.0949599742889404 */

 0x57u, 0xDAu, 0x0Bu, 0x00u, /* Tap(13), 0.0926007032394409 */

 0xF8u, 0xFBu, 0x0Au, 0x00u, /* Tap(14), 0.0858144760131836 */

 0x9Fu, 0xA7u, 0x09u, 0x00u, /* Tap(15), 0.0754278898239136 */

 0x61u, 0x05u, 0x08u, 0x00u, /* Tap(16), 0.0626641511917114 */

 0xC6u, 0x43u, 0x06u, 0x00u, /* Tap(17), 0.0489432811737061 */

 0x65u, 0x90u, 0x04u, 0x00u, /* Tap(18), 0.0356565713882446 */

 0x0Bu, 0x11u, 0x03u, 0x00u, /* Tap(19), 0.0239576101303101 */

 0xA2u, 0xDEu, 0x01u, 0x00u, /* Tap(20), 0.0146067142486572 */

 0xBCu, 0x02u, 0x01u, 0x00u, /* Tap(21), 0.00789594650268555 */

 0xFEu, 0x77u, 0x00u, 0x00u, /* Tap(22), 0.0036618709564209 */

 0x38u, 0x2Du, 0x00u, 0x00u, /* Tap(23), 0.00137996673583984 */

 0x64u, 0x0Au, 0x00u, 0x00u, /* Tap(24), 0.000317096710205078 */
};

