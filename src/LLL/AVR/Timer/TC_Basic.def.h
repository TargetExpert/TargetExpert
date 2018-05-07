/*********************************************************************

          File: TC_Basic.def.h

   Description: AVR T/C basic func. syntax definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/03/08

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_Basic_def_h_
#define _TC_Basic_def_h_

#pragma __FunCX_Section Begin

#include "TC_Basic.var.h"

// Definition of "Set" Macros.
// ** Set_WGMode_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#define Set_WGMode_TC_D_Block_OneChan(__PeriNum, __Mode) \
  sclb_reg_common(TCCR, __PeriNum, Null_Param_, (__Mode & (1 << i)), _TC, __PeriNum, _Mode[i]);

#define Set_WGMode_TC_D_Block_BiggerOneChan(__PeriNum, __Mode) \
  (i > 1) ? \
    (sclb_reg_common(TCCR, __PeriNum, B, (__Mode & (1 << i)), _TC, __PeriNum, _Mode[i])) \
    : (sclb_reg_common(TCCR, __PeriNum, A, (__Mode & (1 << i)), _TC, __PeriNum, _Mode[i]));

// for 8bit Peripherals.
#if defined(TCCR0) || defined(TCCR2)
#define Set_WGMode_TC_D_Block_8bit(__PeriNum, __Mode) \
  Set_WGMode_TC_D_Block_OneChan(__PeriNum, __Mode)
#else
#define Set_WGMode_TC_D_Block_8bit(__PeriNum, __Mode) \
  Set_WGMode_TC_D_Block_BiggerOneChan(__PeriNum, __Mode)
#endif

// for 16bit Peripheral.
#define Set_WGMode_TC_D_Block_16bit(__PeriNum, __Mode) \
  Set_WGMode_TC_D_Block_BiggerOneChan(__PeriNum, __Mode)

// Definition Prototyping.
#define Set_WGMode_TC_D_Proto(__PeriNum, __PeriBit, __Mode) \
  Begin_ \
    uint8_t _TC##__PeriNum##_Mode[WGM_BQTY_##__PeriBit##Bit] = TCWGMArr_##__PeriBit##bit(__PeriNum); \
    IfSafe_(__Mode < pow(2, WGM_BQTY_##__PeriBit##Bit), \
      register uint8_t i = 0; \
      ForSafe_(i = 0, i < WGM_BQTY_##__PeriBit##Bit, i++, \
        Set_WGMode_TC_D_Block_##__PeriBit##bit(__PeriNum, __Mode) \
      ) \
    ) \
  End_
#pragma __FunCX_InLevel_Except End

// Set_ClockSelect_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#define Set_ClockSelect_TC_D_Block_NullReg(__PeriNum, __ClockSel) \
  sclb_reg_common(TCCR, __PeriNum, Null_Param_, (__ClockSel & (1 << i)), CS, __PeriNum, 0 + i);

#define Set_ClockSelect_TC_D_Block_BReg(__PeriNum, __ClockSel) \
  sclb_reg_common(TCCR, __PeriNum, B, (__ClockSel & (1 << i)), CS, __PeriNum, 0 + i);

// for 8bit Peripherals.
#if defined(TCCR0) || defined(TCCR2)
#define Set_ClockSelect_TC_D_Block_8bit(__PeriNum, __ClockSel) \
  Set_ClockSelect_TC_D_Block_NullReg(__PeriNum, __ClockSel)
#else
#define Set_ClockSelect_TC_D_Block_8bit(__PeriNum, __ClockSel) \
  Set_ClockSelect_TC_D_Block_BReg(__PeriNum, __ClockSel)
#endif

// for 16bit Peripherals.
#define Set_ClockSelect_TC_D_Block_16bit(__PeriNum, __ClockSel) \
  Set_ClockSelect_TC_D_Block_BReg(__PeriNum, __ClockSel)

// Definition Prototyping.
#define Set_ClockSelect_TC_D_Proto(__PeriNum, __PeriBit, __ClockSel) \
  C_( \
    IfSafe_(__ClockSel < pow(2, CS_BQTY), \
      register uint8_t i = 0; \
      ForSafe_(i = 0, i < CS_BQTY, i++, \
        Set_ClockSelect_TC_D_Block_##__PeriBit##bit(__PeriNum, __ClockSel) \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_COMode_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#define Set_COMode_TC_D_Block_Common(__PeriNum, __Mode, __RegAlpha, __Channel) \
  sclb_reg_common(TCCR, __PeriNum, __RegAlpha, (__Mode & (1 << i)), COM, __PeriNum, __Channel##0 + i);

// for 8bit Peripherals.
#if defined(TCCR0) || defined(TCCR2)
#define Set_COMode_TC_D_Block_8bit_Case_ChA(__PeriNum, __Mode) \
  CaseSafe_(ChanA, \
    Set_COMode_TC_D_Block_Common(__PeriNum, __Mode, Null_Param_, ) \
  )
#else
#define Set_COMode_TC_D_Block_8bit_Case_ChA(__PeriNum, __Mode) \
  CaseSafe_(ChanA, \
    Set_COMode_TC_D_Block_Common(__PeriNum, __Mode, A, A) \
  )
#endif

#if defined(COM0B0) || defined(COM2B0)
#define Set_COMode_TC_D_Block_8bit_Case_ChB(__PeriNum, __Mode) \
  CaseSafe_(ChanB, \
    Set_COMode_TC_D_Block_Common(__PeriNum, __Mode, A, B) \
  )
#else
#define Set_COMode_TC_D_Block_8bit_Case_ChB(__PeriNum, __Mode) \
  Null_Syntax_
#endif

#define Set_COMode_TC_D_Block_8bit_Case_ChC(__PeriNum, __Mode) \
  Null_Syntax_

// for 16bit Peripherals.
#if defined(COM1A0) || defined(COM3A0) || defined(COM4A0) || defined(COM5A0)
#define Set_COMode_TC_D_Block_16bit_Case_ChA(__PeriNum, __Mode) \
  CaseSafe_(ChanA, \
    Set_COMode_TC_D_Block_Common(__PeriNum, __Mode, A, A) \
  )
#endif

#if defined(COM1B0) || defined(COM3B0) || defined(COM4B0) || defined(COM5B0)
#define Set_COMode_TC_D_Block_16bit_Case_ChB(__PeriNum, __Mode) \
  CaseSafe_(ChanB, \
    Set_COMode_TC_D_Block_Common(__PeriNum, __Mode, A, B) \
  )
#endif

#if defined(COM1C0) || defined(COM3C0) || defined(COM4C0) || defined(COM5C0)
#define Set_COMode_TC_D_Block_16bit_Case_ChC(__PeriNum, __Mode) \
  CaseSafe_(ChanC, \
    Set_COMode_TC_D_Block_Common(__PeriNum, __Mode, A, C) \
  )
#else
#define Set_COMode_TC_D_Block_16bit_Case_ChC(__PeriNum, __Mode) \
  Null_Syntax_
#endif

// Definition Prototyping.
#define Set_COMode_TC_D_Proto(__PeriNum, __PeriBit, __Mode, __Channel) \
  C_( \
    IfSafe_((__Mode < pow(2, COM_BQTY)) && (__Channel < TC_##__PeriBit##Bit_Peri_Ch_Qty), \
      register uint8_t i = 0; \
      ForSafe_(i = 0, i < COM_BQTY, i++, \
        SwitchSafe_(__Channel, \
          Set_COMode_TC_D_Block_##__PeriBit##bit_Case_ChA(__PeriNum, __Mode) \
          Set_COMode_TC_D_Block_##__PeriBit##bit_Case_ChB(__PeriNum, __Mode) \
          Set_COMode_TC_D_Block_##__PeriBit##bit_Case_ChC(__PeriNum, __Mode) \
        ) \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_FOCompare_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#define Set_FOCompare_TC_D_Block_Common(__PeriNum, __Enable, __RegAlpha, __Channel) \
  sclb_reg_common(TCCR, __PeriNum, __RegAlpha, __Enable, FOC, __PeriNum, __Channel);

// for 8bit Peripherals.
#if defined(TCCR0) || defined(TCCR2)
#define Set_FOCompare_TC_D_Block_8bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_FOCompare_TC_D_Block_Common(__PeriNum, __Enable, Null_Param_, Null_Param_) \
  )
#else
#define Set_FOCompare_TC_D_Block_8bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_FOCompare_TC_D_Block_Common(__PeriNum, __Enable, B, A) \
  )
#endif

#if defined(COM0B0) || defined(COM2B0)
#define Set_FOCompare_TC_D_Block_8bit_Case_ChB(__PeriNum, __Enable) \
  CaseSafe_(ChanB, \
    Set_FOCompare_TC_D_Block_Common(__PeriNum, __Enable, B, B) \
  )
#else
#define Set_FOCompare_TC_D_Block_8bit_Case_ChB(__PeriNum, __Enable) \
  Null_Syntax_
#endif

#define Set_FOCompare_TC_D_Block_8bit_Case_ChC(__PeriNum, __Enable) \
  Null_Syntax_

// for 16bit Peripherals.
#if defined(COM1A0) || defined(COM3A0) || defined(COM4A0) || defined(COM5A0)
#define Set_FOCompare_TC_D_Block_16bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_FOCompare_TC_D_Block_Common(__PeriNum, __Enable, C, A) \
  )
#endif

#if defined(COM1B0) || defined(COM3B0) || defined(COM4B0) || defined(COM5B0)
#define Set_FOCompare_TC_D_Block_16bit_Case_ChB(__PeriNum, __Enable) \
  CaseSafe_(ChanB, \
    Set_FOCompare_TC_D_Block_Common(__PeriNum, __Enable, C, B) \
  )
#endif

#if defined(COM1C0) || defined(COM3C0) || defined(COM4C0) || defined(COM5C0)
#define Set_FOCompare_TC_D_Block_16bit_Case_ChC(__PeriNum, __Enable) \
  CaseSafe_(ChanC, \
    Set_FOCompare_TC_D_Block_Common(__PeriNum, __Enable, C, C) \
  )
#else
#define Set_FOCompare_TC_D_Block_16bit_Case_ChC(__PeriNum, __Enable) \
  Null_Syntax_
#endif

// Definition Prototyping.
#define Set_FOCompare_TC_D_Proto(__PeriNum, __PeriBit, __Enable, __Channel) \
  C_( \
    IfSafe_(__Channel < TC_##__PeriBit##Bit_Peri_Ch_Qty, \
      SwitchSafe_(__Channel, \
        Set_FOCompare_TC_D_Block_##__PeriBit##bit_Case_ChA(__PeriNum, __Enable) \
        Set_FOCompare_TC_D_Block_##__PeriBit##bit_Case_ChB(__PeriNum, __Enable) \
        Set_FOCompare_TC_D_Block_##__PeriBit##bit_Case_ChC(__PeriNum, __Enable) \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_TOInterruptEnable_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#define Set_TOInterruptEnable_TC_D_Block_Common(__PeriNum, __Enable, __Reg, __RegPeriNum) \
  sclb_reg_common(__Reg, __RegPeriNum, Null_Param_, __Enable, TOIE, __PeriNum, Null_Param_);

// for 8bit Peripherals.
#if defined(TIMSK0) || defined(TIMSK1) || defined(TIMSK2)
#define Set_TOInterruptEnable_TC_D_Block_8bit(__PeriNum, __Enable) \
  Set_TOInterruptEnable_TC_D_Block_Common(__PeriNum, __Enable, TIMSK, __PeriNum)
#else
#define Set_TOInterruptEnable_TC_D_Block_8bit(__PeriNum, __Enable) \
  Set_TOInterruptEnable_TC_D_Block_Common(__PeriNum, __Enable, TIMSK, Null_Param_)
#endif

// for 16bit Peripherals.
#if defined(ETIMSK)
#define Set_TOInterruptEnable_TC_D_Block_16bit(__PeriNum, __Enable) \
  Set_TOInterruptEnable_TC_D_Block_Common(__PeriNum, __Enable, ETIMSK, Null_Param_)
#else
#define Set_TOInterruptEnable_TC_D_Block_16bit(__PeriNum, __Enable) \
  Set_TOInterruptEnable_TC_D_Block_Common(__PeriNum, __Enable, TIMSK, __PeriNum)
#endif

#define Set_TOInterruptEnable_TC_D_Proto(__PeriNum, __PeriBit, __Enable) \
  C_( \
    Set_TOInterruptEnable_TC_D_Block_##__PeriBit##bit(__PeriNum, __Enable) \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_TOverflow_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#define Set_TOverflow_TC_D_Block_Common(__PeriNum, __Enable, __Reg, __RegPeriNum) \
  sclb_reg_common(__Reg, __RegPeriNum, Null_Param_, __Enable, TOIE, __PeriNum, Null_Param_);

// for 8bit Peripherals.
#if defined(TIFR0) || defined(TIFR1) || defined(TIFR2)
#define Set_TOverflow_TC_D_Block_8bit(__PeriNum, __Enable) \
  Set_TOverflow_TC_D_Block_Common(__PeriNum, __Enable, TIFR, __PeriNum)
#else
#define Set_TOverflow_TC_D_Block_8bit(__PeriNum, __Enable) \
  Set_TOverflow_TC_D_Block_Common(__PeriNum, __Enable, TIFR, Null_Param_)
#endif

// for 16bit Peripherals.
#if defined(ETIFR)
#define Set_TOverflow_TC_D_Block_16bit(__PeriNum, __Enable) \
  Set_TOverflow_TC_D_Block_Common(__PeriNum, __Enable, ETIFR, Null_Param_)
#else
#define Set_TOverflow_TC_D_Block_16bit(__PeriNum, __Enable) \
  Set_TOverflow_TC_D_Block_Common(__PeriNum, __Enable, TIFR, __PeriNum)
#endif

// Definition Prototyping.
#define Set_TOverflow_TC_D_Proto(__PeriNum, __PeriBit, __Enable) \
  C_( \
    Set_TOverflow_TC_D_Block_##__PeriBit##bit(__PeriNum, __Enable) \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_OCIEnable_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#define Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, __Reg, __RegPeriNum, __Channel) \
  sclb_reg_common(__Reg, __RegPeriNum, Null_Param_, __Enable, OCIE, __PeriNum, __Channel);

// for 8bit Peripherals.
// Channel A.
#if defined(OCIE0) || defined(OCIE2)
// for Single Channels.
#define Set_OCIEnable_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, TIMSK, Null_Param_, Null_Param_) \
  )
#define Set_OCIEnable_TC_D_Block_PeriNum2_8bit_Case_ChA(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Enable)
#else
// for Multi Channels.
#define Set_OCIEnable_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, TIMSK, __PeriNum, A) \
  )
#define Set_OCIEnable_TC_D_Block_PeriNum2_8bit_Case_ChA(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Enable)
#endif

// Channel B.
#if defined(OCIE0B) || defined(OCIE2B)
#define Set_OCIEnable_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Enable) \
  CaseSafe_(ChanB, \
    Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, TIMSK, __PeriNum, B) \
  )
#define Set_OCIEnable_TC_D_Block_PeriNum2_8bit_Case_ChB(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Enable)
#else
#define Set_OCIEnable_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Enable) \
  Null_Syntax_
#define Set_OCIEnable_TC_D_Block_PeriNum2_8bit_Case_ChB(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Enable)
#endif

// Channel C(8Bit is none).
#define Set_OCIEnable_TC_D_Block_PeriNum0_8bit_Case_ChC(__PeriNum, __Enable) \
  Null_Syntax_
#define Set_OCIEnable_TC_D_Block_PeriNum2_8bit_Case_ChC(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum0_8bit_Case_ChC(__PeriNum, __Enable)

// for 16bit Peripherals.
// Channel A.
#if !defined(TIMSK)//defined(OCIE1A) || defined(OCIE3A)
#define Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, TIMSK, __PeriNum, A) \
  )
#define Set_OCIEnable_TC_D_Block_PeriNum3_16bit_Case_ChA(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Enable)
#define Set_OCIEnable_TC_D_Block_PeriNum4_16bit_Case_ChA(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Enable)
#define Set_OCIEnable_TC_D_Block_PeriNum5_16bit_Case_ChA(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Enable)
#else
#define Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, TIMSK, Null_Param_, A) \
  )
#define Set_OCIEnable_TC_D_Block_PeriNum3_16bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, ETIMSK, Null_Param_, A) \
  )
#endif

// Channel B.
#if !defined(TIMSK)//defined(OCIE1B) || defined(OCIE3B)
#define Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Enable) \
  CaseSafe_(ChanB, \
    Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, TIMSK, __PeriNum, B) \
  )
#define Set_OCIEnable_TC_D_Block_PeriNum3_16bit_Case_ChB(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Enable)
#define Set_OCIEnable_TC_D_Block_PeriNum4_16bit_Case_ChB(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Enable)
#define Set_OCIEnable_TC_D_Block_PeriNum5_16bit_Case_ChB(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Enable)
#else
#define Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Enable) \
  CaseSafe_(ChanB, \
    Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, TIMSK, Null_Param_, B) \
  )
#define Set_OCIEnable_TC_D_Block_PeriNum3_16bit_Case_ChB(__PeriNum, __Enable) \
  CaseSafe_(ChanB, \
    Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, ETIMSK, Null_Param_, B) \
  )
#endif

// Channel C.
#if defined(ETIMSK)//defined(OCIE1C) || defined(OCIE3C)
#define Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Enable) \
  CaseSafe_(ChanC, \
    Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, ETIMSK, Null_Param_, C) \
  )
#define Set_OCIEnable_TC_D_Block_PeriNum3_16bit_Case_ChC(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Enable)
#else
#define Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Enable) \
  Null_Syntax_
#define Set_OCIEnable_TC_D_Block_PeriNum3_16bit_Case_ChC(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Enable)
#endif

// Definition Prototyping.
#define Set_OCIEnable_TC_D_Proto(__PeriNum, __PeriBit, __Enable, __Channel) \
  C_( \
    IfSafe_(__Channel < TC_##__PeriBit##Bit_Peri_Ch_Qty, \
      SwitchSafe_(__Channel, \
        Set_OCIEnable_TC_D_Block_PeriNum##__PeriNum##_##__PeriBit##bit_Case_ChA(__PeriNum, __Enable) \
        Set_OCIEnable_TC_D_Block_PeriNum##__PeriNum##_##__PeriBit##bit_Case_ChB(__PeriNum, __Enable) \
        Set_OCIEnable_TC_D_Block_PeriNum##__PeriNum##_##__PeriBit##bit_Case_ChC(__PeriNum, __Enable) \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_OCompare_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#define Set_OCompare_TC_D_Block_Common(__PeriNum, __Enable, __Reg, __RegPeriNum, __Channel) \
  sclb_reg_common(__Reg, __RegPeriNum, Null_Param_, __Enable, OCIE, __PeriNum, __Channel);

// for 8bit Peripherals.
// Channel A.
#if defined(OCF0) || defined(OCF2)
// for Single Channels.
#define Set_OCompare_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_OCIEnable_TC_D_Block_Common(__PeriNum, __Enable, TIFR, Null_Param_, Null_Param_) \
  )
#define Set_OCompare_TC_D_Block_PeriNum2_8bit_Case_ChA(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Enable)
#else
// for Multi Channels.
#define Set_OCompare_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_OCompare_TC_D_Block_Common(__PeriNum, __Enable, TIFR, __PeriNum, A) \
  )
#define Set_OCompare_TC_D_Block_PeriNum2_8bit_Case_ChA(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Enable)
#endif

// Channel B.
#if defined(OCF0B) || defined(OCF2B)
#define Set_OCompare_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Enable) \
  CaseSafe_(ChanB, \
    Set_OCompare_TC_D_Block_Common(__PeriNum, __Enable, TIFR, __PeriNum, B) \
  )
#define Set_OCompare_TC_D_Block_PeriNum2_8bit_Case_ChB(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Enable)
#else
#define Set_OCompare_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Enable) \
  Null_Syntax_
#define Set_OCompare_TC_D_Block_PeriNum2_8bit_Case_ChB(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Enable)
#endif

// Channel C(8Bit is none).
#define Set_OCompare_TC_D_Block_PeriNum0_8bit_Case_ChC(__PeriNum, __Enable) \
  Null_Syntax_
#define Set_OCompare_TC_D_Block_PeriNum2_8bit_Case_ChC(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum0_8bit_Case_ChC(__PeriNum, __Enable)

// for 16bit Peripherals.
// Channel A.
#if defined(OCIE1A) || defined(OCIE3A) || defined(OCIE4A) || defined(OCIE5A)
#define Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_OCompare_TC_D_Block_Common(__PeriNum, __Enable, TIFR, __PeriNum, A) \
  )
#define Set_OCompare_TC_D_Block_PeriNum3_16bit_Case_ChA(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Enable)
#define Set_OCompare_TC_D_Block_PeriNum4_16bit_Case_ChA(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Enable)
#define Set_OCompare_TC_D_Block_PeriNum5_16bit_Case_ChA(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Enable)
#else
#define Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_OCompare_TC_D_Block_Common(__PeriNum, __Enable, TIFR, Null_Param_, A) \
  )
#define Set_OCompare_TC_D_Block_PeriNum3_16bit_Case_ChA(__PeriNum, __Enable) \
  CaseSafe_(ChanA, \
    Set_OCompare_TC_D_Block_Common(__PeriNum, __Enable, ETTIFR, Null_Param_, A) \
  )
#endif

// Channel B.
#if defined(OCIE1B) || defined(OCIE3B) || defined(OCIE4B) || defined(OCIE5B)
#define Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Enable) \
  CaseSafe_(ChanB, \
    Set_OCompare_TC_D_Block_Common(__PeriNum, __Enable, TIFR, __PeriNum, B) \
  )
#define Set_OCompare_TC_D_Block_PeriNum3_16bit_Case_ChB(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Enable)
#define Set_OCompare_TC_D_Block_PeriNum4_16bit_Case_ChB(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Enable)
#define Set_OCompare_TC_D_Block_PeriNum5_16bit_Case_ChB(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Enable)
#else
#define Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Enable) \
  CaseSafe_(ChanB, \
    Set_OCompare_TC_D_Block_Common(__PeriNum, __Enable, TIFR, Null_Param_, B) \
  )
#define Set_OCompare_TC_D_Block_PeriNum3_16bit_Case_ChB(__PeriNum, __Enable) \
  CaseSafe_(ChanB, \
    Set_OCompare_TC_D_Block_Common(__PeriNum, __Enable, ETIFR, Null_Param_, B) \
  )
#endif

// Channel C.
#if defined(OCIE1C) || defined(OCIE3C) || defined(OCIE4C) || defined(OCIE5C)
#define Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Enable) \
  CaseSafe_(ChanC, \
    Set_OCompare_TC_D_Block_Common(__PeriNum, __Enable, ETIFR, Null_Param_, C) \
  )
#define Set_OCompare_TC_D_Block_PeriNum3_16bit_Case_ChC(__PeriNum, __Enable) \
  Set_OCIEnable_TC_D_Block_16bit_Case_ChC(__PeriNum, __Enable)
#else
#define Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Enable) \
  Null_Syntax_
#define Set_OCompare_TC_D_Block_PeriNum3_16bit_Case_ChC(__PeriNum, __Enable) \
  Set_OCompare_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Enable)
#endif

// Definition Prototyping.
#define Set_OCompare_TC_D_Proto(__PeriNum, __PeriBit, __Enable, __Channel) \
  C_( \
    IfSafe_(__Channel < TC_##__PeriBit##Bit_Peri_Ch_Qty, \
      SwitchSafe_(__Channel, \
        Set_OCIEnable_TC_D_Block_PeriNum##__PeriNum##_##__PeriBit##bit_Case_ChA(__PeriNum, __Enable) \
        Set_OCIEnable_TC_D_Block_PeriNum##__PeriNum##_##__PeriBit##bit_Case_ChB(__PeriNum, __Enable) \
        Set_OCIEnable_TC_D_Block_PeriNum##__PeriNum##_##__PeriBit##bit_Case_ChC(__PeriNum, __Enable) \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_ICNCanceler_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_ICNCanceler_TC_D_Proto(__PeriNum, Enable) \
  C_( \
    sclb_reg_common(TCCR, __PeriNum, B, Enable, ICNC, __PeriNum, ); \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_ICESelect_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_ICESelect_TC_D_Proto(__PeriNum, Enable) \
  C_( \
    sclb_reg_common(TCCR, __PeriNum, B, Enable, ICES, __PeriNum, ); \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_ICIEnable_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#if defined(TIMSK)
#define Set_ICIEnable_TC_D_Block_PeriNum1(__PeriNum, __Enable) \
  sclb_reg_common(TIMSK, , , __Enable, TICIE, __PeriNum, );
#define Set_ICIEnable_TC_D_Block_PeriNum3(__PeriNum, __Enable) \
  sclb_reg_common(ETIMSK, , , __Enable, TICIE, __PeriNum, );
#else
#define Set_ICIEnable_TC_D_Block_PeriNum1(__PeriNum, __Enable) \
  sclb_reg_common(TIMSK, __PeriNum, , __Enable, ICIE, __PeriNum, );
#define Set_ICIEnable_TC_D_Block_PeriNum3(__PeriNum, __Enable) \
  Set_ICIEnable_TC_D_Block_PeriNum1(__PeriNum, __Enable)
#endif

// Definition Prototyping.
#define Set_ICIEnable_TC_D_Proto(__PeriNum, __Enable) \
  C_( \
    Set_ICIEnable_TC_D_Block_PeriNum##__PeriNum(__PeriNum, __Enable) \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_ICapture_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#if defined(TIFR)
#define Set_ICapture_TC_D_Block_PeriNum1(__PeriNum, __Enable) \
  sclb_reg_common(TIFR, , , Enable, ICF, __PeriNum, );
#define Set_ICapture_TC_D_Block_PeriNum3(__PeriNum, __Enable) \
  sclb_reg_common(ETIFR, , , Enable, ICF, __PeriNum, );
#else
#define Set_ICapture_TC_D_Block_PeriNum1(__PeriNum, __Enable) \
  sclb_reg_common(TIFR, __PeriNum, , __Enable, ICF, __PeriNum, );
#define Set_ICapture_TC_D_Block_PeriNum3(__PeriNum, __Enable) \
  Set_ICIEnable_TC_D_Block_PeriNum1(__PeriNum, __Enable)
#endif

// Definition Prototyping.
#define Set_ICapture_TC_D_Proto(__PeriNum, __Enable) \
  C_( \
    Set_ICapture_TC_D_Block_PeriNum##__PeriNum(__PeriNum, __Enable) \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_TCReg_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#if defined(TCNT0) || defined(TCNT2)
#define Set_TCReg_TC_D_Block_8Bit(__PeriNum, __Value) \
  TCNT##__PeriNum = (uint8_t)__Value;
#endif
#if defined(TCNT1) || defined(TCNT3) || defined(TCNT4) || defined(TCNT5)
#define Set_TCReg_TC_D_Block_16Bit(__PeriNum, __Value) \
  TCNT##__PeriNum##H = (uint8_t)(__Value >> 8); \
  TCNT##__PeriNum##L = (uint8_t)__Value;
#endif

// Definition Prototyping.
#define Set_TCReg_TC_D_Proto(__PeriNum, __PeriBit, __Value) \
  C_( \
    Set_TCReg_TC_D_Block_##__PeriBit##Bit(__PeriNum, __Value) \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_OCompareReg_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// for 8bit Peripherals.
// Channel A.
#if defined(OCR0) || defined(OCR2)
// for Single Channels.
#define Set_OCompareReg_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Value) \
  CaseSafe_(ChanA, \
    OCR##__PeriNum = (uint8_t)__Value; \
  )
#define Set_OCompareReg_TC_D_Block_PeriNum2_8bit_Case_ChA(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Value)
#else
// for Multi Channels.
#define Set_OCompareReg_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Value) \
  CaseSafe_(ChanA, \
    OCR##__PeriNum##A = (uint8_t)__Value; \
  )
#define Set_OCompareReg_TC_D_Block_PeriNum2_8bit_Case_ChA(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum0_8bit_Case_ChA(__PeriNum, __Value)
#endif

// Channel B.
#if defined(OCR0B) || defined(OCR2B)
#define Set_OCompareReg_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Value) \
  CaseSafe_(ChanB, \
    OCR##__PeriNum##B = (uint8_t)__Value; \
  )
#define Set_OCompareReg_TC_D_Block_PeriNum2_8bit_Case_ChB(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Value)
#else
#define Set_OCompareReg_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Value) \
  Null_Syntax_
#define Set_OCompareReg_TC_D_Block_PeriNum2_8bit_Case_ChB(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum0_8bit_Case_ChB(__PeriNum, __Value)
#endif

// Channel C(8Bit is none).
#define Set_OCompareReg_TC_D_Block_PeriNum0_8bit_Case_ChC(__PeriNum, __Value) \
  Null_Syntax_
#define Set_OCompareReg_TC_D_Block_PeriNum2_8bit_Case_ChC(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum0_8bit_Case_ChC(__PeriNum, __Value)

// for 16bit Peripherals.
// Channel A.
#if defined(OCR1A) || defined(OCR3A) || defined(OCR4A) || defined(OCR5A)
#define Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Value) \
  CaseSafe_(ChanA, \
    OCR##__PeriNum##AH = (uint8_t)(__Value >> 8); \
    OCR##__PeriNum##AL = (uint8_t)__Value; \
  )
#define Set_OCompareReg_TC_D_Block_PeriNum3_16bit_Case_ChA(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum4_16bit_Case_ChA(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum5_16bit_Case_ChA(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Value)
#else
#define Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Value) \
  CaseSafe_(ChanA, \
    OCR##__PeriNum##AH = (uint8_t)(__Value >> 8); \
    OCR##__PeriNum##AL = (uint8_t)__Value; \
  )
#define Set_OCompareReg_TC_D_Block_PeriNum3_16bit_Case_ChA(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum4_16bit_Case_ChA(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum5_16bit_Case_ChA(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChA(__PeriNum, __Value)
#endif

// Channel B.
#if defined(OCR1B) || defined(OCR3B) || defined(OCR4B) || defined(OCR5B)
#define Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Value) \
  CaseSafe_(ChanB, \
    OCR##__PeriNum##BH = (uint8_t)(__Value >> 8); \
    OCR##__PeriNum##BL = (uint8_t)__Value; \
  )
#define Set_OCompareReg_TC_D_Block_PeriNum3_16bit_Case_ChB(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum4_16bit_Case_ChB(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum5_16bit_Case_ChB(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Value)
#else
#define Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Value) \
  CaseSafe_(ChanB, \
    OCR##__PeriNum##BH = (uint8_t)(__Value >> 8); \
    OCR##__PeriNum##BL = (uint8_t)__Value; \
  )
#define Set_OCompareReg_TC_D_Block_PeriNum3_16bit_Case_ChB(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum4_16bit_Case_ChB(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum5_16bit_Case_ChB(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChB(__PeriNum, __Value)
#endif

// Channel C.
#if defined(OCR1C) || defined(OCR3C) || defined(OCR4C) || defined(OCR5C)
#define Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Value) \
  CaseSafe_(ChanC, \
    OCR##__PeriNum##CH = (uint8_t)(__Value >> 8); \
    OCR##__PeriNum##CL = (uint8_t)__Value; \
  )
#define Set_OCompareReg_TC_D_Block_PeriNum3_16bit_Case_ChC(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum4_16bit_Case_ChC(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum5_16bit_Case_ChC(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Value)
#else
#define Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Value) \
  Null_Syntax_
#define Set_OCompareReg_TC_D_Block_PeriNum3_16bit_Case_ChC(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum4_16bit_Case_ChC(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Value)
#define Set_OCompareReg_TC_D_Block_PeriNum5_16bit_Case_ChC(__PeriNum, __Value) \
  Set_OCompareReg_TC_D_Block_PeriNum1_16bit_Case_ChC(__PeriNum, __Value)
#endif

// Definition Prototyping.
#define Set_OCompareReg_TC_D_Proto(__PeriNum, __PeriBit, __Value, __Channel) \
  C_( \
    SwitchSafe_(__Channel, \
      Set_OCompareReg_TC_D_Block_PeriNum##__PeriNum##_##__PeriBit##bit_Case_ChA(__PeriNum, __Value) \
      Set_OCompareReg_TC_D_Block_PeriNum##__PeriNum##_##__PeriBit##bit_Case_ChB(__PeriNum, __Value) \
      Set_OCompareReg_TC_D_Block_PeriNum##__PeriNum##_##__PeriBit##bit_Case_ChC(__PeriNum, __Value) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// ** Set_ICNCanceler_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_ICaptureReg_TC_D_Proto(__PeriNum, __Value) \
  C_( \
    ICR##__PeriNum##H = (uint8_t)(__Value >> 8); \
    ICR##__PeriNum##L = (uint8_t)__Value; \
  )
#pragma __FunCX_InLevel_Except End

/*
 * This section is 8/16(common) bit Timer/Counter function flag setting Definitions.
 */

// T/C 0
#if defined(TCCR0) || defined(TCCR0A)
#define Set_WGMode_TC0_D(Mode) \
  Set_WGMode_TC_D_Proto(0, 8, Mode)
#define Set_ClockSelect_TC0_D(ClockSel) \
  Set_ClockSelect_TC_D_Proto(0, 8, ClockSel)
#define Set_COMode_TC0_D(Mode, Channel) \
  Set_COMode_TC_D_Proto(0, 8, Mode, Channel)
#define Set_FOCompare_TC0_D(Enable, Channel) \
  Set_FOCompare_TC_D_Proto(0, 8, Enable, Channel)
#define Set_TOInterruptEnable_TC0_D(Enable) \
  Set_TOInterruptEnable_TC_D_Proto(0, 8, Enable)
#define Set_TOverflow_TC0_D(Enable) \
  Set_TOverflow_TC_D_Proto(0, 8, Enable)
#define Set_OCIEnable_TC0_D(Enable, Channel) \
  Set_OCIEnable_TC_D_Proto(0, 8, Enable, Channel)
#define Set_OCompare_TC0_D(Enable, Channel) \
  Set_OCompare_TC_D_Proto(0, 8, Enable, Channel)
#endif

// T/C 1
#if defined(TCCR1A)
#define Set_WGMode_TC1_D(Mode) \
  Set_WGMode_TC_D_Proto(1, 16, Mode)
#define Set_ClockSelect_TC1_D(ClockSel) \
  Set_ClockSelect_TC_D_Proto(1, 16, ClockSel)
#define Set_COMode_TC1_D(Mode, Channel) \
  Set_COMode_TC_D_Proto(1, 16, Mode, Channel)
#define Set_FOCompare_TC1_D(Enable, Channel) \
  Set_FOCompare_TC_D_Proto(1, 16, Enable, Channel)
#define Set_TOInterruptEnable_TC1_D(Enable) \
  Set_TOInterruptEnable_TC_D_Proto(1, 16, Enable)
#define Set_TOverflow_TC1_D(Enable) \
  Set_TOverflow_TC_D_Proto(1, 16, Enable)
#define Set_OCIEnable_TC1_D(Enable, Channel) \
  Set_OCIEnable_TC_D_Proto(1, 16, Enable, Channel)
#define Set_OCompare_TC1_D(Enable, Channel) \
  Set_OCompare_TC_D_Proto(1, 16, Enable, Channel)
#endif

// T/C 2
#if defined(TCCR2) || defined(TCCR2A)
#define Set_WGMode_TC2_D(Mode) \
  Set_WGMode_TC_D_Proto(2, 8, Mode)
#define Set_ClockSelect_TC2_D(ClockSel) \
  Set_ClockSelect_TC_D_Proto(2, 8, ClockSel)
#define Set_COMode_TC2_D(Mode, Channel) \
  Set_COMode_TC_D_Proto(2, 8, Mode, Channel)
#define Set_FOCompare_TC2_D(Enable, Channel) \
  Set_FOCompare_TC_D_Proto(2, 8, Enable, Channel)
#define Set_TOInterruptEnable_TC2_D(Enable) \
  Set_TOInterruptEnable_TC_D_Proto(2, 8, Enable)
#define Set_TOverflow_TC2_D(Enable) \
  Set_TOverflow_TC_D_Proto(2, 8, Enable)
#define Set_OCIEnable_TC2_D(Enable, Channel) \
  Set_OCIEnable_TC_D_Proto(2, 8, Enable, Channel)
#define Set_OCompare_TC2_D(Enable, Channel) \
  Set_OCompare_TC_D_Proto(2, 8, Enable, Channel)
#endif

// T/C 3
#if defined(TCCR3A)
#define Set_WGMode_TC3_D(Mode) \
  Set_WGMode_TC_D_Proto(3, 16, Mode)
#define Set_ClockSelect_TC3_D(ClockSel) \
  Set_ClockSelect_TC_D_Proto(3, 16, ClockSel)
#define Set_COMode_TC3_D(Mode, Channel) \
  Set_COMode_TC_D_Proto(3, 16, Mode, Channel)
#define Set_FOCompare_TC3_D(Enable, Channel) \
  Set_FOCompare_TC_D_Proto(3, 16, Enable, Channel)
#define Set_TOInterruptEnable_TC3_D(Enable) \
  Set_TOInterruptEnable_TC_D_Proto(3, 16, Enable)
#define Set_TOverflow_TC3_D(Enable) \
  Set_TOverflow_TC_D_Proto(3, 16, Enable)
#define Set_OCIEnable_TC3_D(Enable, Channel) \
  Set_OCIEnable_TC_D_Proto(3, 16, Enable, Channel)
#define Set_OCompare_TC3_D(Enable, Channel) \
  Set_OCompare_TC_D_Proto(3, 16, Enable, Channel)
#endif

// T/C 4
#if defined(TCCR4A)
#define Set_WGMode_TC4_D(Mode) \
  Set_WGMode_TC_D_Proto(4, 16, Mode)
#define Set_ClockSelect_TC4_D(ClockSel) \
  Set_ClockSelect_TC_D_Proto(4, 16, ClockSel)
#define Set_COMode_TC4_D(Mode, Channel) \
  Set_COMode_TC_D_Proto(4, 16, Mode, Channel)
#define Set_FOCompare_TC4_D(Enable, Channel) \
  Set_FOCompare_TC_D_Proto(4, 16, Enable, Channel)
#define Set_TOInterruptEnable_TC4_D(Enable) \
  Set_TOInterruptEnable_TC_D_Proto(4, 16, Enable)
#define Set_TOverflow_TC4_D(Enable) \
  Set_TOverflow_TC_D_Proto(4, 16, Enable)
#define Set_OCIEnable_TC4_D(Enable, Channel) \
  Set_OCIEnable_TC_D_Proto(4, 16, Enable, Channel)
#define Set_OCompare_TC4_D(Enable, Channel) \
  Set_OCompare_TC_D_Proto(4, 16, Enable, Channel)
#endif

// T/C 5
#if defined(TCCR5A)
#define Set_WGMode_TC5_D(Mode) \
  Set_WGMode_TC_D_Proto(5, 16, Mode)
#define Set_ClockSelect_TC5_D(ClockSel) \
  Set_ClockSelect_TC_D_Proto(5, 16, ClockSel)
#define Set_COMode_TC5_D(Mode, Channel) \
  Set_COMode_TC_D_Proto(5, 16, Mode, Channel)
#define Set_FOCompare_TC5_D(Enable, Channel) \
  Set_FOCompare_TC_D_Proto(5, 16, Enable, Channel)
#define Set_TOInterruptEnable_TC5_D(Enable) \
  Set_TOInterruptEnable_TC_D_Proto(5, 16, Enable)
#define Set_TOverflow_TC5_D(Enable) \
  Set_TOverflow_TC_D_Proto(5, 16, Enable)
#define Set_OCIEnable_TC5_D(Enable, Channel) \
  Set_OCIEnable_TC_D_Proto(5, 16, Enable, Channel)
#define Set_OCompare_TC5_D(Enable, Channel) \
  Set_OCompare_TC_D_Proto(5, 16, Enable, Channel)
#endif

/*
 * This section is only 16 bit Timer/Counter function flag setting Definitions.
 */

// T/C 1
#if defined(TCCR1B)
#define Set_ICNCanceler_TC1_D(Enable) \
  Set_ICNCanceler_TC_D_Proto(1, Enable)
#define Set_ICESelect_TC1_D(Enable) \
  Set_ICESelect_TC_D_Proto(1, Enable)
#define Set_ICIEnable_TC1_D(Enable) \
  Set_ICIEnable_TC_D_Proto(1, Enable)
#define Set_ICapture_TC1_D(Enable) \
  Set_ICapture_TC_D_Proto(1, Enable)
#endif

// T/C 3
#if defined(TCCR3B)
#define Set_ICNCanceler_TC3_D(Enable) \
  Set_ICNCanceler_TC_D_Proto(3, Enable)
#define Set_ICESelect_TC3_D(Enable) \
  Set_ICESelect_TC_D_Proto(3, Enable)
#define Set_ICIEnable_TC3_D(Enable) \
  Set_ICIEnable_TC_D_Proto(3, Enable)
#define Set_ICapture_TC3_D(Enable) \
  Set_ICapture_TC_D_Proto(3, Enable)
#endif

// T/C 4
#if defined(TCCR4B)
#define Set_ICNCanceler_TC4_D(Enable) \
  Set_ICNCanceler_TC_D_Proto(4, Enable)
#define Set_ICESelect_TC4_D(Enable) \
  Set_ICESelect_TC_D_Proto(4, Enable)
#define Set_ICIEnable_TC4_D(Enable) \
  Set_ICIEnable_TC_D_Proto(4, Enable)
#define Set_ICapture_TC4_D(Enable) \
  Set_ICapture_TC_D_Proto(4, Enable)
#endif

// T/C 5
#if defined(TCCR5B)
#define Set_ICNCanceler_TC5_D(Enable) \
  Set_ICNCanceler_TC_D_Proto(5, Enable)
#define Set_ICESelect_TC5_D(Enable) \
  Set_ICESelect_TC_D_Proto(5, Enable)
#define Set_ICIEnable_TC5_D(Enable) \
  Set_ICIEnable_TC_D_Proto(5, Enable)
#define Set_ICapture_TC5_D(Enable) \
  Set_ICapture_TC_D_Proto(5, Enable)
#endif

/*
 * This section is 8/16(common) bit Timer/Counter Control Register setting Definitions.
 */

// T/C 0
#if defined(TCCR0) || defined(TCCR0A)
#define Set_TCReg_TC0_D(Value) \
  Set_TCReg_TC_D_Proto(0, 8, Value)
#define Set_OCompareReg_TC0_D(Value, Channel) \
  Set_OCompareReg_TC_D_Proto(0, 8, Value, Channel)
#endif

// T/C 1
#if defined(TCCR1A)
#define Set_TCReg_TC1_D(Value) \
  Set_TCReg_TC_D_Proto(1, 16, Value)
#define Set_OCompareReg_TC1_D(Value, Channel) \
  Set_OCompareReg_TC_D_Proto(1, 16, Value, Channel)
#endif

// T/C 2
#if defined(TCCR2) || defined(TCCR2A)
#define Set_TCReg_TC2_D(Value) \
  Set_TCReg_TC_D_Proto(2, 8, Value)
#define Set_OCompareReg_TC2_D(Value, Channel) \
  Set_OCompareReg_TC_D_Proto(2, 8, Value, Channel)
#endif

// T/C 3
#if defined(TCCR3A)
#define Set_TCReg_TC3_D(Value) \
  Set_TCReg_TC_D_Proto(3, 16, Value)
#define Set_OCompareReg_TC3_D(Value, Channel) \
  Set_OCompareReg_TC_D_Proto(3, 16, Value, Channel)
#endif

// T/C 4
#if defined(TCCR4A)
#define Set_TCReg_TC4_D(Value) \
  Set_TCReg_TC_D_Proto(4, 16, Value)
#define Set_OCompareReg_TC4_D(Value, Channel) \
  Set_OCompareReg_TC_D_Proto(4, 16, Value, Channel)
#endif

// T/C 5
#if defined(TCCR5A)
#define Set_TCReg_TC5_D(Value) \
  Set_TCReg_TC_D_Proto(5, 16, Value)
#define Set_OCompareReg_TC5_D(Value, Channel) \
  Set_OCompareReg_TC_D_Proto(5, 16, Value, Channel)
#endif

/*
 * This section is only 16 bit Timer/Counter Control Register setting Definitions.
 */

// T/C 1
#if defined(TCCR1B)
#define Set_ICaptureReg_TC1_D(Value) \
  Set_ICaptureReg_TC_D_Proto(1, Value)
#endif

// T/C 3
#if defined(TCCR3B)
#define Set_ICaptureReg_TC3_D(Value) \
  Set_ICaptureReg_TC_D_Proto(3, Value)
#endif

// T/C 4
#if defined(TCCR4B)
#define Set_ICaptureReg_TC4_D(Value) \
  Set_ICaptureReg_TC_D_Proto(4, Value)
#endif

// T/C 5
#if defined(TCCR5B)
#define Set_ICaptureReg_TC5_D(Value) \
  Set_ICaptureReg_TC_D_Proto(5, Value)
#endif

#pragma __FunCX_Section End

#endif // _TC_Basic_def_h_