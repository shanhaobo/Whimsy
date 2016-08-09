#ifndef __WIZ_BASIC_MPP_BIT_OP_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_MPP_BIT_OP_HPP__SHANHAOBO_19800429__


#include "./WizBasicMPPBool.hpp"

/////////////////////////////////////////

/// Not

#define WIZ_MPP_BIT_NOT(x)              WIZ_MPP_COMBINE(WIZ_MPP_PREDEF_BIT_NOT_, WIZ_MPP_BOOL(x))

/// 预定义
#define WIZ_MPP_PREDEF_BIT_NOT_0 1
#define WIZ_MPP_PREDEF_BIT_NOT_1 0

/////////////////////////////////////////

/// And

#define WIZ_MPP_BIT_AND(x, y)           WIZ_MPP_BRIDGE_BIT_AND_I(WIZ_MPP_BOOL(x), WIZ_MPP_BOOL(y))
#define WIZ_MPP_BRIDGE_BIT_AND_I(x, y)  WIZ_MPP_COMBINE(WIZ_MPP_PREDEF_BIT_AND_, WIZ_MPP_COMBINE(x, y))

/// 预定义
#define WIZ_MPP_PREDEF_BIT_AND_00 0
#define WIZ_MPP_PREDEF_BIT_AND_01 0
#define WIZ_MPP_PREDEF_BIT_AND_10 0
#define WIZ_MPP_PREDEF_BIT_AND_11 1

/////////////////////////////////////////

/// Or
#define WIZ_MPP_BIT_OR(x, y)            WIZ_MPP_BRIDGE_BIT_OR_I(WIZ_MPP_BOOL(x), WIZ_MPP_BOOL(y))
#define WIZ_MPP_BRIDGE_BIT_OR_I(x, y)   WIZ_MPP_COMBINE(WIZ_MPP_PREDEF_BIT_OR_, WIZ_MPP_COMBINE(x, y))

/// 预定义
#define WIZ_MPP_PREDEF_BIT_OR_00 0
#define WIZ_MPP_PREDEF_BIT_OR_01 1
#define WIZ_MPP_PREDEF_BIT_OR_10 1
#define WIZ_MPP_PREDEF_BIT_OR_11 1

/////////////////////////////////////////

/// Xor
#define WIZ_MPP_BIT_XOR(x, y)           WIZ_MPP_BRIDGE_BIT_XOR_I(x, y)
#define WIZ_MPP_BRIDGE_BIT_XOR_I(x, y)  WIZ_MPP_PREDEF_BIT_XOR_##x##y

/// 预定义
#define WIZ_MPP_PREDEF_BIT_XOR_00 1
#define WIZ_MPP_PREDEF_BIT_XOR_01 0
#define WIZ_MPP_PREDEF_BIT_XOR_10 0
#define WIZ_MPP_PREDEF_BIT_XOR_11 1

/////////////////////////////////////////

#endif /*__WIZ_BASIC_MPP_BIT_OP_HPP__SHANHAOBO_19800429__*/
