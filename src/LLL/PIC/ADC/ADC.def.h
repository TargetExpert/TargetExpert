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
        if(Channel >= 0 && Channel <= 7)\
            ADCON0bits.CHS = Channel;\
    )

#define Set_ConversionClock_ADC_D(mode) \
    C_(\
        switch(mode){\
        case _ADC_MODE_CLOCK_F_DIV_2: \
        ADCON0bits.ADCS = 0; ADCON1bits.ADCS2 = 0; break; \
        case _ADC_MODE_CLOCK_F_DIV_8: \
        ADCON0bits.ADCS = 1; ADCON1bits.ADCS2 = 0; break; \
        case _ADC_MODE_CLOCK_F_DIV_32: \
        ADCON0bits.ADCS = 2; ADCON1bits.ADCS2 = 0; break; \
        case _ADC_MODE_CLOCK_F_RC: \
        ADCON0bits.ADCS = 3; ADCON1bits.ADCS2 = 0; break; \
        case _ADC_MODE_CLOCK_F_DIV_4: \
        ADCON0bits.ADCS = 0; ADCON1bits.ADCS2 = 1; break; \
        case _ADC_MODE_CLOCK_F_DIV_16: \
        ADCON0bits.ADCS = 1; ADCON1bits.ADCS2 = 1; break; \
        case _ADC_MODE_CLOCK_F_DIV_64: \
        ADCON0bits.ADCS = 2; ADCON1bits.ADCS2 = 1; break; \
        default: \
        } \
    )

#define Set_On_ADC_D(Enable) \
    C_(\
        ADCON0bits.ADON = Enable;\
    )

#define Set_ResultFormat_ADC_D(mode) \
    C_(\
        if(mode == 0 || mode == 1) \
            ADCON1bits.ADFM = mode\
    )

#define Set_PortConfigBit_D(mode) \
    C_(\
        ADCON1bits.PCFG = mode; \
    )

#define Get_Result_D() \
    C_(\
        ADCON0bits.GO_NOT_DONE = 1; \
        while(ADCON0bits.GO_NOT_DONE);\
        Set_ADCValue(lsv(ADRESH, 8) | ADRESL); \
        return Get_ADCValue(); \
    )

#endif //_ADC_def_h_