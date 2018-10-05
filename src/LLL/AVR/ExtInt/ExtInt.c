/*********************************************************************

          File: ExtInt.h

   Description: AVR External Interrupt Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/05/10

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "ExtInt.h"

#define Set_InterruptSenseCont_ExtInt_Func(__PeriNum) \
  DECL_FUNC(, void, Set_InterruptSenseCont_ExtInt##__PeriNum, uint8_t Value) \
  Set_InterruptSenseCont_ExtInt##__PeriNum##_D(Value)

#define Set_InterruptEnable_ExtInt_Func(__PeriNum) \
  DECL_FUNC(, void, Set_InterruptEnable_ExtInt##__PeriNum, bool Enable) \
  Set_InterruptEnable_ExtInt##__PeriNum##_D(Enable)

#define Set_InterruptFlag_ExtInt_Func(__PeriNum) \
  DECL_FUNC(, void, Set_InterruptFlag_ExtInt##__PeriNum, bool Enable) \
  Set_InterruptFlag_ExtInt##__PeriNum##_D(Enable)

#if defined(INT0)
Set_InterruptSenseCont_ExtInt_Func(0)
Set_InterruptEnable_ExtInt_Func(0)
Set_InterruptFlag_ExtInt_Func(0)
#endif

#if defined(INT1)
Set_InterruptSenseCont_ExtInt_Func(1)
Set_InterruptEnable_ExtInt_Func(1)
Set_InterruptFlag_ExtInt_Func(1)
#endif

#if defined(INT2)
Set_InterruptSenseCont_ExtInt_Func(2)
Set_InterruptEnable_ExtInt_Func(2)
Set_InterruptFlag_ExtInt_Func(2)
#endif

#if defined(INT3)
Set_InterruptSenseCont_ExtInt_Func(3)
Set_InterruptEnable_ExtInt_Func(3)
Set_InterruptFlag_ExtInt_Func(3)
#endif

#if defined(INT4)
Set_InterruptSenseCont_ExtInt_Func(4)
Set_InterruptEnable_ExtInt_Func(4)
Set_InterruptFlag_ExtInt_Func(4)
#endif

#if defined(INT5)
Set_InterruptSenseCont_ExtInt_Func(5)
Set_InterruptEnable_ExtInt_Func(5)
Set_InterruptFlag_ExtInt_Func(5)
#endif

#if defined(INT6)
Set_InterruptSenseCont_ExtInt_Func(6)
Set_InterruptEnable_ExtInt_Func(6)
Set_InterruptFlag_ExtInt_Func(6)
#endif

#if defined(INT7)
Set_InterruptSenseCont_ExtInt_Func(7)
Set_InterruptEnable_ExtInt_Func(7)
Set_InterruptFlag_ExtInt_Func(7)
#endif

#define IMPL_SET_FUNCP(__Type, __FuncName, __DestValue) \
  IMPL_FUNC(, void, Set_##__FuncName, __Type *(*__TxV)(), \
    __DestValue = __TxV; \
  )

#define Set_AnyInterruptInvokeFunc_ExtInt(__IntName, __PeriNum) \
  IMPL_SET_FUNCP(void, __IntName##InvokeFunc_ExtInt##__PeriNum, __IntName##Func_ExtInt##__PeriNum)

#if defined(INT0)
Set_AnyInterruptInvokeFunc_ExtInt(ExternalInterrupt, 0)
#endif

#if defined(INT1)
Set_AnyInterruptInvokeFunc_ExtInt(ExternalInterrupt, 1)
#endif

#if defined(INT2)
Set_AnyInterruptInvokeFunc_ExtInt(ExternalInterrupt, 2)
#endif

#if defined(INT3)
Set_AnyInterruptInvokeFunc_ExtInt(ExternalInterrupt, 3)
#endif

#if defined(INT4)
Set_AnyInterruptInvokeFunc_ExtInt(ExternalInterrupt, 4)
#endif

#if defined(INT5)
Set_AnyInterruptInvokeFunc_ExtInt(ExternalInterrupt, 5)
#endif

#if defined(INT6)
Set_AnyInterruptInvokeFunc_ExtInt(ExternalInterrupt, 6)
#endif

#if defined(INT7)
Set_AnyInterruptInvokeFunc_ExtInt(ExternalInterrupt, 7)
#endif

#define DECL_ISR_FUNC_ExtIntn_vect(__PeriNum) \
  ISR(INT##__PeriNum##_vect)

#define IMPL_ISR_FUNC_ExtIntn_vect(__PeriNum) \
  DECL_ISR_FUNC_ExtIntn_vect(__PeriNum) \
  IMPL_FUNC_CONTENTS( \
    ExternalInterruptFunc_ExtInt##__PeriNum(); \
  )
  /*
  IMPL_FUNC_CONTENTS( \
    cli(); \
    ExternalInterruptFunc_ExtInt##__PeriNum(); \
    sei(); \
  )
  */

#if defined(INT0)
IMPL_ISR_FUNC_ExtIntn_vect(0)
#endif

#if defined(INT1)
IMPL_ISR_FUNC_ExtIntn_vect(1)
#endif

#if defined(INT2)
IMPL_ISR_FUNC_ExtIntn_vect(2)
#endif

#if defined(INT3)
IMPL_ISR_FUNC_ExtIntn_vect(3)
#endif

#if defined(INT4)
IMPL_ISR_FUNC_ExtIntn_vect(4)
#endif

#if defined(INT5)
IMPL_ISR_FUNC_ExtIntn_vect(5)
#endif

#if defined(INT6)
IMPL_ISR_FUNC_ExtIntn_vect(6)
#endif

#if defined(INT7)
IMPL_ISR_FUNC_ExtIntn_vect(7)
#endif