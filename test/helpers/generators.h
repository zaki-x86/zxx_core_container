#pragma once

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <unistd.h>


template<typename T>
T generate_numeric(const T, const T);
char generate_char();
std::string generate_string(const size_t);



// --- Imp ---

template<typename T>
T generate_numeric(const T from, const T to)
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<T> distr(from, to);
    return distr(generator);
}



char generate_char()
{
    
    const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    const size_t max_index = (sizeof(charset) - 1);
    char out = charset[ generate_numeric<int>(0, max_index) ];

    if (out != '\0' && isalnum(out))
        return out;
    
    return 'x';
}




std::string generate_string(const size_t len)
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    if (tmp_s.size() != 0)
        return tmp_s;

    else if (tmp_s.size() == 0)
    {
        tmp_s = "empty";
        return tmp_s;
    }

    else
        return "empty";  
}


