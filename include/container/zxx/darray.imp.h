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

BEGIN_NS_ZXX_CORE_CONTAINER

template <typename T, typename Allocator>
struct Darray_base {

  /**
   * @brief The _Tp_alloc_type member type is a type alias that represents the
   * type of the allocator to use for allocating elements of type T. It is
   * defined using the rebind template of the Allocator class template, which
   * allows you to create a new allocator type that is compatible with a
   * different type.
   */
  using _Tp_alloc_type = std::allocator_traits<Allocator>;

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