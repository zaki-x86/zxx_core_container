#include <iostream>
#include <zx_containers/dynamic_array.hpp>

using namespace zx_containers;

int main(int argc, char const *argv[])
{
    // darray<int> a = 5;               // illegal
    
    darray<int> b = darray<int>(5)   // OK
    darray<int> c(10, 500)           // OK

    return 0;
}
