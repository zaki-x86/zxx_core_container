/**
 * @file unordered_map.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief Unordered Map container API
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _UNORDERED_MAP_H_

#define _UNORDERED_MAP_H_

class unordered_map
{
public:
    unordered_map() = default;
    unordered_map(unordered_map &&) = default;
    unordered_map(const unordered_map &) = default;
    unordered_map &operator=(unordered_map &&) = default;
    unordered_map &operator=(const unordered_map &) = default;
    ~unordered_map() = default;

private:
    
};

#endif // !_UNORDERED_MAP_H
