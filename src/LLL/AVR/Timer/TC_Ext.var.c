/*********************************************************************

          File: TC_Ext.var.c

   Description: AVR TC extended Variables definition Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/25

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "TC_Ext.var.h"

static TCChanOptionsInformations
__attribute__ ((externally_visible))
    _TOptInfo[TE_HAVE_TC_QTY] = InitialFormOptInfoValuesArr;

TCChanOptionsInformations Get_TOptInfo(uint8_t __PeriNum) {
  return _TOptInfo[__PeriNum];
}

void Set_TOptInfo(uint8_t __PeriNum, TCChanOptionsInformations __TCOptiValue) {
  _TOptInfo[__PeriNum] = __TCOptiValue;
}