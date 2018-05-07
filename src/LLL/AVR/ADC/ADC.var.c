/*********************************************************************

          File: ADC.var.c

   Description: AVR ADC Variables definition Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/26

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "ADC.var.h"

static unsigned int _ADCValue = 0;

unsigned int Get_ADCValue() {
  return _ADCValue;
}

void Set_ADCValue(unsigned int ADCValue) {
  _ADCValue = ADCValue;
}