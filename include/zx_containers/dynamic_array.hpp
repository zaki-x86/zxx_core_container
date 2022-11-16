/**
 * @file darray.h
 * @brief A class template for a darray type
 * @see [Dynamic Arrays](data/darray.md)
 * @version 0.1
 * @date 2022-11-07
 * @author M Zaki
 * 
 * @copyright Copyright (c) Zaki 2022
 * 
 */

#pragma once

#include <iostream>
#include <algorithm>

namespace zx_containers
{

#define __GROWTH_FACTOR__ 2
#define __INITIAL_SIZE__ 10

template <typename T>
class darray
{
private:
    size_t m_capacity;
    size_t m_size;
    T* m_data;
    void resize();

public:

    // ************
    // member types
    // ************
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using difference_type = std::ptrdiff_t;
    using size_type = size_t;

    // constructors & destructors
    darray();
    explicit darray( size_type n, const value_type& value = {} );
    darray(const darray&);
    darray( darray&& x );
    ~darray();

    // operations
    void push_back( value_type value );
    void set( size_type index, value_type value );
    void insert( size_type index, value_type value );
    value_type at( size_type index ) const;
    value_type pop_back();
    value_type erase(size_type index );
    size_type size() const;
    size_type capacity() const;
    bool empty();
    void clear();
    std::ostream& print(std::ostream&) const;
    //template<typename U> friend std::ostream& operator<<(std::ostream& os, U const& ar);
};

}// namespace zx_containers


#include "dynamic_array.impl.hpp"