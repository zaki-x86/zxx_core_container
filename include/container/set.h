/**
 * @file set.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief Set container API
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _SET_H_

#define _SET_H_

class set
{
public:
    set() = default;
    set(set &&) = default;
    set(const set &) = default;
    set &operator=(set &&) = default;
    set &operator=(const set &) = default;
    ~set() = default;

private:
    
};

#endif // !_SET_H_