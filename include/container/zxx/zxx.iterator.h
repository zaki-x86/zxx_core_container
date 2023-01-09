#include <iostream>

#include "config/zxx.config.h"

#ifndef _ZXX_ITERATOR_H_

#define _ZXX_ITERATOR_H_

BEGIN_NS_ZXX_CORE_CONTAINER

// This iterator adapter is 'normal' in the sense that it does not
// change the semantics of any of the operators of its iterator
// parameter.  Its primary purpose is to convert an iterator that is
// not a class, e.g. a pointer, into an iterator that is a class.
// The _Container parameter exists solely so that different containers
// using this template can instantiate different types, even if the
// _Iterator parameter is the same.
using std::iterator;
using std::iterator_traits;
template <typename _Iterator, typename _Container> class _normal_iterator {
protected:
  _Iterator _m_current;

public:
  typedef
      typename iterator_traits<_Iterator>::iterator_category iterator_category;
  typedef typename iterator_traits<_Iterator>::value_type value_type;
  typedef typename iterator_traits<_Iterator>::difference_type difference_type;
  typedef typename iterator_traits<_Iterator>::reference reference;
  typedef typename iterator_traits<_Iterator>::pointer pointer;

  _normal_iterator() : _m_current(_Iterator()) {}

  explicit _normal_iterator(const _Iterator &_i) : _m_current(_i) {}

  // Allow iterator to const_iterator conversion
  template <typename _Iter>
  _normal_iterator(
      const _normal_iterator<
          _Iter, typename std::__enable_if<
                     _Container,
                     (std::__are_same<_Iter, typename _Container::pointer>::
                          _value)>::_type> &_i)
      : _m_current(_i.base()) {}

  // Forward iterator requirements
  reference operator*() const { return *_m_current; }

  pointer operator->() const { return _m_current; }

  _normal_iterator &operator++() {
    ++_m_current;
    return *this;
  }

  _normal_iterator operator++(int) { return _normal_iterator(_m_current++); }

  // Bidirectional iterator requirements
  _normal_iterator &operator--() {
    --_m_current;
    return *this;
  }

  _normal_iterator operator--(int) { return _normal_iterator(_m_current--); }

  // Random access iterator requirements
  reference operator[](const difference_type &_n) const {
    return _m_current[_n];
  }

  _normal_iterator &operator+=(const difference_type &_n) {
    _m_current += _n;
    return *this;
  }

  _normal_iterator operator+(const difference_type &_n) const {
    return _normal_iterator(_m_current + _n);
  }

  _normal_iterator &operator-=(const difference_type &_n) {
    _m_current -= _n;
    return *this;
  }

  _normal_iterator operator-(const difference_type &_n) const {
    return _normal_iterator(_m_current - _n);
  }

  const _Iterator &base() const { return _m_current; }
};

// Note: In what follows, the left- and right-hand-side iterators are
// allowed to vary in types (conceptually in cv-qualification) so that
// comparaison between cv-qualified and non-cv-qualified iterators be
// valid.  However, the greedy and unfriendly operators in std::rel_ops
// will make overload resolution ambiguous (when in scope) if we don't
// provide overloads whose operands are of the same type.  Can someone
// remind me what generic programming is about? -- Gaby

// Forward iterator requirements
template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool operator==(const _normal_iterator<_IteratorL, _Container> &_lhs,
                       const _normal_iterator<_IteratorR, _Container> &_rhs) {
  return _lhs.base() == _rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool operator==(const _normal_iterator<_Iterator, _Container> &_lhs,
                       const _normal_iterator<_Iterator, _Container> &_rhs) {
  return _lhs.base() == _rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool operator!=(const _normal_iterator<_IteratorL, _Container> &_lhs,
                       const _normal_iterator<_IteratorR, _Container> &_rhs) {
  return _lhs.base() != _rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool operator!=(const _normal_iterator<_Iterator, _Container> &_lhs,
                       const _normal_iterator<_Iterator, _Container> &_rhs) {
  return _lhs.base() != _rhs.base();
}

// Random access iterator requirements
template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool operator<(const _normal_iterator<_IteratorL, _Container> &_lhs,
                      const _normal_iterator<_IteratorR, _Container> &_rhs) {
  return _lhs.base() < _rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool operator<(const _normal_iterator<_Iterator, _Container> &_lhs,
                      const _normal_iterator<_Iterator, _Container> &_rhs) {
  return _lhs.base() < _rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool operator>(const _normal_iterator<_IteratorL, _Container> &_lhs,
                      const _normal_iterator<_IteratorR, _Container> &_rhs) {
  return _lhs.base() > _rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool operator>(const _normal_iterator<_Iterator, _Container> &_lhs,
                      const _normal_iterator<_Iterator, _Container> &_rhs) {
  return _lhs.base() > _rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool operator<=(const _normal_iterator<_IteratorL, _Container> &_lhs,
                       const _normal_iterator<_IteratorR, _Container> &_rhs) {
  return _lhs.base() <= _rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool operator<=(const _normal_iterator<_Iterator, _Container> &_lhs,
                       const _normal_iterator<_Iterator, _Container> &_rhs) {
  return _lhs.base() <= _rhs.base();
}

template <typename _IteratorL, typename _IteratorR, typename _Container>
inline bool operator>=(const _normal_iterator<_IteratorL, _Container> &_lhs,
                       const _normal_iterator<_IteratorR, _Container> &_rhs) {
  return _lhs.base() >= _rhs.base();
}

template <typename _Iterator, typename _Container>
inline bool operator>=(const _normal_iterator<_Iterator, _Container> &_lhs,
                       const _normal_iterator<_Iterator, _Container> &_rhs) {
  return _lhs.base() >= _rhs.base();
}

// _GLIBCXX_RESOLVE_LIB_DEFECTS
// According to the resolution of DR179 not only the various comparison
// operators but also operator- must accept mixed iterator/const_iterator
// parameters.
template <typename _IteratorL, typename _IteratorR, typename _Container>
inline typename _normal_iterator<_IteratorL, _Container>::difference_type
operator-(const _normal_iterator<_IteratorL, _Container> &_lhs,
          const _normal_iterator<_IteratorR, _Container> &_rhs) {
  return _lhs.base() - _rhs.base();
}

template <typename _Iterator, typename _Container>
inline _normal_iterator<_Iterator, _Container> operator+(
    typename _normal_iterator<_Iterator, _Container>::difference_type _n,
    const _normal_iterator<_Iterator, _Container> &_i) {
  return _normal_iterator<_Iterator, _Container>(_i.base() + _n);
}
END_NS_ZXX_CORE_CONTAINER

#endif // !