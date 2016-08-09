#ifndef __WIZ_BASIC_MPP_STRINGIZE_HPP__SHANHAOBO_19800429__
#define __WIZ_BASIC_MPP_STRINGIZE_HPP__SHANHAOBO_19800429__

#ifndef WIZ_MPP_STRINGIZE

/// 示例:Macro_1,是分别是一个宏, 并且要转换成"Macro"
/// #define  Macro_1   Macro
/// #define  WIZ_MPP_STRINGIZE_Error(x)  #x
/// 解析 WIZ_MPP_STRINGIZE_Error(Macro_1) => "Macro_1" （并未达到预期的"Macro"）
/// 编译器会直接将Macro_1当作字符串处理
/// 如果用下面正确的WIZ_MPP_STRINGIZE,就会进入WIZ_MPP_BRIDGE_STRINGIZE((text)),在这时编辑器会将Macro_1展开

#   define WIZ_MPP_STRINGIZE(text)              WIZ_MPP_BRIDGE_STRINGIZE((text))
#   define WIZ_MPP_BRIDGE_STRINGIZE(text)       WIZ_MPP_BRIDGE_STRINGIZE_IMPL text

#   define WIZ_MPP_BRIDGE_STRINGIZE_IMPL(text)  #text

#endif /*WIZ_MPP_STRINGIZE*/

#endif /*__WIZ_BASIC_MPP_STRINGIZE_HPP__SHANHAOBO_19800429__*/
