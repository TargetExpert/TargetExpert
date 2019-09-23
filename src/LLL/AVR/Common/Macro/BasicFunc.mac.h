/*********************************************************************

          File: BasicFunc_Mac.h

   Description: Basic Function macro Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2017/10/07

 Copyright (c) 2017, MinLC(Minimalist Library Collections) Project,
 All rights reserved.

 ** The "MinLC" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _BasicFunc_mac_h_
#define _BasicFunc_mac_h_

#include "Syntax.mac.h"

#define IMPL_DECL_CONTENTS(Contents) \
  Syntax_Contents(Contents)

#define IMPL_FUNC_CONTENTS(Contents) \
  C_(Contents)

#define HELPER_PARAM_VAR(...) __VA_ARGS__

#define DECL_FUNC(__DefTarget, __ReturnType, __FuncName, __Params) \
  __DefTarget __ReturnType __FuncName(__Params)

#define DECL_FUNC_VAR(__DefTarget, __ReturnType, __FuncName, ...) \
  __DefTarget __ReturnType __FuncName(__VA_ARGS__)

#define IMPL_FUNC(__DefTarget, __ReturnType, __FuncName, __Params, __FuncContents) \
  DECL_FUNC(__DefTarget, __ReturnType, __FuncName, __Params) \
  IMPL_FUNC_CONTENTS(__FuncContents)

#endif // _BasicFunc_mac_h_
