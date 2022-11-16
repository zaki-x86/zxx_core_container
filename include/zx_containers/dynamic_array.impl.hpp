#include "dynamic_array.hpp"    // Useless but it's added to disable error squiggles 

// *************************
// create an alias template:
// *************************
template <typename T>
using dynamic_array = typename zx_containers::darray<T>;



namespace
{
/**
 * @name Imported aliases
 * using typename aliases 
 */
///@{
    template <typename T>
    using value_type = typename dynamic_array<T>::value_type;
    template <typename T>
    using reference = typename dynamic_array<T>::reference;
    template <typename T>
    using const_reference = typename dynamic_array<T>::const_reference;
    template <typename T>
    using pointer = typename dynamic_array<T>::pointer;
    template <typename T>
    using const_pointer = typename dynamic_array<T>::const_pointer;
    template <typename T>
    using size_type = typename dynamic_array<T>::size_type;
///@}
}

template<typename T>
zx_containers::darray<T>::darray()
:m_capacity(__INITIAL_SIZE__),
m_data(new T[m_capacity]),
m_size(0)
{
    if (m_data == nullptr)
        throw std::bad_alloc();

    m_size = 0;
}

template<typename T>
zx_containers::darray<T>::darray(const darray& x)
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = __INITIAL_SIZE__;

    m_data = new T[m_capacity];
    m_size = x.size();

    for (long i = 0; i < x.size(); i++)
        push_back(x.get(i));
}


template<typename T>
zx_containers::darray<T>::~darray()
{
    delete[] m_data;
}

template<typename T>
void zx_containers::darray<T>::push_back( value_type value )
{
    if (m_size >= m_capacity)
        resize();

    *(m_data + m_size) = value;
    m_size ++;
}

template<typename T>
void zx_containers::darray<T>::set( size_type index, value_type value )
{
    if ( index < 0 )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if ( index < m_size )
    {
        *(m_data + index) = value;
        return;
    }

    // keep resizing as long as index > m_capacity
    while( index > m_capacity )
        resize();

    for (size_t i = m_size; i <= index; i++)
    {
        *(m_data + i) = {};
        m_size++;
    }
    
    *(m_data + index) = value;
}

template<typename T>
void zx_containers::darray<T>::insert( size_type index, value_type value )
{
    if ( index < 0 )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if (index > m_size)
        throw std::out_of_range("Invalid: Exceeds range, use set(size_type, T) instead");
    
    else if ( m_size == m_capacity )
        resize();
    
    for (long i = m_size - 1; i >= index; i--)
        m_data[i+1] = m_data[i];  
    
    m_data[index] = value;
    m_size ++;
    
}

template<typename T>
auto zx_containers::darray<T>::at( size_type index ) const -> value_type
{
    if ( index < 0 )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if ( index >= m_size )
        throw std::out_of_range("Invalid: index is out of range\n");
    
    return m_data[index];
}

template<typename T>
auto zx_containers::darray<T>::pop_back() -> value_type
{
    if (m_size == 0)
        throw std::logic_error("Can't pop_back an empty array");
    
    m_size--;
    
    return m_data[m_size];
}

template<typename T>
auto zx_containers::darray<T>::erase( size_type index ) -> value_type
{
    if ( index < 0 )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if ( index > m_size - 1 )
        throw std::out_of_range("Invalid: Index out of bound");
    else if ( m_size == 0 )
        throw std::logic_error("Can't erase elements from an empty array");
    
    T deleted = m_data[index];
    
    for (long i = index; i <= m_size - 1; i++)
        m_data[i] = m_data[i + 1];
    
    m_size--;
    
    return deleted;
}

template<typename T>
auto zx_containers::darray<T>::size() const -> size_type
{
    return m_size;
}

template<typename T>
auto zx_containers::darray<T>::capacity() const -> size_type
{
    return m_capacity;
}

template<typename T>
bool zx_containers::darray<T>::empty()
{
    return m_size == 0;
}

template<typename T>
void zx_containers::darray<T>::resize()
{
    T* tmp = new T[m_capacity * __GROWTH_FACTOR__];
    if (tmp == nullptr)
        throw std::bad_alloc();
    
    std::copy(m_data, m_data + m_capacity, tmp);
    delete[] m_data;
    m_data = tmp;
    m_capacity = m_capacity * __GROWTH_FACTOR__;
}

template<typename T>
void zx_containers::darray<T>::clear()
{
    if (m_size == 0)
        return;
    
    delete[] m_data;
    this->m_capacity = __INITIAL_SIZE__;
    this->m_size = 0;
    this->m_data = new T[m_capacity];

    if (m_data == nullptr)
        throw std::bad_alloc();
}

template<typename T>
std::ostream& zx_containers::darray<T>::print(std::ostream& os) const
{
    os << "{ ";
        for (size_t i = 0; i < m_size; i++)
        {
            os << m_data[i] << ", ";
            if ( i == m_size - 1 )
                os << m_data[i];
        }
        os << " }\n";
        return os;
}

template<typename U>
inline std::ostream& operator<<(std::ostream& os, zx_containers::darray<U> const& obj)
{
    return obj.print(os);
}