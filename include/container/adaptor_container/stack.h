/**
 * @file stack.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief stack container API
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _STACK_H_

#define _STACK_H_

class stack
{
public:
    stack() = default;
    stack(stack &&) = default;
    stack(const stack &) = default;
    stack &operator=(stack &&) = default;
    stack &operator=(const stack &) = default;
    ~stack() = default;

private:
    
};

#endif // !_STACK_H_