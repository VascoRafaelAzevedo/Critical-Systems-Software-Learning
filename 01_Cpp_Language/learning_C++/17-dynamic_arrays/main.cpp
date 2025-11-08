#include <iostream>

int main() {
    int size {3};
    int *arr {new int[3]{1,2,3}}; 

    for (int i {}; i < size; ++i)
    {
        std::cout << "Element " << i << ": " << *(arr + i) << std::endl;
        std::cout << "Element memory" << i << ": " << (arr + i) << std::endl;
    }
    
    delete []arr;
    arr = nullptr;

    return 0;
}