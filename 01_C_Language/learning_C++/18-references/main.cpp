#include <iostream>

int main() {

    int i = 20;
    int &i_ref = i;
    int *i_ptr = &i;

    std::cout << "Variable: " << i << " Reference: " << i_ref << std::endl;
    
    i_ref = 10;
    std::cout << "Variable: " << i << " Reference: " << i_ref << std::endl;

    std::cout << "Variable: " << &i << " Reference: " << &i_ref << std::endl; //a referencia é tratada pelo 
    //compilador como um pointer constante, nao precisa de mais memria porque trata como um unico objeto
    std::cout << "Pointer: " << &i_ptr << " Reference: " << &i_ref << std::endl;

    int a {12};
    const int* const a_ptr {&a};

    std::cout << *a_ptr << std::endl;

    //*a_ptr = 10; //big erro nao pode ser mudado

    //uma referencia constante é isto, nao podes mudar nem a referencia nem o valor nela


    return 0;
}