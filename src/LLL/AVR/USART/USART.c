/*********************************************************************

          File: USART.c

   Description: AVR USART Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/01/09

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "USART.h"

/*
 * This section is USART setting Functions.
 */

//#define AVR_MODE_BIT(__Num) __Num


/*
 * Baud Rate Setting Function.
 *
 * Descriptions : Set Baud Rate to UBRRnL and UBRRnH.
 *
 * Return Type : void
 * Params :
 * 1. BaudRate - Input your wish Baud rate.
 */

#define Set_BaudRate_USART_Func(__PeriNum) \
  DECL_FUNC(, void, Set_BaudRate_USART##__PeriNum, unsigned long BaudRate) \
  Set_BaudRate_USART##__PeriNum##_D(BaudRate)

/*
 * Character Size(Data Bit) Setting Function.
 *
 * Descriptions : Set for Character Size(Data Bit).
 *
 * Return Type : void
 * Params :
 * 1. CharSize - Input your wish Character Size(Data Bit).
 *               Character size is 0 : 5bit, 1 : 6bit, 2 : 7bit, 3 : 8bit, 7 : 9bit
 */

#define Set_CharSize_USART_Func(__PeriNum) \
  DECL_FUNC(, void, Set_CharSize_USART##__PeriNum, unsigned char CharSize) \
  Set_CharSize_USART##__PeriNum##_D(CharSize)

/*
 * Parity bit Setting Function.
 *
 * Descriptions : Set for Parity bit.
 *
 * Return Type : void
 * Params :
 * 1. Parity - Input your wish Parity bit.
 *             0 : No parity, 2 : Enabled, Even, 3 : Enabled, Odd
 */

#define Set_Parity_USART_Func(__PeriNum) \
  DECL_FUNC(, void, Set_Parity_USART##__PeriNum, unsigned char Parity) \
  Set_Parity_USART##__PeriNum##_D(Parity)

/*
 * Stop bit Setting Function.
 *
 * Descriptions : Set for Stop bit.
 *
 * Return Type : void
 * Params :
 * 1. StopBit - Input your wish Stop bit.
 *              0 : 1bit, 1 : 2bits
 */

#define Set_StopBit_USART_Func(__PeriNum) \
  DECL_FUNC(, void, Set_StopBit_USART##__PeriNum, unsigned char Stopbit) \
  Set_StopBit_USART##__PeriNum##_D(Stopbit)

/*
 * Serial Mode Setting Function.
 *
 * Descriptions : Set for kind of mode to Serial Activate.
 *
 * Return Type : void
 * Params :
 * 1. Mode - Set or unset for UMSELn(or UMSELn(b) on ATMega328) bit on UCSRnC register.
 */

#define Set_SerialMode_USART_Func(__PeriNum) \
  DECL_FUNC(, void, Set_SerialMode_USART##__PeriNum, unsigned char Mode) \
  Set_SerialMode_USART##__PeriNum##_D(Mode)

/*
 * Double Speed Setting Function.
 *
 * Descriptions : Set a Double Speed Mode if phriperal enable to Async mode.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for U2Xn bit on UCSRnA register.
 */

#define Set_DoubleSpeed_USART_Func(__PeriNum) \
  DECL_FUNC(, void, Set_DoubleSpeed_USART##__PeriNum, bool Enable) \
  Set_DoubleSpeed_USART##__PeriNum##_D(Enable)

/*
 * USART Enable Setting Function.
 *
 * Descriptions : Enable/Disable set for USART.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for TXENn or RXENn bit on UCSRnB register.
 *             false : disable, true : enable
 * 2. Target - Select of Enable target for Tx or Rx or Both.
 *             0 : Tx, 1 : Rx, 2 : Both
 */

#define Set_Enable_USART_Func(__PeriNum) \
  DECL_FUNC(, void, Set_Enable_USART##__PeriNum, HELPER_PARAM_VAR(bool Enable, unsigned char Target)) \
  Set_Enable_USART##__PeriNum##_D(Enable, Target)

/*
 * Interrupt Setting Function.
 *
 * Descriptions : Enable/Disable set for Interrupt.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for TXCIEn or RXCIEn bit on UCSRmB register.
 *             false : disable, true : enable
 * 2. Target - Select of Enable target for Tx or Rx or Both.
 *             0 : Tx, 1 : Rx, 2 : Both
 */

#define Set_Interrupt_USART_Func(__PeriNum) \
  DECL_FUNC(, void, Set_Interrupt_USART##__PeriNum, HELPER_PARAM_VAR(bool Enable, unsigned char Target)) \
  Set_Interrupt_USART##__PeriNum##_D(Enable, Target)

#if defined(UBRRH) || defined(UBRR0H)
Set_BaudRate_USART_Func(0)
Set_CharSize_USART_Func(0)
Set_Parity_USART_Func(0)
Set_StopBit_USART_Func(0)
Set_SerialMode_USART_Func(0)
Set_DoubleSpeed_USART_Func(0)
Set_Enable_USART_Func(0)
Set_Interrupt_USART_Func(0)
#endif
#if defined(UBRR1H)
Set_BaudRate_USART_Func(1)
Set_CharSize_USART_Func(1)
Set_Parity_USART_Func(1)
Set_StopBit_USART_Func(1)
Set_SerialMode_USART_Func(1)
Set_DoubleSpeed_USART_Func(1)
Set_Enable_USART_Func(1)
Set_Interrupt_USART_Func(1)
#endif
#if defined(UBRR2H)
Set_BaudRate_USART_Func(2)
Set_CharSize_USART_Func(2)
Set_Parity_USART_Func(2)
Set_StopBit_USART_Func(2)
Set_SerialMode_USART_Func(2)
Set_DoubleSpeed_USART_Func(2)
Set_Enable_USART_Func(2)
Set_Interrupt_USART_Func(2)
#endif
#if defined(UBRR3H)
Set_BaudRate_USART_Func(3)
Set_CharSize_USART_Func(3)
Set_Parity_USART_Func(3)
Set_StopBit_USART_Func(3)
Set_SerialMode_USART_Func(3)
Set_DoubleSpeed_USART_Func(3)
Set_Enable_USART_Func(3)
Set_Interrupt_USART_Func(3)
#endif

/*
 * This section is USART Tx Functions(Send_*).
 */

#define Send_One_USART_Func(__PeriNum) \
  DECL_FUNC(, void, Send_One_USART##__PeriNum, unsigned char Char) \
  IMPL_FUNC_CONTENTS( \
    while(!(UCSR##__PeriNum##A & (1 << UDRE##__PeriNum))) ; \
    UDR##__PeriNum = Char; \
  )
/*
void Send_One(uint8_t Char) {
  while(!(UCSR0A & (1 << UDRE0))) ;

  UDR0 = Char;
}
*/

#define Send_String_USART_Func(__PeriNum) \
  DECL_FUNC(, void, Send_String_USART##__PeriNum, unsigned char *String) \
  IMPL_FUNC_CONTENTS( \
    while(*String) Send_One_USART##__PeriNum(*String++); \
  )
/*
void Send_String(uint8_t *String) {
  while(*String) Send_One(*String++);
}
*/

#if defined(UBRRH) || defined(UBRR0H)
Send_One_USART_Func(0)
Send_String_USART_Func(0)
#endif
#if defined(UBRR1H)
Send_One_USART_Func(1)
Send_String_USART_Func(1)
#endif
#if defined(UBRR2H)
Send_One_USART_Func(2)
Send_String_USART_Func(2)
#endif
#if defined(UBRR3H)
Send_One_USART_Func(3)
Send_String_USART_Func(3)
#endif

/*
 * This section is USART setting for Function pointer of Tx/Rx
 * Invoking(Interrupt Invoker) Functions(Set_RxInvokeFuncn, Set_TxInvokeFuncn).
 */

#define IMPL_SET_FUNCP(__Type, __FuncName, __DestValue) \
  IMPL_FUNC(, void, Set_##__FuncName, __Type *(*__TxV)(), \
    __DestValue = __TxV; \
  )
#define Set_TxRxInvokeFunc_USART(__PeriNum) \
  IMPL_SET_FUNCP(void, RxInvokeFunc_USART##__PeriNum, RecvFunc_USART##__PeriNum) \
  IMPL_SET_FUNCP(void, TxInvokeFunc_USART##__PeriNum, TransFunc_USART##__PeriNum) \
  IMPL_SET_FUNCP(void, DataEmptyInvokeFunc_USART##__PeriNum, DataEmptyFunc_USART##__PeriNum)

#if defined(UBRRH) || defined(UBRR0H)
Set_TxRxInvokeFunc_USART(0)
#endif
#if defined(UBRR1H)
Set_TxRxInvokeFunc_USART(1)
#endif
#if defined(UBRR2H)
Set_TxRxInvokeFunc_USART(2)
#endif
#if defined(UBRR3H)
Set_TxRxInvokeFunc_USART(3)
#endif

/*
 * List of ISR to USART.
 *
 * // USART(*) - ATMega328P
 * 18. USART_RX_vect // USART Rx Complete
 * 19. USART_UDRE_vect // USART, Data Register Empty
 * 20. USART_TX_vect // USART Tx Complete
 *
 * // USART(*) - ATMega128
 * 18. USART0_RX_vect // USART0, Rx Complete
 * 19. USART0_UDRE_vect // USART0 Data Register Empty
 * 20. USART0_TX_vect // USART0, Tx Complete
 *
 * 30. USART1_RX_vect // USART1, Rx Complete
 * 31. USART1_UDRE_vect // USART1, Data Register Empty
 * 32. USART1_TX_vect	// USART1, Tx Complete
 *
 */

/*
 * This section is USART ISR Functions(only Internal, Interrupts).
 */

#if defined(__AVR_ATmega328P__) && defined(UBRR0H)
#define DECL_ISR_FUNC_USART_RX_vect_V \
  ISR(USART_RX_vect)
#define DECL_ISR_FUNC_USART_UDRE_vect_V \
  ISR(USART_UDRE_vect)
#define DECL_ISR_FUNC_USART_TX_vect_V \
  ISR(USART_TX_vect)

#define IMPL_ISR_FUNC_USART_RX_vect_V \
  DECL_ISR_FUNC_USART_RX_vect_V \
  IMPL_FUNC_CONTENTS( \
    cli(); \
    RecvFunc_USART0(); \
    sei(); \
  )
#define IMPL_ISR_FUNC_USART_UDRE_vect_V \
  DECL_ISR_FUNC_USART_UDRE_vect_V \
  IMPL_FUNC_CONTENTS( \
    cli(); \
    DataEmptyFunc_USART0(); \
    sei(); \
  )
#define IMPL_ISR_FUNC_USART_TX_vect_V \
  DECL_ISR_FUNC_USART_TX_vect_V \
  IMPL_FUNC_CONTENTS( \
    cli(); \
    TransFunc_USART0(); \
    sei(); \
  )
#else
#define DECL_ISR_FUNC_USART_RX_vect(__Num) \
  ISR(USART##__Num##_RX_vect)
#define DECL_ISR_FUNC_USART_UDRE_vect(__Num) \
  ISR(USART##__Num##_UDRE_vect)
#define DECL_ISR_FUNC_USART_TX_vect(__Num) \
  ISR(USART##__Num##_TX_vect)
#define IMPL_ISR_FUNC_USART_RX_vect(__Num) \
  DECL_ISR_FUNC_USART_RX_vect(__Num) \
  IMPL_FUNC_CONTENTS( \
    cli(); \
    RecvFunc_USART##__Num(); \
    sei(); \
    )
#define IMPL_ISR_FUNC_USART_UDRE_vect(__Num) \
  DECL_ISR_FUNC_USART_UDRE_vect(__Num) \
  IMPL_FUNC_CONTENTS( \
    cli(); \
    DataEmptyFunc_USART##__Num(); \
    sei(); \
    )
#define IMPL_ISR_FUNC_USART_TX_vect(__Num) \
  DECL_ISR_FUNC_USART_TX_vect(__Num) \
  IMPL_FUNC_CONTENTS( \
    cli(); \
    TransFunc_USART##__Num(); \
    sei(); \
    )
#endif

#if defined(__AVR_ATmega328P__) && defined(UBRR0H)
IMPL_ISR_FUNC_USART_RX_vect_V
IMPL_ISR_FUNC_USART_UDRE_vect_V
IMPL_ISR_FUNC_USART_TX_vect_V
#else
#if defined(UBRRH) || defined(UBRR0H)
IMPL_ISR_FUNC_USART_RX_vect(0)
IMPL_ISR_FUNC_USART_UDRE_vect(0)
IMPL_ISR_FUNC_USART_TX_vect(0)
#endif
#if defined(UBRR1H)
IMPL_ISR_FUNC_USART_RX_vect(1)
IMPL_ISR_FUNC_USART_UDRE_vect(1)
IMPL_ISR_FUNC_USART_TX_vect(1)
#endif
#if defined(UBRR2H)
IMPL_ISR_FUNC_USART_RX_vect(2)
IMPL_ISR_FUNC_USART_UDRE_vect(2)
IMPL_ISR_FUNC_USART_TX_vect(2)
#endif
#if defined(UBRR3H)
IMPL_ISR_FUNC_USART_RX_vect(3)
IMPL_ISR_FUNC_USART_UDRE_vect(3)
IMPL_ISR_FUNC_USART_TX_vect(3)
#endif

#endif