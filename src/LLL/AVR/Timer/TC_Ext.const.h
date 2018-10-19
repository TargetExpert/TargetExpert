/*********************************************************************

          File: TC_Ext.const.h

   Description: AVR TC extended Constants definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/12

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_Ext_const_h_
#define _TC_Ext_const_h_

#include "TC_Basic.const.h"

// Definition of "Array of Prescaler".
// {1, 8, 32, 64, 128, 256, 1024}
#define TCPrescalerArr_Type1 \
  Begin_ Prescale_1, Prescale_8, Prescale_32, Prescale_64, Prescale_128, Prescale_256, Prescale_1024 End_
// {1, 8, 64, 256, 1024, EXT_CLOCK_FALL, EXT_CLOCK_RISING}
#define TCPrescalerArr_Type2 \
  Begin_ Prescale_1, Prescale_8, Prescale_64, Prescale_256, Prescale_1024, Prescale_Clock_Fall, Prescale_Clock_Rising End_
#define TCPrescalerArr_Void \
  Begin_ Prescale_Void, Prescale_Void, Prescale_Void, Prescale_Void, Prescale_Void, Prescale_Void, Prescale_Void End_

// T/C 0
#if defined(TCCR0)
#define TCPrescalerArr_PeriNum0 TCPrescalerArr_Type1
#else
#define TCPrescalerArr_PeriNum0 TCPrescalerArr_Type2
#endif

// T/C 1
#if defined(TCCR1A)
#define TCPrescalerArr_PeriNum1 , TCPrescalerArr_Type2
#endif

// T/C 2
#if defined(TCCR2)
#define TCPrescalerArr_PeriNum2 , TCPrescalerArr_Type2
#else
#define TCPrescalerArr_PeriNum2 , TCPrescalerArr_Type1
#endif

// T/C 3
#if defined(TCCR3A)
#define TCPrescalerArr_PeriNum3 , TCPrescalerArr_Type2
#else
#define TCPrescalerArr_PeriNum3 Null_
#endif

// T/C 4
#if defined(TCCR4A)
#define TCPrescalerArr_PeriNum4 , TCPrescalerArr_Type2
#else
#define TCPrescalerArr_PeriNum4 Null_
#endif

// T/C 5
#if defined(TCCR5A)
#define TCPrescalerArr_PeriNum5 , TCPrescalerArr_Type2
#else
#define TCPrescalerArr_PeriNum5 Null_
#endif

#define TCPrescalerArr \
  Begin_ \
    TCPrescalerArr_PeriNum0 \
    TCPrescalerArr_PeriNum1 \
    TCPrescalerArr_PeriNum2 \
    TCPrescalerArr_PeriNum3 \
    TCPrescalerArr_PeriNum4 \
    TCPrescalerArr_PeriNum5 \
  End_

// Definition of "Array of Peripherals at Device".
// T/C 0
#if defined(TCCR0) || defined(TCCR0A)
#define TCPeri_Bit_PeriNum0 TC_ResBit(0)
#endif

// T/C 1
#if defined(TCCR1A)
#define TCPeri_Bit_PeriNum1 , TC_ResBit(1)
#else
#define TCPeri_Bit_PeriNum1 Null__
#endif

// T/C 2
#if defined(TCCR2) || defined(TCCR2A)
#define TCPeri_Bit_PeriNum2 , TC_ResBit(2)
#else
#define TCPeri_Bit_PeriNum1 Null__
#endif

// T/C 3
#if defined(TCCR3A)
#define TCPeri_Bit_PeriNum3 , TC_ResBit(3)
#else
#define TCPeri_Bit_PeriNum3 Null_
#endif

// T/C 4
#if defined(TCCR4A)
#define TCPeri_Bit_PeriNum4 , TC_ResBit(4)
#else
#define TCPeri_Bit_PeriNum4 Null_
#endif

// T/C 5
#if defined(TCCR5A)
#define TCPeri_Bit_PeriNum5 , TC_ResBit(5)
#else
#define TCPeri_Bit_PeriNum5 Null_
#endif

#define TCPeriBitInfoArr \
  Begin_ \
    TCPeri_Bit_PeriNum0 \
    TCPeri_Bit_PeriNum1 \
    TCPeri_Bit_PeriNum2 \
    TCPeri_Bit_PeriNum3 \
    TCPeri_Bit_PeriNum4 \
    TCPeri_Bit_PeriNum5 \
  End_

// Definition of "Array of Channel Quantity of a Peripheral".
// T/C 0
#if defined(TCCR0)
#define TCChan_Qty_PeriNum0 0
#else
#define TCChan_Qty_PeriNum0 2
#endif

// T/C 1
#if defined(__AVR_ATmega128__)
#define TCChan_Qty_PeriNum1 , 3
#else
#define TCChan_Qty_PeriNum1 , 2
#endif

// T/C 2
#if defined(TCCR2)
#define TCChan_Qty_PeriNum2 , 1
#else
#define TCChan_Qty_PeriNum2 , 2
#endif

// T/C 3
#if defined(TCCR3A)
#define TCChan_Qty_PeriNum3 , 3
#else
#define TCChan_Qty_PeriNum3 Null_
#endif

// T/C 4
#if defined(TCCR4A)
#define TCChan_Qty_PeriNum4 , 3
#else
#define TCChan_Qty_PeriNum4 Null_
#endif

// T/C 5
#if defined(TCCR5A)
#define TCChan_Qty_PeriNum5 , 3
#else
#define TCChan_Qty_PeriNum5 Null_
#endif

#define TCPeriChanQtyInfoArr \
  Begin_ \
    TCChan_Qty_PeriNum0 \
    TCChan_Qty_PeriNum1 \
    TCChan_Qty_PeriNum2 \
    TCChan_Qty_PeriNum3 \
    TCChan_Qty_PeriNum4 \
    TCChan_Qty_PeriNum5 \
  End_

// Definition of "Initial Array forms of T/C (n)bit Waveform Generation values."
#if defined(TCCR0) || defined(TCCR2)
#define TC8BitWGModeArr \
  Begin_ \
    Begin_ NORMODE , 0, 'n', false, 0, 0 End_, \
    Begin_ CTCMODE, 2, 'c', true, 2, 0 End_, \
    Begin_ FPWM_8 , 3, 'f', false, 3, 0 End_, \
    Begin_ PCPWM_8 , 1, 'p', false, 1, 0 End_, \
  End_
#define TC8BitPWMModeMaxQty 4
#else
#define TC8BitWGModeArr \
  Begin_ \
    Begin_ NORMODE , 0, 'n', false, 0, 0 End_, \
    Begin_ CTCMODE, 2, 'c', true, 2, 0 End_, \
    Begin_ FPWM_8 , 3, 'f', false, 3, 0 End_, \
    Begin_ PCPWM_8 , 1, 'p', false, 1, 0 End_, \
    Begin_ FPWM_V , 7, 'f', true, 7, 0 End_, \
    Begin_ PCPWM_V , 5, 'p', true, 5, 0 End_ \
  End_
#define TC8BitPWMModeMaxQty 6
#endif

#define TC16BitWGModeArr \
  Begin_ \
    Begin_ NORMODE , 0, 'n', false, 0, 0 End_, \
    Begin_ CTCMODE , 4, 'c', true, 4, 8 End_, \
    Begin_ FPWM_8 , 5, 'f', false, 5, 0 End_, \
    Begin_ FPWM_9 , 6, 'f', false, 6, 0 End_, \
    Begin_ FPWM_10 , 7, 'f', false, 7, 0 End_, \
    Begin_ FPWM_V , 15, 'f', true, 15, -1 End_, \
    Begin_ PCPWM_8 , 1, 'p', false, 1, 0 End_, \
    Begin_ PCPWM_9 , 2, 'p', false, 2, 0 End_, \
    Begin_ PCPWM_10 , 3, 'p', false, 3, 0 End_, \
    Begin_ PCPWM_V , 11, 'p', true, 11, -1 End_, \
    Begin_ PFCPWM , 9, 'a', true, 9, -1 End_ \
  End_
#define TC16BitPWMModeMaxQty 11

#define ModeArrMaxQty TC16BitPWMModeMaxQty

#define TCPWMModeValueArr \
  Begin_ \
    TC8BitPWMModeMaxQty \
    , \
    TC16BitPWMModeMaxQty \
  End_

// Definition of "Initial Array forms of T/C Frequency optimal values."
#if TC_NBit_Peri_Ch_MaxQty >= 1
#define InvertPWMArrElem0 false,
#endif
#if TC_NBit_Peri_Ch_MaxQty >= 2
#define InvertPWMArrElem1 false,
#else
#define InvertPWMArrElem1 Null_
#endif
#if TC_NBit_Peri_Ch_MaxQty >= 3
#define InvertPWMArrElem2 false
#else
#define InvertPWMArrElem2 Null_
#endif

#define InitialFormOptInfoValues \
  Begin_ \
    false, \
    Begin_ \
      InvertPWMArrElem0 \
      InvertPWMArrElem1 \
      InvertPWMArrElem2 \
    End_, \
    false, TC_MAX_FREQERR_MARGIN \
  End_

// T/C 0
#if defined(TCCR0) || defined(TCCR0A)
#define InitialFormOptInfoValues0 InitialFormOptInfoValues
#endif

// T/C 1
#if defined(TCCR1A)
#define InitialFormOptInfoValues1 , InitialFormOptInfoValues
#else
#define InitialFormOptInfoValues1 Null_
#endif

// T/C 2
#if defined(TCCR2) || defined(TCCR2A)
#define InitialFormOptInfoValues2 , InitialFormOptInfoValues
#else
#define InitialFormOptInfoValues2 Null_
#endif

// T/C 3
#if defined(TCCR3A)
#define InitialFormOptInfoValues3 , InitialFormOptInfoValues
#else
#define InitialFormOptInfoValues3 Null_
#endif

// T/C 4
#if defined(TCCR4A)
#define InitialFormOptInfoValues4 , InitialFormOptInfoValues
#else
#define InitialFormOptInfoValues4 Null_
#endif

// T/C 5
#if defined(TCCR5A)
#define InitialFormOptInfoValues5 , InitialFormOptInfoValues
#else
#define InitialFormOptInfoValues5 Null_
#endif

#define InitialFormOptInfoValuesArr \
  Begin_ \
    InitialFormOptInfoValues0 \
    InitialFormOptInfoValues1 \
    InitialFormOptInfoValues2 \
    InitialFormOptInfoValues3 \
    InitialFormOptInfoValues4 \
    InitialFormOptInfoValues5 \
  End_

#define DIFF_MARGIN_FREQ_VALUE (100) // Unit is Hz.

#define EXT_CLOCK_FALL 1025
#define EXT_CLOCK_RISING 1026

#define PWM_8_MAX (255)

#pragma __FunCX_InLevel_Except End

#endif // _TC_Ext_const_h_
