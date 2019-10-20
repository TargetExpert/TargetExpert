/*********************************************************************

          File: SPI.c

   Description: PIC SPI Source Part.

        Author: Jinseong Jeon (aimer120@nate.com)

       Created: 2019/10/15

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "SPI.h"

/*
 * This section is SPI setting Functions.
 */

/*
 * Master/Slave Mode Setting Function.
 *
 * Descriptions : Set for kind of master or slave mode to activate.
 *
 * Return Type : void
 * Params :
 * 1. Mode - Input your wish operation mode.
 *           0 : Master & CLK=Fosc/4 , 1 : Master & CLK=Fosc/16
 *           2 : Master & CLK=Fosc/64, 3 : Master & CLK=TMR2 output/2
 *           4 : Slave & CLK=SCK Pin & SS Pin Control Enable
 *           5 : Slave & CLK=SCK Pin & SS Pin Control Disable
 *           10 : Master & CLK=Fosc/(4*(SSPnADD+1))
 *             <Possible if SSP1CON1 register exists, In other case reserved>
 */
#define Set_MasterSlave_SPI_Func(__Num) \
  DECL_FUNC(, void, Set_MasterSlave_SPI##__Num, unsigned char Mode) \
  Set_MasterSlave_SPI##__Num##_D(Mode)

/*
 * SPI Bus Mode Setting Function.
 *
 * Descriptions : Set for kind of standard SPI bus mode.
 *
 * Return Type : void
 * Params :
 * 1. Mode - Input your wish SPI bus mode.
 *           0 : Idle(0) Active(1) Idle -> Active Sampling <CKP(0) & CKE(1)>
 *           1 : Idle(0) Active(1) Active -> Idle Sampling <CKP(0) & CKE(0)>
 *           2 : Idle(1) Active(0) Idle -> Active Sampling <CKP(1) & CKE(1)>
 *           3 : Idle(1) Active(0) Active -> Idle Sampling <CKP(1) & CKE(0)>
 */
#define Set_BusMode_SPI_Func(__Num) \
  DECL_FUNC(, void, Set_BusMode_SPI##__Num, unsigned char Mode) \
  Set_BusMode_SPI##__Num##_D(Mode)

/*
 * Sample bit Setting Function.
 *
 * Descriptions : Set for sample bit.
 *
 * Return Type : void
 * Params :
 * 1. Sample - Input your wish sample timing of input data.
 *             0 : at middle of data output time, 1 : at end of data output time
 */
#define Set_SampleBit_SPI_Func(__Num) \
  DECL_FUNC(, void, Set_SampleBit_SPI##__Num, unsigned char Sample) \
  Set_SampleBit_SPI##__Num##_D(Sample)

/*
 * Serial Port Enable Setting Function.
 *
 * Descriptions : Enable/Disable SCK, SDO, SDI and SS as serial port pins.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for SSPnEN bit on SSPnCON1 register.
 *             false : disable, true : enable
 */
#define Set_SerialPort_SPI_Func(__Num) \
  DECL_FUNC(, void, Set_SerialPort_SPI##__Num, bool Enable) \
  Set_SerialPort_SPI##__Num##_D(Enable)

/*
 * Global Interrupt Enable Setting Function.
 *
 * Descriptions : Set or unset for GIE bit on INTCON register.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for GIE bit on INTCON register.
 *             false : disable, true : enable
 */
#define Set_Global_Intr_SPI_Func() \
  DECL_FUNC(, void, Set_Global_Intr_SPI, bool Enable) \
  Set_Global_Intr_SPI_D(Enable)

/*
 * Peripheral Interrupt Enable Setting Function.
 *
 * Descriptions : Set or unset for PEIE bit on INTCON register.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for PEIE bit on INTCON register.
 *             false : disable, true : enable
 */
#define Set_Peripheral_Intr_SPI_Func() \
  DECL_FUNC(, void, Set_Peripheral_Intr_SPI, bool Enable) \
  Set_Peripheral_Intr_SPI_D(Enable)

/*
 * Synchronous Serial Port Interrupt Enable Setting Function.
 *
 * Descriptions : Set or unset for SSPnIE bit on PIEn register.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or unset for SSPnIE bit on PIEn register.
 *             false : disable, true : enable
 */
#define Set_Serial_Intr_SPI_Func(__Num) \
  DECL_FUNC(, void, Set_Serial_Intr_SPI##__Num, bool Enable) \
  Set_Serial_Intr_SPI##__Num##_D(Enable)

/*
 * SPI Reset Function.
 *
 * Descriptions : Reset SPI Configuration.
 *
 * Return Type : void
 * Params : void
 */
#define Reset_SPI_Func(__Num) \
  DECL_FUNC(, void, Reset_SPI##__Num, void) \
  Set_SerialPort_SPI##__Num##_D(0)

#if defined(_PEIE)
Set_Global_Intr_SPI_Func()
Set_Peripheral_Intr_SPI_Func()
#endif
#if defined(SSPCON) || defined(SSP1CON1)
Set_MasterSlave_SPI_Func(1)
Set_BusMode_SPI_Func(1)
Set_SampleBit_SPI_Func(1)
Set_SerialPort_SPI_Func(1)
Set_Serial_Intr_SPI_Func(1)
Reset_SPI_Func(1)
#endif
#if defined(SSP2CON1)
Set_MasterSlave_SPI_Func(2)
Set_BusMode_SPI_Func(2)
Set_SampleBit_SPI_Func(2)
Set_SerialPort_SPI_Func(2)
Set_Serial_Intr_SPI_Func(2)
Reset_SPI_Func(2)
#endif

/*
 * This section is SPI Tx Functions(Send_*).
 */

/*
void Send_One(uint8_t Data) {
  while((SSPnCON & WCOL) || (SSPnSTAT & BF));
  SSPBUF = Data;
}
*/
#define Send_One_SPI_Func(__Num, __PeriNum, __Chan, __PreA, __PreB) \
  IMPL_FUNC(, void, Send_One_SPI##__Num, unsigned char Data, \
    while(bit_is_set(SSP##__PeriNum##CON##__Chan, __PreA##_WCOL) || \
          bit_is_set(SSP##__PeriNum##STAT, __PreB##_BF)); \
    SSP##__PeriNum##BUF = Data; \
  )

/*
void Send_String(uint8_t *String) {
  while(*String) Send_One(*String++);
}
*/
#define Send_String_SPI_Func(__Num) \
  IMPL_FUNC(, void, Send_String_SPI##__Num, unsigned char *Data_String, \
    while(*Data_String) Send_One_SPI##__Num(*Data_String++); \
  )

#if defined(SSP1CON1)
Send_One_SPI_Func(1, 1, 1, , )
Send_String_SPI_Func(1)
#elif defined(SSPCON)
Send_One_SPI_Func(1, , , , )
Send_String_SPI_Func(1)
#endif
#if defined(SSP2CON1)
Send_One_SPI_Func(2, 2, 1, _SSP2CON1, _SSP2STAT)
Send_String_SPI_Func(2)
#endif

/*
 * This section is SPI setting for Function pointer of Tx/Rx
 * Invoking(Interrupt Invoker) Functions(Set_RxInvokeFuncn, Set_TxInvokeFuncn).
 */

#define IMPL_SET_FUNCP(__Type, __FuncName, __DestValue,) \
  IMPL_FUNC(, void, Set_##__FuncName, __Type *(*__InvokeFunc_SPI)(), \
    __DestValue = __InvokeFunc_SPI; \
  )
#define Set_TxRxInvokeFunc_SPI(__Num) \
  IMPL_SET_FUNCP(void, RxInvokeFunc_SPI##__Num, RecvFunc_SPI##__Num) \
  IMPL_SET_FUNCP(void, TxInvokeFunc_SPI##__Num, XferFunc_SPI##__Num)

/*
 * List of ISR to SPI.
 *
 * // SPI(*) - PIC16F87XA
 * SSPnIF flag bit set // SPI RxTx Complete
 *
 */

/*
 * This section is SPI ISR Functions(only Internal, Interrupts).
 */

/*
 * Reserved ISR Processing
 *
#define DECL_ISR_FUNC_SPI_RX_TX_V \
  void ISR_SPI(void) __interrupt 0

#define IMPL_ISR_FUNC_SPI_RX_TX_V \
  DECL_ISR_FUNC_SPI_RX_TX_V \
  IMPL_FUNC_CONTENTS( \
    INTCON &= ~(_GIE); \
    Hit_Serial_Intr_SPI1_D( \
      Check_Buffer_Full_SPI1_D( RecvFunc_SPI1(); ) \
      Check_Rx_Overflow_SPI1_D() \
      Check_Tx_Collision_SPI1_D() \
      XferFunc_SPI1(); \
    ) \
    Hit_Serial_Intr_SPI2_D( \
      Check_Buffer_Full_SPI2_D( RecvFunc_SPI2(); ) \
      Check_Rx_Overflow_SPI2_D() \
      Check_Tx_Collision_SPI2_D() \
      XferFunc_SPI2(); \
    ) \
    INTCON |= _GIE; \
  )

#if defined(_SSPIE) || defined(_SSP1IE) || defined(_SSP2IE)
IMPL_ISR_FUNC_SPI_RX_TX_V
#endif
 */
