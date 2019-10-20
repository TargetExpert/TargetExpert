/*********************************************************************

          File: PIC_BitSet.mac.h

   Description: PIC Bit set macro Header Part.

        Author: Jinseong Jeon (aimer120@nate.com)

       Created: 2019/10/11

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _PIC_BITSET_MAC_H_
#define _PIC_BITSET_MAC_H_

#pragma __FunX_Section Begin

#include "Convert.bit.h"

#pragma __FunX_InLevel_Except Begin

#define bit_is_set(reg, bit) (reg & bit)

#ifdef _CONVERT_BIT_H_
  #define CONV_BIT_(weight)	weight2bit(weight)
#else
  #define CONV_BIT_(weight)	0
#endif

#pragma __FunX_InLevel_Except End

#pragma __FunX_Section End

#endif // _PIC_BITSET_MAC_H_
