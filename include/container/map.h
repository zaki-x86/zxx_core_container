/**
 * @file map.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief Map container API
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _MAP_H_

#define _MAP_H_

class map
{
public:
    map() = default;
    map(map &&) = default;
    map(const map &) = default;
    map &operator=(map &&) = default;
    map &operator=(const map &) = default;
    ~map() = default;

private:
    
};

#endif // !_MAP_H_