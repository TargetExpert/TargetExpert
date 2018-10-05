/*********************************************************************

          File: PWM.c

   Description: AVR PWM Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/01/22

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "PWM.h"

#if defined(TCCR0) || defined(TCCR2)
#define Set_DutyRatio_PWM_8Bit_Func(__PeriNum) \
  DECL_FUNC(, void, Set_DutyRatio_PWM##__PeriNum, double DutyRatio) \
  Set_DutyRatio_PWM##__PeriNum##_D(DutyRatio)
#else
#define Set_DutyRatio_PWM_8Bit_Func(__PeriNum) \
  DECL_FUNC(, void, Set_DutyRatio_PWM##__PeriNum, HELPER_PARAM_VAR(unsigned char Channel, double DutyRatio)) \
  Set_DutyRatio_PWM##__PeriNum##_D(Channel, DutyRatio)
#endif

#define Set_DutyRatio_PWM_16Bit_Func(__PeriNum) \
  DECL_FUNC(, void, Set_DutyRatio_PWM##__PeriNum, HELPER_PARAM_VAR(unsigned char Channel, double DutyRatio)) \
  Set_DutyRatio_PWM##__PeriNum##_D(Channel, DutyRatio)

#define Set_DutyRatio_PWM_Func(__PeriNum, __PeriBit) \
  Set_DutyRatio_PWM_##__PeriBit##Bit_Func(__PeriNum)

// T/C 0(8 bit)
#if defined(TCCR0) || defined(TCCR0A)
Set_DutyRatio_PWM_Func(0, 8)
#endif

// T/C 1(16 bit)
#if defined(TCCR1A)
Set_DutyRatio_PWM_Func(1, 16)
#endif

// T/C 2(8 bit)
#if defined(TCCR2) || defined(TCCR2A)
Set_DutyRatio_PWM_Func(2, 8)
#endif

// T/C 3(16 bit)
#if defined(TCCR3A)
Set_DutyRatio_PWM_Func(3, 16)
#endif

// T/C 4(16 bit)
#if defined(TCCR4A)
Set_DutyRatio_PWM_Func(3, 16)
#endif

// T/C 5(16 bit)
#if defined(TCCR5A)
Set_DutyRatio_PWM_Func(3, 16)
#endif