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

#include "config/config.h"

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
  GLIBZXX_CONSTEXPR20 explicit darray(const Allocator &alloc = Allocator());

  GLIBZXX_CONSTEXPR20 darray(const darray &other);

  GLIBZXX_CONSTEXPR20 darray(const darray &other, Allocator &alloc);

  GLIBZXX_CONSTEXPR20 darray(darray &&other);

  GLIBZXX_CONSTEXPR20 darray(darray &&other, Allocator &alloc);

  GLIBZXX_CONSTEXPR20 darray(size_type n, const value_type &value = value_type(),
                           const Allocator &alloc = Allocator());

  GLIBZXX_CONSTEXPR20 explicit darray(size_type n,
                                    const Allocator &alloc = Allocator());

  template <typename InputIterator>
  GLIBZXX_CONSTEXPR20 darray(InputIterator first, InputIterator last,
                           const Allocator &alloc = Allocator());

  GLIBZXX_CONSTEXPR20 darray(std::initializer_list<T> init,
                           const Allocator &alloc = Allocator());

  ~darray();

  GLIBZXX_CONSTEXPR20 darray &operator=(const darray &x);

  GLIBZXX_CONSTEXPR20 darray &operator=(darray &&x);

  GLIBZXX_CONSTEXPR20 darray &operator=(std::initializer_list<T> init);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR20 friend bool operator==(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR20 friend bool operator!=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR20 friend bool operator<(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR20 friend bool operator>(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR20 friend bool operator<=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR20 friend bool operator>=(const darray &x, const darray &y);

#if __cplusplus >= 202003L
  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR20 friend bool operator>=<(const darray &x,
                                            const darray &y) const;
#endif

  GLIBZXX_CONSTEXPR20 iterator begin();

  GLIBZXX_CONSTEXPR20 const_iterator cbegin() const;

  GLIBZXX_CONSTEXPR20 iterator end();

  GLIBZXX_CONSTEXPR20 const_iterator cend() const;

  GLIBZXX_CONSTEXPR20 reverse_iterator rbegin();

  GLIBZXX_CONSTEXPR20 const_reverse_iterator crbegin() const;

  GLIBZXX_CONSTEXPR20 reverse_iterator rend();

  GLIBZXX_CONSTEXPR20 const_reverse_iterator crend() const;

  GLIBZXX_CONSTEXPR20 reference operator[](size_type n);

  GLIBZXX_CONSTEXPR20 const_reference operator[](size_type n) const;

  GLIBZXX_CONSTEXPR20 reference at(size_type n);

  GLIBZXX_CONSTEXPR20 const_reference at(size_type n) const;

  GLIBZXX_CONSTEXPR20 reference front();

  GLIBZXX_CONSTEXPR20 const_reference front() const;

  GLIBZXX_CONSTEXPR20 reference back();

  GLIBZXX_CONSTEXPR20 const_reference back() const;

  template <class... Args> GLIBZXX_CONSTEXPR20 void emplace_back(Args &&... args);

  template <class... Args>
  GLIBZXX_CONSTEXPR20 iterator emplace(const_iterator it, Args &&... args);

  GLIBZXX_CONSTEXPR20 void push_back(const T &x);

  GLIBZXX_CONSTEXPR20 void push_back(T &&x);

  GLIBZXX_CONSTEXPR20 void pop_back();

  GLIBZXX_CONSTEXPR20 iterator insert(const_iterator it, const T &x);

  GLIBZXX_CONSTEXPR20 iterator insert(const_iterator it, T &&x);

  GLIBZXX_CONSTEXPR20 iterator insert(const_iterator it, size_type n, T &x);

  template <class InputIterator>
  GLIBZXX_CONSTEXPR20 iterator insert(const_iterator it, InputIterator first,
                                    InputIterator last);

  GLIBZXX_CONSTEXPR20 iterator insert(const_iterator it,
                                    std::initializer_list<T> init);

  GLIBZXX_CONSTEXPR20 iterator erase(const_iterator it);

  GLIBZXX_CONSTEXPR20 iterator erase(const_iterator first, const_iterator last);

  GLIBZXX_CONSTEXPR20 void clear();

  GLIBZXX_CONSTEXPR20 void swap(darray &darr);

  GLIBZXX_CONSTEXPR20 size_type capacity() const noexcept;

  GLIBZXX_CONSTEXPR20 size_type size() const noexcept;

  GLIBZXX_CONSTEXPR20 size_type max_size() const noexcept;

  GLIBZXX_CONSTEXPR20 bool empty() const noexcept;

  GLIBZXX_CONSTEXPR20 void reserve(size_type n);

  GLIBZXX_CONSTEXPR20 void shrink_to_fit();

  GLIBZXX_CONSTEXPR20 Allocator get_allocator() const;

  GLIBZXX_CONSTEXPR20 std::ostream &print(std::ostream &) const;
};

END_NS_ZXX_CORE_CONTAINER


#endif // !_ZXX_DARRAY_H_