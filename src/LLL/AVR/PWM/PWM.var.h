/*********************************************************************

          File: PWM.var.h

   Description: AVR PWM Variables definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/06

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _PWM_var_h_
#define _PWM_var_h_

#pragma __FunCX_Section Begin

#include "PWM.const.h"

#include "TC_Basic.strt.h"

#pragma __FunCX_InLevel_Except Begin

TCFreqOptiValueStoreage Get_TCOVExtInfo(uint8_t PeriNum);
void Set_TCOVExtInfo(uint8_t PeriNum, TCFreqOptiValueStoreage TCOptiValue);

#pragma __FunCX_InLevel_Except End

#pragma __FunCX_Section End

#endif // _PWM_var_h_