/**
 * @file darray.tcc
 * @author M Zaki (mamadov_zicx@gmail.com)
 * @brief Implementation of a dynamic array container
 * @version 0.1
 * @date 2022-12-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "config/zxx.config.h"
//#include "zxx_darray.h" // Useless but it's added to disable error squiggles
#include <memory>

BEGIN_NS_ZXX_CORE_CONTAINER

template <typename T, typename Allocator>
struct Darray_base {

  /**
   * @brief createS a new allocator type `_Tp_alloc_type` that is parameterized with the same type as `Darray_base`.
   * 
   * This can be used to create a new allocator object that is compatible with `Darray_base`, regardless of the original type of the allocator.
   * 
   * @note In C++11 and earlier, the `std::allocator` class template defined a nested type called `rebind`, which could be used to create a new allocator type that was parameterized with a different type. For example, you could use `std::allocator<int>::rebind<char>::other` to create an allocator type that could be used to allocate char objects, using an allocator that was originally designed to allocate int objects.
   * In C++17, the rebind type was deprecated and replaced with a rebind_alloc type trait, which is defined in the <memory> header file. To create a new allocator type that is parameterized with a different type.
   */
  using _Tp_alloc_type = typename std::allocator_traits<Allocator>::template rebind_alloc<T>;
  using pointer = typename std::allocator_traits<_Tp_alloc_type>::pointer;

  /**
   * @brief Nested struct to store the data for the vector.
   *
   */
  struct _Darray_impl {
    T *_m_start;
    T *_m_finish;
    T *_m_end_of_storage;
    Allocator _m_allocator;

    _Darray_impl()
        : _m_start(nullptr), _m_finish(nullptr), _m_end_of_storage(nullptr) {}
    _Darray_impl(const Allocator &a)
        : _m_start(nullptr), _m_finish(nullptr), _m_end_of_storage(nullptr),
          _m_allocator(a) {}
  };

  // Default constructor creates an empty Darray_impl object with _m_start,
  // _m_finish, and _m_end_of_storage all set to nullptr.
  Darray_base() {}

  // Constructor that takes an allocator object creates a Darray_impl object
  // with _m_start, _m_finish, and _m_end_of_storage all set to nullptr and the
  // allocator object stored as a member variable.
  Darray_base(const Allocator &a) : _m_impl(a) {}

  // Destructor calls the allocator's deallocate() function to free the memory
  // used by the vector's data.
  ~Darray_base() {
    _m_deallocate(_m_impl._m_start,
                  _m_impl._m_end_of_storage - _m_impl._m_start);
  }

  // Returns a reference to the allocator object.
  Allocator &_m_get_Tp_allocator() { return _m_impl._m_allocator; }
  const Allocator &_m_get_Tp_allocator() const { return _m_impl._m_allocator; }

  // Returns a reference to the Darray_impl object.
  _Darray_impl &_m_get_impl() { return _m_impl; }
  const _Darray_impl &_m_get_impl() const { return _m_impl; }

public:
  _Darray_impl _m_impl;

  // Helper function to deallocate memory using
  // Helper function to deallocate memory using the allocator's deallocate()
  // function.
  void _m_deallocate(T *p, std::size_t n) {
    if (p)
      _m_impl._m_allocator.deallocate(p, n);
  }

  void _m_allocate(std::size_t n) {
      _m_impl._m_allocator.allocate(n);
  }
  
};




END_NS_ZXX_CORE_CONTAINER

/* */