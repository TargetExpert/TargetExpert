/*********************************************************************

          File: TC_Ext.def.h

   Description: AVR T/C extended func. syntax definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/13

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_Ext_def_h_
#define _TC_Ext_def_h_

#pragma __FunCX_Section Begin

#include "TC_Basic.var.h"
#include "TC_Ext.var.h"

#include "TC_Basic.h"
#include "TC_ExtIn.h"

// Set_ICFTop_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_ICFTop_TC_D_Proto(__PeriNum, __Enable) \
  C_( \
    TCChanOptionsInformations _TTOptInfo = Get_TOptInfo(__PeriNum); \
    \
    _TTOptInfo.IsICFTop = __Enable; \
    \
    uint8_t _TCOMode = 0; \
    IfSafe_(_TTOptInfo.IsICFTop, \
      IfSafe_(_TTOptInfo.IsToggleMode, _TTOptInfo.IsToggleMode = false;) \
      _TCOMode = COM_NONINV; \
    ) \
    \
    Set_TOptInfo(__PeriNum, _TTOptInfo); \
    _UpdateWGMode(__PeriNum); \
    \
    TCFreqOptiValueStoreage _TTCOVInfo = Get_TCOVInfo(__PeriNum); \
    \
    Set_COMode_TC##__PeriNum(_TCOMode, ChanA); \
    Set_WGMode_TC##__PeriNum(_TTCOVInfo.TCWGMNBitPeriInfo.WGMValue); \
  )
#pragma __FunCX_InLevel_Except End

// Set_ToggledOut_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_ToggledOut_TC_D_Proto(__PeriNum, __Enable) \
  C_( \
    TCChanOptionsInformations _TTOptInfo = Get_TOptInfo(__PeriNum); \
    \
    _TTOptInfo.IsToggleMode = __Enable; \
    \
    uint8_t _TCOMode = 0; \
    IfSafe_(_TTOptInfo.IsToggleMode, \
      IfSafe_(_TTOptInfo.IsInvertPWM[ChanA], _TTOptInfo.IsInvertPWM[ChanA] = false;) \
      IfSafe_(_TTOptInfo.IsICFTop, _TTOptInfo.IsICFTop = false;) \
      \
      _TCOMode = COM_TOGGLE; \
    ) \
    ElseSafe_(_TCOMode = COM_NONINV;) \
    \
    Set_TOptInfo(__PeriNum, _TTOptInfo); \
    _UpdateWGMode(__PeriNum); \
    \
    TCFreqOptiValueStoreage _TTCOVInfo = Get_TCOVInfo(__PeriNum); \
    \
    Set_COMode_TC##__PeriNum(_TCOMode, ChanA); \
    Set_WGMode_TC##__PeriNum(_TTCOVInfo.TCWGMNBitPeriInfo.WGMValue); \
  )
#pragma __FunCX_InLevel_Except End

// Set_InvertOut_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_InvertOut_TC_D_Proto(__PeriNum, __Enable, __Channel) \
  C_( \
    TCChanOptionsInformations _TTOptInfo = Get_TOptInfo(__PeriNum); \
    \
    _TTOptInfo.IsInvertPWM[__Channel] = __Enable; \
    \
    uint8_t _TCOMode = 0; \
    IfSafe_(__Channel == ChanA, _TTOptInfo.IsToggleMode = false;) \
    \
    IfSafe_(_TTOptInfo.IsInvertPWM[__Channel], _TCOMode = COM_INV;) \
    ElseSafe_(_TCOMode = COM_NONINV;) \
    \
    Set_TOptInfo(__PeriNum, _TTOptInfo); \
    \
    Set_COMode_TC##__PeriNum(_TCOMode, __Channel); \
  )
#pragma __FunCX_InLevel_Except End

// Set_DiffMarginFreqValue_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_DiffMarginFreqValue_TC_D_Proto(__PeriNum, __DiffMarginFreqValue) \
  C_( \
    IfSafe_(DiffMarginFreqValue <= TC_MAX_FREQERR_MARGIN, \
      TCChanOptionsInformations _TTOptInfo = Get_TOptInfo(__PeriNum); \
      _TTOptInfo.DiffMarginFreqValue = __DiffMarginFreqValue; \
      Set_TOptInfo(__PeriNum, _TTOptInfo); \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_Period_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_Period_TC_D_Proto(__PeriNum, __Period, __Mode) \
  C_( \
    TCFreqOptiValueStoreage _TCOptiValue = _GetAutoCalculatedPeriodByModeName(__PeriNum, __Mode, __Period); \
    IfSafe_(!_TCOptiValue.TCCalcValInfo.Able, return false;) \
    \
    uint8_t _TCOMode = 0; \
    IfSafe_(_TCOptiValue.TCWGMNBitPeriInfo.WGMValue == NORMODE, _TCOMode = COM_NORMAL;) \
    ElseSafe_(_TCOMode = COM_NONINV;) \
    \
    Set_TCOVInfo(__PeriNum, _TCOptiValue); \
    _UpdateWGMode(__PeriNum); \
    \
    TCFreqOptiValueStoreage _TTCOVInfo = Get_TCOVInfo(__PeriNum); \
    \
    Set_COMode_TC##__PeriNum(_TCOMode, ChanA); \
    Set_ClockSelect_TC##__PeriNum(_TTCOVInfo.TCCalcValInfo.NBit); \
    Set_WGMode_TC##__PeriNum(_TTCOVInfo.TCWGMNBitPeriInfo.WGMValue); \
    Set_TCReg_TC##__PeriNum(_TTCOVInfo.TCCalcValInfo.TCnt); \
    \
    return true; \
  )
#pragma __FunCX_InLevel_Except End

// Set_Period_TC(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_PeriodForAutoMode_TC_D_Proto(__PeriNum, __Period) \
  C_( \
    TCFreqOptiValueStoreage _TCOptiValue = _GetTCPeriodAutoSelectionByPeripheral(__PeriNum, __Period); \
    IfSafe_(!_TCOptiValue.TCCalcValInfo.Able, return false;) \
    \
    uint8_t _TCOMode = 0; \
    IfSafe_(_TCOptiValue.TCWGMNBitPeriInfo.WGMValue == NORMODE, _TCOMode = COM_NORMAL;) \
    ElseSafe_(_TCOMode = COM_NONINV;) \
    \
    Set_TCOVInfo(__PeriNum, _TCOptiValue); \
    _UpdateWGMode(__PeriNum); \
    \
    TCFreqOptiValueStoreage _TTCOVInfo = Get_TCOVInfo(__PeriNum); \
    \
    Set_COMode_TC##__PeriNum(_TCOMode, ChanA); \
    Set_ClockSelect_TC##__PeriNum(_TTCOVInfo.TCCalcValInfo.NBit); \
    Set_WGMode_TC##__PeriNum(_TTCOVInfo.TCWGMNBitPeriInfo.WGMValue); \
    Set_TCReg_TC##__PeriNum(_TTCOVInfo.TCCalcValInfo.TCnt); \
    \
    return true; \
  )
#pragma __FunCX_InLevel_Except End

// T/C 0
#if defined(TCCR0) || defined(TCCR0A)
#define Set_ICFTop_TC0_D(Enable) \
  Set_ICFTop_TC_D_Proto(0, Enable)
#define Set_ToggledOut_TC0_D(Enable) \
  Set_ToggledOut_TC_D_Proto(0, Enable)
#define Set_InvertOut_TC0_D(Enable, Channel) \
  Set_InvertOut_TC_D_Proto(0, Enable, Channel)
#define Set_DiffMarginFreqValue_TC0_D(DiffMarginFreqValue) \
  Set_DiffMarginFreqValue_TC_D_Proto(0, DiffMarginFreqValue)
#define Set_Period_TC0_D(Period, Mode) \
  Set_Period_TC_D_Proto(0, Period, Mode)
#define Set_PeriodForAutoMode_TC0_D(Period) \
  Set_PeriodForAutoMode_TC_D_Proto(0, Period)
#endif

// T/C 1
#if defined(TCCR1A)
#define Set_ICFTop_TC1_D(Enable) \
  Set_ICFTop_TC_D_Proto(1, Enable)
#define Set_ToggledOut_TC1_D(Enable) \
  Set_ToggledOut_TC_D_Proto(1, Enable)
#define Set_InvertOut_TC1_D(Enable, Channel) \
  Set_InvertOut_TC_D_Proto(1, Enable, Channel)
#define Set_DiffMarginFreqValue_TC1_D(DiffMarginFreqValue) \
  Set_DiffMarginFreqValue_TC_D_Proto(1, DiffMarginFreqValue)
#define Set_Period_TC1_D(Period, Mode) \
  Set_Period_TC_D_Proto(1, Period, Mode)
#define Set_PeriodForAutoMode_TC1_D(Period) \
  Set_PeriodForAutoMode_TC_D_Proto(1, Period)
#endif

// T/C 2
#if defined(TCCR2) || defined(TCCR2A)
#define Set_ICFTop_TC2_D(Enable) \
  Set_ICFTop_TC_D_Proto(2, Enable)
#define Set_ToggledOut_TC2_D(Enable) \
  Set_ToggledOut_TC_D_Proto(2, Enable)
#define Set_InvertOut_TC2_D(Enable, Channel) \
  Set_InvertOut_TC_D_Proto(2, Enable, Channel)
#define Set_DiffMarginFreqValue_TC2_D(DiffMarginFreqValue) \
  Set_DiffMarginFreqValue_TC_D_Proto(2, DiffMarginFreqValue)
#define Set_Period_TC2_D(Period, Mode) \
  Set_Period_TC_D_Proto(2, Period, Mode)
#define Set_PeriodForAutoMode_TC2_D(Period) \
  Set_PeriodForAutoMode_TC_D_Proto(2, Period)
#endif

// T/C 3
#if defined(TCCR3A)
#define Set_ICFTop_TC3_D(Enable) \
  Set_ICFTop_TC_D_Proto(3, Enable)
#define Set_ToggledOut_TC3_D(Enable) \
  Set_ToggledOut_TC_D_Proto(3, Enable)
#define Set_InvertOut_TC3_D(Enable, Channel) \
  Set_InvertOut_TC_D_Proto(3, Enable, Channel)
#define Set_DiffMarginFreqValue_TC3_D(DiffMarginFreqValue) \
  Set_DiffMarginFreqValue_TC_D_Proto(3, DiffMarginFreqValue)
#define Set_Period_TC3_D(Period, Mode) \
  Set_Period_TC_D_Proto(3, Period, Mode)
#define Set_PeriodForAutoMode_TC3_D(Period) \
  Set_PeriodForAutoMode_TC_D_Proto(3, Period)
#endif

// T/C 4
#if defined(TCCR4A)
#define Set_ICFTop_TC4_D(Enable) \
  Set_ICFTop_TC_D_Proto(4, Enable)
#define Set_ToggledOut_TC4_D(Enable) \
  Set_ToggledOut_TC_D_Proto(4, Enable)
#define Set_InvertOut_TC4_D(Enable, Channel) \
  Set_InvertOut_TC_D_Proto(4, Enable, Channel)
#define Set_DiffMarginFreqValue_TC4_D(DiffMarginFreqValue) \
  Set_DiffMarginFreqValue_TC_D_Proto(4, DiffMarginFreqValue)
#define Set_Period_TC4_D(Period, Mode) \
  Set_Period_TC_D_Proto(4, Period, Mode)
#define Set_PeriodForAutoMode_TC4_D(Period) \
  Set_PeriodForAutoMode_TC_D_Proto(4, Period)
#endif

// T/C 5
#if defined(TCCR5A)
#define Set_ICFTop_TC5_D(Enable) \
  Set_ICFTop_TC_D_Proto(5, Enable)
#define Set_ToggledOut_TC5_D(Enable) \
  Set_ToggledOut_TC_D_Proto(5, Enable)
#define Set_InvertOut_TC5_D(Enable, Channel) \
  Set_InvertOut_TC_D_Proto(5, Enable, Channel)
#define Set_DiffMarginFreqValue_TC5_D(DiffMarginFreqValue) \
  Set_DiffMarginFreqValue_TC_D_Proto(5, DiffMarginFreqValue)
#define Set_Period_TC5_D(Period, Mode) \
  Set_Period_TC_D_Proto(5, Period, Mode)
#define Set_PeriodForAutoMode_TC5_D(Period) \
  Set_PeriodForAutoMode_TC_D_Proto(5, Period)
#endif

#pragma __FunCX_Section End

#endif // _TC_Ext_def_h_
