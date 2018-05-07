/*********************************************************************

          File: TC_Basic.const.h

   Description: AVR TC basic Constants definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/06

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_Basic_const_h_
#define _TC_Basic_const_h_

#pragma __FunCX_Section Begin

#include "TC.const.h"

#pragma __FunCX_InLevel_Except Begin

#define PWM_Peripheral_Qty TE_HAVE_TC_QTY
#define PWM_Prescalar_Qty TC_Prescalar_Qty

// This section is define for PWM Mode.
// fixed T/C Mode lists.
#define NORMODE 0

// Fast PWM Mode lists.
#define FPWM_8 11
#define FPWM_9 12
#define FPWM_10 13

// Phase Correct PWM Mode lists.
#define PCPWM_8 21
#define PCPWM_9 22
#define PCPWM_10 23

// Variodic T/C Mode lists.
#define FPWM_V 31 // Fast PWM Mode
#define CTCMODE 32 // CTC Mode
#define PCPWM_V 33 // Phase Correct PWM Mode
#define PFCPWM 34 // Phase and Frquency Correct PWM Mode

//#define TCMODE_QTY 11

#define TC_DEFAULT_FREQERR_MARGIN 5.0f
#define TC_MAX_FREQERR_MARGIN 20.0f

#define TC_MODE_NORMODE false
#define TC_MODE_OTHERS true

// Definition of "Array of Registers".
// for Waveform Generation Mode.
#define TCWGMArr_S Begin_
#define TCWGMArr_BitsBasic(__PeriNum) \
  WGM##__PeriNum##0, WGM##__PeriNum##1
#define TCWGMArr_BitsEx1(__PeriNum) \
  , WGM##__PeriNum##2
#define TCWGMArr_BitsEx2(__PeriNum) \
  , WGM##__PeriNum##3
#define TCWGMArr_E End_

#if defined(TCCR0) || defined(TCCR2)
#define TCWGMArr_8bit(__PeriNum) \
  TCWGMArr_S TCWGMArr_BitsBasic(__PeriNum) TCWGMArr_E
#else
#define TCWGMArr_8bit(__PeriNum) \
  TCWGMArr_S TCWGMArr_BitsBasic(__PeriNum) TCWGMArr_BitsEx1(__PeriNum) TCWGMArr_E
#endif
#define TCWGMArr_16bit(__PeriNum) \
  TCWGMArr_S TCWGMArr_BitsBasic(__PeriNum) TCWGMArr_BitsEx1(__PeriNum) TCWGMArr_BitsEx2(__PeriNum) TCWGMArr_E

// Definition of "Initial Array forms of T/C Waveform Generation mode information values."
// via "_TCWGMNBitPeriInfo"
#define InitialFormWGModeValues \
  Begin_ \
    NORMODE, 0, 'n', false \
  End_ \

// Definition of "Initial Array forms of T/C Frequency Calculation values."
// via "_TCCalcValueInformations"
#define InitialFormFreqCalcValues \
  Begin_ \
    false, 65535, 0, 1025, 255, 0.0f, 0.0f, 100.0f \
  End_ \

// Definition of "Initial Array forms of T/C Frequency optimal values."
// via "_TCFreqOptiValueStoreage"
#define InitialFormFreqOptiValues \
  Begin_ \
    InitialFormWGModeValues \
    , \
    InitialFormFreqCalcValues \
  End_

// T/C 0
#if defined(TCCR0) || defined(TCCR0A)
#define InitialFormFreqOptiValues0 InitialFormFreqOptiValues
#endif

// T/C 1
#if defined(TCCR1A)
#define InitialFormFreqOptiValues1 , InitialFormFreqOptiValues
#else
#define InitialFormFreqOptiValues1 Null_
#endif

// T/C 2
#if defined(TCCR2) || defined(TCCR2A)
#define InitialFormFreqOptiValues2 , InitialFormFreqOptiValues
#else
#define InitialFormFreqOptiValues2 Null_
#endif

// T/C 3
#if defined(TCCR3A)
#define InitialFormFreqOptiValues3 , InitialFormFreqOptiValues
#else
#define InitialFormFreqOptiValues3 Null_
#endif

// T/C 4
#if defined(TCCR4A)
#define InitialFormFreqOptiValues4 , InitialFormFreqOptiValues
#else
#define InitialFormFreqOptiValues4 Null_
#endif

// T/C 5
#if defined(TCCR5A)
#define InitialFormFreqOptiValues5 , InitialFormFreqOptiValues
#else
#define InitialFormFreqOptiValues5 Null_
#endif

#define InitialFormFreqOptiValuesArr \
  Begin_ \
    InitialFormFreqOptiValues0 \
    InitialFormFreqOptiValues1 \
    InitialFormFreqOptiValues2 \
    InitialFormFreqOptiValues3 \
    InitialFormFreqOptiValues4 \
    InitialFormFreqOptiValues5 \
  End_

// Definition of "Initial Array forms of T/C Frequency optimal values."
// via "_TCFreqOptiValueStoreage"
#define InitialFormDefaultAutoModeValue \
  TC_MODE_NORMODE

// T/C 0
#if defined(TCCR0) || defined(TCCR0A)
#define InitialFormDefaultAutoModeValue0 InitialFormDefaultAutoModeValue
#endif

// T/C 1
#if defined(TCCR1A)
#define InitialFormDefaultAutoModeValue1 , InitialFormDefaultAutoModeValue
#else
#define InitialFormDefaultAutoModeValue1 Null_
#endif

// T/C 2
#if defined(TCCR2) || defined(TCCR2A)
#define InitialFormDefaultAutoModeValue2 , InitialFormDefaultAutoModeValue
#else
#define InitialFormDefaultAutoModeValue2 Null_
#endif

// T/C 3
#if defined(TCCR3A)
#define InitialFormDefaultAutoModeValue3 , InitialFormDefaultAutoModeValue
#else
#define InitialFormDefaultAutoModeValue3 Null_
#endif

// T/C 4
#if defined(TCCR4A)
#define InitialFormDefaultAutoModeValue4 , InitialFormDefaultAutoModeValue
#else
#define InitialFormDefaultAutoModeValue4 Null_
#endif

// T/C 5
#if defined(TCCR5A)
#define InitialFormDefaultAutoModeValue5 , InitialFormDefaultAutoModeValue
#else
#define InitialFormDefaultAutoModeValue5 Null_
#endif

#define InitialFormDefaultAutoModeValuesArr \
  Begin_ \
    InitialFormDefaultAutoModeValue0 \
    InitialFormDefaultAutoModeValue1 \
    InitialFormDefaultAutoModeValue2 \
    InitialFormDefaultAutoModeValue3 \
    InitialFormDefaultAutoModeValue4 \
    InitialFormDefaultAutoModeValue5 \
  End_

#pragma __FunCX_InLevel_Except End

#pragma __FunCX_Section End

#endif // _TC_Basic_const_h_
