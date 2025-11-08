#include <iostream>

int main() {

    int *ptr {nullptr};
    int **ptr2 {nullptr};

    ptr2 = &ptr;

    ptr = new int;

    *ptr = 1;

    std::cout << *ptr << std::endl;
    std::cout << ptr << std::endl;
    std::cout << *ptr2 << std::endl;
    std::cout << **ptr2 << std::endl;
    
    std::cout << &ptr << std::endl;
    std::cout << ptr2 << std::endl;

    delete ptr;
    ptr = nullptr;

    std::cout << ptr2 << std::endl;
    std::cout << *ptr2 << std::endl;
    std::cout << **ptr2 << std::endl; //crash porque não existe esta memoria
    return 0;
}