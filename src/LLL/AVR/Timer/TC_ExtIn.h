/*********************************************************************

          File: TC_ExtIn.h

   Description: AVR T/C internal func. Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/12

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_ExtIn_h_
#define _TC_ExtIn_h_

#include <stdint.h>

#include "TC_Basic.strt.h"

void _UpdateWGMode(uint8_t __PeriNum);

TCFreqOptiValueStoreage _GetAutoCalculatedPeriodByModeName(uint8_t __PeriNum, uint8_t __ModeName, double __WishFreq);
TCFreqOptiValueStoreage _GetTCPeriodAutoSelectionByPeripheral(uint8_t __PeriNum, double __Period);

double Get_xman(uint8_t __Perinum);

#endif // _TC_ExtIn_h_
