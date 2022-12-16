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
 * @todo Set up iterator methods
 * @todo Set up an allocator, to delegate all resource allocations ops to it
 * @todo set up initialization methods to abstract construction to
 * @todo use modern c20 `constexpr` overloads of class method
 * @todo add methods that depeneds heavily on iterators and allocators: emplace, swap, .. etc
 * @todo add operators ==, !=, .. etc
 */
template <typename T,  typename Allocator = std::allocator<T>>
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
    ///@brief alias for allocator type
    using allocator_type = Allocator;
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
        typedef std::random_access_iterator_tag iterator_category;

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
    /**********************************************/
    /**@name Constructors, Assignments and Destructors
     * 
    */
    /*********************************************/

    ///@{
    /**
     * @brief Default constructor
     * 
     * constructs an empty darray container
     * 
     * @remarks
     * Uses a member initializer list to set the following parameters:
     * - `m_capacity`: sets default value for max capacity
     * - `m_data`: allocates memory for internal data storage
     * - `m_size`: sets initial size to zero
     * 
     * You can check if resource allocation successeded by using `resource_allocation_failed()` function after initialization.
     * 
     * @subsubsection examples Example
     * @snippet test_suites/dynamic_array_test.cpp Default constructor
     * Expected output:
     * @snippet test_suites/dynamic_array_test.cpp Expected output
     */
    darray();

    /**
     * @brief fill constructor
     * 
     * constructs darray with `n` elements of value `value`
     * @remark
     * sets a default value to `value` if not specified
     * 
     * 
     * @param n number of elements to fill the container with
     * @param value value to copy over the array
     * 
     * @note This is an explicit construct, decelrations of this type is not allowed:
     * 
     * @subsubsection examples Example
     * 
     */
    explicit darray( size_type n, const value_type& value = {} );

    /**
     * @brief copy constructor
     *  
     * @param x container to copy
     */
    darray( const darray& x );

    /**
     * @brief move constructor
     * 
     * 
     * @param x container to move
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
     * @brief Destroy the container
     * 
     */
    ~darray();
    ///@} // end of Constructors and Destructors

    // ********************
    /**
     * @name iterators
     */
    // ********************

    ///@{

    /**
     * @brief returns a a pointer to the beginning of the container
     * @return iterator a pointer to the beginning of the container
     */
    iterator begin();

    /**
     * @brief returns a pointer to one-step-past the end of the container
     * @return iterator a pointer to one-step-past the end of the container
     */
    iterator end();
    
    // ********************
    /**
     * @name Accessors
     */
    // ********************

    ///@{

    /**
     * @brief access specified element with bounds checking
     * 
     * @remarks 
     * Returns a reference to the element at specified location `index`, with bounds checking.
     * 
     * @param index position of the element that needs to be retrieved
     * @return const_reference reference to the element to be retrieved
     * 
     * @throws std::logic_error if negative index is supplied
     * @throws std::out_of_range if index is out of bounds
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     */
    const_reference at( size_type index ) const;

    /**
     * @brief Returns a reference to the element at specified location `index`. No bounds checking is performed.

     * @param index position of element to be retrieved
     * @return const_reference constant reference to the element
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     * 
     * @todo to be implemented
     */
    const_reference operator[]( size_type index ) const;

    /**
     * @brief Returns a reference to the first element in the container.
     * 
     * @return const_reference reference to the first element
     * 
     * @throws std::logic_error of darray is empty
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     * 
     * @todo to be implemented
     */
    const_reference front() const;

    /**
     * @brief Returns a reference to the last element in the container.
     * 
     * @return const_reference reference to the last element
     * 
     * @throws std::logic_error of darray is empty
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     * 
     * @todo to be implemented
     */
    const_reference back() const;

    /**
     * @brief direct access to the underlying array
     * 
     * @remarks
     * Returns pointer to the underlying array serving as element storage. 
     * The pointer is such that range [data(); data()+size()) is always a valid range, 
     * even if the container is empty (data() is not dereferenceable in that case).
     * 
     * @return value_type* pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     */
    value_type* data() noexcept;

    ///@} // end of Accessors


    // **********************
    /**
     * @name Iterators
     */
    // **********************
    ///@{
    
    ///@} // end of Iterators


    // **********************
    /**
     * @name Capacity
     */
    // **********************
    ///@{
    
    /**
     * @brief returns the number of elements in the container
     * 
     * @return size_type the number of elements in the container
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     */
    size_type size() const noexcept;

    /**
     * @brief returns the number of elements that can be held in currently allocated storage
     * 
     * @return size_type Capacity of the currently allocated storage.
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     */
    size_type capacity() const noexcept;

    /**
     * @brief checks whether the container is empty
     * 
     * @return true if container is empty
     * @return false if container if there's at least one element in the container
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     */
    bool empty() const noexcept;

    /**
     * @brief Increase the capacity of the container (the total number of elements that the darray can hold without requiring reallocation) to a value that's greater or equal to `new_cap`. If `new_cap` is greater than the current capacity(), new storage is allocated, otherwise the function does nothing.
     * 
     * @remarks 
     * reserve() does not change the size of the vector.
     * 
     * If new_cap is greater than capacity(), all iterators, including the past-the-end iterator, and all references to the elements are invalidated. Otherwise, no iterators or references are invalidated.
     * 
     * @param new_cap the new capacity of the container
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     * 
     * @todo to be implemented
     */
    void reserve( size_type new_cap );

    /**
     * @brief Requests the removal of unused capacity.
     * 
     * It is a non-binding request to reduce `capacity()` to `size()`. It depends on the implementation whether the request is fulfilled.
     * 
     * If reallocation occurs, all iterators, including the past the end iterator, and all references to the elements are invalidated. If no reallocation takes place, no iterators or references are invalidated.
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     * 
     * @todo to be implemented
     */
    void shrink_to_fit();

    ///@} // end of Capacity


    // **********************
    /**
     * @name Modifiers
     */
    // **********************

    ///@{
    
    /**
     * @brief Add value at the end of the array
     * 
     * Appends the given element value to the end of the container.
     * 
     * @param value value to be copied
     * @return none
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     * 
     */
    void push_back( const value_type& value );

    /**
     * @overload void push_back(const value_type& value);
     */
    void push_back( value_type&& value );

    /**
     * @brief set `value` at a specified `index` in the container
     * 
     * @param index position of element to be changed in the container
     * @param value value to be set
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     * 
     * @todo use iterator
     */
    void set( size_type index, value_type& value );

    /**
     * @overload void set( size_type index, value_type& value );
     */
    void set( size_type index, value_type&& value );

    /**
     * Insert value at a given index and shift array to the right
     * 
     * @param index index of the array
     * @param value value to be copied
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     * 
     * @todo use iterator instead of index, add overload functions
     */
    void insert( size_type index, const value_type& value );

    /**
     * @overload void insert(size_type index, const value_type& value);
     */
    void insert( size_type index, value_type&& value );

    /**
     * @brief constructs an element in-place at the end
     * 
     * @tparam ...Args types of arguments to forward to the constructor of the element
     * @param ...args arguments to forward to the constructor of the element
     * @return none
     * @return reference to the constructed element in the container
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     * 
     * @todo to be implemented
     */
    template<class... Args>
    void emplace_back( Args&&... args );

    /**
     * @overload void emplace_back( Args&&... args );
     * @todo to be implemented
     */
    template<class... Args>
    reference emplace_back( Args&&... args );

    /**
     * @brief removes last element of the container
     * 
     * @return value_type popped element of the container
     * 
     * @throws std::logic_error if container is empty
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     */
    value_type pop_back();
    
    /**
     * @brief removes element at a specified index
     * 
     * @param index index of element to be removed
     * @return value_type removed element
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     * 
     * @todo use iterator
     */
    value_type erase(size_type index);

    /**
     * @brief clears the content of the container
     * 
     * Erases all elements from the container. After this call, size() returns zero.
     * 
     * Invalidates any references, pointers, or iterators referring to contained elements. Any past-the-end iterators are also invalidated.  
     * 
     * Leaves the capacity() of the vector unchanged
     * 
     * @subsubsection complexities Complexity
     * 
     * @subsubsection examples Example
     */
    void clear();

    ///@} // end of modifiers


    // ********************
    /**
    * @name Utilities
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
    * @name Reader
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


    // **********************
    /**
     * @name Friends
     */
    // **********************
    ///@{
    
    ///@} // end of Capacity

};

}// namespace zx_containers

