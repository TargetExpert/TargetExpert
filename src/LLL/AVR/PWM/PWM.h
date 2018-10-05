/*********************************************************************

          File: PWM.h

   Description: AVR PWM Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/01/22

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _PWM_h_
#define _PWM_h_

#include "PWM.def.h"

#if defined(TCCR0) || defined(TCCR2)
#define DECL_FUNC_SETTINGS_DUTY_8_PWM(__PeriNum) \
  DECL_FUNC(, void, Set_DutyRatio_PWM##__PeriNum, double DutyRatio);
#endif
#define DECL_FUNC_SETTINGS_DUTY_8_16_PWM(__PeriNum) \
  DECL_FUNC(, void, Set_DutyRatio_PWM##__PeriNum, HELPER_PARAM_VAR(unsigned char Channel, double DutyRatio));

#if defined(TCCR0) || defined(TCCR0A)
#if defined(TCCR0)
DECL_FUNC_SETTINGS_DUTY_8_PWM(0)
#else
DECL_FUNC_SETTINGS_DUTY_8_16_PWM(0)
#endif
#endif

#if defined(TCCR1A)
DECL_FUNC_SETTINGS_DUTY_8_16_PWM(1)
#endif

#if defined(TCCR2) || defined(TCCR2A)
#if defined(TCCR0)
DECL_FUNC_SETTINGS_DUTY_8_PWM(2)
#else
DECL_FUNC_SETTINGS_DUTY_8_16_PWM(2)
#endif
#endif

#if defined(TCCR3A)
DECL_FUNC_SETTINGS_DUTY_8_16_PWM(3)
#endif


#endif // _PWM_h_
