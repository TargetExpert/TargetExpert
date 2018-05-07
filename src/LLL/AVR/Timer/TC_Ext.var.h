/*********************************************************************

          File: TC_Ext.var.h

   Description: AVR TC extended Variables definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/06

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_Ext_var_h_
#define _TC_Ext_var_h_

#pragma __FunCX_Section Begin

#include "TC_Ext.const.h"
#include "TC_Ext.strt.h"

#pragma __FunCX_InLevel_Except Begin

TCChanOptionsInformations Get_TOptInfo(uint8_t __PeriNum);
void Set_TOptInfo(uint8_t __PeriNum, TCChanOptionsInformations __TCOptiValue);

#pragma __FunCX_InLevel_Except End

#pragma __FunCX_Section End

#endif // _TC_Ext_var_h_
