/**
 * @file queue.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief queue container API
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _QUEUE_H_

#define _QUEUE_H_

class queue
{
public:
    queue() = default;
    queue(queue &&) = default;
    queue(const queue &) = default;
    queue &operator=(queue &&) = default;
    queue &operator=(const queue &) = default;
    ~queue() = default;

private:
    
};

#endif // !_QUEUE_H_