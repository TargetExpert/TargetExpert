/*********************************************************************

          File: FuncImplSet_mac.h

   Description: FuncImplSet macro Header Part.

        Author: Doohoon Kim (Gabriel Kim, invi.dh.kim@gmail.com)

       Created: 2016/09/18

 Copyright (c) 2017, MinLC(Minimalist Library Collections) Project,
 All rights reserved.

 ** The "MinLC" is distributed under the "3-clause BSD" license.
    See details COPYING.

*********************************************************************/

#ifndef _FuncImplSet_mac_h_
#define _FuncImplSet_mac_h_

#include "BasicFunc_Mac.h"

#define IMPL_GET_FUNC(__ReturnType, __FuncName, __ReturnValue) \
  IMPL_FUNC(, __ReturnType, Get_##__FuncName, , return __ReturnValue;)

#define IMPL_SET_FUNC(__Type, __FuncName, __DestValue) \
  IMPL_FUNC(, void, Set_##__FuncName, __Type __TxV, __DestValue = __TxV;)

#define IMPL_GET_SET_FUNC(__Type, __FuncName, __Value) \
  IMPL_GET_FUNC(__Type, __FuncName, __Value) \
  IMPL_SET_FUNC(__Type, __FuncName, __Value)

#define DECL_VFUNC(__ReturnType, __FuncName, __Params) \
  DECL_FUNC(virtual, __ReturnType, __FuncName, __Params) = 0;

#define DECL_GET_VFUNC(__ReturnType, __FuncName) \
  DECL_VFUNC(__ReturnType, Get_##__FuncName, )

#define DECL_SET_VFUNC(__ParamType, __FuncName) \
  DECL_VFUNC(void, Set_##__FuncName, __ParamType _TxV)

#define DECL_GET_SET_VFUNC(__Type, __FuncName) \
  DECL_GET_VFUNC(__Type, __FuncName) \
  DECL_SET_VFUNC(__Type, __FuncName)

#define DECL_GET_FUNC(__ReturnType, __FuncName) \
  DECL_FUNC(__ReturnType, Get_##__FuncName, );

#define DECL_SET_FUNC(__ParamType, __FuncName) \
  DECL_FUNC(void, Set_##__FuncName, __ParamType _TxV);

#define DECL_GET_SET_FUNC(__Type, __FuncName) \
  DECL_GET_FUNC(__Type, __FuncName) \
  DECL_SET_FUNC(__Type, __FuncName)

// __DefTarget __ReturnType __FuncName(__Params)

#endif // _FuncImplSet_mac_hpp_