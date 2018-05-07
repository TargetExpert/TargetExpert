/*********************************************************************

          File: ADC.c

   Description: AVR Analog-to-Digital converter Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/01/11

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "ADC.h"

/*
 * Analog Channel Selection(MUXn) Function.
 *
 * Descriptions : Selection of Analog Channel.
 *
 * See details in ATMega32* or ATMega64/128 serise full datasheets.
 * atmega328 - http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf
 * atmega128 - http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8151-8-bit-AVR-ATmega128A_Datasheet.pdf
 *
 * Return Type : void
 * Params :
 * 1. Channel - Set of MUX* bit on ADMUX register.
 */

#define Set_ChannelSelection_ADC_Func \
  DECL_FUNC(, void, Set_ChannelSelection_ADC, unsigned char Channel) \
  Set_ChannelSelection_ADC_D(Channel)

/*
 * Reference Selection Setting Function.
 *
 * Descriptions : Set for Reference Selection.
 *
 * Return Type : void
 * Params :
 * 1. Reference - Input your wish Reference mode.
 */

#define Set_ReferenceSelection_ADC_Func \
  DECL_FUNC(, void, Set_ReferenceSelection_ADC, unsigned char Reference) \
  Set_ReferenceSelection_ADC_D(Reference)

/*
 * ADC Left Adjust Result Setting Function.
 *
 * Descriptions : Set for ADC Left Adjust Result.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or Unset of ADC Left Adjust Result.
 */

#define Set_LeftAdjResult_ADC_Func \
  DECL_FUNC(, void, Set_LeftAdjResult_ADC, bool Enable) \
  Set_LeftAdjResult_ADC_D(Enable)

/*
 * ADC Enable Setting Function.
 *
 * Descriptions : Set for ADC Enable.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or Unset of ADC Enable.
 */

#define Set_Enable_ADC_Func \
  DECL_FUNC(, void, Set_Enable_ADC, bool Enable) \
  Set_Enable_ADC_D(Enable)

/*
 * ADC Start Conversion Setting Function.
 *
 * Descriptions : Set for ADC Start Conversion.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or Unset of ADC Start Conversion.
 */

#define Set_StartConversion_ADC_Func \
  DECL_FUNC(, void, Set_StartConversion_ADC, bool Enable) \
  Set_StartConversion_ADC_D(Enable)

#if defined(ADATE)
/*
 * ADC Auto Trigger Enable Setting Function.
 *
 * Descriptions : Set for ADC Auto Trigger Enable.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or Unset of ADC Auto Trigger Enable.
 */

#define Set_AutoTriggerEnable_ADC_Func \
  DECL_FUNC(, void, Set_AutoTriggerEnable_ADC, bool Enable) \
  Set_AutoTriggerEnable_ADC_D(Enable)

#elif defined(ADFR)
/*
 * ADC Free Running Select Setting Function.
 *
 * Descriptions : Set for ADC Free Running Select.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or Unset of ADC Free Running Select.
 */

#define Set_FreeRunningSelect_ADC_Func \
  DECL_FUNC(, void, Set_FreeRunningSelect_ADC, bool Enable) \
  Set_FreeRunningSelect_ADC_D(Enable)
#endif

/*
 * ADC Interrupt Flag Setting Function.
 *
 * Descriptions : Set for ADC Interrupt Flag.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or Unset of ADC Interrupt Flag.
 */

#define Set_InterruptFlag_ADC_Func \
  DECL_FUNC(, void, Set_InterruptFlag_ADC, bool Enable) \
  Set_InterruptFlag_ADC_D(Enable)

/*
 * ADC Interrupt Enable Setting Function.
 *
 * Descriptions : Set for ADC Interrupt Enable.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or Unset of ADC Interrupt Enable.
 */

#define Set_InterruptEnable_ADC_Func \
  DECL_FUNC(, void, Set_InterruptEnable_ADC, bool Enable) \
  Set_InterruptEnable_ADC_D(Enable)

/*
 * ADC Prescaler Select Setting Function.
 *
 * Descriptions : Set for Prescaler Select.
 *
 * Return Type : void
 * Params :
 * 1. Prescaler - Input your wish Prescaler.
 */

#define Set_PrescalerSelect_ADC_Func \
  DECL_FUNC(, void, Set_PrescalerSelect_ADC, unsigned char Prescaler) \
  Set_PrescalerSelect_ADC_D(Prescaler)

/*
 * Analog Comparator Multiplexer Enable Setting Function.
 *
 * Descriptions : Set for Analog Comparator Multiplexer Enable.
 *
 * Return Type : void
 * Params :
 * 1. Enable - Set or Unset of Analog Comparator Multiplexer Enabling.
 */

#define Set_ACMuxEnable_ADC_Func \
  DECL_FUNC(, void, Set_ACMuxEnable_ADC, bool Enable) \
  Set_ACMuxEnable_ADC_D(Enable)

/*
 * ADC Auto Trigger Source Setting Function.
 *
 * Descriptions : Set for ADC Auto Trigger Source.
 *
 * Return Type : void
 * Params :
 * 1. Source - Input your wish Trigger Source.
 */

#define Set_AutoTriggerSource_ADC_Func \
  DECL_FUNC(, void, Set_AutoTriggerSource_ADC, unsigned char Source) \
  Set_AutoTriggerSource_ADC_D(Source)


#define Get_MeasureValue_ADC_Func \
  DECL_FUNC(, unsigned int, Get_MeasureValue_ADC, ) \
  C_( \
    Get_MeasureValue_ADC_D(); \
    return Get_ADCValue(); \
  )

// Setting functions.
Set_ChannelSelection_ADC_Func
Set_ReferenceSelection_ADC_Func
Set_LeftAdjResult_ADC_Func
Set_Enable_ADC_Func
Set_StartConversion_ADC_Func
#if defined(ADATE)
Set_AutoTriggerEnable_ADC_Func
#elif defined(ADFR)
Set_FreeRunningSelect_ADC_Func
#endif
Set_InterruptFlag_ADC_Func
Set_InterruptEnable_ADC_Func
Set_PrescalerSelect_ADC_Func

// Ext
#if defined(ADCSRB)
Set_ACMuxEnable_ADC_Func
Set_AutoTriggerSource_ADC_Func
#endif

// Getting functions.
Get_MeasureValue_ADC_Func

#define IMPL_SET_FUNCP(__Type, __FuncName, __DestValue) \
  IMPL_FUNC(, void, Set_##__FuncName, __Type *(*__TxV)(), \
    __DestValue = __TxV; \
  )
#define Set_ConversionCompleteInterruptInvokeFunc_ADC \
  IMPL_SET_FUNCP(void, ConversionCompleteInvokeFunc_ADC, ConversionCompleteInterruptFunc_ADC) \

Set_ConversionCompleteInterruptInvokeFunc_ADC

/*
 * List of ISR to 10 bit ADC.
 *
 * // ADC(*)
 * 21. ADC_vect // ADC Conversion Complete
 *
 */

#define DECL_ISR_FUNC_ADC_CONV_vect_V \
  ISR(ADC_vect)

#define IMPL_ISR_FUNC_ADC_CONV_vect_V \
  DECL_ISR_FUNC_ADC_CONV_vect_V \
  C_( \
    cli(); \
    Set_ADCValue(ADC); \
    ConversionCompleteInterruptFunc_ADC(); \
    Set_StartConversion_ADC(true); \
    sei(); \
  )

IMPL_ISR_FUNC_ADC_CONV_vect_V