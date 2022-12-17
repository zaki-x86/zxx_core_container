/**
 * @file unordered_multimap.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief Unordered Multimap container API
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _UNORDERED_MULTIMAP_H_

#define _UNORDERED_MULTIMAP_H_

class unordered_multimap
{
public:
    unordered_multimap() = default;
    unordered_multimap(unordered_multimap &&) = default;
    unordered_multimap(const unordered_multimap &) = default;
    unordered_multimap &operator=(unordered_multimap &&) = default;
    unordered_multimap &operator=(const unordered_multimap &) = default;
    ~unordered_multimap() = default;

private:
    
};

#endif // !_UNORDERED_MULTIMAP_H_