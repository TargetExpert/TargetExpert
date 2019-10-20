/*********************************************************************

          File: ADC.var.h

   Description: PIC ADC Variables definition Header Part.

        Author: Kwangyeon Kim (onting, hemool123@naver.com)

       Created: 2019/10/20

 Copyright (c) 2019, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _ADC_var_h_
#define _ADC_var_h_

#include "ADC.const.h"

DECL_FUNC(, unsigned int, Get_ADCValue, void);
DECL_FUNC(, void, Set_ADCValue, unsigned int ADRES);

#endif //_ADC_var_h_