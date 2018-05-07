/*********************************************************************

          File: ADC.var.h

   Description: AVR ADC Variables definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/26

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _ADC_var_h_
#define _ADC_var_h_

#pragma __FunCX_Section Begin

#pragma __FunCX_InLevel_Except Begin

#include "ADC.const.h"

unsigned int Get_ADCValue();
void Set_ADCValue(unsigned int ADCValue);

#pragma __FunCX_InLevel_Except End

#pragma __FunCX_Section End

#endif // _ADC_var_h_
