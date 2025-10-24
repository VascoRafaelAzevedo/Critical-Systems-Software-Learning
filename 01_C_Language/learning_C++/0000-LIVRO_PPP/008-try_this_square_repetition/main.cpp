#include <iostream>

int square(int num)
{
    int result {0};
    
    for (int i = 0; i < num; i++)
    {
        result += num; 
    }
    
    return result;
}


int main() {

    int input {};
    std::cout << "Insert a value to square: " << std::endl;
    std::cin >> input;
    std::cout << "Square: " << square(input) << std::endl;


    return 0;
}