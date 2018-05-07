/*********************************************************************

          File: ADC.const.h

   Description: AVR ADC essential Constants definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/27

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _ADC_const_h_
#define _ADC_const_h_

#include "Common.inc.h"

#pragma __FunCX_InLevel_Except Begin
#define AVR_MODE_BIT(__Num) __Num

#define ADPRES_2 1
#define ADPRES_4 2
#define ADPRES_8 3
#define ADPRES_16 4
#define ADPRES_32 5
#define ADPRES_64 6
#define ADPRES_128 7

// Definition of "Quantity of Register Bits".
#if defined(MUX4)
#define MUX_BQTY AVR_MODE_BIT(5) // Qty. for MUXn Register Bits.
#else
#define MUX_BQTY AVR_MODE_BIT(4) // Qty. for MUXn Register Bits.
#endif
#define REFS_BQTY AVR_MODE_BIT(2) // Qty. for REFS Register Bits.
#define ADPS_BQTY AVR_MODE_BIT(3) // Qty. for ADPSn Register Bits.
#define ADTS_BQTY AVR_MODE_BIT(3) // Qty. for ADTSn Register Bits.

// Definition of "Array of Registers".
#define ADCMUXArr_S Begin_
#define ADCMUXArr_BitsBasic MUX0, MUX1, MUX2, MUX3
#define ADCMUXArr_BitsEx , MUX4
#define ADCMUXArr_E End_

#if defined(MUX4)
#define ADCChannelArr \
  ADCMUXArr_S \
  ADCMUXArr_BitsBasic \
  ADCMUXArr_BitsEx \
  ADCMUXArr_E
#else
#define ADCChannelArr \
  ADCMUXArr_S \
  ADCMUXArr_BitsBasic \
  ADCMUXArr_E
#endif
#pragma __FunCX_InLevel_Except End

#endif // _ADC_const_h_
