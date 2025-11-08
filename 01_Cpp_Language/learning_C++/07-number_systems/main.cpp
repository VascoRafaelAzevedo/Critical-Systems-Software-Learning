#include <iostream>

int main() {
    int i  = 15;
    int i2 = 017; //octal, not used
    int i3 = 0x0F;
    int i4 = 0b00001111; //only possiblle since C++12

    std::cout << i << std::endl;
    std::cout << i2 << std::endl;
    std::cout << i3 << std::endl;
    std::cout << i4 << std::endl;


    
    return 0;
}