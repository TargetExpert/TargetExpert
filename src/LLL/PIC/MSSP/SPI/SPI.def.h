/*********************************************************************

          File: SPI.def.h

   Description: PIC SPI syntax definition Header Part.

        Author: Jinseong Jeon (aimer120@nate.com)

       Created: 2019/10/09

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _SPI_DEF_H_
#define _SPI_DEF_H_

#pragma __FunCX_Section Begin

#include "MSSP_base.def.h"

#pragma __FunCX_InLevel_Except Begin

// Definition of "Quantity of Register Bits".
#define SSPM_SPI_BQTY SSPM_BQTY
#define SCK_SPI_BQTY (CKP_BQTY + CKE_BQTY)
#define SMP_SPI_BQTY SMP_BQTY

#pragma __FunCX_InLevel_Except End

// Set_MasterSlave_SPI(n) Definition.
#pragma __FunCX_InLevel_Except Begin
#define Set_MasterSlave_SPI_D_Block Set_MasterSlave_MSSP_D_Block

// Definition Prototyping.
#define Set_MasterSlave_SPI_D_Proto(__PeriNum, __Chan, __PreA, __PreB, __Mode) \
  C_( \
    IfSafe_((__Mode >= 0 && __Mode < 6) || __Mode == 10, \
      register unsigned char i = 0; \
      IFSafe_(!(__Mode == 5 && (SSP##__PeriNum##STAT & __PreB##_CKE)), \
        ForSafe_(i = 0, i < SSPM_SPI_BQTY, i++, \
          Set_MasterSlave_SPI_D_Block(__PeriNum, __Chan, __PreA, __Mode) \
        ) \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_BusMode_SPI(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_BusMode_SPI_D_Proto(__PeriNum, __Chan, __PreA, __PreB, __Mode) \
  C_( \
    IfSafe_(__Mode >= 0 && __Mode < powf(2, SCK_SPI_BQTY), \
      register unsigned char i = 0; \
      ForSafe_(i = 0, i < SCK_SPI_BQTY, i++, \
        (i != 0) ? \
          (sclb_reg_common(SSP, __PeriNum, CON##__Chan, ((__Mode) & (1 << i)), CONV_BIT_(__PreA##_CKP), , )) \
          : (sclb_reg_common(SSP, __PeriNum, STAT, (~(__Mode) & (1 << i)), CONV_BIT_(__PreB##_CKE), , )); \
      ) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_SampleBit_SPI(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_SampleBit_SPI_D_Proto(__PeriNum, __Prefix, __Sample) \
  C_( \
    IfSafe_(__Sample >= 0 && __Sample < powf(2, SMP_SPI_BQTY), \
      sclb_reg_common(SSP, __PeriNum, STAT, __Sample, CONV_BIT_(__Prefix##_SMP), , ); \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_SerialPort_SPI(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_SerialPort_SPI_D_Proto Set_SerialPort_MSSP_D_Proto
#pragma __FunCX_InLevel_Except End

// Set_Global_Intr_SPI(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_Global_Intr_SPI_D_Proto Set_Global_Intr_MSSP_D_Proto
#pragma __FunCX_InLevel_Except End

// Set_Peripheral_Intr_SPI(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_Peripheral_Intr_SPI_D_Proto Set_Peripheral_Intr_MSSP_D_Proto
#pragma __FunCX_InLevel_Except End

// Set_Serial_Intr_SPI(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_Serial_Intr_SPI_D_Proto Set_Serial_Intr_MSSP_D_Proto
#pragma __FunCX_InLevel_Except End

/*
 * Reserved ISR Processing
 *
// Check_Buffer_Full_SPI(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Check_Buffer_Full_SPI_D_Proto Check_Buffer_Full_MSSP_D_Proto
#pragma __FunCX_InLevel_Except End

// Check_Rx_Overflow_SPI(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Check_Rx_Overflow_SPI_D_Proto Check_Rx_Overflow_MSSP_D_Proto
#pragma __FunCX_InLevel_Except End

// Check_Tx_Collision_SPI(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Check_Tx_Collision_SPI_D_Proto Check_Tx_Collision_MSSP_D_Proto
#pragma __FunCX_InLevel_Except End

// Hit_Serial_Intr_SPI(n) Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Hit_Serial_Intr_SPI_D_Proto Hit_Serial_Intr_MSSP_D_Proto
#pragma __FunCX_InLevel_Except End
 */

#if defined(SSP1CON1)
#define Set_MasterSlave_SPI1_D(Mode) \
  Set_MasterSlave_SPI_D_Proto(1, 1, , , Mode)
#define Set_BusMode_SPI1_D(Mode) \
  Set_BusMode_SPI_D_Proto(1, 1, , , Mode)
#define Set_SampleBit_SPI1_D(Sample) \
  Set_SampleBit_SPI_D_Proto(1, , Sample)
#define Set_SerialPort_SPI1_D(Enable) \
  Set_SerialPort_SPI_D_Proto(1, 1, , Enable)
//#define Check_Buffer_Full_SPI1_D(Syntax) \
  Check_Buffer_Full_SPI_D_Proto(1, , Syntax)
//#define Check_Rx_Overflow_SPI1_D(Syntax) \
  Check_Rx_Overflow_SPI_D_Proto(1, 1, , Syntax)
//#define Check_Tx_Collision_SPI1_D(Syntax) \
  Check_Tx_Collision_SPI_D_Proto(1, 1, , Syntax)
#elif defined(SSPCON)
#define Set_MasterSlave_SPI1_D(Mode) \
  Set_MasterSlave_SPI_D_Proto(, , , , Mode)
#define Set_BusMode_SPI1_D(Mode) \
  Set_BusMode_SPI_D_Proto(, , , , Mode)
#define Set_SampleBit_SPI1_D(Sample) \
  Set_SampleBit_SPI_D_Proto(, , Sample)
#define Set_SerialPort_SPI1_D(Enable) \
  Set_SerialPort_SPI_D_Proto(, , , Enable)
//#define Check_Buffer_Full_SPI1_D(Syntax) \
  Check_Buffer_Full_SPI_D_Proto(, , Syntax)
//#define Check_Rx_Overflow_SPI1_D(Syntax) \
  Check_Rx_Overflow_SPI_D_Proto(, , , Syntax)
//#define Check_Tx_Collision_SPI1_D(Syntax) \
  Check_Tx_Collision_SPI_D_Proto(, , , Syntax)
#endif
#if defined(SSP2CON1)
#define Set_MasterSlave_SPI2_D(Mode) \
  Set_MasterSlave_SPI_D_Proto(2, 1, _SSP2CON1, _SSP2STAT, Mode)
#define Set_BusMode_SPI2_D(Mode) \
  Set_BusMode_SPI_D_Proto(2, 1, _SSP2CON1, _SSP2STAT, Mode)
#define Set_SampleBit_SPI2_D(Sample) \
  Set_SampleBit_SPI_D_Proto(2, _SSP2STAT, Sample)
#define Set_SerialPort_SPI2_D(Enable) \
  Set_SerialPort_SPI_D_Proto(2, 1, _SSP2CON1, Enable)
//#define Check_Buffer_Full_SPI2_D(Syntax) \
  Check_Buffer_Full_SPI_D_Proto(2, _SSP2STAT, Syntax)
//#define Check_Rx_Overflow_SPI2_D(Syntax) \
  Check_Rx_Overflow_SPI_D_Proto(2, 1, _SSP2CON1, Syntax)
//#define Check_Tx_Collision_SPI2_D(Syntax) \
  Check_Tx_Collision_SPI_D_Proto(2, 1, _SSP2CON1, Syntax)
#endif

#if defined(_PEIE)
#define Set_Global_Intr_SPI_D(Enable) \
  Set_Global_Intr_SPI_D_Proto(Enable)
#define Set_Peripheral_Intr_SPI_D(Enable) \
  Set_Peripheral_Intr_SPI_D_Proto(Enable)
#endif

#if defined(_SSP1IE)
  #if defined(PIE8)
  #define Set_Serial_Intr_SPI1_D(Enable) \
    Set_Serial_Intr_SPI_D_Proto(3, 1, Enable)
  //#define Hit_Serial_Intr_SPI1_D(Syntax) \
    Hit_Serial_Intr_SPI_D_Proto(3, 1, Syntax)
  #else
  #define Set_Serial_Intr_SPI1_D(Enable) \
    Set_Serial_Intr_SPI_D_Proto(1, 1, Enable)
  //#define Hit_Serial_Intr_SPI1_D(Syntax) \
    Hit_Serial_Intr_SPI_D_Proto(1, 1, Syntax)
  #endif
#elif defined(_SSPIE)
#define Set_Serial_Intr_SPI1_D(Enable) \
  Set_Serial_Intr_SPI_D_Proto(1, , Enable)
//#define Hit_Serial_Intr_SPI1_D(Syntax) \
  Hit_Serial_Intr_SPI_D_Proto(1, , Syntax)
#endif
#if defined(_SSP2IE)
  #if defined(PIE8)
  #define Set_Serial_Intr_SPI2_D(Enable) \
    Set_Serial_Intr_SPI_D_Proto(3, 2, Enable)
  //#define Hit_Serial_Intr_SPI2_D(Syntax) \
    Hit_Serial_Intr_SPI_D_Proto(3, 2, Syntax)
  #elif defined(PIE4)
    #if defined(PIE0)
    #define Set_Serial_Intr_SPI2_D(Enable) \
      Set_Serial_Intr_SPI_D_Proto(2, 2, Enable)
    //#define Hit_Serial_Intr_SPI2_D(Syntax) \
      Hit_Serial_Intr_SPI_D_Proto(2, 2, Syntax)
    #else
    #define Set_Serial_Intr_SPI2_D(Enable) \
      Set_Serial_Intr_SPI_D_Proto(4, 2, Enable)
    //#define Hit_Serial_Intr_SPI2_D(Syntax) \
      Hit_Serial_Intr_SPI_D_Proto(4, 2, Syntax)
    #endif
  #else
  #define Set_Serial_Intr_SPI2_D(Enable) \
    Set_Serial_Intr_SPI_D_Proto(1, 2, Enable)
  //#define Hit_Serial_Intr_SPI2_D(Syntax) \
    Hit_Serial_Intr_SPI_D_Proto(1, 2, Syntax)
  #endif
#endif

/*
 * Reserved ISR Processing
 *
#ifndef Hit_Serial_Intr_SPI2_D(Syntax)
#define Hit_Serial_Intr_SPI2_D(Syntax)
#endif
 */

#pragma __FunCX_Section End

#endif // _SPI_DEF_H_
