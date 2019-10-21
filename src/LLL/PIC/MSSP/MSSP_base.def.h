/*********************************************************************

          File: MSSP_base.def.h

   Description: PIC MSSP base func. syntax definition Header Part.

        Author: Jinseong Jeon (aimer120@nate.com)

       Created: 2019/10/09

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _MSSP_BASE_DEF_H_
#define _MSSP_BASE_DEF_H_

#pragma __FunCX_Section Begin

#include "Common.inc.h"

#pragma __FunCX_InLevel_Except Begin

#define PIC_MODE_BIT(__Num) __Num

// Definition of "Quantity of Register Bits".
#define SSPM_BQTY PIC_MODE_BIT(4)
#define SSPEN_BQTY PIC_MODE_BIT(1)
#define CKP_BQTY PIC_MODE_BIT(1)
#define CKE_BQTY PIC_MODE_BIT(1)
#define SMP_BQTY PIC_MODE_BIT(1)
#define GIE_BQTY PIC_MODE_BIT(1)
#define PEIE_BQTY PIC_MODE_BIT(1) 
#define SSPIE_BQTY PIC_MODE_BIT(1)

#pragma __FunCX_InLevel_Except End

// Set_MasterSlave_MSSP(n)_Base Definition.
#pragma __FunCX_InLevel_Except Begin
#if defined(_SSP1M0)
#define Set_MasterSlave_MSSP_D_Block(__PeriNum, __Chan, __Prefix, __Mode) \
  sclb_reg_common(SSP, __PeriNum, CON##__Chan, ((__Mode) & (1 << i)), CONV_BIT_(__Prefix##_SSP1M0) + i, , );
#elif defined(_SSPM0)
#define Set_MasterSlave_MSSP_D_Block(__PeriNum, __Chan, __Prefix, __Mode) \
  sclb_reg_common(SSP, __PeriNum, CON##__Chan, ((__Mode) & (1 << i)), CONV_BIT_(__Prefix##_SSPM0) + i, , );
#endif
#pragma __FunCX_InLevel_Except End

// Set_SerialPort_MSSP(n)_Base Definition.
#pragma __FunCX_InLevel_Except Begin
#if defined(_SSP1EN)
#define Set_SerialPort_MSSP_D_Block(__PeriNum, __Chan, __Prefix, __Enable) \
  sclb_reg_common(SSP, __PeriNum, CON##__Chan, __Enable, CONV_BIT_(__Prefix##_SSP1EN), , );
#elif defined(_SSPEN)
#define Set_SerialPort_MSSP_D_Block(__PeriNum, __Chan, __Prefix, __Enable) \
  sclb_reg_common(SSP, __PeriNum, CON##__Chan, __Enable, CONV_BIT_(__Prefix##_SSPEN), , );
#endif

// Definition Prototyping.
#define Set_SerialPort_MSSP_D_Proto(__PeriNum, __Chan, __Prefix, __Enable) \
  C_( \
    IfSafe_(__Enable >= 0 && __Enable < powf(2, SSPEN_BQTY), \
      Set_SerialPort_MSSP_D_Block(__PeriNum, __Chan, __Prefix, __Enable) \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_Global_Intr_MSSP(n)_Base Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_Global_Intr_MSSP_D_Proto(__Enable) \
  C_( \
    IfSafe_(__Enable >= 0 && __Enable < powf(2, GIE_BQTY), \
      sclb_reg_common(INT, , CON, __Enable, CONV_BIT_(_GIE), , ); \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_Peripheral_Intr_MSSP(n)_Base Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_Peripheral_Intr_MSSP_D_Proto(__Enable) \
  C_( \
    IfSafe_(__Enable >= 0 && __Enable < powf(2, PEIE_BQTY), \
      sclb_reg_common(INT, , CON, __Enable, CONV_BIT_(_PEIE), , ); \
    ) \
  )
#pragma __FunCX_InLevel_Except End

// Set_Serial_Intr_MSSP(n)_Base Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Set_Serial_Intr_MSSP_D_Proto(__Chan, __BitNum, __Enable) \
  C_( \
    IfSafe_(__Enable >= 0 && __Enable < powf(2, SSPIE_BQTY), \
      sclb_reg_common(PIE, , __Chan, __Enable && bit_is_set(INTCON, _PEIE) && \
      bit_is_set(INTCON, _GIE), CONV_BIT_(_SSP##__BitNum##IE), , ); \
    ) \
  )
#pragma __FunCX_InLevel_Except End

/*
 * Reserved ISR Processing
 *
// Check_Buffer_Full_MSSP(n)_Base Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Check_Buffer_Full_MSSP_D_Proto(__PeriNum, __Prefix, __Syntax) \
  IfSafe_(bit_is_set(SSP##__PeriNum##STAT, __Prefix##_BF), __Syntax)
#pragma __FunCX_InLevel_Except End

// Check_Rx_Overflow_MSSP(n)_Base Definition.
#pragma __FunCX_InLevel_Except Begin
#if defined(_SSP1OV)
#define OF_Bit_MSSP_D_Block(__Prefix) \
  (__Prefix##_SSP1OV)
#elif defined(_SSPOV)
#define OF_Bit_MSSP_D_Block(__Prefix) \
  (__Prefix##_SSPOV)
#endif

// Definition Prototyping.
#define Check_Rx_Overflow_MSSP_D_Proto(__PeriNum, __Chan, __Prefix, __Syntax) \
  IfSafe_(bit_is_set(SSP##__PeriNum##CON##__Chan, OF_Bit_MSSP_D_Block(__Prefix)), \
    SSP##__PeriNum##CON##__Chan &= ~OF_Bit_MSSP_D_Block(__Prefix); \
    __Syntax \
  )
#pragma __FunCX_InLevel_Except End

// Check_Tx_Collision_MSSP(n)_Base Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Check_Tx_Collision_MSSP_D_Proto(__PeriNum, __Chan, __Prefix, __Syntax) \
  IfSafe_(bit_is_set(SSP##__PeriNum##CON##__Chan, __Prefix##_WCOL), \
    SSP##__PeriNum##CON##__Chan &= ~(__Prefix##_WCOL); \
    __Syntax \
  )
#pragma __FunCX_InLevel_Except End

// Hit_Serial_Intr_MSSP(n)_Base Definition.
#pragma __FunCX_InLevel_Except Begin
// Definition Prototyping.
#define Hit_Serial_Intr_MSSP_D_Proto(__Chan, __BitNum, __Syntax) \
  IfSafe_(bit_is_set(PIR##__Chan, _SSP##__BitNum##IF), __Syntax)
#pragma __FunCX_InLevel_Except End
 */
#pragma __FunCX_Section End

#endif // __MSSP_BASE_DEF_H_
