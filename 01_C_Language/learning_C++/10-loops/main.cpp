#include <iostream>

const int COUNT{10};

int main()
{

    // for loop
    for (int i{}; i < COUNT; i++)
    {
        std::cout << i << " I love C++" << std::endl;
    }

    // while loop
    int j{};

    while (j < COUNT)
    {
        std::cout << j << " I love C++" << std::endl;
        j++;
    }

    // do while

    int n = 100;
    int arr[n]; // ❌ não é permitido em C++ padrão (só em extensões tipo GCC)

    int l{};
    do
    {
        std::cout << l << " I love C++" << std::endl; 
        l++;
    } while (l < COUNT);

    return 0;
}