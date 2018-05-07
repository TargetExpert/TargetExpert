/*********************************************************************

          File: TC_Basic.h

   Description: AVR Timer/Counter basic func. Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/13

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_Basic_h_
#define _TC_Basic_h_

#include "TC_Basic.def.h"

#include "TimeConv.h"

/*
 * List of 8/16 bit Timer/Counter function flag setting Functions.
 *
 * Qty : 8
 *
 * void Set_WGMode_TCn(uint8_t Mode);
 * void Set_ClockSelect_TCn(uint8_t ClockSel);
 * void Set_COMode_TCn(uint8_t Mode, uint8_t Channel);
 * void Set_FOCompare_TCn(bool Enable, uint8_t Channel);
 * void Set_TOInterruptEnable_TCn(bool Enable);
 * void Set_TOverflow_TCn(bool Enable);
 * void Set_OCIEnable_TCn(bool Enable, uint8_t Channel);
 * void Set_OCompare_TCn(bool Enable, uint8_t Channel);
 */

#define DECL_FUNC_SETTINGS_TC_BASIC_8_16(__PeriNum) \
  DECL_FUNC(, void, Set_WGMode_TC##__PeriNum, uint8_t Mode); \
  DECL_FUNC(, void, Set_ClockSelect_TC##__PeriNum, uint8_t ClockSel); \
  DECL_FUNC(, void, Set_COMode_TC##__PeriNum, HELPER_PARAM_VAR(uint8_t Mode, uint8_t Channel)); \
  DECL_FUNC(, void, Set_FOCompare_TC##__PeriNum, HELPER_PARAM_VAR(bool Enable, uint8_t Channel)); \
  DECL_FUNC(, void, Set_TOInterruptEnable_TC##__PeriNum, bool Enable); \
  DECL_FUNC(, void, Set_TOverflow_TC##__PeriNum, bool Enable); \
  DECL_FUNC(, void, Set_OCIEnable_TC##__PeriNum, HELPER_PARAM_VAR(bool Enable, uint8_t Channel)); \
  DECL_FUNC(, void, Set_OCompare_TC##__PeriNum, HELPER_PARAM_VAR(bool Enable, uint8_t Channel));

/*
 * List of 16 bit Timer/Counter function flag setting Functions.
 *
 * Qty : 4
 *
 * void Set_ICNCanceler_TCn(bool Enable); //
 * void Set_ICESelect_TCn(bool Enable); //
 * void Set_ICIEnable_TCn(bool Enable); //
 * void Set_ICapture_TCn(bool Enable); //
 */

#define DECL_FUNC_SETTINGS_TC_BASIC_16(__PeriNum) \
  DECL_FUNC(, void, Set_ICNCanceler_TC##__PeriNum, bool Enable); \
  DECL_FUNC(, void, Set_ICESelect_TC##__PeriNum, bool Enable); \
  DECL_FUNC(, void, Set_ICIEnable_TC##__PeriNum, bool Enable); \
  DECL_FUNC(, void, Set_ICapture_TC##__PeriNum, bool Enable);

/*
 * List of 8/16 bit Timer/Counter Control Register setting Functions.
 *
 * Qty : 2
 *
 * void Set_TCReg_TCn(unsigned int Value);
 * void Set_OCompareReg_TCn(uint16_t Value, uint8_t Channel);
 */

#define DECL_FUNC_REGISTER_TC_BASIC_8_16(__PeriNum) \
  DECL_FUNC(, void, Set_TCReg_TC##__PeriNum, uint16_t Value); \
  DECL_FUNC(, void, Set_OCompareReg_TC##__PeriNum, HELPER_PARAM_VAR(uint16_t Value, uint8_t Channel));

/*
 * List of 16 bit Timer/Counter Control Register setting Functions.
 *
 * Qty : 1
 *
 * void Set_CaptureReg_TCn(uint16_t Value);
 */

#define DECL_FUNC_REGISTER_TC_BASIC_16(__PeriNum) \
  DECL_FUNC(, void, Set_ICaptureReg_TC##__PeriNum, uint16_t Value);

/*
 * List of Interrupt invoking Functions.
 *
 * Target :
 * 1. Output Compare Match
 * 2. Overflow Interrupt
 * 3. Input Capture Interrupt(only 16 bit Timer/Counter)
 *
 * Type Qty : 1
 *
 * static void *(*OCMatchInterruptFunc_TCnx)();
 */

#define DECL_FUNCP_INVOKE_TC_BASIC(__IntName, __PeriNum, __Channel) \
  DECL_FUNC(static, void, *(*__IntName##Func_TC##__PeriNum##__Channel), void);

/*
 * List of Timer/Counter n(x) setting for Function pointer.
 *
 * x is channel.
 *
 * Target :
 * 1. Output Compare Match
 * 2. Overflow Interrupt
 * 3. Input Capture Interrupt(only 16 bit Timer/Counter)
 *
 * Type Qty : 1
 *
 * void Set_(##Interrupt Name##)InvokeFunc_TCn(##x##)(void *(*(##Interrupt Name##)InvokeFunc_TCn(##x##))());
 */

#define DECL_FUNC_SET_FUNCP_TC_BASIC(__IntName, __PeriNum, __Channel) \
  DECL_FUNC(, void, Set_##__IntName##InvokeFunc_TC##__PeriNum##__Channel, void *(*__IntName##InvokeFunc_TC##__PeriNum##__Channel)());

/*
 * Declarations for uses methods.
 */

#if defined(TCCR0) || defined(TCCR0A)
DECL_FUNC_SETTINGS_TC_BASIC_8_16(0)
DECL_FUNC_REGISTER_TC_BASIC_8_16(0)

#if defined(TIMSK0)
// Output Compare Match Interrupt invoker for 328
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 0, A)
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 0, B)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 0, A)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 0, B)
#else
// Output Compare Match Interrupt invoker for 128
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 0, )
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 0, )
#endif

#if defined(TOIE0)
// for Timer n Overflow Interrupt invoker
DECL_FUNCP_INVOKE_TC_BASIC(TOInterrupt, 0, )
DECL_FUNC_SET_FUNCP_TC_BASIC(TOInterrupt, 0, )
#endif

#endif

#if defined(TCCR1A)
DECL_FUNC_SETTINGS_TC_BASIC_8_16(1)
DECL_FUNC_SETTINGS_TC_BASIC_16(1)
DECL_FUNC_REGISTER_TC_BASIC_8_16(1)
DECL_FUNC_REGISTER_TC_BASIC_16(1)

#if defined(TIMSK1)
// Output Compare Match Interrupt invoker for 328
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 1, A)
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 1, B)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 1, A)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 1, B)
#else
// Output Compare Match Interrupt invoker for 128
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 1, A)
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 1, B)
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 1, C)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 1, A)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 1, B)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 1, C)
#endif

#if defined(TOIE1)
// for Timer n Overflow Interrupt invoker
DECL_FUNCP_INVOKE_TC_BASIC(TOInterrupt, 1, )
DECL_FUNC_SET_FUNCP_TC_BASIC(TOInterrupt, 1, )
#endif

#if defined(ICIE1) || defined(TICIE1)
DECL_FUNCP_INVOKE_TC_BASIC(ICInterrupt, 1,)
DECL_FUNC_SET_FUNCP_TC_BASIC(ICInterrupt, 1, )
#endif

#endif

#if defined(TCCR2) || defined(TCCR2A)
DECL_FUNC_SETTINGS_TC_BASIC_8_16(2)
DECL_FUNC_REGISTER_TC_BASIC_8_16(2)

#if defined(TIMSK2)
// Output Compare Match Interrupt invoker for 328
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 2, A)
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 2, B)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 2, A)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 2, B)
#else
// Output Compare Match Interrupt invoker for 128
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 2, )
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 2, )
#endif

#if defined(TOIE2)
// for Timer n Overflow Interrupt invoker
DECL_FUNCP_INVOKE_TC_BASIC(TOInterrupt, 2, )
DECL_FUNC_SET_FUNCP_TC_BASIC(TOInterrupt, 2, )
#endif
#endif

#if defined(TCCR3A)
DECL_FUNC_SETTINGS_TC_BASIC_8_16(3)
DECL_FUNC_SETTINGS_TC_BASIC_16(3)
DECL_FUNC_REGISTER_TC_BASIC_8_16(3)
DECL_FUNC_REGISTER_TC_BASIC_16(3)

#if defined(ETIMSK)
// Output Compare Match Interrupt invoker for 128
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 3, A)
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 3, B)
DECL_FUNCP_INVOKE_TC_BASIC(OCMatchInterrupt, 3, C)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 3, A)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 3, B)
DECL_FUNC_SET_FUNCP_TC_BASIC(OCMatchInterrupt, 3, C)
#endif

#if defined(TOIE3)
// for Timer n Overflow Interrupt invoker
DECL_FUNCP_INVOKE_TC_BASIC(TOInterrupt, 3, )
DECL_FUNC_SET_FUNCP_TC_BASIC(TOInterrupt, 3, )
#endif

#if defined(TICIE3)
DECL_FUNCP_INVOKE_TC_BASIC(ICInterrupt, 3, )
DECL_FUNC_SET_FUNCP_TC_BASIC(ICInterrupt, 3, )
#endif
#endif

#endif // _TC_Basic_h_
