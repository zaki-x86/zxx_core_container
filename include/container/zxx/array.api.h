/**
 * @file array.api.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief Defines array class and its functions accessible by users
 * @version 0.1
 * @date 2023-01-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef _ARRAY_API_H_

#define _ARRAY_API_H_

// <--- std headers --->
#include <iterator>
#include <memory>

// <--- zxx::core headers --->
#include "array.traits.h"
#include "config/zxx.config.h"

// <--- array headers --->

BEGIN_NS_ZXX_CORE_CONTAINER

/**
 * @brief Represents a fixed-size array with elements of type T and size N.
 * @tparam T The type of the elements stored in the array.
 * @tparam N The size of the array.
 */
template <typename T, size_t N> struct array {

  // types:

  /**
   * @brief A reference to an element in the array.
   */
  typedef T &reference;

  /**
   * @brief A const reference to an element in the array.
   *
   */
  typedef const T &const_reference;

  /**
   * @brief An iterator that can be used to traverse the elements of the array.
   *
   */
  typedef T *iterator;

  /**
   * @brief A const iterator that can be used to traverse the elements of the
   * array.
   *
   */
  typedef const T *const_iterator;

  /**
   * @brief The type used to represent sizes and indices for the array.
   *
   */
  typedef size_t size_type;

  /**
   * @brief The type used to represent the difference between two iterators for
   * the array.
   *
   */
  typedef ptrdiff_t difference_type;

  /**
   * @brief The type of the elements stored in the array.
   *
   */
  typedef T value_type;

  /**
   * @brief A pointer to an element in the array.
   *
   */
  typedef T *pointer;

  /**
   * @brief A const pointer to an element in the array.
   *
   */
  typedef const T *const_pointer;

  /**
   * @brief A reverse iterator for the array.
   *
   */
  typedef std::reverse_iterator<iterator> reverse_iterator;

  /**
   * @brief A const reverse iterator for the array.
   *
   */
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  T elems[N];

  // no explicit construct/copy/destroy for aggregate type

  /**
   * @brief Fills the array with copies of the given value.
   * @param u The value to fill the array with.
   */
  void fill(const T &u);

  /**
   * @brief Swaps the contents of this array with the contents of another array.
   * @param other The array to swap with.
   */
  void swap(array<T, N> &);

  // iterators:

  /**
   * @brief Returns an iterator pointing to the first element of the array.
   * @return An iterator pointing to the first element of the array.
   */
  const_iterator begin();

  /**
   * @brief Returns a const iterator pointing to the first element of the array.
   * @return A const iterator pointing to the first element of the array.
   */
  iterator begin() const;

  /**
   * @brief Returns an iterator pointing to the element following the last
   * element of the array.
   * @return An iterator pointing to the element following the last element of
   * the array.
   */
  const_iterator end();

  /**
   * @brief Returns a const iterator pointing to the element following the last
   * element of the array.
   * @return A const iterator pointing to the element following the last element
   * of the array.
   */
  iterator end() const;

  /**
   * @brief Returns a reverse iterator pointing to the last element of the
   * array.
   * @return A reverse iterator pointing to the last element of the array.
   */
  const_reverse_iterator rbegin();

  /**
   * @brief Returns a const reverse iterator pointing to the last element of the
   * array.
   * @return A const reverse iterator pointing to the last element of the array.
   */
  const_reverse_iterator rbegin() const;

  /**
   * @brief Returns a reverse iterator pointing to the element preceding the
   * first element of the array.
   * @return A reverse iterator pointing to the element preceding the first
   * element of the array.
   */
  reverse_iterator rend();

  /**
   * @brief Returns a const reverse iterator pointing to the element preceding
   * the first element of the array.
   * @return A const reverse iterator pointing to the element preceding the
   * first element of the array.
   */
  reverse_iterator rend() const;

  /**
   * @brief Returns a const iterator pointing to the first element of the array.
   * @return A const iterator pointing to the first element of the array.
   */
  const_reverse_iterator cbegin() const;

  /**
   * @brief Returns a const iterator pointing to the element following the last
   * element of the array.
   * @return A const iterator pointing to the element following the last element
   * of the array.
   */
  const_iterator cend() const;

  /**
   * @brief Returns a const reverse iterator pointing to the last element of the
   * array.
   * @return A const reverse iterator pointing to the last element of the array.
   */
  const_iterator crbegin() const;

  /**
   * @brief Returns a const reverse iterator pointing to the element preceding
   * the first element of the array.
   * @return A const reverse iterator pointing to the element preceding the
   * first element of the array.
   */
  const_reverse_iterator crend() const;

  // capacity:

  /**
   * @brief Returns the number of elements in the array.
   * @return The number of elements in the array.
   */
  ZXX_CONSTEXPR size_type size();

  /**
   * @brief Returns the maximum number of elements that the array can hold.
   * @return The maximum number of elements that the array can hold.
   */
  ZXX_CONSTEXPR size_type max_size();

  /**
   * @brief
   * @return
   */
  ZXX_CONSTEXPR bool empty();

  // element access:

  /**
   * @brief
   * @param n
   * @return
   */
  reference operator[](size_type n);

  /**
   * @brief
   * @param n
   * @return
   */
  const_reference operator[](size_type n) const;

  /**
   * @brief
   * @param n
   * @return
   */
  const_reference at(size_type n) const;

  /**
   * @brief
   * @param n
   * @return
   */
  reference at(size_type n);

  /**
   * @brief
   * @return
   */
  reference front();

  /**
   * @brief
   * @return
   */
  const_reference front() const;

  /**
   * @brief
   * @return
   */
  reference back();

  /**
   * @brief
   * @return
   */
  const_reference back() const;

  /**
   * @brief
   * @return
   */
  T *data();

  /**
   * @brief
   * @return
   */
  const T *data() const;
};

// Array comparisons.
template <typename _T, size_t _N>
ZXX_FORCE_INLINE bool operator==(const array<_T, _N> &_one, const array<_T, _N> &_two) {
  return std::equal(_one.begin(), _one.end(), _two.begin());
}

template <typename _T, size_t _N>
ZXX_FORCE_INLINE bool operator!=(const array<_T, _N> &_one, const array<_T, _N> &_two) {
  return !(_one == _two);
}

template <typename _T, size_t _N>
ZXX_FORCE_INLINE bool operator<(const array<_T, _N> &_a, const array<_T, _N> &_b) {
  return std::lexicographical_compare(_a.begin(), _a.end(), _b.begin(),
                                      _b.end());
}

template <typename _T, size_t _N>
ZXX_FORCE_INLINE bool operator>(const array<_T, _N> &_one, const array<_T, _N> &_two) {
  return _two < _one;
}

template <typename _T, size_t _N>
ZXX_FORCE_INLINE bool operator<=(const array<_T, _N> &_one, const array<_T, _N> &_two) {
  return !(_one > _two);
}

template <typename _T, size_t _N>
ZXX_FORCE_INLINE bool operator>=(const array<_T, _N> &_one, const array<_T, _N> &_two) {
  return !(_one < _two);
}

template <class _T, size_t _N>
std::ostream &operator<<(std::ostream &os, const array<_T, _N> &arr) {
  os << "[";
  for (const auto &x : arr) {
    os << x << ", ";
  }
  os << "]";
  return os;
}

END_NS_ZXX_CORE_CONTAINER

#endif // !_ARRAY_API_H_
