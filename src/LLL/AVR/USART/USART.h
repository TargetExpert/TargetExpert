/*********************************************************************

          File: USART.h

   Description: AVR USART Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/01/09

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _USART_h_
#define _USART_h_

#include "USART.def.h"

/*
 * List of USART Setting Functions.
 *
 * Qty : 7
 *
 * void Set_BaudRate_USARTx(unsigned int BaudRate);
 * void Set_CharSize_USARTx(unsigned char CharSize);
 * void Set_Parity_USARTx(unsigned char Parity);
 * void Set_StopBit_USARTx(unsigned char Stopbit);
 * void Set_SerialMode_USARTx(unsigned char Mode);
 * void Set_DoubleSpeed_USARTx(bool Enable);
 * void Set_Interrupt_USARTx(bool Enable, unsigned char Target);
 */

#define DECL_FUNC_SETTINGS_USART(__Num) \
  DECL_FUNC(, void, Set_BaudRate_USART##__Num, unsigned long BaudRate); \
  DECL_FUNC(, void, Set_CharSize_USART##__Num, unsigned char CharSize); \
  DECL_FUNC(, void, Set_Parity_USART##__Num, unsigned char Parity); \
  DECL_FUNC(, void, Set_StopBit_USART##__Num, unsigned char Stopbit); \
  DECL_FUNC(, void, Set_SerialMode_USART##__Num, unsigned char Mode); \
  DECL_FUNC(, void, Set_DoubleSpeed_USART##__Num, bool Enable); \
  DECL_FUNC(, void, Set_Enable_USART##__Num, HELPER_PARAM_VAR(bool Enable, unsigned char Target));\
  DECL_FUNC(, void, Set_Interrupt_USART##__Num, HELPER_PARAM_VAR(bool Enable, unsigned char Target));

/*
 * List of USART Tx Functions.
 *
 * Qty : 2
 *
 * void Send_One_USARTn(unsigned char Char);
 * void Send_String_USARTn(unsigned char *String);
 */

#define DECL_FUNC_SEND_USART(__Num) \
  DECL_FUNC(, void, Send_One_USART##__Num, unsigned char Char); \
  DECL_FUNC(, void, Send_String_USART##__Num, unsigned char *String);

/*
 * List of USART Receive invoking Functions.
 *
 * Qty : 3
 *
 * static void *(*RecvFunc_USARTn)();
 * static void *(*TransFunc_USARTn)();
 * static void *(*DataEmptyFunc_USARTn)();
 */
// it's "invoking Function pointer".

#define DECL_FUNCP_USART_RX_TX(__Num) \
  DECL_FUNC(static, void, *(*RecvFunc_USART##__Num), void); \
  DECL_FUNC(static, void, *(*TransFunc_USART##__Num), void); \
  DECL_FUNC(static, void, *(*DataEmptyFunc_USART##__Num), void);

/*
 * List of USART setting for Function pointer.
 *
 * Qty : 3
 *
 * void Set_RxInvokeFunc_USARTn(void *(*RxInvokeFunc_USARTn)());
 * void Set_TxInvokeFunc_USARTn(void *(*TxInvokeFunc_USARTn)());
 * void Set_DataEmptyInvokeFunc_USARTn(void *(*DataEmptyInvokeFunc_USARTn)());
 */

#define DECL_FUNC_SET_FUNCP_USART(__Num) \
  DECL_FUNC(, void, Set_RxInvokeFunc_USART##__Num, void *(*RxInvokeFunc_USART##__Num)()); \
  DECL_FUNC(, void, Set_TxInvokeFunc_USART##__Num, void *(*TxInvokeFunc_USART##__Num)()); \
  DECL_FUNC(, void, Set_DataEmptyInvokeFunc_USART##__Num, void *(*DataEmptyInvokeFunc_USART##__Num)());

/*
 * Declarations for uses methods.
 */

#if defined(UBRRH) || defined(UBRR0H)
DECL_FUNC_SETTINGS_USART(0)
DECL_FUNC_SEND_USART(0)
DECL_FUNCP_USART_RX_TX(0)
DECL_FUNC_SET_FUNCP_USART(0)

#ifndef TE_HAVE_USART_UART_QTY
#define TE_HAVE_USART_UART_QTY 1
#endif
#endif

#if defined(UBRR1H)
DECL_FUNC_SETTINGS_USART(1)
DECL_FUNC_SEND_USART(1)
DECL_FUNCP_USART_RX_TX(1)
DECL_FUNC_SET_FUNCP_USART(1)

#if defined(TE_HAVE_USART_UART_QTY)
#undef TE_HAVE_USART_UART_QTY
#endif
#define TE_HAVE_USART_UART_QTY 2
#endif

#if defined(UBRR2H)
DECL_FUNC_SETTINGS_USART(2)
DECL_FUNC_SEND_USART(2)
DECL_FUNCP_USART_RX_TX(2)
DECL_FUNC_SET_FUNCP_USART(2)

#if defined(TE_HAVE_USART_UART_QTY)
#undef TE_HAVE_USART_UART_QTY
#endif
#define TE_HAVE_USART_UART_QTY 3
#endif

#if defined(UBRR3H)
DECL_FUNC_SETTINGS_USART(3)
DECL_FUNC_SEND_USART(3)
DECL_FUNCP_USART_RX_TX(3)
DECL_FUNC_SET_FUNCP_USART(3)

#if defined(TE_HAVE_USART_UART_QTY)
#undef TE_HAVE_USART_UART_QTY
#endif
#define TE_HAVE_USART_UART_QTY 4
#endif

#endif // _USART_h_
