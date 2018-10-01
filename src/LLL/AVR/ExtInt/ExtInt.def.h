/*********************************************************************

          File: ExtInt.def.h

   Description: AVR External Interrupt syntax definition
                Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/05/10

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _ExtInt_def_h_
#define _ExtInt_def_h_

#pragma __FunCX_Section Begin

#include "Common.inc.h"

#pragma __FunCX_InLevel_Except Begin

#define AVR_MODE_BIT(__Num) __Num

#define ISCn_BQTY AVR_MODE_BIT(2)
#define INT_BQTY AVR_MODE_BIT(2)
#define INTF_BQTY AVR_MODE_BIT(2)

#pragma __FunCX_InLevel_Except End

// Set_InterruptSenseCont_ExtInt(n) Definition
#pragma __FunCX_InLevel_Except Begin
#if defined(INT4)
#define Set_InterruptSenseCont_ExtInt_D_Common(__PeriNum, __Value) \
  (__PeriNum > 3) ? \
    (sclb_reg_common(EICR, , B, (__Value & (1 << i)), ISC, __PeriNum, 0 + i)) \
    : (sclb_reg_common(EICR, , A, (__Value & (1 << i)), ISC, __PeriNum, 0 + i));
#else
#define Set_InterruptSenseCont_ExtInt_D_Common(__PeriNum, __Value) \
  sclb_reg_common(EICR, , A, (__Value & (1 << i)), ISC, __PeriNum, 0 + i);
#endif

// Definition Prototyping.
#define Set_InterruptSenseCont_ExtInt_D_Proto(__PeriNum, __Value) \
  C_( \
    IfSafe_(__Value < pow(2, ISCn_BQTY), \
      register unsigned char i = 0; \
      ForSafe_(i = 0, i < ISCn_BQTY, i++, \
        Set_InterruptSenseCont_ExtInt_D_Common(__PeriNum, __Value) \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_InterruptEnable_ExtInt(n) Definition
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_InterruptEnable_ExtInt_D_Proto(__PeriNum, __Enable) \
  C_( \
    sclb_reg_common(EIMSK, , , __Enable, INT, __PeriNum, ); \
  )
#pragma __FunCX_InLevel_Except End

// Set_InterruptFlag_ExtInt(n) Definition
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_InterruptFlag_ExtInt_D_Proto(__PeriNum, __Enable) \
  C_( \
    sclb_reg_common(EIFR, , , __Enable, INTF, __PeriNum, ); \
  )
#pragma __FunCX_InLevel_Except End

#if defined(INT0)
#define Set_InterruptSenseCont_ExtInt0_D(Value) \
  Set_InterruptSenseCont_ExtInt_D_Proto(0, Value)
#define Set_InterruptEnable_ExtInt0_D(Enable) \
  Set_InterruptEnable_ExtInt_D_Proto(0, Enable)
#define Set_InterruptFlag_ExtInt0_D(Enable) \
  Set_InterruptFlag_ExtInt_D_Proto(0, Enable)
#endif

#if defined(INT1)
#define Set_InterruptSenseCont_ExtInt1_D(Value) \
  Set_InterruptSenseCont_ExtInt_D_Proto(1, Value)
#define Set_InterruptEnable_ExtInt1_D(Enable) \
  Set_InterruptEnable_ExtInt_D_Proto(1, Enable)
#define Set_InterruptFlag_ExtInt1_D(Enable) \
  Set_InterruptFlag_ExtInt_D_Proto(1, Enable)
#endif

#if defined(INT2)
#define Set_InterruptSenseCont_ExtInt2_D(Value) \
  Set_InterruptSenseCont_ExtInt_D_Proto(2, Value)
#define Set_InterruptEnable_ExtInt2_D(Enable) \
  Set_InterruptEnable_ExtInt_D_Proto(2, Enable)
#define Set_InterruptFlag_ExtInt2_D(Enable) \
  Set_InterruptFlag_ExtInt_D_Proto(2, Enable)
#endif

#if defined(INT3)
#define Set_InterruptSenseCont_ExtInt3_D(Value) \
  Set_InterruptSenseCont_ExtInt_D_Proto(3, Value)
#define Set_InterruptEnable_ExtInt3_D(Enable) \
  Set_InterruptEnable_ExtInt_D_Proto(3, Enable)
#define Set_InterruptFlag_ExtInt3_D(Enable) \
  Set_InterruptFlag_ExtInt_D_Proto(3, Enable)
#endif

#if defined(INT4)
#define Set_InterruptSenseCont_ExtInt4_D(Value) \
  Set_InterruptSenseCont_ExtInt_D_Proto(4, Value)
#define Set_InterruptEnable_ExtInt4_D(Enable) \
  Set_InterruptEnable_ExtInt_D_Proto(4, Enable)
#define Set_InterruptFlag_ExtInt4_D(Enable) \
  Set_InterruptFlag_ExtInt_D_Proto(4, Enable)
#endif

#if defined(INT5)
#define Set_InterruptSenseCont_ExtInt5_D(Value) \
  Set_InterruptSenseCont_ExtInt_D_Proto(5, Value)
#define Set_InterruptEnable_ExtInt5_D(Enable) \
  Set_InterruptEnable_ExtInt_D_Proto(5, Enable)
#define Set_InterruptFlag_ExtInt5_D(Enable) \
  Set_InterruptFlag_ExtInt_D_Proto(5, Enable)
#endif

#if defined(INT6)
#define Set_InterruptSenseCont_ExtInt6_D(Value) \
  Set_InterruptSenseCont_ExtInt_D_Proto(6, Value)
#define Set_InterruptEnable_ExtInt6_D(Enable) \
  Set_InterruptEnable_ExtInt_D_Proto(6, Enable)
#define Set_InterruptFlag_ExtInt6_D(Enable) \
  Set_InterruptFlag_ExtInt_D_Proto(6, Enable)
#endif

#if defined(INT7)
#define Set_InterruptSenseCont_ExtInt7_D(Value) \
  Set_InterruptSenseCont_ExtInt_D_Proto(7, Value)
#define Set_InterruptEnable_ExtInt7_D(Enable) \
  Set_InterruptEnable_ExtInt_D_Proto(7, Enable)
#define Set_InterruptFlag_ExtInt7_D(Enable) \
  Set_InterruptFlag_ExtInt_D_Proto(7, Enable)
#endif

#pragma __FunCX_Section End

#endif // _ExtInt_def_h_
