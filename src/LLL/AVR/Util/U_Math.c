/*********************************************************************

          File: U_Math.c

   Description: AVR utils part of Math Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/05/04

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "U_Math.h"

uint32_t pow_2i(uint8_t y) {
  uint32_t _TVal = 0;
  register uint8_t i = 0;
  for (i = 0; i < y; i++) _TVal |= (1 << i);
  return _TVal;
}