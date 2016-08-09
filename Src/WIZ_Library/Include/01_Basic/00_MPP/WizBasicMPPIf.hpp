#ifndef __WIZ_BASIC_MPP_IF_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_MPP_IF_HPP__SHANHAOBO_19800429__

#include "./WizBasicMPPCombine.hpp"
#include "./WizBasicMPPBool.hpp"

/// C Conditions
/// T True
/// F False
#define WIZ_MPP_IF(C, T, F)     WIZ_MPP_COMBINE(WIZ_MPP_PREDEF_IF_, WIZ_MPP_BOOL(C))(T, F)

/// ‘§¥¶¿Ì
#define WIZ_MPP_PREDEF_IF_0(T, F) F
#define WIZ_MPP_PREDEF_IF_1(T, F) T

#endif /*__WIZ_BASIC_MPP_IF_HPP__SHANHAOBO_19800429__*/
