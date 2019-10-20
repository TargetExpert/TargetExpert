/*********************************************************************

          File: ADC.def.h

   Description: PIC Analog-to-Digital converter syntax definition
                Header Part.

        Author: Kwangyeon Kim (onting, hemool123@naver.com)

       Created: 2019/10/20

 Copyright (c) 2019, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _ADC_def_h_
#define _ADC_def_h_

#include "ADC.var.h"

#define Set_Channel_ADC_D(Channel) \
    C_(\
        ADCON0 \
    )

#endif //_ADC_def_h_