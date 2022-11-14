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

#define GROWTH_FACTOR 2
#define INITIAL_SIZE 10

template <typename T>
class darray
{
private:
    long m_capacity;
    long m_size;
    T* m_data;
    void resize();

public:
    // constructors & destructors
    darray();
    darray(const darray&);
    darray(T&);
    darray(T&&);
    darray(T*, long);
    ~darray();

    // operations
    void push_back(T);
    void set(long, T);
    void insert(long, T);
    T get(long) const;
    T pop_back();
    T erase(long);
    long size() const;
    long capacity() const;
    bool is_empty();
    void reset();
    std::ostream& print(std::ostream&) const;
    //template<typename U> friend std::ostream& operator<<(std::ostream& os, U const& ar);
};

}// namespace zx_containers

template<typename T>
zx_containers::darray<T>::darray()
:m_capacity(INITIAL_SIZE),
m_data(new T[m_capacity]),
m_size(0)
{
    if (m_data == nullptr)
        throw std::bad_alloc();

    m_size = 0;
}

template<typename T>
zx_containers::darray<T>::darray(const darray& other)
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = INITIAL_SIZE;

    m_data = new T[m_capacity];
    m_size = other.size();

    for (long i = 0; i < other.size(); i++)
        push_back(other.get(i));
}

template<typename T>
zx_containers::darray<T>::darray( T& value )
: darray()
{    
    this->push_back(value);
}

template<typename T>
zx_containers::darray<T>::darray( T&& value )
: darray()
{
    this->push_back(value);
}

template<typename T>
zx_containers::darray<T>::darray( T* values, long size )
: darray()
{
    for (long i = 0; i < size; i++)
    {
        this->push_back(*values);
        values++;
    }
}

template<typename T>
zx_containers::darray<T>::~darray()
{
    delete[] m_data;
}

template<typename T>
void zx_containers::darray<T>::push_back( T value )
{
    if (m_size >= m_capacity)
        resize();

    *(m_data + m_size) = value;
    m_size ++;
}

template<typename T>
void zx_containers::darray<T>::set( long index, T value )
{
    if ( index < 0 )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if ( index < m_size )
    {
        *(m_data + index) = value;
        return;
    }

    // keep resizing as long as index > m_capacity
    while( index > m_capacity )
        resize();

    for (size_t i = m_size; i <= index; i++)
    {
        *(m_data + i) = {};
        m_size++;
    }
    
    *(m_data + index) = value;
}

template<typename T>
void zx_containers::darray<T>::insert( long index, T value )
{
    if ( index < 0 )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if (index > m_size)
        throw std::out_of_range("Invalid: Exceeds range, use set(long, T) instead");
    
    else if ( m_size == m_capacity )
        resize();
    
    for (long i = m_size - 1; i >= index; i--)
        m_data[i+1] = m_data[i];  
    
    m_data[index] = value;
    m_size ++;
    
}

template<typename T>
T zx_containers::darray<T>::get( long index ) const
{
    if ( index < 0 )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if ( index >= m_size )
        throw std::out_of_range("Invalid: index is out of range\n");
    
    return m_data[index];
}

template<typename T>
T zx_containers::darray<T>::pop_back()
{
    if (m_size == 0)
        throw std::logic_error("Can't pop_back an empty array");
    
    m_size--;
    
    return m_data[m_size];
}

template<typename T>
T zx_containers::darray<T>::erase( long index )
{
    if ( index < 0 )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if ( index > m_size - 1 )
        throw std::out_of_range("Invalid: Index out of bound");
    else if ( m_size == 0 )
        throw std::logic_error("Can't erase elements from an empty array");
    
    T deleted = m_data[index];
    
    for (long i = index; i <= m_size - 1; i++)
        m_data[i] = m_data[i + 1];
    
    m_size--;
    
    return deleted;
}

template<typename T>
long zx_containers::darray<T>::size() const
{
    return m_size;
}

template<typename T>
long zx_containers::darray<T>::capacity() const
{
    return m_capacity;
}

template<typename T>
bool zx_containers::darray<T>::is_empty()
{
    return m_size == 0;
}

template<typename T>
void zx_containers::darray<T>::resize()
{
    std::cout << "[--resize--] Running resize .. \n";
    T* tmp = new T[m_capacity * GROWTH_FACTOR];
    if (tmp == nullptr)
        throw std::bad_alloc();
    
    std::copy(m_data, m_data + m_capacity, tmp);
    delete[] m_data;
    m_data = tmp;
    m_capacity = m_capacity * GROWTH_FACTOR;
}

template<typename T>
void zx_containers::darray<T>::reset()
{
    if (m_size == 0)
        return;
    
    delete[] m_data;
    this->m_capacity = INITIAL_SIZE;
    this->m_size = 0;
    this->m_data = new T[m_capacity];

    if (m_data == nullptr)
        throw std::bad_alloc();
}

template<typename T>
std::ostream& zx_containers::darray<T>::print(std::ostream& os) const
{
    os << "{ ";
        for (size_t i = 0; i < m_size; i++)
        {
            os << m_data[i] << ", ";
            if ( i == m_size - 1 )
                os << m_data[i];
        }
        os << " }\n";
        return os;
}

template<typename U>
inline std::ostream& operator<<(std::ostream& os, zx_containers::darray<U> const& obj)
{
    return obj.print(os);
}