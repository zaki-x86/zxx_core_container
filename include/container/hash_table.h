/**
 * @file hash_table.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief hash table container API
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef _HASH_TABLE_H_

#define _HASH_TABLE_H_

class hash_table
{
public:
    hash_table() = default;
    hash_table(hash_table &&) = default;
    hash_table(const hash_table &) = default;
    hash_table &operator=(hash_table &&) = default;
    hash_table &operator=(const hash_table &) = default;
    ~hash_table() = default;

private:
    
};

#endif // !_HASH_TABLE_H_

