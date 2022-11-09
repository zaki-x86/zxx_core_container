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
    DynamicArray(T);
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
};


template<typename T>
DynamicArray<T>::DynamicArray()
{

}

template<typename T>
DynamicArray<T>::DynamicArray( T value )
{

}

template<typename T>
DynamicArray<T>::DynamicArray( T* values, size_t size )
{

}

template<typename T>
DynamicArray<T>::~DynamicArray()
{

}

template<typename T>
void DynamicArray<T>::push_back( T value )
{

}

template<typename T>
void DynamicArray<T>::set( size_t index, T value )
{

}

template<typename T>
void DynamicArray<T>::add( size_t index, T value )
{

}

template<typename T>
T DynamicArray<T>::get( size_t index )
{

}

template<typename T>
T DynamicArray<T>::pop()
{

}

template<typename T>
T DynamicArray<T>::remove( size_t index )
{

}

template<typename T>
size_t DynamicArray<T>::size()
{

}

template<typename T>
size_t DynamicArray<T>::capacity()
{
    
}

template<typename T>
bool DynamicArray<T>::is_empty()
{
    
}

template<typename T>
void DynamicArray<T>::read()
{
    
}

}