/**
 * @file DynamicArray.h
 * @brief A class template for a DynamicArray type
 * @see [Dynamic Arrays](data/DynamicArray.md)
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

namespace structs
{

#define GROWTH_FACTOR 2
#define INITIAL_SIZE 10

template <typename T>
class DynamicArray
{
private:
    long m_capacity;
    long m_size;
    T* m_data;
    void resize();

public:
    // constructors & destructors
    DynamicArray();
    DynamicArray(const DynamicArray&);
    DynamicArray(T&);
    DynamicArray(T&&);
    DynamicArray(T*, long);
    ~DynamicArray();

    // operations
    void push_back(T);
    void set(long, T);
    void add(long, T);
    T get(long);
    T pop();
    T remove(long);
    long size();
    long capacity();
    bool is_empty();
    void read();
    void reset();

/*     DynamicArray<T>& operator= (const DynamicArray<T> && other)
    {
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        m_capacity = INITIAL_SIZE;

        m_data = new T[m_capacity];
        m_size = other.size();

        for (long i = 0; i < other.size(); i++)
            push_back(other.get(i));
        
        return *this;
    } */
};

}// namespace structs

template<typename T>
structs::DynamicArray<T>::DynamicArray()
:m_capacity(INITIAL_SIZE),
m_data(new T[m_capacity]),
m_size(0)
{
    if (m_data == nullptr)
        throw std::bad_alloc();

    m_size = 0;
}

template<typename T>
structs::DynamicArray<T>::DynamicArray(const DynamicArray& other)
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
structs::DynamicArray<T>::DynamicArray( T& value )
: DynamicArray()
{    
    this->push_back(value);
}

template<typename T>
structs::DynamicArray<T>::DynamicArray( T&& value )
: DynamicArray()
{
    this->push_back(value);
}

template<typename T>
structs::DynamicArray<T>::DynamicArray( T* values, long size )
: DynamicArray()
{
    for (long i = 0; i < size; i++)
    {
        this->push_back(*values);
        values++;
    }
}

template<typename T>
structs::DynamicArray<T>::~DynamicArray()
{
    delete[] m_data;
}

template<typename T>
void structs::DynamicArray<T>::push_back( T value )
{
    if (m_size >= m_capacity)
        resize();

    *(m_data + m_size) = value;
    m_size ++;
}

template<typename T>
void structs::DynamicArray<T>::set( long index, T value )
{
    if ( index < 0 )
        throw std::logic_error("Invalid: negative indices are not allowed.");
    
    else if ( index < m_size )
    {
        *(m_data + index) = value;
        return;
    }  
}

template<typename T>
void structs::DynamicArray<T>::add( long index, T value )
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
T structs::DynamicArray<T>::get( long index )
{
    if ( index < 0 )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if ( index >= m_size )
        throw std::out_of_range("Invalid: index is out of range\n");
    
    return m_data[index];
}

template<typename T>
T structs::DynamicArray<T>::pop()
{
    if (m_size == 0)
        throw std::logic_error("Can't pop an empty array");
    
    m_size--;
    
    return m_data[m_size];
}

template<typename T>
T structs::DynamicArray<T>::remove( long index )
{
    if ( index < 0 )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if ( index > m_size - 1 )
        throw std::out_of_range("Invalid: Index out of bound");
    else if ( m_size == 0 )
        throw std::logic_error("Can't remove elements from an empty array");
    
    T deleted = m_data[index];
    
    for (long i = index; i <= m_size - 1; i++)
        m_data[i] = m_data[i + 1];
    
    m_size--;
    
    return deleted;
}

template<typename T>
long structs::DynamicArray<T>::size()
{
    return this->m_size;
}

template<typename T>
long structs::DynamicArray<T>::capacity()
{
    return m_capacity;
}

template<typename T>
bool structs::DynamicArray<T>::is_empty()
{
    
}

template<typename T>
void structs::DynamicArray<T>::read()
{
    
}

template<typename T>
void structs::DynamicArray<T>::resize()
{
    T* tmp = new T[m_capacity * GROWTH_FACTOR];
    if (tmp == nullptr)
        throw std::bad_alloc();
    
    std::copy(m_data, m_data + m_capacity, tmp);
    delete[] m_data;
    m_data = tmp;
    m_capacity = m_capacity * GROWTH_FACTOR;
}

template<typename T>
void structs::DynamicArray<T>::reset()
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

