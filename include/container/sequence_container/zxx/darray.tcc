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

#include "zxx_darray.h"     // Useless but it's added to disable error squiggles


namespace container
{
    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>::darray()
    {

    }

    template<typename T, typename Allocator>    
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>::darray( Allocator& alloc )
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>::darray( const darray& other )
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>::darray( 
        const darray& other, 
        Allocator& alloc 
    )
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>::darray( darray&& other )
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>::darray( 
        darray&& other, 
        Allocator& alloc 
    )
    {
        
    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>::darray( 
        size_type n, 
        const value_type& value = {},
        const Allocator& alloc = Allocator()
    )
    {
        
    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>::darray( 
        size_type count,
        const Allocator& alloc = Allocator() )
    
    {
        
    }

    template<typename T, typename Allocator>
    template<typename InputIterator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::darray( 
        InputIterator first, 
        InputIterator last, 
        const Allocator& alloc = Allocator() 
    )
    {
        
    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>::darray( 
        zxx::initializer_list<T> init,
        const Allocator& alloc = Allocator() 
    )
    {
        
    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>& 
    darray<T, Allocator>::operator=( const darray& x )
    {
        
    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>& 
    darray<T, Allocator>::operator=( darray&& x )
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR 
    darray<T, Allocator>& 
    darray<T, Allocator>::operator=( zxx::initializer_list<T> init )
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::iterator
    darray<T, Allocator>::begin()
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::const_iterator
    darray<T, Allocator>::cbegin() const
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::iterator
    darray<T, Allocator>::end()
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::const_iterator
    darray<T, Allocator>::cend() const
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::reverse_iterator
    darray<T, Allocator>::rbegin()
    {

    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::const_reverse_iterator
    darray<T, Allocator>::crbegin() const
    {

    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::reverse_iterator
    darray<T, Allocator>::rend()
    {

    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::const_reverse_iterator
    darray<T, Allocator>::crend() const
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::reference 
    darray<T, Allocator>::operator[]( size_type n )
    {

    } 
    
    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::const_reference
    darray<T, Allocator>::operator[]( size_type n ) const
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::reference
    darray<T, Allocator>::at( size_type n )
    {

    } 
    
    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::const_reference
    darray<T, Allocator>::at( size_type n ) const
    {

    } 
    
    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::reference
    darray<T, Allocator>::front()
    {

    } 
    
    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::const_reference
    darray<T, Allocator>::front() const
    {

    } 
    
    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::reference
    darray<T, Allocator>::back()
    {

    } 
    
    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::const_reference 
    darray<T, Allocator>::back() const
    {

    }

    template<typename T, typename Allocator>
    template<class ...Args>
    GLIBZXX_CONSTEXPR
    void 
    darray<T, Allocator>::emplace_back( Args&&... args )
    {
        
    } 

    template<typename T, typename Allocator>
    template<class ...Args>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::iterator 
    darray<T, Allocator>::emplace( const_iterator it, Args&&... args )
    {
        
    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    void 
    darray<T, Allocator>::push_back( const T& x )
    {
        
    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    void 
    darray<T, Allocator>::push_back( T&& x )
    {
        
    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    void 
    darray<T, Allocator>::pop_back()
    {
        
    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::iterator 
    darray<T, Allocator>::insert( const_iterator it, const T& x )
    {
        
    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::iterator 
    darray<T, Allocator>::insert( const_iterator it, T&& x )
    {
        
    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::iterator 
    darray<T, Allocator>::insert( const_iterator it, size_type n, T& x )
    {
        
    } 

    template<typename T, typename Allocator>
    template<class InputIterator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::iterator
    darray<T, Allocator>::insert( const_iterator it, InputIterator first, InputIterator last )
    {
        
    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::iterator
    darray<T, Allocator>::insert(const_iterator it, zxx::initializer_list<T> init )
    {
        
    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::iterator
    darray<T, Allocator>::erase( const_iterator it )
    {
        
    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    typename darray<T, Allocator>::iterator
    darray<T, Allocator>::erase( const_iterator first, const_iterator last )
    {
        
    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    void 
    darray<T, Allocator>::clear()
    {
        
    } 

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    void
    darray<T, Allocator>::swap( darray& darr )
    {
        
    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::size_type
    darray<T, Allocator>::capacity() const noexcept
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::size_type 
    darray<T, Allocator>::size() const noexcept
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    darray<T, Allocator>::size_type
    darray<T, Allocator>::max_size() const noexcept
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    bool 
    darray<T, Allocator>::empty() const noexcept
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    void 
    darray<T, Allocator>::reserve( size_type n )
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    void 
    darray<T, Allocator>::shrink_to_fit()
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    Allocator 
    darray<T, Allocator>::get_allocator() const
    {

    }

    template<typename T, typename Allocator>
    GLIBZXX_CONSTEXPR
    std::ostream&
    darray<T, Allocator>::print( std::ostream& os ) const
    {

    }
} // namespace container

template<typename U>
GLIBZXX_CONSTEXPR 
std::ostream& 
operator<<(std::ostream& os, container::darray<U> const& obj)
{
    return obj.print(os);
}

template< class T, class Alloc >
GLIBZXX_CONSTEXPR
bool operator==( 
    const container::darray< class T, class Alloc >& x,
    const container::darray< class T, class Alloc >& y
)
{

}

template< class T, class Alloc >
GLIBZXX_CONSTEXPR
bool operator!=( 
    const container::darray< class T, class Alloc >& x,
    const container::darray< class T, class Alloc >& y
)
{

}

template< class T, class Alloc >
GLIBZXX_CONSTEXPR
bool operator<( 
    const container::darray< class T, class Alloc >& x,
    const container::darray< class T, class Alloc >& y 
)
{

}

template< class T, class Alloc >
GLIBZXX_CONSTEXPR
bool operator>( 
    const container::darray< class T, class Alloc >& x,
    const container::darray< class T, class Alloc >& y 
)
{

}

template< class T, class Alloc >
GLIBZXX_CONSTEXPR
bool operator<=( 
    const container::darray< class T, class Alloc >& x,
    const container::darray< class T, class Alloc >& y
)
{

}

template< class T, class Alloc >
GLIBZXX_CONSTEXPR
bool operator>=( 
    const container::darray< class T, class Alloc >& x,
    const container::darray< class T, class Alloc >& y
) 
{

}

#if __cplusplus >= 202003L
template< class T, class Alloc >
GLIBZXX_CONSTEXPR
bool operator>=<( 
    const container::darray< class T, class Alloc >& x,
    const container::darray< class T, class Alloc >& y
)
{

}
#endif