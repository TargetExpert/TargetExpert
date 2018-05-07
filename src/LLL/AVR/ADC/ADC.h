/*********************************************************************

          File: ADC.h

   Description: AVR Analog-to-Digital converter Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/01/11

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _ADC_h_
#define _ADC_h_

#include "ADC.def.h"

/*
 * List of 10 bit Analog-to-Digital Converter function flag setting Functions.
 *
 * Qty : 12
 *
 * // ADMUX
 * void Set_ChannelSelection_ADC(unsigned char Channel);
 * void Set_ReferenceSelection_ADC(unsigned char Reference);
 * void Set_LeftAdjResult_ADC(bool Enable);
 * void Set_Enable_ADC(bool Enable);
 * // ADCSRA
 * void Set_StartConversion_ADC(bool Enable);
 * void Set_AutoTriggerEnable_ADC(bool Enable); // for 328 series.
 * void Set_FreeRunningSelect_ADC(bool Enable); // for 128 series.
 * void Set_InterruptFlag_ADC(bool Enable);
 * void Set_InterruptEnable_ADC(bool Enable);
 * void Set_PrescalerSelect_ADC(unsigned char Prescaler);
 * // ADCSRB(for 328 series)
 * void Set_ACMuxEnable_ADC(bool Enable);
 * void Set_AutoTriggerSource_ADC(unsigned char Source);
 *
 */

#define DECL_FUNC_SETTINGS_ADC_1 \
  DECL_FUNC(, void __attribute__((weak)), Set_ChannelSelection_ADC, unsigned char Channel); \
  DECL_FUNC(, void __attribute__((weak)), Set_ReferenceSelection_ADC, unsigned char Reference); \
  DECL_FUNC(, void __attribute__((weak)), Set_LeftAdjResult_ADC, bool Enable); \
  DECL_FUNC(, void __attribute__((weak)), Set_Enable_ADC, bool Enable); \
  DECL_FUNC(, void __attribute__((weak)), Set_StartConversion_ADC, bool Enable); \
  DECL_FUNC(, void __attribute__((weak)), Set_InterruptFlag_ADC, bool Enable); \
  DECL_FUNC(, void __attribute__((weak)), Set_InterruptEnable_ADC, bool Enable); \
  DECL_FUNC(, void __attribute__((weak)), Set_PrescalerSelect_ADC, unsigned char Prescaler);

#if defined(ADATE)
#define DECL_FUNC_SETTINGS_ADC_2 \
  DECL_FUNC(, void __attribute__((weak)), Set_AutoTriggerEnable_ADC, bool Enable);
#elif defined(ADFR)
#define DECL_FUNC_SETTINGS_ADC_2 \
  DECL_FUNC(, void __attribute__((weak)), Set_FreeRunningSelect_ADC, bool Enable);
#endif

#define DECL_FUNC_SETTINGS_ADC_EXT \
  DECL_FUNC(, void __attribute__((weak)), Set_ACMuxEnable_ADC, bool Enable); \
  DECL_FUNC(, void __attribute__((weak)), Set_AutoTriggerSource_ADC, unsigned char Source);

#define DECL_FUNC_GETTINGS_ADC \
  DECL_FUNC(, unsigned int __attribute__((weak)), Get_MeasureValue_ADC, );

/*
 * List of ADC Conversion Complete invoking Functions.
 *
 * Qty : 1
 *
 * static void *(*ConversionCompleteInterruptFunc_ADC)();
 */

#define DECL_FUNCP_ADC_CONVCOMPLETE \
  DECL_FUNC(static, void, *(*ConversionCompleteInterruptFunc_ADC), void);

/*
 * List of ADC Conversion Complete setting for Function pointer.
 *
 * Qty : 1
 *
 * void Set_ConversionCompleteInvokeFunc_ADC(void *(*ConversionCompleteInvokeFunc_ADC)());
 */

#define DECL_FUNCP_SET_ADC \
  DECL_FUNC(, void __attribute__((weak)), Set_ConversionCompleteInvokeFunc_ADC, void *(*ConversionCompleteInvokeFunc_ADC)());

/*
 * Declarations for uses methods.
 */

DECL_FUNC_SETTINGS_ADC_1
DECL_FUNC_SETTINGS_ADC_2
DECL_FUNC_GETTINGS_ADC

#if defined(ADCSRB)
DECL_FUNC_SETTINGS_ADC_EXT
#endif

DECL_FUNCP_ADC_CONVCOMPLETE
DECL_FUNCP_SET_ADC

//void init_ADC();

#endif // _ADC_h_
