#include <iostream>

int main() {

    char c = 'a';

    for (int i {}; i < 26; ++i)
    {
        std::cout << (char) (c + i) << "\t" << c + i << std::endl;

    }
    
    char c1 = 'A';

    for (int i {}; i < 26; ++i)
    {
        std::cout << (char) (c1 + i) << "\t" << c1 + i << std::endl;

    }
    
    char c2 = '0';

    for (int i {}; i < 10; ++i)
    {
        std::cout << (char) (c2 + i) << "\t" << c2 + i << std::endl;

    }
    


    return 0;
}