/*********************************************************************

          File: TC_Basic.var.c

   Description: AVR TC basic Variables definition Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/25

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "TC_Basic.var.h"

static TCFreqOptiValueStoreage
__attribute__ ((externally_visible))
    _TCOVInfo[TE_HAVE_TC_QTY] = InitialFormFreqOptiValuesArr;

static bool
__attribute__ ((externally_visible))
    _DefaultAutoMode[TE_HAVE_TC_QTY] = InitialFormDefaultAutoModeValuesArr;

TCFreqOptiValueStoreage Get_TCOVInfo(uint8_t PeriNum) {
  return _TCOVInfo[PeriNum];
}

void Set_TCOVInfo(uint8_t PeriNum, TCFreqOptiValueStoreage TCOptiValue) {
  _TCOVInfo[PeriNum] = TCOptiValue;
}

bool Get_DefaultAutoMode(uint8_t PeriNum) {
  return _DefaultAutoMode[PeriNum];
}

void Set_DefaultAutoMode(uint8_t PeriNum, bool DefaultAutoMode) {
  _DefaultAutoMode[PeriNum] = DefaultAutoMode;
}