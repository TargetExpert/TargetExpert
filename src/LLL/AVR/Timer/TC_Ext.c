/*********************************************************************

          File: TC_ext.c

   Description: AVR Timer/Counter extended func. Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/13

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "TC_Ext.h"

#define Set_ICFTop_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_ICFTop_TC##__PeriNum, bool Enable) \
  Set_ICFTop_TC##__PeriNum##_D(Enable)

#define Set_ToggledOut_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_ToggledOut_TC##__PeriNum, bool Enable) \
  Set_ToggledOut_TC##__PeriNum##_D(Enable)

#define Set_InvertOut_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_InvertOut_TC##__PeriNum, HELPER_PARAM_VAR(bool Enable, uint8_t Channel)) \
  Set_InvertOut_TC##__PeriNum##_D(Enable, Channel)

#define Set_DiffMarginFreqValue_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_DiffMarginFreqValue_TC##__PeriNum, double DiffMarginFreqValue) \
  Set_DiffMarginFreqValue_TC##__PeriNum##_D(DiffMarginFreqValue)

#define Set_Period_TC_Func(__PeriNum) \
  DECL_FUNC(, bool, Set_Period_TC##__PeriNum, HELPER_PARAM_VAR(double Period, uint8_t Mode)) \
  Set_Period_TC##__PeriNum##_D(Period, Mode)

#define Set_PeriodForAutoMode_TC_Func(__PeriNum) \
  DECL_FUNC(, bool, Set_PeriodForAutoMode_TC##__PeriNum, double Period) \
  Set_PeriodForAutoMode_TC##__PeriNum##_D(Period)

// T/C 0(8 bit)
#if defined(TCCR0) || defined(TCCR0A)
Set_ToggledOut_TC_Func(0)
Set_InvertOut_TC_Func(0)
Set_DiffMarginFreqValue_TC_Func(0)
Set_Period_TC_Func(0)
Set_PeriodForAutoMode_TC_Func(0)
#endif

// T/C 1(16 bit)
#if defined(TCCR1A)
Set_ICFTop_TC_Func(1)
Set_ToggledOut_TC_Func(1)
Set_InvertOut_TC_Func(1)
Set_DiffMarginFreqValue_TC_Func(1)
Set_Period_TC_Func(1)
Set_PeriodForAutoMode_TC_Func(1)
#endif

// T/C 2(8 bit)
#if defined(TCCR2) || defined(TCCR2A)
Set_ToggledOut_TC_Func(2)
Set_InvertOut_TC_Func(2)
Set_DiffMarginFreqValue_TC_Func(2)
Set_Period_TC_Func(2)
Set_PeriodForAutoMode_TC_Func(2)
#endif

// T/C 3(16 bit)
#if defined(TCCR3A)
Set_ICFTop_TC_Func(3)
Set_ToggledOut_TC_Func(3)
Set_InvertOut_TC_Func(3)
Set_DiffMarginFreqValue_TC_Func(3)
Set_Period_TC_Func(3)
Set_PeriodForAutoMode_TC_Func(3)
#endif

// T/C 4(16 bit)
#if defined(TCCR4A)
Set_ICFTop_TC_Func(4)
Set_ToggledOut_TC_Func(4)
Set_InvertOut_TC_Func(4)
Set_DiffMarginFreqValue_TC_Func(4)
Set_Period_TC_Func(4)
Set_PeriodForAutoMode_TC_Func(4)
#endif

// T/C 5(16 bit)
#if defined(TCCR5A)
Set_ICFTop_TC_Func(5)
Set_ToggledOut_TC_Func(5)
Set_InvertOut_TC_Func(5)
Set_DiffMarginFreqValue_TC_Func(5)
Set_Period_TC_Func(5)
Set_PeriodForAutoMode_TC_Func(5)
#endif