/*********************************************************************

          File: TC_ExtIn.c

   Description: AVR T/C internal of extended functions Source Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/04/12

 Copyright (c) 2018, TargetExpert Project, and Gabriel Kim(Doohoon Kim)
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#include "TC_Basic.var.h"
#include "TC_Ext.var.h"

#include "TC_ExtIn.h"

#include <stdlib.h>

#include "U_Math.h"

/*
#include "USART.h"
#include <stdio.h>
#include <string.h>
*/
//static double xman[PWM_Prescalar_Qty];

void _UpdateWGMode(uint8_t __PeriNum) {
  // _UpdateWGMode (for ICF, OCR(Toggle Mode))
  // update module for waveform generation mode.
  TCFreqOptiValueStoreage _TTCOVInfo = Get_TCOVInfo(__PeriNum);
  TCChanOptionsInformations _TTOptInfo = Get_TOptInfo(__PeriNum);
  _TTCOVInfo.TCWGMNBitPeriInfo.WGMValue =
      (uint8_t)(_TTCOVInfo.TCWGMNBitPeriInfo.WGMRefValue +
                      ((_TTOptInfo.IsICFTop
                        && _TTCOVInfo.TCWGMNBitPeriInfo.IsVariodicTop)
                       ? _TTCOVInfo.TCWGMNBitPeriInfo.ICFMoveValue : 0));
  Set_TCOVInfo(__PeriNum, _TTCOVInfo);
}

uint8_t _GetTCPeripheralChannelInfo(uint8_t __PeriNum) {
  if (__PeriNum > PWM_Peripheral_Qty - 1) return 0;

  uint8_t _TPWM_PeripheralChannelInfo[PWM_Peripheral_Qty] = TCPeriChanQtyInfoArr;
  return _TPWM_PeripheralChannelInfo[__PeriNum];
}

uint8_t _GetTCPeripheralBit(uint8_t __PeriNum) {
  if (__PeriNum > PWM_Peripheral_Qty - 1) return 0;

  // 1 * 4(max) = 4
  uint8_t _TTC_PeripheralBit[PWM_Peripheral_Qty] = TCPeriBitInfoArr;
  return _TTC_PeripheralBit[__PeriNum];
  // all variables summations is 4 bytes.
  // maximum raise stack memory is 184 bytes.
}

uint8_t _GetTCModeBit(uint8_t __PeriNum, uint8_t __Mode) {
  if (__PeriNum > PWM_Peripheral_Qty - 1) return 0;

  uint8_t _TBit = 0;
  uint8_t _TStaticTCModeBit[2][6] = {
      {FPWM_8, FPWM_9, FPWM_10, PCPWM_8, PCPWM_9, PCPWM_10},
      {8, 9, 10, 8, 9, 10}
  };

  register uint8_t i = 0;
  for (i = 0; i < 6; i++)
    if (__Mode == _TStaticTCModeBit[0][i]) {
      _TBit = _TStaticTCModeBit[1][i];
      break;
    }

  if (_TBit == 0)
    _TBit = _GetTCPeripheralBit(__PeriNum);

  return _TBit;
  // all variables summations is 1 bytes.
  // maximum raise stack memory is 181 bytes.
}

uint8_t _GetModeBitValueByTCPWMModeValueArr(uint8_t __PeriBit) {
  uint8_t _TTCPWMModeValueArr[2] = TCPWMModeValueArr; // 1 * 2 = 2
  uint8_t _TArrIndex = (uint8_t)((__PeriBit == 8) ? 0 : 1); // 1
  return _TTCPWMModeValueArr[_TArrIndex];
  // all variables summations is 3 bytes.
  // maximum raise stack memory is 184 bytes.
}

#define _ModeArrInitialization(__Bit) \
  TCWGMNBitPeriInformations _TModeArr[TC##__Bit##BitPWMModeMaxQty] = TC##__Bit##BitWGModeArr; \
  register uint8_t i = 0; \
  for (i = 0; i < TC##__Bit##BitPWMModeMaxQty; i++) { \
    _TTCModeArr[i] = _TModeArr[i]; \
  }

// must using free.
TCModeData _GetTCModeArr(uint8_t __PeriBit, uint8_t __ModeBitQty) {
  TCModeData _TTCModeArr = (TCModeData)malloc(sizeof(TCModeData) * __ModeBitQty); // 1 * 2 * (6 ~ 11) = 12(min) ~ 22(max)

  if (__PeriBit == 8) { _ModeArrInitialization(8) } // 2 * 1 * (4 ~ 6) = 8(min) ~ 12(max)
  else { _ModeArrInitialization(16) } // 2 * 1 * 11 = 22

  return _TTCModeArr;
  // all variables summations is 43(min) ~ 57(max) bytes.
  // maximum raise stack memory is 224(min) ~ 238(max) bytes.
}

double _GetAutoCalculatedTCCountByFreq(double __CalcFreq, double __WishFreq, uint8_t __TCModeBit) {
  uint16_t _TMaxTopValue = (uint16_t)pow_2i(__TCModeBit);
  double _TCount = _TMaxTopValue - (uint16_t)(__CalcFreq / __WishFreq);
  if ((uint16_t)_TCount > _TMaxTopValue) _TCount = 0.0f;
  return _TCount;
}

TCFreqOptiValueStoreage _GetAutoCalculatedPeriodByMode(uint8_t __PeriNum, TCWGMNBitPeriInformations __Mode, double __WishFreq) {
  TCFreqOptiValueStoreage _TNowTCFreqOptiValue = InitialFormFreqOptiValues;
  _TNowTCFreqOptiValue.TCWGMNBitPeriInfo = __Mode;
  _TNowTCFreqOptiValue.TCCalcValInfo.Able = false;

  if (__PeriNum > PWM_Peripheral_Qty - 1) return _TNowTCFreqOptiValue;

  // 2 * 4 * 7 = 56
  uint16_t _TPrescalerArr[PWM_Peripheral_Qty][PWM_Prescalar_Qty] = TCPrescalerArr;

  uint8_t _TTCPeriBit = _GetTCPeripheralBit(__PeriNum);
  uint8_t _TTCModeBit = _GetTCModeBit(__PeriNum, _TNowTCFreqOptiValue.TCWGMNBitPeriInfo.ModeName);
  uint8_t _TSigniture = _TNowTCFreqOptiValue.TCWGMNBitPeriInfo.ModeSigniture;

  if ((_TTCPeriBit == 8) && (_TTCModeBit > 8))
    return _TNowTCFreqOptiValue; // do not support this mode in 8 bit pwm peripheral.

  bool _TCheckNormalMode = (_TSigniture == 'n') ? true : false;
  uint16_t _TWGModeMaxTopValue = (uint16_t)pow_2i(_TTCModeBit);

  uint16_t _TOptiTop[PWM_Prescalar_Qty]; // 14
  double _TOptiTCCount[PWM_Prescalar_Qty], _TCalcActRealFreq[PWM_Prescalar_Qty]; // 56

  register uint16_t i = 0;

  for (i = 0; i < PWM_Prescalar_Qty; i++) {
    _TOptiTop[i] = _TWGModeMaxTopValue;
    _TOptiTCCount[i] = 0;
    _TCalcActRealFreq[i] = F_CPU;
  }
  // variables summations is 193 bytes at this section.
  // i is N.
  uint8_t _TBaseLineTopSumRes = (uint8_t)((_TSigniture == 'f' || _TSigniture == 'c') ? 1 : 0); // 1
  uint8_t _TBaseLineMulRes = (uint8_t)((_TSigniture == 'f' || _TCheckNormalMode) ? 1 : 2); // 1
  double _TFreqOverBaseLineMulRes = ((double)F_CPU) / _TBaseLineMulRes;

  for (i = 0; i < PWM_Prescalar_Qty; i++) {
    uint16_t _TN = _TPrescalerArr[__PeriNum][i]; // 2

    if (_TN >= EXT_CLOCK_FALL) break;

    double _TCalcFreqByPrescalar =
        _TFreqOverBaseLineMulRes * (1.0f / ((double)_TN * ((double)_TBaseLineTopSumRes + (double)((_TCheckNormalMode) ? 1 : _TOptiTop[i])))); // 8

    // variables summations is 213 bytes at this section.
    if (_TCalcFreqByPrescalar > __WishFreq && !_TCheckNormalMode) continue;

    // for normal mode.
    if (_TCheckNormalMode)
      _TOptiTCCount[i] = _GetAutoCalculatedTCCountByFreq(_TCalcFreqByPrescalar, __WishFreq, _TTCModeBit);

    if (__Mode.IsVariodicTop) {
      uint16_t _TOptiTopValue = _TOptiTop[i]; // 2
      double _TCalcNSub = _TN; // 8
      // section of Variodic "Top" value.
      // this loop is calculation for optimized TOP value.
      register uint16_t j = 0;

      for (j = 0; j < _TWGModeMaxTopValue; j++) {
        // variables summations is 221 bytes at this section.
        double _TCalcN =
            _TFreqOverBaseLineMulRes * (1.0f / (__WishFreq * (double)(_TBaseLineTopSumRes + j))); // 8

        // If the value obtained by subtracting
        // the criterion N from the calculated N is less than zero..
        if ((_TCalcN - _TN) < 0.0f) break;
        if ((_TCalcN -_TN >= 0.0f) && (_TCalcN - _TN < _TCalcNSub)) {
          _TCalcNSub = _TCalcN - _TN;
          _TOptiTopValue = j;
        }
      }

      if (_TOptiTopValue != _TOptiTop[i])
        _TOptiTop[i] = _TOptiTopValue;
    }

    _TCalcActRealFreq[i] =
        _TFreqOverBaseLineMulRes * (1.0f / ((double)_TN * ((double)_TBaseLineTopSumRes + (_TOptiTop[i] - ((_TCheckNormalMode) ? _TOptiTCCount[i] : 0)))));
  }

  double _TMinFreqError = F_CPU, _TMinFreqErrorRate = 100.0f;
  int8_t _TIndex = -1; // 1
  bool _TIsDetect = false; // 1
  // variables summations is 211 bytes at this section.

  for (i = 0; i < PWM_Prescalar_Qty; i++) {
    double _TActRealFreq = _TCalcActRealFreq[i];
    double _TFreqError = fabs(__WishFreq - _TActRealFreq);
    double _TFreqErrorRate = (_TFreqError / __WishFreq) * 100;

    if (_TFreqErrorRate < _TMinFreqErrorRate) {
      _TMinFreqError = _TFreqError;
      _TMinFreqErrorRate = _TFreqErrorRate;
      _TIndex = (int8_t)i;
      _TIsDetect = true;
    }
  }

  if (!_TIsDetect)
    return _TNowTCFreqOptiValue;

  _TNowTCFreqOptiValue.TCCalcValInfo.Able = true;
  _TNowTCFreqOptiValue.TCCalcValInfo.N = _TPrescalerArr[__PeriNum][_TIndex];
  _TNowTCFreqOptiValue.TCCalcValInfo.NBit = (uint8_t)(_TIndex + 1);

  _TNowTCFreqOptiValue.TCCalcValInfo.Top = _TOptiTop[_TIndex];
  //_TNowTCFreqOptiValue.TCCalcValInfo.TCnt = _TWGModeMaxTopValue - (uint16_t)_TOptiTCCount[_TIndex];
  _TNowTCFreqOptiValue.TCCalcValInfo.TCnt = (uint16_t)_TOptiTCCount[_TIndex];
  _TNowTCFreqOptiValue.TCCalcValInfo.CalcFreq = _TCalcActRealFreq[_TIndex];
  _TNowTCFreqOptiValue.TCCalcValInfo.FreqError = _TMinFreqError;
  _TNowTCFreqOptiValue.TCCalcValInfo.FreqErrorRate = _TMinFreqErrorRate;

  return _TNowTCFreqOptiValue;
  // all variables summations is 82 bytes.
  // maximum raise stack memory is 211 bytes.
}

TCFreqOptiValueStoreage _GetAutoCalculatedPeriodByModeName(uint8_t __PeriNum, uint8_t __ModeName, double __WishFreq) {
  uint8_t _TTCPeriBit = _GetTCPeripheralBit(__PeriNum);
  uint8_t _TTCModeBitQty = _GetModeBitValueByTCPWMModeValueArr(_TTCPeriBit);
  TCModeData _TTCModeArr = _GetTCModeArr(_TTCPeriBit, _TTCModeBitQty); // 12(min) ~ 22(max) is not released.

  TCFreqOptiValueStoreage _TNowTCFreqOptiValue = InitialFormFreqOptiValues;
  register uint8_t i = 0;
  for (i = 0; i < _TTCModeBitQty; i++) {
    if (_TTCModeArr[i].ModeName == __ModeName) {
      _TNowTCFreqOptiValue = _GetAutoCalculatedPeriodByMode(__PeriNum, _TTCModeArr[i], __WishFreq);
      break;
    }
  }

  free(_TTCModeArr);
  return _TNowTCFreqOptiValue;
}

#define _SwapArr(_1, _2) { TCFreqOptiValueStoreage _T = _1; _1 = _2; _2 = _T; }

TCFreqOptiValueStoreage _GetTCPeriodAutoSelectionByPeripheral(uint8_t __PeriNum, double __Period) {
  /*
   * I tried to allocate _TTCFreqOptiValueStoreage array dynamically,
   * but because of avr-gcc's compiler bug (4.9.3 or earlier)
   * I could not dynamically allocate it, but it was statically allocated.
   * Therefore, if a better version is loaded based on avr-gcc installed on arduino,
   * i'll change this syntax.
   */
  TCFreqOptiValueStoreage _TTCFreqOptiValueStoreage[ModeArrMaxQty]; // 32 * 10 = 320

  // variables summations is 73 bytes at this section.
  uint8_t _TTCPeriBit = _GetTCPeripheralBit(__PeriNum);
  uint8_t _TTCModeBitQty = _GetModeBitValueByTCPWMModeValueArr(_TTCPeriBit);
  TCModeData _TTCModeArr = _GetTCModeArr(_TTCPeriBit, _TTCModeBitQty); // 12(min) ~ 22(max) is not released.

  // 32 + 45 + 22 + 6(min) ~ 11(max) = 105(min) ~ 110(max)
  // variables summations is 105(min) ~ 110(max) bytes at this section.
  register uint8_t i = 0;

  for (i = 0; i < _TTCModeBitQty; i++) {
    _TTCFreqOptiValueStoreage[i] = _GetAutoCalculatedPeriodByMode(__PeriNum, _TTCModeArr[i], __Period);
  }

  // executing sort(refer to frequency error rate).
  for (i = 0; i < _TTCModeBitQty - 1; i++) {
    register uint8_t j = 0;
    for (j = i + 1; j < _TTCModeBitQty; j++) {
      if (_TTCFreqOptiValueStoreage[i].TCCalcValInfo.FreqErrorRate > _TTCFreqOptiValueStoreage[j].TCCalcValInfo.FreqErrorRate)
        _SwapArr(_TTCFreqOptiValueStoreage[i], _TTCFreqOptiValueStoreage[j]);
    }
  }

  uint8_t _TIndex = 0;
  double _TFreqErrorMax = 0.0f;
  TCChanOptionsInformations _TTOptInfo = Get_TOptInfo(__PeriNum);
  // extract index of refer to margin freq(Error Rate).
  for (i = 0; i < _TTCModeBitQty; i++) {
    if (_TTCFreqOptiValueStoreage[i].TCCalcValInfo.FreqErrorRate >= _TFreqErrorMax
        && _TTCFreqOptiValueStoreage[i].TCCalcValInfo.FreqErrorRate < _TTOptInfo.DiffMarginFreqValue) {
      _TIndex = i;
      _TFreqErrorMax = _TTCFreqOptiValueStoreage[i].TCCalcValInfo.FreqErrorRate;
    }
  }

  // executing sort(refer to top value).
  for (i = 0; i < _TIndex; i++) {
    register uint8_t j = 0;
    for (j = i + 1; j < _TIndex + 1; j++) {
      if (_TTCFreqOptiValueStoreage[i].TCCalcValInfo.Top < _TTCFreqOptiValueStoreage[j].TCCalcValInfo.Top
          && _TTCFreqOptiValueStoreage[i].TCCalcValInfo.FreqErrorRate >= _TTCFreqOptiValueStoreage[j].TCCalcValInfo.FreqErrorRate)
        _SwapArr(_TTCFreqOptiValueStoreage[i], _TTCFreqOptiValueStoreage[j]);
    }
  }

  TCFreqOptiValueStoreage _TTCFreqOptiValue = InitialFormFreqOptiValues;
  uint8_t _TFindAutoModeIndex = 0;

  for (i = 0; i < _TIndex; i++) {
    if (!Get_DefaultAutoMode(__PeriNum)
        && _TTCFreqOptiValueStoreage[i].TCWGMNBitPeriInfo.ModeSigniture == 'n') {
      _TFindAutoModeIndex = i;
      break;
    }
    else {
      if (Get_DefaultAutoMode(__PeriNum) && i == 0
          && _TTCFreqOptiValueStoreage[i].TCWGMNBitPeriInfo.ModeSigniture == 'n') {
        continue;
      }
      else {
        _TFindAutoModeIndex = i;
        break;
      }
    }
  }

  if (_TTCFreqOptiValueStoreage[_TFindAutoModeIndex].TCCalcValInfo.FreqErrorRate
      > _TTOptInfo.DiffMarginFreqValue) {
    free(_TTCModeArr);
    return _TTCFreqOptiValue;
  }

  _TTCFreqOptiValue = _TTCFreqOptiValueStoreage[_TFindAutoModeIndex];

  free(_TTCModeArr);
  return _TTCFreqOptiValue;
  // all variables summations is 107(min) ~ 112(max) bytes.
  // maximum raise stack memory is 287(min) ~ 292(max) bytes.
}

/*
double Get_xman(uint8_t __Perinum) {
  return xman[__Perinum];
}
*/