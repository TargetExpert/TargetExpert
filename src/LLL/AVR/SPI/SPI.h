/*********************************************************************

          File: SPI.h

   Description: AVR SPI Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2019/03/02

 Copyright (c) 2018-2019, TargetExpert Project is
 Gabriel Kim(Doohoon Kim), All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _SPI_h_
#define _SPI_h_

#include "SPI.def.h"

/*
 * List of SPI Setting Functions.
 *
 * Qty : 7
 *
 * void Set_Enable_SPIx(bool Enable);
 * void Set_DataOrder_SPIx(bool Order);
 * void Set_SelectModeMS_SPIx(bool Mode);
 * void Set_ClockPol_SPIx(unsigned char ClkPol);
 * void Set_ClockPhase_SPIx(unsigned char ClkPhase);
 * void Set_ClockRate_SPIx(unsigned char Rate);
 * void Set_Interrupt_SPIx(bool Enable);
 */

#define DECL_FUNC_SETTINGS_SPI(__Num) \
  DECL_FUNC(, void, Set_Enable_SPI##__Num, bool Enable); \
  DECL_FUNC(, void, Set_DataOrder_SPI##__Num, bool Order); \
  DECL_FUNC(, void, Set_SelectModeMS_SPI##__Num, bool Mode); \
  DECL_FUNC(, void, Set_ClockPol_SPI##__Num, unsigned char ClkPol); \
  DECL_FUNC(, void, Set_ClockPhase_SPI##__Num, unsigned char ClkPhase); \
  DECL_FUNC(, void, Set_ClockRate_SPI##__Num, unsigned char Rate); \
  DECL_FUNC(, void, Set_Interrupt_SPI##__Num, bool Enable);

/*
 * List of SPI Tx Functions.
 *
 * Qty : 2
 *
 * void Send_One_SPI(unsigned char Char);
 * void Send_String_SPI(unsigned char *String);
 */

#define DECL_FUNC_SEND_SPI(__Num) \
  DECL_FUNC(, void, Send_One_SPI##__Num, unsigned char Char); \
  DECL_FUNC(, void, Send_String_SPI##__Num, unsigned char *String);

/*
 * List of SPI Interrupt invoking Functions.
 *
 * Qty : 1
 *
 * static void *(*SerialTransCompleteFunc_SPIn)();
 */
// it's "invoking Function pointer".

#define DECL_FUNCP_SPI_INT(__Num) \
  DECL_FUNC(static, void, *(*SerialTransCompleteFunc_SPI##__Num), void);

/*
 * List of SPI setting for Function pointer.
 *
 * Qty : 1
 *
 * void Set_STCInvokeFunc_SPIn(void *(*STCInvokeFunc_SPIn)());
 */

#define DECL_FUNC_SET_FUNCP_SPI(__Num) \
  DECL_FUNC(, void, Set_STCInvokeFunc_SPI##__Num, void *(*STCInvokeFunc_SPI##__Num)()); \

/*
 * Declarations for uses methods.
 */

#if defined(UBRRH) || defined(UBRR0H)
DECL_FUNC_SETTINGS_SPI(0)
DECL_FUNC_SEND_SPI(0)
DECL_FUNCP_SPI_INT(0)
DECL_FUNC_SET_FUNCP_SPI(0)

#ifndef TE_HAVE_SPI_QTY
#define TE_HAVE_SPI_QTY 1
#endif
#endif

#if defined(UBRR1H)
DECL_FUNC_SETTINGS_SPI(1)
DECL_FUNC_SEND_SPI(1)
DECL_FUNCP_SPI_INT(1)
DECL_FUNC_SET_FUNCP_SPI(1)

#if defined(TE_HAVE_SPI_QTY)
#undef TE_HAVE_SPI_QTY
#endif
#define TE_HAVE_SPI_QTY 2
#endif

#if defined(UBRR2H)
DECL_FUNC_SETTINGS_SPI(2)
DECL_FUNC_SEND_SPI(2)
DECL_FUNCP_SPI_INT(2)
DECL_FUNC_SET_FUNCP_SPI(2)

#if defined(TE_HAVE_SPI_QTY)
#undef TE_HAVE_SPI_QTY
#endif
#define TE_HAVE_SPI_QTY 3
#endif

#if defined(UBRR3H)
DECL_FUNC_SETTINGS_SPI(3)
DECL_FUNC_SEND_SPI(3)
DECL_FUNCP_SPI_INT(3)
DECL_FUNC_SET_FUNCP_SPI(3)

#if defined(TE_HAVE_SPI_QTY)
#undef TE_HAVE_SPI_QTY
#endif
#define TE_HAVE_SPI_QTY 4
#endif

#endif // _SPI_h_
