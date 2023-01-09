
#include <type_traits>

#include "config/zxx.config.h"

#ifndef _ARRAY_TRAITS_H_

#define _ARRAY_TRAITS_H_

BEGIN_NS_ZXX_CORE_CONTAINER

    using size_t = std::size_t;   
     
    /**
     * `_array_traits` is a class template that is used to provide information about the size and element type of an `zxx::core::array` object. 
     * It is an implementation detail of the `zxx::core::array` class, and it is not intended to be used directly by users of `zxx::core::array`.
     * 
     * The purpose of `_array_traits` is to allow the `zxx::core::array` class to support arrays of both fixed and variable size. By using a class template, `_array_traits` can provide different implementations of `zxx::core::array` for arrays of different sizes.
     * 
     * For example, the specialization `template<typename _T> struct _array_traits<_T, 0>` is used to provide information about an `zxx::core::array` object that has a size of 0. This specialization allows the use of `zxx::core::array` objects with a size of 0, which is not allowed by the default implementation of `zxx::core::array`.
     * 
     * On the other hand, the primary template template<typename _T, size_t _N> struct `_array_traits` is used to provide information about an `zxx::core::array` object that has a size of _N, where _N is a non-zero size specified as a template argument. This primary template provides the default implementation of `zxx::core::array` for arrays of non-zero size.
     * 
     * It's worth noting that the `_array_traits` class template is derived from the GCC implementation of the Standard Template Library (STL), and it may not be present in other implementations of the STL. In the standard C++ library, the `zxx::core::array` class is implemented using other class templates and helper functions, rather than using a class template like `_array_traits`.
     * 
     */
    template<typename _T, size_t _N>
    struct _array_traits
    {
        typedef _T _Type[_N];
        #if __cplusplus >= 201703L
            typedef std::is_swappable<_T> _Is_swappable;
            typedef std::is_nothrow_swappable<_T> _Is_nothrow_swappable;
        #endif

        static ZXX_CONSTEXPR _T&
        _s_ref(const _Type& __t, size_t __n) noexcept
        { return const_cast<_T&>(__t[__n]); }

        static ZXX_CONSTEXPR _T*
        _s_ptr(const _Type& __t) noexcept
        { return const_cast<_T*>(__t); }
    };

    template<typename _T>
    struct _array_traits<_T, 0>
    {
        struct _Type { };
        #if cplusplus >= 201703L
            typedef std::true_type _Is_swappable;
            typedef std::true_type _Is_nothrow_swappable;
        #endif

        static ZXX_CONSTEXPR _T&
        _s_ref(const _Type&, size_t) noexcept
        { return *static_cast<_T*>(nullptr); }

        static ZXX_CONSTEXPR _T*
        _s_ptr(const _Type&) noexcept
        { return nullptr; }
    };

END_NS_ZXX_CORE_CONTAINER

#endif // !_ARRAY_TRAITS_H_
