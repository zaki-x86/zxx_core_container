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
  constexpr explicit darray(const Allocator &alloc = Allocator());

  constexpr darray(const darray &other);

  constexpr darray(const darray &other, Allocator &alloc);

  constexpr darray(darray &&other);

  constexpr darray(darray &&other, Allocator &alloc);

  constexpr darray(size_type n, const value_type &value = value_type(),
                           const Allocator &alloc = Allocator());

  constexpr explicit darray(size_type n,
                                    const Allocator &alloc = Allocator());

  template <typename InputIterator>
  constexpr darray(InputIterator first, InputIterator last,
                           const Allocator &alloc = Allocator());

  constexpr darray(std::initializer_list<T> init,
                           const Allocator &alloc = Allocator());

  ~darray();

  constexpr darray &operator=(const darray &x);

  constexpr darray &operator=(darray &&x);

  constexpr darray &operator=(std::initializer_list<T> init);

  template <typename U, typename Alloc>
  constexpr friend bool operator==(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  constexpr friend bool operator!=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  constexpr friend bool operator<(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  constexpr friend bool operator>(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  constexpr friend bool operator<=(const darray &x, const darray &y);

  template <typename U, typename Alloc>
  constexpr friend bool operator>=(const darray &x, const darray &y);

#if __cplusplus >= 202003L
  template <typename U, typename Alloc>
  constexpr friend bool operator>=<(const darray &x,
                                            const darray &y) const;
#endif

  constexpr iterator begin();

  constexpr const_iterator cbegin() const;

  constexpr iterator end();

  constexpr const_iterator cend() const;

  constexpr reverse_iterator rbegin();

  constexpr const_reverse_iterator crbegin() const;

  constexpr reverse_iterator rend();

  constexpr const_reverse_iterator crend() const;

  constexpr reference operator[](size_type n);

  constexpr const_reference operator[](size_type n) const;

  constexpr reference at(size_type n);

  constexpr const_reference at(size_type n) const;

  constexpr reference front();

  constexpr const_reference front() const;

  constexpr reference back();

  constexpr const_reference back() const;

  template <class... Args> constexpr void emplace_back(Args &&... args);

  template <class... Args>
  constexpr iterator emplace(const_iterator it, Args &&... args);

  constexpr void push_back(const T &x);

  constexpr void push_back(T &&x);

  constexpr void pop_back();

  constexpr iterator insert(const_iterator it, const T &x);

  constexpr iterator insert(const_iterator it, T &&x);

  constexpr iterator insert(const_iterator it, size_type n, T &x);

  template <class InputIterator>
  constexpr iterator insert(const_iterator it, InputIterator first,
                                    InputIterator last);

  constexpr iterator insert(const_iterator it,
                                    std::initializer_list<T> init);

  constexpr iterator erase(const_iterator it);

  constexpr iterator erase(const_iterator first, const_iterator last);

  constexpr void clear();

  constexpr void swap(darray &darr);

  constexpr size_type capacity() const noexcept;

  constexpr size_type size() const noexcept;

  constexpr size_type max_size() const noexcept;

  constexpr bool empty() const noexcept;

  constexpr void reserve(size_type n);

  constexpr void shrink_to_fit();

  constexpr Allocator get_allocator() const;

  constexpr std::ostream &print(std::ostream &) const;
};

END_NS_ZXX_CORE_CONTAINER


#endif // !_ZXX_DARRAY_H_