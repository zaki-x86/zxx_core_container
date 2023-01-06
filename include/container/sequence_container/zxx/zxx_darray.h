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

#pragma once

#define DEBUG true ///< Flag set to enable some logging for debugging

#include <algorithm>
#include <exception>
#include <iostream>
#include <memory>
#include <type_traits>

#include "config/zxx_config.h"

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
  GLIBZXX_CONSTEXPR explicit darray(const Allocator &alloc = Allocator());

  GLIBZXX_CONSTEXPR
  darray(const darray &other);

  GLIBZXX_CONSTEXPR
  darray(const darray &other, Allocator &alloc);

  GLIBZXX_CONSTEXPR
  darray(darray &&other);

  GLIBZXX_CONSTEXPR
  darray(darray &&other, Allocator &alloc);

  GLIBZXX_CONSTEXPR
  darray(size_type n, const value_type &value = value_type(),
         const Allocator &alloc = Allocator());

  GLIBZXX_CONSTEXPR explicit darray(size_type n,
                                    const Allocator &alloc = Allocator());

  template <typename InputIterator>
  GLIBZXX_CONSTEXPR darray(InputIterator first, InputIterator last,
                           const Allocator &alloc = Allocator());

  GLIBZXX_CONSTEXPR
  darray(std::initializer_list<T> init, const Allocator &alloc = Allocator());

  ~darray();

  GLIBZXX_CONSTEXPR
  darray &operator=(const darray &x);

  GLIBZXX_CONSTEXPR
  darray &operator=(darray &&x);

  GLIBZXX_CONSTEXPR
  darray &operator=(std::initializer_list<T> init);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR friend bool operator==(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR friend bool operator!=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR friend bool operator<(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR friend bool operator>(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR friend bool operator<=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR friend bool operator>=(const darray &x, const darray &y);

#if __cplusplus >= 202003L
  template <typename U, typename Alloc>
  GLIBZXX_CONSTEXPR friend bool operator>=<(const darray &x,
                                            const darray &y) const;
#endif

  GLIBZXX_CONSTEXPR
  iterator begin();

  GLIBZXX_CONSTEXPR
  const_iterator cbegin() const;

  GLIBZXX_CONSTEXPR
  iterator end();

  GLIBZXX_CONSTEXPR
  const_iterator cend() const;

  GLIBZXX_CONSTEXPR
  reverse_iterator rbegin();

  GLIBZXX_CONSTEXPR
  const_reverse_iterator crbegin() const;

  GLIBZXX_CONSTEXPR
  reverse_iterator rend();

  GLIBZXX_CONSTEXPR
  const_reverse_iterator crend() const;

  GLIBZXX_CONSTEXPR
  reference operator[](size_type n);

  GLIBZXX_CONSTEXPR
  const_reference operator[](size_type n) const;

  GLIBZXX_CONSTEXPR
  reference at(size_type n);

  GLIBZXX_CONSTEXPR
  const_reference at(size_type n) const;

  GLIBZXX_CONSTEXPR
  reference front();

  GLIBZXX_CONSTEXPR
  const_reference front() const;

  GLIBZXX_CONSTEXPR
  reference back();

  GLIBZXX_CONSTEXPR
  const_reference back() const;

  template <class... Args> GLIBZXX_CONSTEXPR void emplace_back(Args &&... args);

  template <class... Args>
  GLIBZXX_CONSTEXPR iterator emplace(const_iterator it, Args &&... args);

  GLIBZXX_CONSTEXPR
  void push_back(const T &x);

  GLIBZXX_CONSTEXPR
  void push_back(T &&x);

  GLIBZXX_CONSTEXPR
  void pop_back();

  GLIBZXX_CONSTEXPR
  iterator insert(const_iterator it, const T &x);

  GLIBZXX_CONSTEXPR
  iterator insert(const_iterator it, T &&x);

  GLIBZXX_CONSTEXPR
  iterator insert(const_iterator it, size_type n, T &x);

  template <class InputIterator>
  GLIBZXX_CONSTEXPR iterator insert(const_iterator it, InputIterator first,
                                    InputIterator last);

  GLIBZXX_CONSTEXPR
  iterator insert(const_iterator it, std::initializer_list<T> init);

  GLIBZXX_CONSTEXPR
  iterator erase(const_iterator it);

  GLIBZXX_CONSTEXPR
  iterator erase(const_iterator first, const_iterator last);

  GLIBZXX_CONSTEXPR
  void clear();

  GLIBZXX_CONSTEXPR
  void swap(darray &darr);

  GLIBZXX_CONSTEXPR
  size_type capacity() const noexcept;

  GLIBZXX_CONSTEXPR
  size_type size() const noexcept;

  GLIBZXX_CONSTEXPR
  size_type max_size() const noexcept;

  GLIBZXX_CONSTEXPR
  bool empty() const noexcept;

  GLIBZXX_CONSTEXPR
  void reserve(size_type n);

  GLIBZXX_CONSTEXPR
  void shrink_to_fit();

  GLIBZXX_CONSTEXPR
  Allocator get_allocator() const;

  GLIBZXX_CONSTEXPR
  std::ostream &print(std::ostream &) const;
};

END_NS_ZXX_CORE_CONTAINER
