/*********************************************************************

          File: PWM.def.h

   Description: AVR PWM syntax definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/06

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _PWM_def_h_
#define _PWM_def_h_

#pragma __FunCX_Section Begin

#include "TC_Ext.var.h"
#include "PWM.var.h"

#include "TC_Basic.h"

#pragma __FunCX_InLevel_Except Begin

// Common Syntax for ICFTop Check.
#define Set_DutyRatio_PWM_D_Check_ICFTop_Block(__PeriNum) \
  IfSafe_(_TTOptInfo.IsICFTop, Set_ICaptureReg_TC##__PeriNum(_TDutyValue); )

// Common Syntax for Toggle Mode Check.
#define Set_DutyRatio_PWM_D_Check_ToggleMode_And_Isnt_ChanA_Block(__PeriNum) \
  IfSafe_(_TTOptInfo.IsToggleMode && Channel != ChanA, _TDutyValue /= 2; )

// Common Syntax for Toggle Mode Check.
#define Set_DutyRatio_PWM_D_Check_Isnt_ToggleMode_And_ChanA_Block(__PeriNum, __Channel) \
  IfSafe_(!(_TTOptInfo.IsToggleMode && __Channel == ChanA), \
    Set_COMode_TC##__PeriNum(((!_TTOptInfo.IsInvertPWM[__Channel]) ? COM_NONINV : COM_INV), __Channel); \
  )
// ICFTop Check for 8bit Peripherals.
#if defined(TCCR0) || defined(TCCR2)
#define Set_DutyRatio_PWM_D_Check_ICFTop_Block_8bit(__PeriNum) \
  Null_Syntax_
#else
#define Set_DutyRatio_PWM_D_Check_ICFTop_Block_8bit(__PeriNum) \
  Null_Syntax_
#endif

// ICFTop Check for 16bit Peripherals.
#define Set_DutyRatio_PWM_D_Check_ICFTop_Block_16bit(__PeriNum) \
  Set_DutyRatio_PWM_D_Check_ICFTop_Block(__PeriNum)

// Toggle Mode and isn't Channel A Check for 8bit Peripherals.
#if defined(TCCR0) || defined(TCCR2)
#define Set_DutyRatio_PWM_D_Check_ToggleMode_And_Isnt_ChanA_Block_8bit(__PeriNum) \
  Null_Syntax_
#else
#define Set_DutyRatio_PWM_D_Check_ToggleMode_And_Isnt_ChanA_Block_8bit(__PeriNum) \
  Set_DutyRatio_PWM_D_Check_ToggleMode_And_Isnt_ChanA_Block(__PeriNum)
#endif

// Toggle Mode and isn't Channel A Check for 16bit Peripherals.
#define Set_DutyRatio_PWM_D_Check_ToggleMode_And_Isnt_ChanA_Block_16bit(__PeriNum) \
  Set_DutyRatio_PWM_D_Check_ToggleMode_And_Isnt_ChanA_Block(__PeriNum)

// isn't (Toggle Mode Check and Channel A) for 8bit Peripherals.
#if defined(TCCR0) || defined(TCCR2)
#define Set_DutyRatio_PWM_D_Check_Isnt_ToggleMode_And_ChanA_Block_8bit(__PeriNum, __Channel) \
  Null_Syntax_
#else
#define Set_DutyRatio_PWM_D_Check_Isnt_ToggleMode_And_ChanA_Block_8bit(__PeriNum, __Channel) \
  Set_DutyRatio_PWM_D_Check_Isnt_ToggleMode_And_ChanA_Block(__PeriNum, __Channel)
#endif

// isn't (Toggle Mode Check and Channel A) for 16bit Peripherals.
#define Set_DutyRatio_PWM_D_Check_Isnt_ToggleMode_And_ChanA_Block_16bit(__PeriNum, __Channel) \
  Set_DutyRatio_PWM_D_Check_Isnt_ToggleMode_And_ChanA_Block(__PeriNum, __Channel)

// Duty is Percentage.
// In this case, "A Channel" is the reference Period.
// Therefore, the duty should not be set.
#define Set_DutyRatio_PWM_D_Proto(__PeriNum, __PeriBit, __Channel, __DutyRatio) \
  C_( \
    TCFreqOptiValueStoreage _TTCOVInfo = Get_TCOVInfo(__PeriNum); \
    TCChanOptionsInformations _TTOptInfo = Get_TOptInfo(__PeriNum); \
    IfSafe_(_TTCOVInfo.TCCalcValInfo.Able, \
      unsigned int _TDutyValue = _TTCOVInfo.TCCalcValInfo.Top; \
      \
      Set_DutyRatio_PWM_D_Check_ICFTop_Block_##__PeriBit##bit(__PeriNum) \
      Set_DutyRatio_PWM_D_Check_ToggleMode_And_Isnt_ChanA_Block_##__PeriBit##bit(__PeriNum) \
      \
      _TDutyValue *= __DutyRatio / 100.0f; \
      \
      Set_DutyRatio_PWM_D_Check_Isnt_ToggleMode_And_ChanA_Block_##__PeriBit##bit(__PeriNum, __Channel) \
      \
      Set_OCompareReg_TC##__PeriNum(_TDutyValue, __Channel); \
    ) \
  )

#pragma __FunCX_InLevel_Except End

// T/C 0(8 bit)
#if defined(TCCR0)
#define Set_DutyRatio_PWM0_D(DutyRatio) \
  Set_DutyRatio_PWM_D_Proto(0, 8, ChanA, DutyRatio)
#else
#define Set_DutyRatio_PWM0_D(Channel, DutyRatio) \
  Set_DutyRatio_PWM_D_Proto(0, 8, Channel, DutyRatio)
#endif

// T/C 1(16 bit)
#if defined(TCCR1A)
#define Set_DutyRatio_PWM1_D(Channel, DutyRatio) \
  Set_DutyRatio_PWM_D_Proto(1, 16, Channel, DutyRatio)
#endif

// T/C 2(8 bit)
#if defined(TCCR2)
#define Set_DutyRatio_PWM2_D(DutyRatio) \
  Set_DutyRatio_PWM_D_Proto(2, 8, ChanA, DutyRatio)
#else
#define Set_DutyRatio_PWM2_D(Channel, DutyRatio) \
  Set_DutyRatio_PWM_D_Proto(2, 8, Channel, DutyRatio)
#endif

// T/C 3(16 bit)
#if defined(TCCR3A)
#define Set_DutyRatio_PWM3_D(Channel, DutyRatio) \
  Set_DutyRatio_PWM_D_Proto(3, 16, Channel, DutyRatio)
#endif

// T/C 3(16 bit)
#if defined(TCCR4A)
#define Set_DutyRatio_PWM4_D(Channel, DutyRatio) \
  Set_DutyRatio_PWM_D_Proto(4, 16, Channel, DutyRatio)
#endif

// T/C 3(16 bit)
#if defined(TCCR5A)
#define Set_DutyRatio_PWM5_D(Channel, DutyRatio) \
  Set_DutyRatio_PWM_D_Proto(5, 16, Channel, DutyRatio)
#endif

#pragma __FunCX_Section End

#endif // _PWM_def_h_
