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
GLIBZXX_CONSTEXPR darray<T, Allocator>::darray(const Allocator &alloc) {}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR darray<T, Allocator>::darray(const darray &other) {}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR darray<T, Allocator>::darray(const darray &other,
                                               Allocator &alloc) {}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR darray<T, Allocator>::darray(darray &&other) {}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR darray<T, Allocator>::darray(darray &&other,
                                               Allocator &alloc) {}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR darray<T, Allocator>::darray(size_type n,
                                               const value_type &value,
                                               const Allocator &alloc) {}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR darray<T, Allocator>::darray(size_type n,
                                               const Allocator &alloc)

{}

template <typename T, typename Allocator>
template <typename InputIterator>
GLIBZXX_CONSTEXPR darray<T, Allocator>::darray(InputIterator first,
                                               InputIterator last,
                                               const Allocator &alloc) {}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR darray<T, Allocator>::darray(std::initializer_list<T> init,
                                               const Allocator &alloc) {}

template <typename T, typename Allocator> darray<T, Allocator>::~darray() {}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR darray<T, Allocator> &
darray<T, Allocator>::operator=(const darray &x) {

  return darray<T>();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR darray<T, Allocator> &
darray<T, Allocator>::operator=(darray &&x) {
  return darray<T>();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR darray<T, Allocator> &
darray<T, Allocator>::operator=(std::initializer_list<T> init) {
  return darray<T>();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::iterator
darray<T, Allocator>::begin() {
  return typename darray<T, Allocator>::iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::const_iterator
darray<T, Allocator>::cbegin() const {
  return typename darray<T, Allocator>::const_iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::iterator
darray<T, Allocator>::end() {
  return typename darray<T, Allocator>::iterator();
  ;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::const_iterator
darray<T, Allocator>::cend() const {
  return typename darray<T, Allocator>::const_iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::reverse_iterator
darray<T, Allocator>::rbegin() {
  return typename darray<T, Allocator>::reverse_iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::const_reverse_iterator
darray<T, Allocator>::crbegin() const {
  return typename darray<T, Allocator>::const_reverse_iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::reverse_iterator
darray<T, Allocator>::rend() {
  return typename darray<T, Allocator>::reverse_iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::const_reverse_iterator
darray<T, Allocator>::crend() const {
  return typename darray<T, Allocator>::const_reverse_iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::reference
darray<T, Allocator>::operator[](size_type n) {
  typename darray<T, Allocator>::reference a;
  return a;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::const_reference
darray<T, Allocator>::operator[](size_type n) const {
  typename darray<T, Allocator>::const_reference a;
  return a;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::reference
darray<T, Allocator>::at(size_type n) {
  typename darray<T, Allocator>::reference a;
  return a;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::const_reference
darray<T, Allocator>::at(size_type n) const {
  typename darray<T, Allocator>::const_reference a;
  return a;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::reference
darray<T, Allocator>::front() {
  typename darray<T, Allocator>::reference a;
  return a;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::const_reference
darray<T, Allocator>::front() const {
  typename darray<T, Allocator>::const_reference a;
  return a;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::reference
darray<T, Allocator>::back() {
  typename darray<T, Allocator>::reference a;
  return a;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::const_reference
darray<T, Allocator>::back() const {
  typename darray<T, Allocator>::const_reference a;
  return a;
}

template <typename T, typename Allocator>
template <class... Args>
GLIBZXX_CONSTEXPR void darray<T, Allocator>::emplace_back(Args &&... args) {
  return;
}

template <typename T, typename Allocator>
template <class... Args>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::iterator
darray<T, Allocator>::emplace(const_iterator it, Args &&... args) {
  return typename darray<T, Allocator>::iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR void darray<T, Allocator>::push_back(const T &x) {
  return;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR void darray<T, Allocator>::push_back(T &&x) {
  return;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR void darray<T, Allocator>::pop_back() {
  return;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::iterator
darray<T, Allocator>::insert(const_iterator it, const T &x) {
  return typename darray<T, Allocator>::iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::iterator
darray<T, Allocator>::insert(const_iterator it, T &&x) {
  return typename darray<T, Allocator>::iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::iterator
darray<T, Allocator>::insert(const_iterator it, size_type n, T &x) {
  return typename darray<T, Allocator>::iterator();
}

template <typename T, typename Allocator>
template <class InputIterator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::iterator
darray<T, Allocator>::insert(const_iterator it, InputIterator first,
                             InputIterator last) {
  return typename darray<T, Allocator>::iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::iterator
darray<T, Allocator>::insert(const_iterator it, std::initializer_list<T> init) {
  return typename darray<T, Allocator>::iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::iterator
darray<T, Allocator>::erase(const_iterator it) {
  return typename darray<T, Allocator>::iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::iterator
darray<T, Allocator>::erase(const_iterator first, const_iterator last) {
  return typename darray<T, Allocator>::iterator();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR void darray<T, Allocator>::clear() {
  return;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR void darray<T, Allocator>::swap(darray &darr) {
  return;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::size_type
darray<T, Allocator>::capacity() const noexcept {
  return 1;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::size_type
darray<T, Allocator>::size() const noexcept {
  return 1;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::size_type
darray<T, Allocator>::max_size() const noexcept {
  return 1;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR bool darray<T, Allocator>::empty() const noexcept {
  return false;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR void darray<T, Allocator>::reserve(size_type n) {
  return;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR void darray<T, Allocator>::shrink_to_fit() {
  return;
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR typename darray<T, Allocator>::allocator_type
darray<T, Allocator>::get_allocator() const {
  return typename darray<T, Allocator>::allocator_type();
}

template <typename T, typename Allocator>
GLIBZXX_CONSTEXPR std::ostream &
darray<T, Allocator>::print(std::ostream &os) const {
  return os;
}

END_NS_ZXX_CORE_CONTAINER // namespace container

    template <typename U>
    GLIBZXX_CONSTEXPR std::ostream &
    operator<<(std::ostream &os, zxx::core::container::darray<U> const &obj) {
  return obj.print(os);
}

template <typename U, typename Alloc>
GLIBZXX_CONSTEXPR bool
operator==(const zxx::core::container::darray<U, Alloc> &x,
           const zxx::core::container::darray<U, Alloc> &y) {
  return false;
}

template <typename U, typename Alloc>
GLIBZXX_CONSTEXPR bool
operator!=(const zxx::core::container::darray<U, Alloc> &x,
           const zxx::core::container::darray<U, Alloc> &y) {
  return false;
}

template <typename U, typename Alloc>
GLIBZXX_CONSTEXPR bool
operator<(const zxx::core::container::darray<U, Alloc> &x,
          const zxx::core::container::darray<U, Alloc> &y) {
  return false;
}

template <typename U, typename Alloc>
GLIBZXX_CONSTEXPR bool
operator>(const zxx::core::container::darray<U, Alloc> &x,
          const zxx::core::container::darray<U, Alloc> &y) {
  return false;
}

template <typename U, typename Alloc>
GLIBZXX_CONSTEXPR bool
operator<=(const zxx::core::container::darray<U, Alloc> &x,
           const zxx::core::container::darray<U, Alloc> &y) {
  return false;
}

template <typename U, typename Alloc>
GLIBZXX_CONSTEXPR bool
operator>=(const zxx::core::container::darray<U, Alloc> &x,
           const zxx::core::container::darray<U, Alloc> &y) {
  return false;
}

#if __cplusplus >= 202003L
template <typename U, typename Alloc>
GLIBZXX_CONSTEXPR bool
operator>=<(const zxx::core::container::darray<U, Alloc> &x,
            const zxx::core::container::darray<U, Alloc> &y) {
  return false;
}
#endif