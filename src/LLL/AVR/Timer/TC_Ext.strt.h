/*********************************************************************

          File: TC_Ext.strt.h

   Description: AVR TC extended struct definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/18

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_Ext_strt_h_
#define _TC_Ext_strt_h_

#pragma __FunCX_Section Begin

#include <stdbool.h>

#include "TC_Basic.const.h"

#pragma __FunCX_InLevel_Except Begin

typedef struct _TCChanOptionsInformations {
  bool IsToggleMode; // 8(1)
  bool IsInvertPWM[TC_NBit_Peri_Ch_MaxQty]; // 8(1)
  bool IsICFTop; // 8(1)
  double DiffMarginFreqValue; // 32(8)
} TCChanOptionsInformations;

#pragma __FunCX_InLevel_Except End

#pragma __FunCX_Section Exd

#endif // _TC_Ext_strt_h_
