#ifndef __WHIMSY_TYPE_HPP__
#define __WHIMSY_TYPE_HPP__

#include "./WMSPrerequisites.hpp"

#include "../../WIZ_Library/include/Wiz.hpp"

#include "./WMSAllocator.hpp"

namespace wms
{
    /////////////////////////////////////////////////////////////

    namespace I
    {
        WIZ_DECLARE_HELPER_I();
    } /// end of namespace I

    namespace U
    {
        WIZ_DECLARE_HELPER_U();
    } /// end of namespace U

    namespace I8
    {
        WIZ_DECLARE_HELPER_I8();
    } /// end of namespace I8

    namespace U8
    {
        WIZ_DECLARE_HELPER_U8();
    } /// end of namespace U8

    namespace I16
    {
        WIZ_DECLARE_HELPER_I16();
    } /// end of namespace I16

    namespace U16
    {
        WIZ_DECLARE_HELPER_U16();
    } /// end of namespace U16

    namespace I32
    {
        WIZ_DECLARE_HELPER_I32();
    } /// end of namespace I32

    namespace U32
    {
        WIZ_DECLARE_HELPER_U32();
    } /// end of namespace U32

    namespace I64
    {
        WIZ_DECLARE_HELPER_I64();
    } /// end of namespace I64

    namespace U64
    {
        WIZ_DECLARE_HELPER_U64();
    } /// end of namespace U64

    /////////////////////////////////////////////////////////////

    namespace Char
    {
        WIZ_DECLARE_HELPER_CHAR();
    } /// end of namespace Char

    namespace WChar
    {
        WIZ_DECLARE_HELPER_WCHAR();
    } /// end of namespace WChar

    namespace MBChar
    {
        WIZ_DECLARE_HELPER_MBCHAR();
    } /// end of namespace MBChar

    /////////////////////////////////////////////////////////////

    namespace F32
    {
        WIZ_DECLARE_HELPER_R32();
    } /// end of namespace F32

    namespace F64
    {
        WIZ_DECLARE_HELPER_R64();
    } /// end of namespace F64

    /////////////////////////////////////////////////////////////

    namespace Void
    {
        typedef void type;
        WIZ_DECLARE_HELPER_VOID();
    } /// end of namespace Void

    namespace Bool
    {
        WIZ_DECLARE_HELPER_BOOL();
    } /// end of namespace Bool

    /////////////////////////////////////////////////////////////

    namespace Size
    {
        WIZ_DECLARE_HELPER_SIZE();
    } /// end of namespace Size

    namespace USize8
    {
        WIZ_DECLARE_HELPER_SIZE8();
    } /// end of namespace Size8

    namespace USize16
    {
        WIZ_DECLARE_HELPER_SIZE16();
    } /// end of namespace Size16

    namespace USize32
    {
        WIZ_DECLARE_HELPER_SIZE32();
    } /// end of namespace Size32

    namespace USize64
    {
        WIZ_DECLARE_HELPER_SIZE64();
    } /// end of namespace Size64

    /////////////////////////////////////////////////////////////

    namespace ID8
    {
        WIZ_DECLARE_HELPER_ID8();
    } /// end of namespace ID8

    namespace ID16
    {
        WIZ_DECLARE_HELPER_ID16();
    } /// end of namespace ID16

    namespace ID32
    {
        WIZ_DECLARE_HELPER_ID32();
    } /// end of namespace ID32

    namespace ID64
    {
        WIZ_DECLARE_HELPER_ID64();
    } /// end of namespace ID64

    /////////////////////////////////////////////////////////////

    template <typename T>
    struct InitList
    {
        typedef typename ::Wiz::InitializerList<T>::Type    type;
    };

    /////////////////////////////////////////////////////////////

    template <typename T, typename A = ::std::allocator<T> > 
    struct Array
    {
        typedef typename ::Wiz::Array::Type<T, A>           type;

        typedef type*                                       ptr;
    };

    template <typename T, typename A = ::std::allocator<T> >
    struct List
    {
        typedef typename ::Wiz::List::Type<T, A>            type;

        typedef type*                                       ptr;
    };

    template <typename T, typename V, class C = ::std::less<T>, typename A = ::std::allocator< ::std::pair<T, V> > >
    struct Map
    {
        typedef typename ::Wiz::Map::Type<T, V, C, A>       type;
    };

    template <typename T, typename V, class C = ::std::less<T>, typename A = ::std::allocator< ::std::pair<T, V> > >
    struct MultiMap
    {
        typedef typename ::Wiz::MultiMap::Type<T, V, C, A>  type;
    };

    template <typename T, class C = ::std::less<T>, typename A = ::std::allocator<T> >
    struct Set
    {
        typedef typename ::Wiz::Set::Type<T, C, A>          type;
    };

    template <typename T, typename A = ::std::allocator<T> >
    struct Deque
    {
        typedef typename ::Wiz::Deque::Type<T, A>           type;
    };

    /////////////////////////////////////////////////////////////

    namespace Str
    {
        typedef ::Wiz::String::Type<::wms::Char::type>      type;
        WMS_DECLARE(type);

		typedef type::tChar									tChar;
    } /// end of namespace Str

    namespace WStr
    {
        typedef ::Wiz::String::Type<::wms::WChar::type>     type;
		WMS_DECLARE(type);

		typedef type::tChar									tChar;
    } /// end of namespace WStr

    /////////////////////////////////////////////////////////////

    namespace Name
    {
        typedef ::Wiz::HashString::Type< ::wms::Str::type, ::Wiz::HashString::Proxy::Category::eSDBM, true, 64, 65536, 1024, ::std::allocator<::wms::Str::tChar> >   type;

        WMS_DECLARE(type);
    } /// end of namespace Name

    /////////////////////////////////////////////////////////////

    namespace Vec2
    {
        typedef ::Wiz::Vector2::Type<::wms::F32::type> type;

        WMS_DECLARE(type);
    } /// end of namespace Vec2

    namespace Vec3
    {
        typedef ::Wiz::Vector3::Type<::wms::F32::type> type;

        WMS_DECLARE(type);
    } /// end of namespace Vec3

    namespace Vec4
    {
        typedef ::Wiz::Vector4::Type<::wms::F32::type> type;

        WMS_DECLARE(type);
    } /// end of namespace Vec4

    /////////////////////////////////////////////////////////////

} /// namespace wms

#endif /// __WHIMSY_TYPE_HPP__
