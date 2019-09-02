/*********************************************************************

          File: TC_Basic.strt.h

   Description: AVR TC basic struct definition Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/21

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TC_Basic_strt_h_
#define _TC_Basic_strt_h_

#pragma __FunCX_Section Begin

#include <stdbool.h>
#include <stdint.h>

#pragma __FunCX_InLevel_Except Begin

typedef struct _TCWGMNBitPeriInfo {
  uint8_t ModeName;
  uint8_t WGMValue;
  uint8_t ModeSigniture;
  bool IsVariodicTop;
  uint8_t WGMRefValue;
  int8_t ICFMoveValue;
} TCWGMNBitPeriInformations;

typedef struct _TCCalcValueInformations {
  bool Able; // 8(1)
  uint16_t Top; // 16(2)
  uint16_t TCnt; // 16(2)
  uint16_t N; // 16(2)
  uint8_t NBit; // 8(1)
  double CalcFreq; // 32(8)
  double FreqError; // 32(8)
  double FreqErrorRate; // 32(8)
} TCCalcValueInformations;

#define TCModeData TCWGMNBitPeriInformations *

typedef struct _TCFreqOptiValueStoreage {
  TCWGMNBitPeriInformations TCWGMNBitPeriInfo;
  TCCalcValueInformations TCCalcValInfo;
} TCFreqOptiValueStoreage; // summation all 32 byte.

#pragma __FunCX_InLevel_Except End

#pragma __FunCX_Section End

#endif // _TC_Basic_strt_h_
