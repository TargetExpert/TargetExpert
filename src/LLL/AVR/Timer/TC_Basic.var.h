/*********************************************************************

          File: TC_Basic.var.h

   Description: AVR TC basic Variables definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/21

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_Basic_var_h_
#define _TC_Basic_var_h_

#pragma __FunCX_Section Begin

#include "TC_Basic.const.h"

#include "TC_Basic.strt.h"

#pragma __FunCX_InLevel_Except Begin

TCFreqOptiValueStoreage Get_TCOVInfo(uint8_t PeriNum);
void Set_TCOVInfo(uint8_t PeriNum, TCFreqOptiValueStoreage TCOptiValue);

bool Get_DefaultAutoMode(uint8_t PeriNum);
void Set_DefaultAutoMode(uint8_t PeriNum, bool DefaultAutoMode);

#pragma __FunCX_InLevel_Except End

#endif //_TC_Basic_var_h_
