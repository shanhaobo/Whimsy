/// 主机字节序
#if 1
#   define WIZ_CFG_ENDIAN_NATIVE             WIZ_CFG_ENDIAN_LITTLE
#else
#   define WIZ_CFG_ENDIAN_NATIVE             WIZ_CFG_ENDIAN_BIG
#endif /**/
/// 参考字节序
#if 1
#   define WIZ_CFG_ENDIAN_CRITERION          WIZ_CFG_ENDIAN_LITTLE
#else
#   define WIZ_CFG_ENDIAN_CRITERION          WIZ_CFG_ENDIAN_BIG
#endif /**/

/// 08 16 32 64 128
#define WIZ_CFG_INT_SIZE                     32
/// 08 16 32 64
#define WIZ_CFG_BOOL_SIZE                    32
/// 32 64
#define WIZ_CFG_REAL_SIZE                    32

#ifndef WIZ_CFG_LIB_TYPE
#if 1
#   define WIZ_CFG_LIB_TYPE                  WIZ_CFG_LIB_TYPE_STATIC
#else
#   define WIZ_CFG_LIB_TYPE                  WIZ_CFG_LIB_TYPE_DYNAMIC
#endif /**/
#endif /*WIZ_CFG_LIB_TYPE*/

#define WIZ_CFG_WCHAR_T_STRING               WIZ_CFG_FALSE
