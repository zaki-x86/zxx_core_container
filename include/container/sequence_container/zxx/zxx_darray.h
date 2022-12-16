/**
 * @file zxx_darray.h
 * @author M Zaki (mamadov_zicx@gmail.com)
 * @brief dynamic array container API
 * @version 0.1
 * @date 2022-12-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @file darray.hpp
 * @author M Zaki
 * @brief A class template for a darray type
 * @see [Dynamic Arrays](data/darray.md)
 * @version 0.1
 * @date 2022-11-07
 * 
 * @copyright Copyright (c) Zaki 2022
 * 
 */

#pragma once

#define DEBUG true  ///< Flag set to enable some logging for debugging 

#include <iostream>
#include <exception>
#include <algorithm>
#include <memory>
#include <type_traits>


#if __cplusplus >= 201103L
#define GLIBZXX_CONSTEXPR constexpr  
#endif
#if __cplusplus >= 201703L
#define GLIBZXX_CONSTEXPR constexpr
#endif
#if __cplusplus >= 202003L
#define GLIBZXX_CONSTEXPR constexpr
#endif

namespace zxx = std;

namespace container
{

template <typename T,  typename Allocator = zxx::allocator<T>>
class darray
{
private:
    size_t m_capacity;                             
    T* m_data;                          
    size_t m_size;                      
    void resize();                      
    bool m_resource_allocation_failed;

public:
    // temporary - till all libraries are implemented
    // ************
    // member types
    // ************
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = zxx::allocator_traits<Allocator>::pointer
    using const_pointer = zxx::allocator_traits<Allocator>::const_pointer;
    using iterator = T*;
    using const_iterator = const T*;
    using difference_type = zxx::ptrdiff_t;
    using allocator_type = Allocator;
    using size_type = size_t;
    using reverse_iterator = zxx::reverse_iterator<iterator> ; 
    using const_reverse_iterator = zxx::reverse_iterator<const_iterator> ; 

public:
    /*****************
     * darray iterator
     *****************/
    struct iterator
    {
        using self = iterator;
        typedef typename Allocator::difference_type difference_type;
        typedef typename Allocator::value_type value_type;
        typedef typename Allocator::reference reference;
        typedef typename Allocator::pointer pointer;
        typedef zxx::random_access_iterator_tag iterator_category;

        iterator() : _m_ptr(nullptr) {};

        iterator( pointer ptr ) :_m_ptr(ptr) {}

        reference operator*() const
        {
            return *_m_ptr;
        }

        pointer operator->() const
        {
            return _m_ptr;
        }

        self& operator++()
        {
            ++_m_ptr;
            return *this;
        }

        self operator++( int )
        {
            return _m_ptr;
        }

        self& operator--()
        {
            _m_ptr--;
            return *this;
        }

        self operator--( int )
        {
            return _m_ptr--;
        }

        self operator+( difference_type d ) const
        {
            return _m_ptr + d;
        }

        self operator-( difference_type d ) const
        {
            return _m_ptr - d;
        }

        bool operator==( const self& x ) const
        {
            return _m_ptr == x._m_ptr;
        }

        bool operator!=( const self& x ) const
        {
            return !(*this == x);
        }


        private:
            pointer _m_ptr;
    };
    

public:
    
    GLIBZXX_CONSTEXPR 
    darray();

    GLIBZXX_CONSTEXPR explicit 
    darray( Allocator& alloc );

    GLIBZXX_CONSTEXPR 
    darray( const darray& other );

    GLIBZXX_CONSTEXPR 
    darray( 
        const darray& other, 
        Allocator& alloc 
    );

    GLIBZXX_CONSTEXPR 
    darray( darray&& other );

    GLIBZXX_CONSTEXPR 
    darray( 
        darray&& other, 
        Allocator& alloc 
    );

    GLIBZXX_CONSTEXPR explicit 
    darray( 
        size_type n, 
        const value_type& value = {},
        const Allocator& alloc = Allocator()
    );

    GLIBZXX_CONSTEXPR 
    darray( 
        size_type count,
        const Allocator& alloc = Allocator() )
    ;

    template<typename InputIterator>
    GLIBZXX_CONSTEXPR
    darray( 
        InputIterator first, 
        InputIterator last, 
        const Allocator& alloc = Allocator() 
    );

    GLIBZXX_CONSTEXPR 
    darray( 
        zxx::initializer_list<T> init,
        const Allocator& alloc = Allocator() 
    );
    
    ~darray();

    GLIBZXX_CONSTEXPR 
    darray& operator=( const darray& x );

    GLIBZXX_CONSTEXPR 
    darray& operator=( darray&& x );

    GLIBZXX_CONSTEXPR 
    darray& operator=( zxx::initializer_list<T> init );

    template< class T, class Alloc >
    GLIBZXX_CONSTEXPR
    friend bool operator==( 
        const darray& x,
        const darray& y
    ) const;

    template< class T, class Alloc >
    GLIBZXX_CONSTEXPR
    friend bool operator!=( 
        const darray& x,
        const darray& y
    ) const;

    template< class T, class Alloc >
    GLIBZXX_CONSTEXPR
    friend bool operator<( 
        const darray& x,
        const darray& y 
    ) const; 

    template< class T, class Alloc >
    GLIBZXX_CONSTEXPR
    friend bool operator>( 
        const darray& x,
        const darray& y 
    ) const; 

    template< class T, class Alloc >
    GLIBZXX_CONSTEXPR
    friend bool operator<=( 
        const darray& x,
        const darray& y
    ) const;

    template< class T, class Alloc >
    GLIBZXX_CONSTEXPR
    friend bool operator>=( 
        const darray& x,
        const darray& y
    ) const;

    #if __cplusplus >= 202003L
    template< class T, class Alloc >
    GLIBZXX_CONSTEXPR
    friend bool operator>=<( 
        const darray& x,
        const darray& y
    ) const;
    #endif


    GLIBZXX_CONSTEXPR
    iterator
    begin();

    GLIBZXX_CONSTEXPR
    const_iterator
    cbegin() const;

    GLIBZXX_CONSTEXPR
    iterator
    end();

    GLIBZXX_CONSTEXPR
    const_iterator
    cend() const;

    GLIBZXX_CONSTEXPR
    reverse_iterator
    rbegin(); 

    GLIBZXX_CONSTEXPR
    const_reverse_iterator
    crbegin() const; 

    GLIBZXX_CONSTEXPR
    reverse_iterator
    rend(); 

    GLIBZXX_CONSTEXPR
    const_reverse_iterator
    crend() const; 


    GLIBZXX_CONSTEXPR
    reference 
    operator[]( size_type n ); 
    
    GLIBZXX_CONSTEXPR
    const_reference
    operator[]( size_type n ) const; 
    
    GLIBZXX_CONSTEXPR
    reference
    at( size_type n ); 
    
    GLIBZXX_CONSTEXPR
    const_reference
    at( size_type n ) const; 
    
    GLIBZXX_CONSTEXPR
    reference
    front(); 
    
    GLIBZXX_CONSTEXPR
    const_reference
    front() const; 
    
    GLIBZXX_CONSTEXPR
    reference
    back(); 
    
    GLIBZXX_CONSTEXPR
    const_reference back() const; 


    template<class ...Args>
    GLIBZXX_CONSTEXPR
    void 
    emplace_back( Args&&... args ); 

    template<class ...Args>
    GLIBZXX_CONSTEXPR
    iterator 
    emplace( const_iterator it, Args&&... args ); 

    GLIBZXX_CONSTEXPR
    void 
    push_back( const T& x ); 

    GLIBZXX_CONSTEXPR
    void 
    push_back( T&& x );

    GLIBZXX_CONSTEXPR
    void 
    pop_back(); 

    GLIBZXX_CONSTEXPR
    iterator 
    insert( const_iterator it, const T& x ); 

    GLIBZXX_CONSTEXPR
    iterator 
    insert( const_iterator it, T&& x ); 

    GLIBZXX_CONSTEXPR
    iterator 
    insert( const_iterator it, size_type n, T& x ); 

    template<class InputIterator>
    GLIBZXX_CONSTEXPR
    iterator
    insert( const_iterator it, InputIterator first, InputIterator last ); 

    GLIBZXX_CONSTEXPR
    iterator
    insert(const_iterator it, zxx::initializer_list<T> init ); 

    GLIBZXX_CONSTEXPR
    iterator
    erase( const_iterator it ); 

    GLIBZXX_CONSTEXPR
    iterator
    erase( const_iterator first, const_iterator last ); 

    GLIBZXX_CONSTEXPR
    void 
    clear(); 

    GLIBZXX_CONSTEXPR
    void
    swap( darray& darr );


    GLIBZXX_CONSTEXPR
    size_type
    capacity() const;

    GLIBZXX_CONSTEXPR
    size_type 
    size() const;

    GLIBZXX_CONSTEXPR
    size_type
    max_size() const;

    GLIBZXX_CONSTEXPR
    bool 
    empty() const;

    GLIBZXX_CONSTEXPR
    void 
    reserve( size_type n );

    GLIBZXX_CONSTEXPR
    void 
    shrink_to_fit();

    
    GLIBZXX_CONSTEXPR
    Allocator 
    get_allocator() const; 

    GLIBZXX_CONSTEXPR
    zxx::ostream&
    print(zxx::ostream&) const;

};

}
