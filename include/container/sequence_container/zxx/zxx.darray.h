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
  CONSTEXPR explicit darray(const Allocator &alloc = Allocator());

  CONSTEXPR darray(const darray &other);

  CONSTEXPR darray(const darray &other, Allocator &alloc);

  CONSTEXPR darray(darray &&other);

  CONSTEXPR darray(darray &&other, Allocator &alloc);

  CONSTEXPR darray(size_type n, const value_type &value = value_type(),
                           const Allocator &alloc = Allocator());

  CONSTEXPR explicit darray(size_type n,
                                    const Allocator &alloc = Allocator());

  template <typename InputIterator>
  CONSTEXPR darray(InputIterator first, InputIterator last,
                           const Allocator &alloc = Allocator());

  CONSTEXPR darray(std::initializer_list<T> init,
                           const Allocator &alloc = Allocator());

  ~darray();

  CONSTEXPR darray &operator=(const darray &x);

  CONSTEXPR darray &operator=(darray &&x);

  CONSTEXPR darray &operator=(std::initializer_list<T> init);

  template <typename U, typename Alloc>
  CONSTEXPR friend bool operator==(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  CONSTEXPR friend bool operator!=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  CONSTEXPR friend bool operator<(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  CONSTEXPR friend bool operator>(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  CONSTEXPR friend bool operator<=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  CONSTEXPR friend bool operator>=(const darray &x, const darray &y);

#if __cplusplus >= 202003L
  template <typename U, typename Alloc>
  CONSTEXPR friend bool operator>=<(const darray &x,
                                            const darray &y) const;
#endif

  CONSTEXPR iterator begin();

  CONSTEXPR const_iterator cbegin() const;

  CONSTEXPR iterator end();

  CONSTEXPR const_iterator cend() const;

  CONSTEXPR reverse_iterator rbegin();

  CONSTEXPR const_reverse_iterator crbegin() const;

  CONSTEXPR reverse_iterator rend();

  CONSTEXPR const_reverse_iterator crend() const;

  CONSTEXPR reference operator[](size_type n);

  CONSTEXPR const_reference operator[](size_type n) const;

  CONSTEXPR reference at(size_type n);

  CONSTEXPR const_reference at(size_type n) const;

  CONSTEXPR reference front();

  CONSTEXPR const_reference front() const;

  CONSTEXPR reference back();

  CONSTEXPR const_reference back() const;

  template <class... Args> CONSTEXPR void emplace_back(Args &&... args);

  template <class... Args>
  CONSTEXPR iterator emplace(const_iterator it, Args &&... args);

  CONSTEXPR void push_back(const T &x);

  CONSTEXPR void push_back(T &&x);

  CONSTEXPR void pop_back();

  CONSTEXPR iterator insert(const_iterator it, const T &x);

  CONSTEXPR iterator insert(const_iterator it, T &&x);

  CONSTEXPR iterator insert(const_iterator it, size_type n, T &x);

  template <class InputIterator>
  CONSTEXPR iterator insert(const_iterator it, InputIterator first,
                                    InputIterator last);

  CONSTEXPR iterator insert(const_iterator it,
                                    std::initializer_list<T> init);

  CONSTEXPR iterator erase(const_iterator it);

  CONSTEXPR iterator erase(const_iterator first, const_iterator last);

  CONSTEXPR void clear();

  CONSTEXPR void swap(darray &darr);

  CONSTEXPR size_type capacity() const noexcept;

  CONSTEXPR size_type size() const noexcept;

  CONSTEXPR size_type max_size() const noexcept;

  CONSTEXPR bool empty() const noexcept;

  CONSTEXPR void reserve(size_type n);

  CONSTEXPR void shrink_to_fit();

  CONSTEXPR Allocator get_allocator() const;

  CONSTEXPR std::ostream &print(std::ostream &) const;
};

END_NS_ZXX_CORE_CONTAINER


#endif // !_ZXX_DARRAY_H_