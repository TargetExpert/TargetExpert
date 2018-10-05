/*********************************************************************

          File: TC.const.h

   Description: AVR TC essential Constants definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/21

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_const_h_
#define _TC_const_h_

#include "Common.inc.h"

#define AVR_MODE_BIT(__Num) __Num

// Definition of "Quantity of T/C Peripherals".
#if defined(TCCR0) || defined(TCCR0A)
#ifndef TE_HAVE_TC_QTY
#define TE_HAVE_TC_QTY 1
#endif
#endif
#if defined(TCCR1A)
#if defined(TE_HAVE_TC_QTY)
#undef TE_HAVE_TC_QTY
#endif
#define TE_HAVE_TC_QTY 2
#endif
#if defined(TCCR2) || defined(TCCR2A)
#if defined(TE_HAVE_TC_QTY)
#undef TE_HAVE_TC_QTY
#endif
#define TE_HAVE_TC_QTY 3
#endif
#if defined(TCCR3A)
#if defined(TE_HAVE_TC_QTY)
#undef TE_HAVE_TC_QTY
#endif
#define TE_HAVE_TC_QTY 4
#endif
#if defined(TCCR4A)
#if defined(TE_HAVE_TC_QTY)
#undef TE_HAVE_TC_QTY
#endif
#define TE_HAVE_TC_QTY 5
#endif
#if defined(TCCR5A)
#if defined(TE_HAVE_TC_QTY)
#undef TE_HAVE_TC_QTY
#endif
#define TE_HAVE_TC_QTY 6
#endif

// Definition of "T/C Resolution Bit of Peripherals".
#define TC_Res_8Bit 8
#define TC_Res_16Bit 16

#if defined(TCCR0) || defined(TCCR0A)
#define TC_0_ResBit TC_Res_8Bit
#endif
#if defined(TCCR1A)
#define TC_1_ResBit TC_Res_16Bit // 16
#endif
#if defined(TCCR2) || defined(TCCR2A)
#define TC_2_ResBit TC_Res_8Bit // 8
#endif
#if defined(TCCR3A)
#define TC_3_ResBit TC_Res_16Bit // 16
#endif
#if defined(TCCR4A)
#define TC_4_ResBit TC_Res_16Bit // 16
#endif
#if defined(TCCR5A)
#define TC_5_ResBit TC_Res_16Bit // 16
#endif

#define TC_ResBit(__PeriNum) \
  TC_##__PeriNum##_ResBit

// Definition of "Channel of a Peripherals".
#if defined(TCCR0) || defined(TCCR2) || defined(COM0A0) || defined(COM1A0) || defined(COM2A0) || defined(COM3A0)
#define ChanA 0
#endif
#if defined(COM0B0) || defined(COM1B0) || defined(COM2B0) || defined(COM3B0)
#define ChanB 1
#endif
#if defined(COM0C0) || defined(COM1C0) || defined(COM2C0) || defined(COM3C0)
#define ChanC 2
#endif

// definition of "Compare modes".
#define COM_NORMAL 0
#define COM_TOGGLE 1
#define COM_NONINV 2
#define COM_INV 3

// Definition of "Quantity of Channel Quantity of a Peripheral".
// for 8bit Peripherals.
#if defined(TCCR0) || defined(TCCR2)
// 8bit One channel.
#define TC_8Bit_Peri_Ch_Qty 1
#else
// 8bit Two channels.
#define TC_8Bit_Peri_Ch_Qty 2
#endif
// for 16bit Peripherals.
#if defined(COM1C0) || defined(COM3C0)
// 16bit Three channels.
#define TC_16Bit_Peri_Ch_Qty 3
#else
// 16bit Two channels.
#define TC_16Bit_Peri_Ch_Qty 2
#endif

#if (TC_16Bit_Peri_Ch_Qty >= TC_8Bit_Peri_Ch_Qty)
#define TC_NBit_Peri_Ch_MaxQty TC_16Bit_Peri_Ch_Qty
#elif (TC_16Bit_Peri_Ch_Qty < TC_8Bit_Peri_Ch_Qty)
#define TC_NBit_Peri_Ch_MaxQty TC_8Bit_Peri_Ch_Qty
#endif

// Definition of "Quantity of Register Bits for Waveform Generation Mode".
#if defined(TCCR0) || defined(TCCR2)
#define TC_8bit_Peri_WGMode_Qty 2 // 2^2 = 4 mode Qty.(8bit, one channel)
#else
#define TC_8bit_Peri_WGMode_Qty 3 // 2^3 = 8 mode Qty.(8bit, two channel)
#endif
#define TC_16bit_Peri_WGMode_Qty 4 // 2^4 = 16 mode Qty.(16bit only, three channel)

// Definition of "Quantity of Register Bits".
#define WGM_BQTY_8Bit AVR_MODE_BIT(TC_8bit_Peri_WGMode_Qty) // Qty. for WGMn Register Bits(8bit T/C).
#define WGM_BQTY_16Bit AVR_MODE_BIT(TC_16bit_Peri_WGMode_Qty) // Qty. for WGMn Register Bits(16Bit T/C).

#define CS_BQTY AVR_MODE_BIT(3) // Common to 8/16bit T/C Periperals.
#define COM_BQTY AVR_MODE_BIT(2) // Common to 8/16bit T/C Periperals.

// Definition of "Quantity of Period Type".
#define TC_Prescalar_Qty 7

// Definition of "Kind of Period".
#define Prescale_1 1
#define Prescale_8 8
#define Prescale_32 32
#define Prescale_64 64
#define Prescale_128 128
#define Prescale_256 256
#define Prescale_1024 1024
// others
#define Prescale_Clock_Fall 1025
#define Prescale_Clock_Rising 1026
#define Prescale_Void 1027

#endif // _TC_const_h_
