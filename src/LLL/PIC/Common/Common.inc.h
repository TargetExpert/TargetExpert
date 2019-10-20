/*********************************************************************

          File: Common.inc.h

   Description: PIC including Common Header Part.

        Author: Kwangyeon Kim (onting, hemool123@naver.com)

       Created: 2019/10/20

 Copyright (c) 2019, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

//This source code is written based on SDCC API

#ifndef _Common_inc_h_
#define _Common_inc_h_

#include <sdcc-lib.h>
#include <pic14/sdcc-lib.h>
#include <pic14/pic16fam.h>
#include <pic14/pic16regs.h>

//define machine feature
#if defined(__SDCC_PIC16F873A) || \
    defined(__SDCC_PIC16F876A)
#define __pic_feature_28_pin__

#elif defined(__SDCC_PIC16F874A) || \
    defined(__SDCC_PIC16F877A)
#define __pic_feature_40_44_pin__

#endif //feautre


#endif // _Common_inc_h_
