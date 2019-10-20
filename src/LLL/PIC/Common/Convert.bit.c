/*********************************************************************

          File: Convert.bit.c

   Description: PIC Bit Conversion Source Part.

        Author: Jinseong Jeon (aimer120@nate.com)

       Created: 2019/10/19

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "Convert.bit.h"

unsigned char weight2bit(unsigned char weight) {
  int bit = 0;
  while ((weight>>=1)>0) { bit++; }
  return bit;
}
