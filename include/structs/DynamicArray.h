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

namespace structs
{

#define GROWTH_FACTOR 2
#define INITIAL_SIZE 10

template <typename T>
class DynamicArray
{
private:
    size_t m_capacity;
    size_t m_size;
    T* m_data;
    void resize();

public:
    // constructors & destructors
    DynamicArray();
    DynamicArray(const DynamicArray&);
    DynamicArray(T&);
    DynamicArray(T&&);
    DynamicArray(T*, size_t);
    ~DynamicArray();

    // operations
    void push_back(T);
    void set(size_t, T);
    void add(size_t, T);
    T get(size_t);
    T pop();
    T remove(size_t);
    size_t size();
    size_t capacity();
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

        for (size_t i = 0; i < other.size(); i++)
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

    for (size_t i = 0; i < other.size(); i++)
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
structs::DynamicArray<T>::DynamicArray( T* values, size_t size )
: DynamicArray()
{
    for (size_t i = 0; i < size; i++)
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
void structs::DynamicArray<T>::set( size_t index, T value )
{
    if ( index < INITIAL_SIZE )
        *(m_data + index) = value;
    
}

template<typename T>
void structs::DynamicArray<T>::add( size_t index, T value )
{

    
}

template<typename T>
T structs::DynamicArray<T>::get( size_t index )
{
    return this->m_data[index];
}

template<typename T>
T structs::DynamicArray<T>::pop()
{

}

template<typename T>
T structs::DynamicArray<T>::remove( size_t index )
{

}

template<typename T>
size_t structs::DynamicArray<T>::size()
{
    return this->m_size;
}

template<typename T>
size_t structs::DynamicArray<T>::capacity()
{
    
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

