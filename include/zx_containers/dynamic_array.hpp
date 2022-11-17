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


namespace zx_containers
{

/**
 * @{ @name Key constants used within class
 */
/**
 * @brief constants used to determine array size and display debugging messages
*/
#define __GROWTH_FACTOR__ 2     ///< Int to be multplied with current array size to resize
#define __INITIAL_SIZE__ 10     ///< Initial size upon init with default constructor
/**
 * @}
 */

/**
 * @class darray
 * @details **A dynamic array container**
 * 
 * @remarks
 * The elements are stored contiguously, which means that elements can be accessed not 
 * only through iterators, but also using offsets to regular pointers to elements. 
 * This means that a pointer to an element of a darray may be passed to any function 
 * that expects a pointer to an element of an array.
 * 
 * @see [Dynamic Arrays](pages/DynamicArray.md)
 * 
 * @tparam T type of the class elements
 * 
 * 
 * @subsection examples Examples
 * @snippet BasicUsage darray_examples.cpp
 * 
 * @subsection subsection-name subsection title
 * @todo iterator_methods Setting up iterator methods
 */
template <typename T>
class darray
{
private:
    size_t m_capacity;                  ///<Stores max capacity of the array              
    T* m_data;                          ///< Array pointer to hold data
    size_t m_size;                      ///< Current array size
    void resize();                      ///< Function to expand array
    bool m_resource_allocation_failed;  ///< Is set to true if failed to allocated memory for `T* m_data`

public:

    // ************
    // member types
    // ************
    /// @brief alias for data type 
    using value_type = T;
    /// @brief alias for lvalue reference 
    using reference = value_type&;
    /// @brief alias for constant lvalue reference
    using const_reference = const value_type&;
    /// @brief alias for pointer type
    using pointer = value_type*;
    /// @brief alias for constant pointer type
    using const_pointer = const value_type*;
    /// @brief alias for difference type
    /// @see https://en.cppreference.com/w/cpp/types/ptrdiff_t
    using difference_type = std::ptrdiff_t;
    /// @brief alias for size type used for index and size accessors
    using size_type = size_t;

    /**********************************************/
    /**@name Constructors and Destructors
     * 
    */
    /*********************************************/

    ///@{
    /**
     * @brief **Default constructor**
     * 
     * @remarks
     * Uses a member initializer list to set the following parameters:
     * - `m_capacity`: sets default value for max capacity
     * - `m_data`: allocates memory for internal data storage
     * - `m_size`: sets initial size to zero
     * 
     * You can check if resource allocation successeded by using `resource_allocation_failed()` function after initialization.
     * 
     * @subsubsection usage-example Example
     * @snippet test_suites/dynamic_array_test.cpp Default constructor
     * @subsubsection usage-expected-output Expected Output
     * @snippet test_suites/dynamic_array_test.cpp Expected output
     */
    darray();

    /**
     * @brief **fill constructor**
     * 
     * @details constructs a container with `n` elements, each elements has a copy of value if provided.
     * 
     * sets a default value to `value` if not specified
     * 
     * 
     * @param n number of elements to fill the array with
     * @param value value to copy over the array
     * 
     * @note This is an explicit construct, decelrations of this type is not allowed:
     * 
     * 
     * 
     */
    explicit darray( size_type n, const value_type& value = {} );

    /**
     * @brief **copy constructor**
     *  
     * @param x array to copy
     */
    darray( const darray& x );

    /**
     * @brief move constructor
     * 
     * ** move constructor **
     * 
     * @param x array to move
     */
    darray( darray&& x );                       

    /**
     * @brief range constructor
     * 
     * @tparam InputIterator 
     * @param first 
     * @param last 
     * 
\    * @remarks 
     * uses default constructor to initialize container
     * initializes a constructor by passing a pointer to the first element of an iterator and a pointer to the last element of the iterator
     * internally, the constructor uses `push_back()` method while iterating over the specified range of the input iterator.
     */
    darray( T* first, T* last );
    
    /**
     * @brief **Destroy the darray object**
     * 
     */
    ~darray();
    ///@} // end of Constructors and Destructors


    // **************************************************************************
    // **************************************************************************
    
    // **********************
    /**
     * @name Setter Methods
     */
    // **********************

    ///@{
    
    /**
     * @brief **Add value (lvalue) at the end of the array**
     * 
     * @param value value to be copied
     * @return none
     * 
     */
    void push_back( const value_type& value );

    /**
     * @brief **Add value (rvalue) at the end of the array**
     * 
     * @param value value to be moved
     * @overload void push_back(const value_type& value);
     */
    void push_back( value_type&& value );

    /**
     * @brief ** Add value (lvalue) at he beginning of the array **
     * 
     * @param value value to be copied
     */
    void push_front( const value_type& value );

    /**
     * @brief ### Add value (rvalue) at the beginning of the array
     * 
     * @param value value to be moved
     * @overload void push_front( const value_type& value );
     */
    void push_front( value_type&& value );    

    /**
     * @brief ** Set value (lvalue) at a specific index **
     * 
     * @param index index of the array
     * @param value value to be copied
     */
    void set( size_type index, value_type& value );

    /**
     * ** Set value (rvalue) at a specific index **
     * 
     * @param index index of the array
     * @param value value to be moved
     * @overload 
     */
    void set( size_type index, value_type&& value );

    /**
     * ** Insert value at a given index and shift array to the right **
     * 
     * @param index index of the array
     * @param value value to be copied
     */
    void insert( size_type index, const value_type& value );

    /**
     * ** Insert value at a given index and shift array to the right **
     * 
     * @param index index of the array
     * @param value value to be moved
     * @overload void insert(size_type index, const value_type& value);
     */
    void insert( size_type index, value_type&& value );

    ///@} // end of Setter Methods

    // ********************
    /**
     * @name Getter Methods
     */
    // ********************

    ///@{

    /**
     * @brief 
     * 
     * @param index 
     * @return value_type 
     */
    value_type at( size_type index ) const;

    /**
     * @brief 
     * 
     * @return size_type 
     */
    size_type size() const;

    /**
     * @brief 
     * 
     * @return size_type 
     */
    size_type capacity() const;

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool empty();

    /**
     * @brief 
     * 
     * @return value_type* 
     */
    value_type* data();

    ///@} // end of Getter Methods

    // ********************
    /**
     * @name Delete Methods
     */
    // ********************

    ///@{

    /**
     * @brief 
     * 
     * @return value_type 
     */
    value_type pop_back();
    
    /**
     * @brief 
     * 
     * @param index 
     * @return value_type 
     */
    value_type erase(size_type index);

    /**
     * @brief 
     * 
     */
    void clear();

    ///@} // end of Delete Methods

    // ********************
    /**
    * @name Helper Methods
     */
    // ********************

    ///@{
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool resource_allocation_failed();

    ///@} // end of Helper Methods

    // ********************
    /**
    * @name Read Methods
     */
    // ********************

    ///@{
    
    /**
     * @brief 
     * 
     * @return std::ostream& 
     */
    std::ostream& print(std::ostream&) const;
    
    ///@} // end of Helper Methods

};

}// namespace zx_containers


#include "implementation/dynamic_array.impl.hpp"