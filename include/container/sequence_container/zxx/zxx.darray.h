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
  explicit darray(const Allocator &alloc = Allocator());

  darray(const darray &other);

  darray(const darray &other, Allocator &alloc);

  darray(darray &&other);

  darray(darray &&other, Allocator &alloc);

  darray(size_type n, const value_type &value = value_type(),
                           const Allocator &alloc = Allocator());

  explicit darray(size_type n,
                                    const Allocator &alloc = Allocator());

  template <typename InputIterator>
  darray(InputIterator first, InputIterator last,
                           const Allocator &alloc = Allocator());

  darray(std::initializer_list<T> init,
                           const Allocator &alloc = Allocator());

  ~darray();

  darray &operator=(const darray &x);

  darray &operator=(darray &&x);

  darray &operator=(std::initializer_list<T> init);

  template <typename U, typename Alloc>
  friend bool operator==(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  friend bool operator!=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  friend bool operator<(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  friend bool operator>(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  friend bool operator<=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  friend bool operator>=(const darray &x, const darray &y);

#if __cplusplus >= 202003L
  template <typename U, typename Alloc>
  friend bool operator>=<(const darray &x,
                                            const darray &y) const;
#endif

  iterator begin();

  const_iterator cbegin() const;

  iterator end();

  const_iterator cend() const;

  reverse_iterator rbegin();

  const_reverse_iterator crbegin() const;

  reverse_iterator rend();

  const_reverse_iterator crend() const;

  reference operator[](size_type n);

  const_reference operator[](size_type n) const;

  reference at(size_type n);

  const_reference at(size_type n) const;

  reference front();

  const_reference front() const;

  reference back();

  const_reference back() const;

  template <class... Args> void emplace_back(Args &&... args);

  template <class... Args>
  iterator emplace(const_iterator it, Args &&... args);

  void push_back(const T &x);

  void push_back(T &&x);

  void pop_back();

  iterator insert(const_iterator it, const T &x);

  iterator insert(const_iterator it, T &&x);

  iterator insert(const_iterator it, size_type n, T &x);

  template <class InputIterator>
  iterator insert(const_iterator it, InputIterator first,
                                    InputIterator last);

  iterator insert(const_iterator it,
                                    std::initializer_list<T> init);

  iterator erase(const_iterator it);

  iterator erase(const_iterator first, const_iterator last);

  void clear();

  void swap(darray &darr);

  size_type capacity() const noexcept;

  size_type size() const noexcept;

  size_type max_size() const noexcept;

  bool empty() const noexcept;

  void reserve(size_type n);

  void shrink_to_fit();

  Allocator get_allocator() const;

  std::ostream &print(std::ostream &) const;
};

END_NS_ZXX_CORE_CONTAINER


#endif // !_ZXX_DARRAY_H_