/*********************************************************************

          File: ExtInt.h

   Description: AVR External Interrupt Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/05/10

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _ExtInt_h_
#define _ExtInt_h_

#include "ExtInt.def.h"

#define DECL_FUNC_SETTINGS_EXTINT(__Num) \
  DECL_FUNC(, void, Set_InterruptSenseCont_ExtInt##__Num, uint8_t Value); \
  DECL_FUNC(, void, Set_InterruptEnable_ExtInt##__Num, bool Enable); \
  DECL_FUNC(, void, Set_InterruptFlag_ExtInt##__Num, bool Enable);


#define DECL_FUNCP_INVOKE_EXTINT_BASIC(__IntName, __PeriNum) \
  DECL_FUNC(static, void, *(*__IntName##Func_ExtInt##__PeriNum), void);

#define DECL_FUNC_SET_FUNCP_EXTINT_BASIC(__IntName, __PeriNum) \
  DECL_FUNC(, void, Set_##__IntName##InvokeFunc_ExtInt##__PeriNum, void *(*__IntName##InvokeFunc_ExtInt##__PeriNum)());

#if defined(INT0)
DECL_FUNC_SETTINGS_EXTINT(0)
DECL_FUNCP_INVOKE_EXTINT_BASIC(ExternalInterrupt, 0)
DECL_FUNC_SET_FUNCP_EXTINT_BASIC(ExternalInterrupt, 0)
#endif

#if defined(INT1)
DECL_FUNC_SETTINGS_EXTINT(1)
DECL_FUNCP_INVOKE_EXTINT_BASIC(ExternalInterrupt, 1)
DECL_FUNC_SET_FUNCP_EXTINT_BASIC(ExternalInterrupt, 1)
#endif

#if defined(INT2)
DECL_FUNC_SETTINGS_EXTINT(2)
DECL_FUNCP_INVOKE_EXTINT_BASIC(ExternalInterrupt, 2)
DECL_FUNC_SET_FUNCP_EXTINT_BASIC(ExternalInterrupt, 2)
#endif

#if defined(INT3)
DECL_FUNC_SETTINGS_EXTINT(3)
DECL_FUNCP_INVOKE_EXTINT_BASIC(ExternalInterrupt, 3)
DECL_FUNC_SET_FUNCP_EXTINT_BASIC(ExternalInterrupt, 3)
#endif

#if defined(INT4)
DECL_FUNC_SETTINGS_EXTINT(4)
DECL_FUNCP_INVOKE_EXTINT_BASIC(ExternalInterrupt, 4)
DECL_FUNC_SET_FUNCP_EXTINT_BASIC(ExternalInterrupt, 4)
#endif

#if defined(INT5)
DECL_FUNC_SETTINGS_EXTINT(5)
DECL_FUNCP_INVOKE_EXTINT_BASIC(ExternalInterrupt, 5)
DECL_FUNC_SET_FUNCP_EXTINT_BASIC(ExternalInterrupt, 5)
#endif

#if defined(INT6)
DECL_FUNC_SETTINGS_EXTINT(6)
DECL_FUNCP_INVOKE_EXTINT_BASIC(ExternalInterrupt, 6)
DECL_FUNC_SET_FUNCP_EXTINT_BASIC(ExternalInterrupt, 6)
#endif

#if defined(INT7)
DECL_FUNC_SETTINGS_EXTINT(7)
DECL_FUNCP_INVOKE_EXTINT_BASIC(ExternalInterrupt, 7)
DECL_FUNC_SET_FUNCP_EXTINT_BASIC(ExternalInterrupt, 7)
#endif



#endif // _ExtInt_h_
