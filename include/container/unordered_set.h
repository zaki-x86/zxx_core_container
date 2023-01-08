/**
 * @file unordered_set.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief Unordered Set container API
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _UNORDERED_SET_H_

#define _UNORDERED_SET_H_

class unordered_set
{
public:
    unordered_set() = default;
    unordered_set(unordered_set &&) = default;
    unordered_set(const unordered_set &) = default;
    unordered_set &operator=(unordered_set &&) = default;
    unordered_set &operator=(const unordered_set &) = default;
    ~unordered_set() = default;

private:
    
};

#endif // !_UNORDERED_SET_H_