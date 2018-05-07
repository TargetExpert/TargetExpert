/*********************************************************************

          File: USART.def.h

   Description: AVR USART syntax definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/03/08

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _USART_def_h_
#define _USART_def_h_

#pragma __FunCX_Section Begin

#include <stdbool.h>

#include <math.h>

#include "AVR_machines.h"
#include "BasicFunc_Mac.h"
#include "BitSet_Mac.h"

#pragma __FunCX_InLevel_Except Begin

#define AVR_MODE_BIT(__Num) __Num

// Definition of "Quantity of Register Bits".
#define UCSZ_BQTY AVR_MODE_BIT(3)
#define UPM_BQTY AVR_MODE_BIT(2)
#define USBS_BQTY AVR_MODE_BIT(1)
#define UMSEL_BQTY AVR_MODE_BIT(2)

// Definition of "Array of Registers".
// for Character Size.
#define USARTUCSZArr_S Begin_
#define USARTUCSZArr_BitsBasic(__PeriNum) \
  UCSZ##__PeriNum##0, UCSZ##__PeriNum##1, UCSZ##__PeriNum##2
#define USARTUCSZArr_E End_

#define USARTUCSZArr(__PeriNum) \
  USARTUCSZArr_S USARTUCSZArr_BitsBasic(__PeriNum) USARTUCSZArr_E

#pragma __FunCX_InLevel_Except End

#pragma __FunCX_InLevel_Except Begin
/*
 * Calculation for Baud Rate to UBRR Function.
 *
 * Descriptions : Set for Waveform Generation Mode.
 *
 * Return Type : unsigned int
 * Params :
 * 1. BaudRate - This is the BaudRate value to convert to UBRR.
 */

#define Calc_BaudRateToUBRR(__PeriNum, __BaudRate) \
  ((unsigned int)(F_CPU / ((bit_is_set(UCSR##__PeriNum##A, U2X##__PeriNum) ? 1 : 2) * 8 * __BaudRate)) - 1)
#pragma __FunCX_InLevel_Except End

// Set_BaudRate_USART(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_BaudRate_USART_D_Proto(__PeriNum, __BaudRate) \
  C_( \
    unsigned int _TUBRR = Calc_BaudRateToUBRR(__PeriNum, __BaudRate); \
    UBRR##__PeriNum##H = (unsigned char)(_TUBRR >> 8); \
    UBRR##__PeriNum##L = (unsigned char)_TUBRR; \
  )
#pragma __FunCX_InLevel_Except End

// Set_CharSize_USART(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_CharSize_USART_D_Proto(__PeriNum, __CharSize) \
  Begin_ \
    uint8_t _USART_CharSize_Arr[UCSZ_BQTY] = USARTUCSZArr(__PeriNum); \
    IfSafe_(__CharSize < pow(2, UCSZ_BQTY), \
      register unsigned char i = 0; \
      ForSafe_(i = 0, i < UCSZ_BQTY, i++, \
        (i == (UCSZ_BQTY - 1)) ? \
            (sclb_reg_common(UCSR, __PeriNum, B, (__CharSize & (1 << i)), _USART, _CharSize, _Arr[i])) \
            : (sclb_reg_common(UCSR, __PeriNum, C, (__CharSize & (1 << i)), _USART, _CharSize, _Arr[i])); \
      ) \
    ) \
  End_
#pragma __FunCX_InLevel_Except End

// Set_Parity_USART(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_Parity_USART_D_Proto(__PeriNum, __Parity) \
  C_( \
    IfSafe_(__Parity < pow(2, UPM_BQTY), \
      register unsigned char i = 0; \
      ForSafe_(i = 0, i < UPM_BQTY, i++, \
        sclb_reg_common(UCSR, __PeriNum, C, (__Parity & (1 << i)), UPM, __PeriNum, 0 + i); \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_StopBit_USART(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_StopBit_USART_D_Proto(__PeriNum, __Stopbit) \
  C_( \
    IfSafe_(__Stopbit < pow(2, USBS_BQTY), \
      register unsigned char i = 0; \
      ForSafe_(i = 0, i < USBS_BQTY, i++, \
        sclb_reg_common(UCSR, __PeriNum, C, (__Stopbit & (1 << i)), USBS, __PeriNum, ); \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_SerialMode_USART(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#if defined(UMSEL00) || defined(UMSEL10) || defined(UMSEL20) || defined(UMSEL30)
#define Set_SerialMode_USART_D_Block(__PeriNum, __Mode) \
  sclb_reg_common(UCSR, __PeriNum, C, (__Mode & (1 << i)), UMSEL, __PeriNum, 0);
#else
#define Set_SerialMode_USART_D_Block(__PeriNum, __Mode) \
  sclb_reg_common(UCSR, __PeriNum, C, (__Mode & (1 << i)), UMSEL, __PeriNum, );
#endif

// Definition Prototyping.
#define Set_SerialMode_USART_D_Proto(__PeriNum, __Mode) \
  C_( \
    IfSafe_(__Mode < pow(2, UMSEL_BQTY), \
      register unsigned char i = 0; \
      ForSafe_(i = 0, i < UMSEL_BQTY, i++, \
        Set_SerialMode_USART_D_Block(__PeriNum, __Mode) \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_DoubleSpeed_USART(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#if defined(UMSEL00) || defined(UMSEL10) || defined(UMSEL20) || defined(UMSEL30)
#define Set_DoubleSpeed_USART_D_Block(__PeriNum, __Enable) \
  sclb_reg_common(UCSR, __PeriNum, A, __Enable && !bit_is_set(UCSR##__PeriNum##C, UMSEL##__PeriNum##0), U2X, __PeriNum, );
#else
#define Set_DoubleSpeed_USART_D_Block(__PeriNum, __Enable) \
  sclb_reg_common(UCSR, __PeriNum, A, __Enable && !bit_is_set(UCSR##__PeriNum##C, UMSEL##__PeriNum), U2X, __PeriNum, );
#endif

// Definition Prototyping.
#define Set_DoubleSpeed_USART_D_Proto(__PeriNum, __Enable) \
  C_( \
    Set_DoubleSpeed_USART_D_Block(__PeriNum, __Enable) \
  )
#pragma __FunCX_InLevel_Except End

// Set_Enable_USART(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_Enable_USART_D_Proto(__PeriNum, __Enable, __Target) \
  C_( \
    IfSafe_(__Target < AVR_MODE_BIT(3), \
      SwitchSafe_(__Target, \
        CaseSafe_(0, \
          sclb_reg_common(UCSR, __PeriNum, B, __Enable, TXEN, __PeriNum, ); \
        ) \
        CaseSafe_(1, \
          sclb_reg_common(UCSR, __PeriNum, B, __Enable, RXEN, __PeriNum, ); \
        ) \
        CaseSafe_(2, \
          sclb_reg_common(UCSR, __PeriNum, B, __Enable, TXEN, __PeriNum, ); \
          sclb_reg_common(UCSR, __PeriNum, B, __Enable, RXEN, __PeriNum, ); \
        ) \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_Interrupt_USART(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_Interrupt_USART_D_Proto(__PeriNum, __Enable, __Target) \
  C_( \
    IfSafe_(__Target < AVR_MODE_BIT(3), \
      SwitchSafe_(__Target, \
        CaseSafe_(0, \
          sclb_reg_common(UCSR, __PeriNum, B, __Enable, TXCIE, __PeriNum, ); \
        ) \
        CaseSafe_(1, \
          sclb_reg_common(UCSR, __PeriNum, B, __Enable, RXCIE, __PeriNum, ); \
        ) \
        CaseSafe_(2, \
          sclb_reg_common(UCSR, __PeriNum, B, __Enable, TXCIE, __PeriNum, ); \
          sclb_reg_common(UCSR, __PeriNum, B, __Enable, RXCIE, __PeriNum, ); \
        ) \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

#if defined(UBRRH) || defined(UBRR0H)
#define Set_BaudRate_USART0_D(BaudRate) \
  Set_BaudRate_USART_D_Proto(0, BaudRate)
#define Set_CharSize_USART0_D(CharSize) \
  Set_CharSize_USART_D_Proto(0, CharSize)
#define Set_Parity_USART0_D(Parity) \
  Set_Parity_USART_D_Proto(0, Parity)
#define Set_StopBit_USART0_D(Stopbit) \
  Set_StopBit_USART_D_Proto(0, Stopbit)
#define Set_SerialMode_USART0_D(Mode) \
  Set_SerialMode_USART_D_Proto(0, Mode)
#define Set_DoubleSpeed_USART0_D(Enable) \
  Set_DoubleSpeed_USART_D_Proto(0, Enable)
#define Set_Enable_USART0_D(Enable, Target) \
  Set_Enable_USART_D_Proto(0, Enable, Target)
#define Set_Interrupt_USART0_D(Enable, Target) \
  Set_Interrupt_USART_D_Proto(0, Enable, Target)
#endif
#if defined(UBRR1H)
#define Set_BaudRate_USART1_D(BaudRate) \
  Set_BaudRate_USART_D_Proto(1, BaudRate)
#define Set_CharSize_USART1_D(CharSize) \
  Set_CharSize_USART_D_Proto(1, CharSize)
#define Set_Parity_USART1_D(Parity) \
  Set_Parity_USART_D_Proto(1, Parity)
#define Set_StopBit_USART1_D(Stopbit) \
  Set_StopBit_USART_D_Proto(1, Stopbit)
#define Set_SerialMode_USART1_D(Mode) \
  Set_SerialMode_USART_D_Proto(1, Mode)
#define Set_DoubleSpeed_USART1_D(Enable) \
  Set_DoubleSpeed_USART_D_Proto(1, Enable)
#define Set_Enable_USART1_D(Enable, Target) \
  Set_Enable_USART_D_Proto(1, Enable, Target)
#define Set_Interrupt_USART1_D(Enable, Target) \
  Set_Interrupt_USART_D_Proto(1, Enable, Target)
#endif
#if defined(UBRR2H)
#define Set_BaudRate_USART2_D(BaudRate) \
  Set_BaudRate_USART_D_Proto(2, BaudRate)
#define Set_CharSize_USART2_D(CharSize) \
  Set_CharSize_USART_D_Proto(2, CharSize)
#define Set_Parity_USART2_D(Parity) \
  Set_Parity_USART_D_Proto(2, Parity)
#define Set_StopBit_USART2_D(Stopbit) \
  Set_StopBit_USART_D_Proto(2, Stopbit)
#define Set_SerialMode_USART2_D(Mode) \
  Set_SerialMode_USART_D_Proto(2, Mode)
#define Set_DoubleSpeed_USART2_D(Enable) \
  Set_DoubleSpeed_USART_D_Proto(2, Enable)
#define Set_Enable_USART2_D(Enable, Target) \
  Set_Enable_USART_D_Proto(2, Enable, Target)
#define Set_Interrupt_USART2_D(Enable, Target) \
  Set_Interrupt_USART_D_Proto(2, Enable, Target)
#endif
#if defined(UBRR3H)
#define Set_BaudRate_USART3_D(BaudRate) \
  Set_BaudRate_USART_D_Proto(3, BaudRate)
#define Set_CharSize_USART3_D(CharSize) \
  Set_CharSize_USART_D_Proto(3, CharSize)
#define Set_Parity_USART3_D(Parity) \
  Set_Parity_USART_D_Proto(3, Parity)
#define Set_StopBit_USART3_D(Stopbit) \
  Set_StopBit_USART_D_Proto(3, Stopbit)
#define Set_SerialMode_USART3_D(Mode) \
  Set_SerialMode_USART_D_Proto(3, Mode)
#define Set_DoubleSpeed_USART3_D(Enable) \
  Set_DoubleSpeed_USART_D_Proto(3, Enable)
#define Set_Enable_USART3_D(Enable, Target) \
  Set_Enable_USART_D_Proto(3, Enable, Target)
#define Set_Interrupt_USART3_D(Enable, Target) \
  Set_Interrupt_USART_D_Proto(3, Enable, Target)
#endif

#pragma __FunCX_Section End

#endif // _USART_def_h_
