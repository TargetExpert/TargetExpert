/*********************************************************************

          File: Common.inc.h

   Description: PIC including Common Header Part.

        Author: Jinseong Jeon (aimer120@nate.com)

       Created: 2019/10/08

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _COMMON_INC_H_
#define _COMMON_INC_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include <math.h>

#include "PIC_machines.h"
#include "BasicFunc.mac.h"
#include "BitSet.mac.h"
#include "PIC_BitSet.mac.h"
#include "FuncImplSet.mac.h"
//#include "FakeCallee.h"

//define machine feature
#if defined(__SDCC_PIC16F873A) || \
    defined(__SDCC_PIC16F876A)
#define __pic_feature_28_pin__

#elif defined(__SDCC_PIC16F874A) || \
    defined(__SDCC_PIC16F877A)
#define __pic_feature_40_44_pin__

#endif //feautre

#endif // _COMMON_INC_H_
