#include <iostream>

int main() {

    int a {0};
    int b = 1;
    int c (2);
    int d {a + b};

    //int e {2.9}; //IT IS AN ERROR
    int f (2.9); //it is a warning it just stores 2
    int g = 2.9; //the same as functional initialization


    std::cout << g << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(g) << std::endl; //always printed in bytes, not bits! 
    std::cout << sizeof(long) << std::endl; //in linux
    
    return 0;
}