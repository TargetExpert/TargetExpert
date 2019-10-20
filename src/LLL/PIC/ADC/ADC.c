/*********************************************************************

          File: ADC.c

   Description: PIC Analog-to-Digital converter Source Part.

        Author: Kwangyeon Kim (onting, hemool123@naver.com)

       Created: 2019/10/20

 Copyright (c) 2019, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "ADC.h"

DECL_FUNC(, void, Set_Channel_ADC, unsigned int Channel) \
    Set_Channel_ADC_D(Channel)

DECL_FUNC(, void, Set_ConversionClock_ADC, unsigned int mode) \
    Set_ConversionClock_ADC_D(mode)

DECL_FUNC(, void, Set_On_ADC, bool Enable) \
    Set_On_ADC_D(Enable)

DECL_FUNC(, void, Set_PortConfigBit, unsigned int mode) \
    Set_PortConfigBit_D(mode);

DECL_FUNC(, void, Get_Result, void) \
    Get_Result_D()
