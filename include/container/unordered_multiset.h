/**
 * @file unordered_multiset.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief Unordered Multiset container API
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _UNORDERED_MULTISET_H_

#define _UNORDERED_MULTISET_H_

class unordered_multiset
{
public:
    unordered_multiset() = default;
    unordered_multiset(unordered_multiset &&) = default;
    unordered_multiset(const unordered_multiset &) = default;
    unordered_multiset &operator=(unordered_multiset &&) = default;
    unordered_multiset &operator=(const unordered_multiset &) = default;
    ~unordered_multiset() = default;

private:
    
};

#endif // !_UNORDERED_MULTISET_H_
