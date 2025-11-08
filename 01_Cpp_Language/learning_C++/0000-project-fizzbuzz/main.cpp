#include <iostream>

const int LOOP_TIMES {100};
const int FIZZ {3};
const int BUZZ {5};
const int FIZZBUZZ {15};



int main() { //muito  facil como assim os gajos n sabem responder a isto

    for (int i {}; i < LOOP_TIMES; i++)
    {
        if (i % 15 == 0)
        {
            std::cout << "FIZZBUZZ" << std::endl;
        }else if (i % 3 == 0)
        {
            std::cout << "FIZZ" << std::endl;
        }else if (i % 5 == 0)
        {
            std::cout << "BUZZ" << std::endl;
        }else {
            std::cout << i << std::endl;
        }
        
        
    }
    
    return 0;
}