#include "../dynamic_array.hpp"     // Useless but it's added to disable error squiggles

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

using namespace zx_containers;

template<typename T>
zx_containers::darray<T>::darray()
try :   m_capacity(__INITIAL_SIZE__), 
        m_data(new value_type[m_capacity]), 
        m_size(0)
{}
catch(...)
{
    m_resource_allocation_failed = true;
}

template<typename T>
zx_containers::darray<T>::darray( size_t n, const value_type& value )
try :   m_capacity(n), 
        m_data(new T[m_capacity]), 
        m_size(n)
{
    for (size_t i = 0; i < m_capacity; i++)
        *(m_data + i) = value;   
}
catch(...)
{
    m_resource_allocation_failed = true;
}

template<typename T>
zx_containers::darray<T>::darray( const darray& x )
{
    #if DEBUG
    std::cout << "[----------] Copied!" << std::endl;
    #endif // DEBUG

    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;

    try
    {
        m_data = new T[x.capacity()];
        m_size = x.size();
        m_capacity = x.capacity();

        for (size_t i = 0; i < x.size(); i++)
            push_back(x.at(i));
    }
    catch(...)
    {
        m_resource_allocation_failed = true;
    }
}

template<typename T>
zx_containers::darray<T>::darray( T* first, T* last )
: darray()
{
   for (T* it = first; it != last; it++)
        push_back(*it);
   
}

template<typename T>
zx_containers::darray<T>::~darray()
{
    delete[] m_data;
}

template<typename T>
void zx_containers::darray<T>::push_back( const value_type& value )
{
    if (m_size >= m_capacity)
        resize();

    *(m_data + m_size) = value;
    m_size ++;
}

template<typename T>
void zx_containers::darray<T>::push_back( value_type&& value )
{
    if (m_size >= m_capacity)
        resize();

    *(m_data + m_size) = std::move(value);
    m_size ++;
}

template<typename T>
void zx_containers::darray<T>::set( size_type index, value_type& value )
{
    if ( index > INT64_MAX )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if ( index < m_size )
    {
        *(m_data + index) = value;
        return;
    }

    // keep resizing as size_t as index > m_capacity
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
void zx_containers::darray<T>::insert( size_type index, const value_type& value )
{
    if ( index > INT64_MAX )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if (index > m_size)
        throw std::out_of_range("Invalid: Exceeds range, use set(size_t, T) instead");
    
    else if ( m_size == m_capacity )
        resize();
    
    for (size_t i = m_size; i > index; i--)
        m_data[i] = m_data[i - 1];  
    
    m_data[index] = value;
    m_size ++;
}

template<typename T>
void zx_containers::darray<T>::insert(size_type index, value_type&& value)
{
    if ( index > INT64_MAX )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if (index > m_size)
        throw std::out_of_range("Invalid: Exceeds range, use set(size_t, T) instead");
    
    else if ( m_size == m_capacity )
        resize();
    
    for (size_t i = m_size; i > index; i--)
        m_data[i] = m_data[i - 1]; 
    
    m_data[index] = std::move(value);
    m_size ++;
}

template<typename T>
auto zx_containers::darray<T>::at( size_type index ) const -> value_type
{
    if ( index > INT64_MAX )
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
    if ( index > INT64_MAX )
        throw std::logic_error("Invalid: negative indices are not allowed.");

    else if ( index > m_size - 1 )
        throw std::out_of_range("Invalid: Index out of bound");
    else if ( m_size == 0 )
        throw std::logic_error("Can't erase elements from an empty array");
    
    T deleted = m_data[index];
    
    for (size_t i = index; i <= m_size - 1; i++)
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
    
    try
    {
        T* tmp = new T[m_capacity * __GROWTH_FACTOR__];
        std::copy(m_data, m_data + m_capacity, tmp);
        delete[] m_data;
        m_data = tmp;
        m_capacity = m_capacity * __GROWTH_FACTOR__;
    }
    catch(const std::exception& e)
    {
        m_resource_allocation_failed = true;
    }    
}

template<typename T>
void zx_containers::darray<T>::clear()
{
    if (m_size == 0)
        return;
    
    delete[] m_data;
    this->m_capacity = __INITIAL_SIZE__;
    this->m_size = 0;
    try
    {
        this->m_data = new T[m_capacity];
    }
    catch(const std::exception& e)
    {
        m_resource_allocation_failed = true;
    }
    
}

template<typename T>
std::ostream& zx_containers::darray<T>::print(std::ostream& os) const
{
    if (m_size == 0)
        os << " { }" ;
    os << "{ ";
        for (size_t i = 0; i < m_size; i++)
        {
            if ( i == m_size - 1 )
            {
                os << m_data[i];
                break;
            }
                
            os << m_data[i] << ", ";
        }
        os << " }\n";
        return os;
}

template<typename T>
bool zx_containers::darray<T>::resource_allocation_failed()
{
    return m_resource_allocation_failed;
}

template<typename U>
inline std::ostream& operator<<(std::ostream& os, zx_containers::darray<U> const& obj)
{
    return obj.print(os);
}

