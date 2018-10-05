/*********************************************************************

          File: PWM.var.c

   Description: AVR PWM Variables definition Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/25

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "PWM.var.h"

static TCFreqOptiValueStoreage
__attribute__ ((externally_visible))
    _TCOVExtInfo[TE_HAVE_TC_QTY] = InitialFormFreqOptiValuesArr;

TCFreqOptiValueStoreage Get_TCOVExtInfo(uint8_t PeriNum) {
  return _TCOVExtInfo[PeriNum];
}

void Set_TCOVExtInfo(uint8_t PeriNum, TCFreqOptiValueStoreage TCOptiValue) {
  _TCOVExtInfo[PeriNum] = TCOptiValue;
}