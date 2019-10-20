/*********************************************************************

          File: ADC.h

   Description: PIC Analog-to-Digital converter Header Part.

        Author: Kwnagyeon Kim (onting, hemool123@naver.com)

       Created: 2019/10/20

 Copyright (c) 2019, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _ADC_h_
#define _ADC_h_

#include "ADC.def.h"

DECL_FUNC(, void __attribute__((weak)), Set_Channel_ADC, unsigned int Channel);
DECL_FUNC(, void __attribute__((weak)), Set_ConversionClock_ADC, unsigned int mode);
DECL_FUNC(, void __attribute__((weak)), Set_On_ADC, bool Enable);
DECL_FUNC(, void __attribute__((weak)), Set_ResultFormet_ADC, unsigned int mode);
DECL_FUNC(, void __attribute__((weak)), Set_PortConfigBit, unsigned int mode);

#endif //_ADC_h_