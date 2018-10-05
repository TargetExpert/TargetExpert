/*********************************************************************

          File: TC_ext.h

   Description: AVR TC extended Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/13

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_Ext_h_
#define _TC_Ext_h_

#include "TC_Ext.def.h"

#define DECL_FUNC_SETTINGS_TC_EXT_8_16(__PeriNum) \
  DECL_FUNC(, void, Set_ToggledOut_TC##__PeriNum, bool Enable); \
  DECL_FUNC(, void, Set_InvertOut_TC##__PeriNum, HELPER_PARAM_VAR(bool Enable, uint8_t Channel)); \
  DECL_FUNC(, void, Set_DiffMarginFreqValue_TC##__PeriNum, double DiffMarginFreqValue); \
  DECL_FUNC(, bool, Set_Period_TC##__PeriNum, HELPER_PARAM_VAR(double Period, uint8_t Mode)); \
  DECL_FUNC(, bool, Set_PeriodForAutoMode_TC##__PeriNum, double Period); \


#define DECL_FUNC_SETTINGS_ICF_16_PWM(__PeriNum) \
  DECL_FUNC(, void, Set_ICFTop_TC##__PeriNum, bool Enable);

#if defined(TCCR0) || defined(TCCR0A)
DECL_FUNC_SETTINGS_TC_EXT_8_16(0)
#endif

#if defined(TCCR1A)
DECL_FUNC_SETTINGS_TC_EXT_8_16(1)
#if defined(ICR1)
DECL_FUNC_SETTINGS_ICF_16_PWM(1)
#endif
#endif

#if defined(TCCR2) || defined(TCCR2A)
DECL_FUNC_SETTINGS_TC_EXT_8_16(2)
#endif

#if defined(TCCR3A)
DECL_FUNC_SETTINGS_TC_EXT_8_16(3)
#if defined(ICR3)
DECL_FUNC_SETTINGS_ICF_16_PWM(3)
#endif
#endif

#if defined(TCCR4A)
DECL_FUNC_SETTINGS_TC_EXT_8_16(4)
#if defined(ICR4)
DECL_FUNC_SETTINGS_ICF_16_PWM(4)
#endif
#endif

#if defined(TCCR5A)
DECL_FUNC_SETTINGS_TC_EXT_8_16(5)
#if defined(ICR5)
DECL_FUNC_SETTINGS_ICF_16_PWM(5)
#endif
#endif  

#endif // _TC_Ext_h_
