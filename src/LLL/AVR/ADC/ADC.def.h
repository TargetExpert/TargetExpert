/*********************************************************************

          File: ADC.def.h

   Description: AVR Analog-to-Digital converter syntax definition
                Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/03/02

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _ADC_def_h_
#define _ADC_def_h_

// Functional language with C based eXtended macros.
#pragma __FunCX_Section Begin

#include "ADC.var.h"

// Definition of "Set" Macros.

#define Set_ChannelSelection_ADC_D(Channel) \
  Begin_ \
    uint8_t _Channel[MUX_BQTY] = ADCChannelArr; \
    IfSafe_(Channel < pow(2, MUX_BQTY), \
      register unsigned char i = 0; \
      ForSafe_(i = 0, i < MUX_BQTY, i++, \
        sclb_reg_common(ADMUX, Null_Param_, Null_Param_, (Channel & (1 << i)), _Channel[i], Null_Param_, Null_Param_); \
      ) \
    ) \
  End_

#define Set_ReferenceSelection_ADC_D(Reference) \
  C_( \
    IfSafe_(Reference < pow(2, REFS_BQTY), \
      register unsigned char i = 0; \
      ForSafe_(i = 0, i < REFS_BQTY, i++, \
        sclb_reg_common(ADMUX, Null_Param_, Null_Param_, (Reference & (1 << i)), REFS, Null_Param_, 0 + i); \
      ) \
    ) \
  )

#define Set_LeftAdjResult_ADC_D(Enable) \
  C_( \
    sclb_reg_common(ADMUX, , , Enable, ADLAR, , ); \
  )

#define Set_Enable_ADC_D(Enable) \
  C_( \
    sclb_reg_common(ADCSRA, , , Enable, ADEN, , ); \
  )

#define Set_StartConversion_ADC_D(Enable) \
  C_( \
    sclb_reg_common(ADCSRA, , , Enable, ADSC, , ); \
  )

#if defined(ADATE)
#define Set_AutoTriggerEnable_ADC_D(Enable) \
  C_( \
    sclb_reg_common(ADCSRA, , , Enable, ADATE, , ); \
  )
#elif defined(ADFR)
#define Set_FreeRunningSelect_ADC_D(Enable) \
  C_( \
    sclb_reg_common(ADCSRA, , , Enable, ADFR, , ); \
  )
#endif

#define Set_InterruptFlag_ADC_D(Enable) \
  C_( \
    sclb_reg_common(ADCSRA, , , Enable, ADIF, , ); \
  )

#define Set_InterruptEnable_ADC_D(Enable) \
  C_( \
    IfSafe_(ConversionCompleteInterruptFunc_ADC == NULL, \
      ConversionCompleteInterruptFunc_ADC = FakeCallee; \
    ) \
    sclb_reg_common(ADCSRA, , , Enable, ADIE, , ); \
  )

#define Set_PrescalerSelect_ADC_D(Prescaler) \
  C_( \
    IfSafe_(Prescaler < pow(2, ADPS_BQTY), \
      register unsigned char i = 0; \
      ForSafe_(i = 0, i < ADPS_BQTY, i++, \
        sclb_reg_common(ADCSRA, , , (Prescaler & (1 << i)), ADPS, , 0 + i); \
      ) \
    ) \
  )

#define Set_ACMuxEnable_ADC_D(Enable) \
  C_( \
    sclb_reg_common(ADCSRB, , , Enable, ACME, , ); \
  )

#define Set_AutoTriggerSource_ADC_D(Source) \
  C_( \
    IfSafe_(Source < pow(2, ADTS_BQTY), \
      register unsigned char i = 0; \
      ForSafe_(i = 0, i < ADTS_BQTY, i++, \
        sclb_reg_common(ADCSRB, , , (Source & (1 << i)), ADTS, , 0 + i); \
      ) \
    ) \
  )

// Definition of "Get" Macros.
#define Get_MeasureValueL_ADC_D() ADCL
#define Get_MeasureValueH_ADC_D() ADCH
#define Get_MeasureValueRes_ADC_D() \
  ((unsigned int)(Get_MeasureValueH_ADC_D() << 8) | Get_MeasureValueL_ADC_D())

#define Get_MeasureValue_ADC_D() \
  C_( \
    Set_StartConversion_ADC(true); \
    while(ADCSRA & (1 << ADSC)); \
    Set_ADCValue(ADC); \
  )

#pragma __FunCX_Section End

#endif // _ADC_def_h_
