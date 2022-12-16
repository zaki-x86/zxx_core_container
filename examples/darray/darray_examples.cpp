#include <iostream>
#include <zx_containers/dynamic_array.hpp>

using namespace zx_containers;

int main(int argc, char const *argv[])
{
    //! [BasicUsage]

    // darray<int> a = 5;               // illegal
    
    std::cout << "Using fill construtor" << std::endl;
    darray<int> b = darray<int>(5);  // OK
    darray<int> c(10, 500);           // OK

    /// print array elements
    std::cout << "darray<int> b = " << b << std::endl;  
    std::cout << "darray<int> c(10, 500) = " << c << std::endl;    

    //! [BasicUsage]

    darray<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);

    darray<int>::iterator it;

    for (it = x.begin(); it != x.end(); ++it)
    {
        std::cout << *it << " ";
    }

    for(auto var : x)
    {
        std::cout << var << " ";
    }
    

    return 0;
}
