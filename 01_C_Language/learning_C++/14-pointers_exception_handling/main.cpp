#include <iostream>

int main() {


    try
    {
        int *data2 = new int [10000000000000000];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    int *data = new int[10000000000000];
    
    std::cout << "Exit ok" << std::endl;


    return 0;
}