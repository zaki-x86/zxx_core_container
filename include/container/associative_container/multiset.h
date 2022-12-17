/**
 * @file multiset.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief Multiset container API
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _MULTISET_H_

#define _MULTISET_H_

class multiset
{
public:
    multiset() = default;
    multiset(multiset &&) = default;
    multiset(const multiset &) = default;
    multiset &operator=(multiset &&) = default;
    multiset &operator=(const multiset &) = default;
    ~multiset() = default;

private:
    
};

#endif // !_MULTISET_H