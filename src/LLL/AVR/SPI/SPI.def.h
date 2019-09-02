/*********************************************************************

          File: SPI.def.h

   Description: AVR SPI syntax definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2019/03/02

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _SPI_def_h_
#define _SPI_def_h_

#include "Common.inc.h"

#define AVR_MODE_BIT(__Num) __Num

// Definition of "Quantity of Register Bits".
#define UCSZ_BQTY AVR_MODE_BIT(3)
#define UPM_BQTY AVR_MODE_BIT(2)
#define USBS_BQTY AVR_MODE_BIT(1)
#define UMSEL_BQTY AVR_MODE_BIT(2)

#endif // _SPI_def_h_
