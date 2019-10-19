/*********************************************************************

          File: ADC.var.c

   Description: AVR ADC Variables definition Source Part.

        Author: Kwangyeon Kim (onting, hemool123@naver.com)

       Created: 2019/10/20

 Copyright (c) 2019, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "ADC.var.h"

static unsigned int value = 0;

IMPL_FUNC(, unsigned int, Get_ADCValue, void, return value;)
IMPL_FUNC(, void, Set_ADCValue, unsigned int ADRES, \
    value = rsv(ADCON1, 7) ? ADRES : rsv(ADRES, 6);)