/**
 * @file multimap.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief Multimap container API
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _MULTIMAP_H_

#define _MULTIMAP_H_

class multimap
{
public:
    multimap() = default;
    multimap(multimap &&) = default;
    multimap(const multimap &) = default;
    multimap &operator=(multimap &&) = default;
    multimap &operator=(const multimap &) = default;
    ~multimap() = default;

private:
    
};

#endif // !_MULTIMAP_H