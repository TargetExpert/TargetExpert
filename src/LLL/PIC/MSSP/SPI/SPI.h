/*********************************************************************

          File: SPI.h

   Description: PIC SPI Header Part.

        Author: Jinseong Jeon (aimer120@nate.com)

       Created: 2019/10/15

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _SPI_H_
#define _SPI_H_

#include "SPI.def.h"

/*
 * List of SPI Setting Functions.
 *
 * Qty : 5
 *
 * void Set_MasterSlave_SPIn(unsigned char Mode);
 * void Set_BusMode_SPIn(unsigned char Mode);
 * void Set_SampleBit_SPIn(unsigned char Sample);
 * void Set_SerialPort_SPIn(bool Enable);
 * void Set_Serial_Intr_SPIn(bool Enable);
 */
#define DECL_FUNC_SETTINGS_SPI(__Num) \
  DECL_FUNC(, void, Set_MasterSlave_SPI##__Num, unsigned char Mode); \
  DECL_FUNC(, void, Set_BusMode_SPI##__Num, unsigned char Mode); \
  DECL_FUNC(, void, Set_SampleBit_SPI##__Num, unsigned char Sample); \
  DECL_FUNC(, void, Set_SerialPort_SPI##__Num, bool Enable); \
  DECL_FUNC(, void, Set_Serial_Intr_SPI##__Num, bool Enable);

/*
 * List of SPI Common Setting Functions.
 *
 * Qty : 2
 *
 * void Set_Global_Intr_SPI(bool Enable);
 * void Set_Peripheral_Intr_SPI(bool Enable);
 */
#define DECL_FUNC_SETTINGS_COMMON_SPI() \
  DECL_FUNC(, void, Set_Global_Intr_SPI, bool Enable); \
  DECL_FUNC(, void, Set_Peripheral_Intr_SPI, bool Enable);

/*
 * List of SPI Reset Functions.
 *
 * Qty : 1
 *
 * void Reset_SPIn();
 */
#define DECL_FUNC_RESET_SPI(__Num) \
  DECL_FUNC(, void, Reset_SPI##__Num, void); \

/*
 * List of SPI Tx Functions.
 *
 * Qty : 2
 *
 * void Send_One_SPIn(unsigned char Char);
 * void Send_String_SPIn(unsigned char *String);
 */
#define DECL_FUNC_SEND_SPI(__Num) \
  DECL_FUNC(, void, Send_One_SPI##__Num, unsigned char Data); \
  DECL_FUNC(, void, Send_String_SPI##__Num, unsigned char *Data_String);

/*
 * List of SPI Receive and Transfer invoking Functions.
 *
 * Qty : 2
 *
 * static void *(*RecvFunc_SPIn)();
 * static void *(*XferFunc_SPIn)();
 */
// it's "invoking Function pointer".
#define DECL_FUNCP_SPI_RX_TX(__Num) \
  DECL_FUNC(static, void, *(*RecvFunc_SPI##__Num), void); \
  DECL_FUNC(static, void, *(*XferFunc_SPI##__Num), void);

/*
 * List of SPI setting for Function pointer.
 *
 * Qty : 2
 *
 * void Set_RxInvokeFunc_SPIn(void *(*RxInvokeFunc_SPIn)());
 * void Set_TxInvokeFunc_SPIn(void *(*TxInvokeFunc_SPIn)());
 */
#define DECL_FUNC_SET_FUNCP_SPI(__Num) \
  DECL_FUNC(, void, Set_RxInvokeFunc_SPI##__Num, void *(*RxInvokeFunc_SPI##__Num)()); \
  DECL_FUNC(, void, Set_TxInvokeFunc_SPI##__Num, void *(*TxInvokeFunc_SPI##__Num)());

/*
 * Declarations for uses methods.
 */
#if defined(_PEIE)
DECL_FUNC_SETTINGS_COMMON_SPI()
#endif
#if defined(SSPCON_ADDR) || defined(SSP1CON1_ADDR)
DECL_FUNC_SETTINGS_SPI(1) 
DECL_FUNC_RESET_SPI(1)
DECL_FUNC_SEND_SPI(1)
DECL_FUNCP_SPI_RX_TX(1)
DECL_FUNC_SET_FUNCP_SPI(1)

  #ifndef TE_HAVE_SPI_QTY
  #define TE_HAVE_SPI_QTY 1
  #endif
#endif
#if defined(SSP2CON1_ADDR)
DECL_FUNC_SETTINGS_SPI(2) 
DECL_FUNC_RESET_SPI(2)
DECL_FUNC_SEND_SPI(2)
DECL_FUNCP_SPI_RX_TX(2)
DECL_FUNC_SET_FUNCP_SPI(2)

  #if defined(TE_HAVE_SPI_QTY)
  #undef TE_HAVE_SPI_QTY
  #endif
#define TE_HAVE_SPI_QTY 2
#endif

#endif // _SPI_H_
