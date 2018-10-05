/*********************************************************************

          File: TC_Basic.c

   Description: AVR Timer/Counter basic func. Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/01/11

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "TC_Basic.h"

/*
 * Support Model.
 *
 * ATMega128(A)
 * ATMega328/P
 */

/*
 * This section is 8/16(common) bit Timer/Counter function flag setting Functions.
 */

/*
 * Waveform Generation Mode(WGMn) Function.
 *
 * Descriptions : Set for Waveform Generation Mode.
 *
 * Notes :
 * when, Timer/Counter2 is same as T/C0, and timer/Counter3 is same as T/C1.
 * See details in ATMega32* or ATMega64/128 serise full datasheets.
 * atmega328 - http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf
 * atmega128 - http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8151-8-bit-AVR-ATmega128A_Datasheet.pdf
 *
 * Return Type : void
 * Params :
 * 1. Mode - Set or unset for WGM* bit on TCCR* register.
 */

#define Set_WGMode_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_WGMode_TC##__PeriNum, uint8_t Mode) \
  Set_WGMode_TC##__PeriNum##_D(Mode)

/*
 * Clock Select(CSn).
 *
 * Descriptions : Set Clock Select for Timer/Counter n.
 *
 * Notes :
 * It's same setting & commit bit absolute address of all T/Cx register.
 *
 * Return Type : void
 * Params :
 * 1. ClockSel - Set or unset for CSn* bit on TCCR* register.
 */

#define Set_ClockSelect_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_ClockSelect_TC##__PeriNum, uint8_t ClockSel) \
  Set_ClockSelect_TC##__PeriNum##_D(ClockSel)

/*
 * Compare Match Output Mode(COMxn).
 *
 * Descriptions : Compare Output Mode for channel n.
 *
 * Return Type : void
 * Params :
 * 1. Mode - Set or unset for COMn* bit on TCCRn(or TCCRn*) register.
 *
 * 2. Channel - Which channel to set or unset.
 *              Channel is 0 : A, 1 : B, 2 : C.
 */

#define Set_COMode_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_COMode_TC##__PeriNum, HELPER_PARAM_VAR(uint8_t Mode, uint8_t Channel)) \
  Set_COMode_TC##__PeriNum##_D(Mode, Channel)

/*
 * Force Output Compare(FOCn) Function.
 *
 * Descriptions : Force Output Compare for channel n.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for FOC* bit on TCCR* register.
 *
 * 2. Channel - Which channel to set or unset.
 *              Channel is 0 : A, 1 : B, 2 : C.
 */

#define Set_FOCompare_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_FOCompare_TC##__PeriNum, HELPER_PARAM_VAR(bool Enable, uint8_t Channel)) \
  Set_COMode_TC##__PeriNum##_D(Enable, Channel)

/*
 * Timer/Counter Overflow Interrupt Enable(TOIEn) Function.
 *
 * Descriptions : Enable or Disable of Timer/Counter Overflow Interrupt Bit.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for TOIE* bit on TIMSK*(or ETIMSK on 128) register.
 */

#define Set_TOInterruptEnable_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_TOInterruptEnable_TC##__PeriNum, bool Enable) \
  Set_TOInterruptEnable_TC##__PeriNum##_D(Enable)

/*
 * Timer/Counter Overflow Flag(TOVn) Function.
 *
 * Descriptions : Enable or Disable of Timer/Counter Overflow Flag Bit.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for TOV* bit on TIFR*(or ETIFR on 128) register.
 */

#define Set_TOverflow_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_TOverflow_TC##__PeriNum, bool Enable) \
  Set_TOverflow_TC##__PeriNum##_D(Enable)

/*
 * Output Compare Match Interrupt Enable(OCIEn(x)) Function.
 *
 * Descriptions : Output Compare Match Interrupt Enable for channel n.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for OCIE* bit on TIMSKn(if ATMega128 is TIMSK or ETIMSK is n = 3) register.
 *
 * 2. Channel - Which channel to set or unset.
 *              Channel is 0 : A, 1 : B, 2 : C.
 */

#define Set_OCIEnable_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_OCIEnable_TC##__PeriNum, HELPER_PARAM_VAR(bool Enable, uint8_t Channel)) \
  Set_OCIEnable_TC##__PeriNum##_D(Enable, Channel)

/*
 * Output Compare(OCFn(x)) Function.
 *
 * Descriptions : Output Compare for channel n.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for OCF* bit on TIFRn(if ATMega128 is TIFR or ETIFR is n = 3) register.
 *
 * 2. Channel - Which channel to set or unset.
 *              Channel is 0 : A, 1 : B, 2 : C.
 */

#define Set_OCompare_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_OCompare_TC##__PeriNum, HELPER_PARAM_VAR(bool Enable, uint8_t Channel)) \
  Set_OCompare_TC##__PeriNum##_D(Enable, Channel)

// T/C 0
#if defined(TCCR0) || defined(TCCR0A)
Set_WGMode_TC_Func(0)
Set_ClockSelect_TC_Func(0)
Set_COMode_TC_Func(0)
Set_FOCompare_TC_Func(0)
Set_TOInterruptEnable_TC_Func(0)
Set_TOverflow_TC_Func(0)
Set_OCIEnable_TC_Func(0)
Set_OCompare_TC_Func(0)
#endif

// T/C 1
#if defined(TCCR1A)
Set_WGMode_TC_Func(1)
Set_ClockSelect_TC_Func(1)
Set_COMode_TC_Func(1)
Set_FOCompare_TC_Func(1)
Set_TOInterruptEnable_TC_Func(1)
Set_TOverflow_TC_Func(1)
Set_OCIEnable_TC_Func(1)
Set_OCompare_TC_Func(1)
#endif

// T/C 2
#if defined(TCCR2) || defined(TCCR2A)
Set_WGMode_TC_Func(2)
Set_ClockSelect_TC_Func(2)
Set_COMode_TC_Func(2)
Set_FOCompare_TC_Func(2)
Set_TOInterruptEnable_TC_Func(2)
Set_TOverflow_TC_Func(2)
Set_OCIEnable_TC_Func(2)
Set_OCompare_TC_Func(2)
#endif

// T/C 3
#if defined(TCCR3A)
Set_WGMode_TC_Func(3)
Set_ClockSelect_TC_Func(3)
Set_COMode_TC_Func(3)
Set_FOCompare_TC_Func(3)
Set_TOInterruptEnable_TC_Func(3)
Set_TOverflow_TC_Func(3)
Set_OCIEnable_TC_Func(3)
Set_OCompare_TC_Func(3)
#endif


/*
 * This section is only 16 bit Timer/Counter function flag setting Functions.
 */

/*
 * Input Capture Noise Canceler(ICNCn) Function.
 *
 * Descriptions : Enable or Disable of Input Capture Noise Canceler Bit.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for ICNCn bit on TCCRnB(n is odd) register.
 */

#define Set_ICNCanceler_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_ICNCanceler_TC##__PeriNum, bool Enable) \
  Set_ICNCanceler_TC##__PeriNum##_D(Enable)

/*
 * Input Capture Edge Select(ICESn) Function.
 *
 * Descriptions : Enable or Disable of Input Capture Edge Select Bit.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for ICESn bit on TCCRnB(n is odd) register.
 */

#define Set_ICESelect_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_ICESelect_TC##__PeriNum, bool Enable) \
  Set_ICESelect_TC##__PeriNum##_D(Enable)

/*
 * Input Capture Interrupt Enable(ICIEn or TICIEn) Function.
 *
 * Descriptions : Enable or Disable of Input Capture Interrupt Enable Bit.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for ICIEn bit on TIMSKn(n is odd, or ETIMSK in 128) register.
 */

#define Set_ICIEnable_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_ICIEnable_TC##__PeriNum, bool Enable) \
  Set_ICIEnable_TC##__PeriNum##_D(Enable)

/*
 * Input Capture Flag(ICFn) Function.
 *
 * Descriptions : Enable or Disable of Input Capture Flag Bit.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for ICFn bit on TIFRn(n is odd, TIFR and ETIFR in 128) register.
 */

#define Set_ICapture_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_ICapture_TC##__PeriNum, bool Enable) \
  Set_ICapture_TC##__PeriNum##_D(Enable)

// T/C 1
#if defined(TCCR1B)
Set_ICNCanceler_TC_Func(1)
Set_ICESelect_TC_Func(1)
Set_ICIEnable_TC_Func(1)
Set_ICapture_TC_Func(1)
#endif

// T/C 3
#if defined(TCCR3B)
Set_ICNCanceler_TC_Func(3)
Set_ICESelect_TC_Func(3)
Set_ICIEnable_TC_Func(3)
Set_ICapture_TC_Func(3)
#endif

/*
 * This section is 8/16(common) bit Timer/Counter Control Register setting Functions.
 */

/*
 * Timer/Counter Register Setting Function.
 *
 * Descriptions : Set value to TCNTnL and TCNTnH(or TCNTn).
 *
 * Return Type : void
 * Params :
 * 1. Value - Input your wish value.
 */

#define Set_TCReg_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_TCReg_TC##__PeriNum, uint16_t Value) \
  Set_TCReg_TC##__PeriNum##_D(Value)

/*
 * Output Compare Register(OCRn(x)(b)) Setting Function.
 *
 * Descriptions : Output Compare value setting to OCR* register for channel n.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set value to OCRn(x)(b) register.
 *
 * 2. Channel - Which channel to set.
 *              Channel is 0 : A, 1 : B, 2 : C.
 */

#define Set_OCompareReg_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_OCompareReg_TC##__PeriNum, HELPER_PARAM_VAR(uint16_t Value, uint8_t Channel)) \
  Set_OCompareReg_TC##__PeriNum##_D(Value, Channel)

// T/C 0
#if defined(TCCR0) || defined(TCCR0A)
Set_TCReg_TC_Func(0)
Set_OCompareReg_TC_Func(0)
#endif

// T/C 1
#if defined(TCCR1A)
Set_TCReg_TC_Func(1)
Set_OCompareReg_TC_Func(1)
#endif

// T/C 2
#if defined(TCCR2) || defined(TCCR2A)
Set_TCReg_TC_Func(2)
Set_OCompareReg_TC_Func(2)
#endif

// T/C 3
#if defined(TCCR3A)
Set_TCReg_TC_Func(3)
Set_OCompareReg_TC_Func(3)
#endif

/*
 * This section is only 16 bit Timer/Counter Control Register setting Functions.
 */

/*
 * Input Capture Register Setting Function.
 *
 * Descriptions : Set value to ICRnL and ICRnH.
 *
 * Return Type : void
 * Params :
 * 1. Value - Input your wish value.
 */

#define Set_ICaptureReg_TC_Func(__PeriNum) \
  DECL_FUNC(, void, Set_ICaptureReg_TC##__PeriNum, uint16_t Value) \
  Set_ICaptureReg_TC##__PeriNum##_D(Value)

// T/C 1
#if defined(TCCR1B)
Set_ICaptureReg_TC_Func(1)
#endif

// T/C 3
#if defined(TCCR3B)
Set_ICaptureReg_TC_Func(3)
#endif

/*
 * This section is Timer/Counter n setting for Function pointer
 * Invoking(Interrupt Invoker) Functions.
 */

#define IMPL_SET_FUNCP(__Type, __FuncName, __DestValue) \
  IMPL_FUNC(, void, Set_##__FuncName, __Type *(*__TxV)(), \
    __DestValue = __TxV; \
  )

#define Set_AnyInterruptInvokeFunc_TC(__IntName, __PeriNum, __Channel) \
  IMPL_SET_FUNCP(void, __IntName##InvokeFunc_TC##__PeriNum##__Channel, __IntName##Func_TC##__PeriNum##__Channel)

// T/C 0
#if defined(TCCR0) || defined(TCCR0A)
#if defined(TIMSK0)
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 0, A)
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 0, B)
#else
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 0, )
#endif

#if defined(TOIE0)
Set_AnyInterruptInvokeFunc_TC(TOInterrupt, 0, )
#endif
#endif

// T/C 1
#if defined(TCCR1A)
#if defined(TIMSK1)
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 1, A)
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 1, B)
#else
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 1, A)
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 1, B)
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 1, C)
#endif

#if defined(TOIE1)
Set_AnyInterruptInvokeFunc_TC(TOInterrupt, 1, )
#endif

#if defined(ICIE1) || defined(TICIE1)
Set_AnyInterruptInvokeFunc_TC(ICInterrupt, 1, )
#endif
#endif

// T/C 2
#if defined(TCCR2) || defined(TCCR2A)
#if defined(TIMSK2)
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 2, A)
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 2, B)
#else
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 2, )
#endif

#if defined(TOIE2)
Set_AnyInterruptInvokeFunc_TC(TOInterrupt, 2, )
#endif
#endif

// T/C 3
#if defined(TCCR3A)
#if defined(ETIMSK)
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 3, A)
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 3, B)
Set_AnyInterruptInvokeFunc_TC(OCMatchInterrupt, 3, C)
#endif

#if defined(TOIE3)
Set_AnyInterruptInvokeFunc_TC(TOInterrupt, 3, )
#endif

#if defined(TICIE3)
Set_AnyInterruptInvokeFunc_TC(ICInterrupt, 3, )
#endif
#endif

/*
 * List of ISR to 8/16 bit Timer/Counter.
 *
 * // Timer/Counter(*) - ATMega328P
 *
 * 14. TIMER0_COMPA_vect // Timer/Counter0 Compare Match A // Complete
 * 15. TIMER0_COMPB_vect // Timer/Counter0 Compare Match B // Complete
 * 16. TIMER0_OVF_vect // Timer/Couner0 Overflow // Complete
 *
 * 10. TIMER1_CAPT_vect // Timer/Counter1 Capture Event // Complete
 * 11. TIMER1_COMPA_vect // Timer/Counter1 Compare Match A // Complete
 * 12. TIMER1_COMPB_vect // Timer/Counter1 Compare Match B // Complete
 * 13. TIMER1_OVF_vect // Timer/Counter1 Overflow // Complete
 *
 * 7. TIMER2_COMPA_vect // Timer/Counter2 Compare Match A // Complete
 * 8. TIMER2_COMPB_vect // Timer/Counter2 Compare Match B // Complete
 * 9. TIMER2_OVF_vect // Timer/Counter2 Overflow // Complete
 *
 * // Timer/Counter(*) - ATMega128
 *
 * 15. TIMER0_COMP_vect // Timer/Counter0 Compare Match // Complete
 * 16. TIMER0_OVF_vect // Timer/Counter0 Overflow // Complete
 *
 * 11. TIMER1_CAPT_vect // Timer/Counter1 Capture Event // Complete
 * 12. TIMER1_COMPA_vect // Timer/Counter1 Compare Match A // Complete
 * 13. TIMER1_COMPB_vect // Timer/Counter1 Compare Match B // Complete
 * 24. TIMER1_COMPC_vect // Timer/Counter1 Compare Match C // Complete
 * 14. TIMER1_OVF_vect // Timer/Counter1 Overflow // Complete
 *
 * 9. TIMER2_COMP_vect // Timer/Counter2 Compare Match // Complete
 * 10. TIMER2_OVF_vect // Timer/Counter2 Overflow // Complete
 *
 * 25. TIMER3_CAPT_vect // Timer/Counter3 Capture Event // Complete
 * 26. TIMER3_COMPA_vect // Timer/Counter3 Compare Match A // Complete
 * 27. TIMER3_COMPB_vect // Timer/Counter3 Compare Match B // Complete
 * 28. TIMER3_COMPC_vect // Timer/Counter3 Compare Match C // Complete
 * 29. TIMER3_OVF_vect // Timer/Counter3 Overflow // Complete
 *
 */

/*
 * This section is ISR Functions of Timer/Counter(n) Output Compare Match Interrupt(only Internal, Interrupts).
 */

// Multi Channel(or Single)
#define DECL_ISR_FUNC_TCn_COMPx_vect(__PeriNum, __Channel) \
  ISR(TIMER##__PeriNum##_COMP##__Channel##_vect)

#define IMPL_ISR_FUNC_TCn_COMPx_vect(__PeriNum, __Channel) \
  DECL_ISR_FUNC_TCn_COMPx_vect(__PeriNum, __Channel) \
  IMPL_FUNC_CONTENTS( \
    cli(); \
    OCMatchInterruptFunc_TC##__PeriNum##__Channel(); \
    sei(); \
  )

// T/C 0
#if defined(TIMSK0)
// for 328 T/C 0
IMPL_ISR_FUNC_TCn_COMPx_vect(0, A)
IMPL_ISR_FUNC_TCn_COMPx_vect(0, B)
#else
// for 128 T/C 0
IMPL_ISR_FUNC_TCn_COMPx_vect(0, )
#endif

// T/C 1
#if defined(TIMSK1)
// for 328 T/C 1
IMPL_ISR_FUNC_TCn_COMPx_vect(1, A)
IMPL_ISR_FUNC_TCn_COMPx_vect(1, B)
#else
// for 128 or others T/C 1
IMPL_ISR_FUNC_TCn_COMPx_vect(1, A)
IMPL_ISR_FUNC_TCn_COMPx_vect(1, B)
IMPL_ISR_FUNC_TCn_COMPx_vect(1, C)
#endif

// T/C 2
#if defined(TIMSK2)
// for 328 T/C 2
IMPL_ISR_FUNC_TCn_COMPx_vect(2, A)
IMPL_ISR_FUNC_TCn_COMPx_vect(2, B)
#else
// for 128 or others T/C 2
IMPL_ISR_FUNC_TCn_COMPx_vect(2, )
#endif

// T/C 3
#if defined(ETIMSK)
// for 128 or others T/C 3
IMPL_ISR_FUNC_TCn_COMPx_vect(3, A)
IMPL_ISR_FUNC_TCn_COMPx_vect(3, B)
IMPL_ISR_FUNC_TCn_COMPx_vect(3, C)
#endif

#include "USART.h"

// ISR of Timer/Counter(n) Overflow Interrupt

#define DECL_ISR_FUNC_TCn_OVF_vect(__PeriNum) \
  ISR(TIMER##__PeriNum##_OVF_vect)

#define IMPL_ISR_FUNC_TCn_OVF_vect(__PeriNum) \
  DECL_ISR_FUNC_TCn_OVF_vect(__PeriNum) \
  C_( \
    cli(); \
    TCFreqOptiValueStoreage _TTCOVInfo = Get_TCOVInfo(__PeriNum); \
    Set_TCReg_TC##__PeriNum(_TTCOVInfo.TCCalcValInfo.TCnt); \
    TOInterruptFunc_TC##__PeriNum(); \
    sei(); \
  )

// T/C 0
#if defined(TOIE0)
IMPL_ISR_FUNC_TCn_OVF_vect(0)
#endif

// T/C 1
#if defined(TOIE1)
IMPL_ISR_FUNC_TCn_OVF_vect(1)
#endif

// T/C 2
#if defined(TOIE2)
// for 328 T/C 2
IMPL_ISR_FUNC_TCn_OVF_vect(2)
#endif

// T/C 3
#if defined(TOIE3)
IMPL_ISR_FUNC_TCn_OVF_vect(3)
#endif

// ISR of Timer/Counter(n) Input Capture Interrupt(only 16 bit Timer/Counter)

#define DECL_ISR_FUNC_TCn_CAPT_vect(__PeriNum) \
  ISR(TIMER##__PeriNum##_CAPT_vect)

#define IMPL_ISR_FUNC_TCn_CAPT_vect(__PeriNum) \
  DECL_ISR_FUNC_TCn_CAPT_vect(__PeriNum) \
  IMPL_FUNC_CONTENTS( \
    cli(); \
    ICInterruptFunc_TC##__PeriNum(); \
    sei(); \
  )

// T/C 1
#if defined(ICIE1) || defined(TICIE1)
IMPL_ISR_FUNC_TCn_CAPT_vect(1)
#endif

// T/C 3
#if defined(TICIE3)
IMPL_ISR_FUNC_TCn_CAPT_vect(3)
#endif