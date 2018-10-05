/*********************************************************************

          File: TimeConv.h

   Description: AVR Time Conversion Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2018/01/23

 Copyright (c) 2018, TargetExpert Project is Gabriel Kim(Doohoon Kim),
 All rights reserved.

 ** The "TargetExpert" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _TimeConv_h_
#define _TimeConv_h_

#include <math.h>

#define UpToUnitPow(__Unit) (pow(1000, __Unit))
#define nSTouS(__nS) ((unsigned int)(__nS * UpToUnitPow(1)))
#define nSTomS(__nS) ((unsigned int)(__nS * UpToUnitPow(2)))
#define nSToS(__nS) ((unsigned int)(__nS * UpToUnitPow(3)))

#define uSToMS(__uS) (nSTomS(__uS))
#define uSToS(__uS) (nSToS(__uS))

#define MSToS(__mS) (uSToS(__mS))

#define nSecToFreq(__nS) ((double)(UpToUnitPow(3) / __nS))
#define uSecToFreq(__uS) ((double)(UpToUnitPow(2) / __uS))
#define mSecToFreq(__mS) ((double)(UpToUnitPow(1) / __mS))

#endif // _TimeConv_h_
