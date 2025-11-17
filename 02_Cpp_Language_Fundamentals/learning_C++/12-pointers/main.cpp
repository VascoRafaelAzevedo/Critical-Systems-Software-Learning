#include <iostream>

int main() {

    // int * ptr {};

    // double * double_ptr {};

    // int * ptr2 {nullptr};
    // double * double_ptr2 {nullptr};



    // std::cout << "Pointer nao explicito: " << *ptr << std::endl; 
    // std::cout << "Pointer explicito: " << *ptr2 << std::endl; 

    // int i {1};
    // int j {2};
    // int l {3};

    // ptr = &i;

    // std::cout << "Ptr memory pointed " << ptr << std::endl;
    // std::cout <<  "Ptr adress memory " << &ptr << std::endl;
    // std::cout <<  "Ptr value on memory pointed " << *ptr << std::endl;

    const char *ptr4 {"Hello world!"}; //dá warning por nao ser constante
    
    char *ptr3 {"Hello world!"}; //dá warning por nao ser constante
    // *ptr3 = 'B'; //MUITO PROIBIDO se queres mudar letras em particular é usar arrays de chars
    std::cout << ptr3 << std::endl;
    std::cout << *ptr3 << std::endl;


    return 0;
}