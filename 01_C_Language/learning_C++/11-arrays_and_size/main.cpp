#include <iostream>

int main()
{

    int array[19]{1, 2, 2, 33, 2, 3, 314, 412, 231, 23, 1, 2};

    for (int element : array)
    {
        std::cout << element << std::endl;
    }

    char array2[6] {'H', 'E', 'L','L', 'O', '\0'};
    char array3[] {"HELLO"};

    std::cout << array3 <<std::endl;
    std::cout << std::size(array3) <<std::endl;

    array2[1000000] =12;
}