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


#ifndef _ZXX_DARRAY_H_

#define _ZXX_DARRAY_H_

#include <algorithm>
#include <exception>
#include <iostream>
#include <memory>
#include <type_traits>

#include "config/zxx.config.h"

BEGIN_NS_ZXX_CORE_CONTAINER
template <typename T, typename Allocator = std::allocator<T>> class darray {
public:
  // temporary - till all libraries are implemented
  // ************
  // member types
  // ************
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using pointer = typename std::allocator_traits<Allocator>::pointer;
  using const_pointer =
      typename std::allocator_traits<Allocator>::const_pointer;
  using iterator = T *;
  using const_iterator = const T *;
  using difference_type = std::ptrdiff_t;
  using allocator_type = Allocator;
  using size_type = size_t;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

public:
  
#if __cplusplus >= 201703L
constexpr
#endif
 explicit darray(const Allocator &alloc = Allocator());

  
#if __cplusplus >= 201703L
constexpr
#endif
 darray(const darray &other);

  
#if __cplusplus >= 201703L
constexpr
#endif
 darray(const darray &other, Allocator &alloc);

  
#if __cplusplus >= 201703L
constexpr
#endif
 darray(darray &&other);

  
#if __cplusplus >= 201703L
constexpr
#endif
 darray(darray &&other, Allocator &alloc);

  
#if __cplusplus >= 201703L
constexpr
#endif
 darray(size_type n, const value_type &value = value_type(),
                           const Allocator &alloc = Allocator());

  
#if __cplusplus >= 201703L
constexpr
#endif
 explicit darray(size_type n,
                                    const Allocator &alloc = Allocator());

  template <typename InputIterator>
  
#if __cplusplus >= 201703L
constexpr
#endif
 darray(InputIterator first, InputIterator last,
                           const Allocator &alloc = Allocator());

  
#if __cplusplus >= 201703L
constexpr
#endif
 darray(std::initializer_list<T> init,
                           const Allocator &alloc = Allocator());

  ~darray();

  
#if __cplusplus >= 201703L
constexpr
#endif
 darray &operator=(const darray &x);

  
#if __cplusplus >= 201703L
constexpr
#endif
 darray &operator=(darray &&x);

  
#if __cplusplus >= 201703L
constexpr
#endif
 darray &operator=(std::initializer_list<T> init);

  template <typename U, typename Alloc>
  
#if __cplusplus >= 201703L
constexpr
#endif
 friend bool operator==(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  
#if __cplusplus >= 201703L
constexpr
#endif
 friend bool operator!=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  
#if __cplusplus >= 201703L
constexpr
#endif
 friend bool operator<(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  
#if __cplusplus >= 201703L
constexpr
#endif
 friend bool operator>(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  
#if __cplusplus >= 201703L
constexpr
#endif
 friend bool operator<=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  
#if __cplusplus >= 201703L
constexpr
#endif
 friend bool operator>=(const darray &x, const darray &y);

#if __cplusplus >= 202003L
  template <typename U, typename Alloc>
  
#if __cplusplus >= 201703L
constexpr
#endif
 friend bool operator>=<(const darray &x,
                                            const darray &y) const;
#endif

  
#if __cplusplus >= 201703L
constexpr
#endif
 iterator begin();

  
#if __cplusplus >= 201703L
constexpr
#endif
 const_iterator cbegin() const;

  
#if __cplusplus >= 201703L
constexpr
#endif
 iterator end();

  
#if __cplusplus >= 201703L
constexpr
#endif
 const_iterator cend() const;

  
#if __cplusplus >= 201703L
constexpr
#endif
 reverse_iterator rbegin();

  
#if __cplusplus >= 201703L
constexpr
#endif
 const_reverse_iterator crbegin() const;

  
#if __cplusplus >= 201703L
constexpr
#endif
 reverse_iterator rend();

  
#if __cplusplus >= 201703L
constexpr
#endif
 const_reverse_iterator crend() const;

  
#if __cplusplus >= 201703L
constexpr
#endif
 reference operator[](size_type n);

  
#if __cplusplus >= 201703L
constexpr
#endif
 const_reference operator[](size_type n) const;

  
#if __cplusplus >= 201703L
constexpr
#endif
 reference at(size_type n);

  
#if __cplusplus >= 201703L
constexpr
#endif
 const_reference at(size_type n) const;

  
#if __cplusplus >= 201703L
constexpr
#endif
 reference front();

  
#if __cplusplus >= 201703L
constexpr
#endif
 const_reference front() const;

  
#if __cplusplus >= 201703L
constexpr
#endif
 reference back();

  
#if __cplusplus >= 201703L
constexpr
#endif
 const_reference back() const;

  template <class... Args> 
#if __cplusplus >= 201703L
constexpr
#endif
 void emplace_back(Args &&... args);

  template <class... Args>
  
#if __cplusplus >= 201703L
constexpr
#endif
 iterator emplace(const_iterator it, Args &&... args);

  
#if __cplusplus >= 201703L
constexpr
#endif
 void push_back(const T &x);

  
#if __cplusplus >= 201703L
constexpr
#endif
 void push_back(T &&x);

  
#if __cplusplus >= 201703L
constexpr
#endif
 void pop_back();

  
#if __cplusplus >= 201703L
constexpr
#endif
 iterator insert(const_iterator it, const T &x);

  
#if __cplusplus >= 201703L
constexpr
#endif
 iterator insert(const_iterator it, T &&x);

  
#if __cplusplus >= 201703L
constexpr
#endif
 iterator insert(const_iterator it, size_type n, T &x);

  template <class InputIterator>
  
#if __cplusplus >= 201703L
constexpr
#endif
 iterator insert(const_iterator it, InputIterator first,
                                    InputIterator last);

  
#if __cplusplus >= 201703L
constexpr
#endif
 iterator insert(const_iterator it,
                                    std::initializer_list<T> init);

  
#if __cplusplus >= 201703L
constexpr
#endif
 iterator erase(const_iterator it);

  
#if __cplusplus >= 201703L
constexpr
#endif
 iterator erase(const_iterator first, const_iterator last);

  
#if __cplusplus >= 201703L
constexpr
#endif
 void clear();

  
#if __cplusplus >= 201703L
constexpr
#endif
 void swap(darray &darr);

  
#if __cplusplus >= 201703L
constexpr
#endif
 size_type capacity() const noexcept;

  
#if __cplusplus >= 201703L
constexpr
#endif
 size_type size() const noexcept;

  
#if __cplusplus >= 201703L
constexpr
#endif
 size_type max_size() const noexcept;

  
#if __cplusplus >= 201703L
constexpr
#endif
 bool empty() const noexcept;

  
#if __cplusplus >= 201703L
constexpr
#endif
 void reserve(size_type n);

  
#if __cplusplus >= 201703L
constexpr
#endif
 void shrink_to_fit();

  
#if __cplusplus >= 201703L
constexpr
#endif
 Allocator get_allocator() const;

  
#if __cplusplus >= 201703L
constexpr
#endif
 std::ostream &print(std::ostream &) const;
};

END_NS_ZXX_CORE_CONTAINER


#endif // !_ZXX_DARRAY_H_