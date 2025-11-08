#include <iostream>

int main() {
    std::cout << "Hello World!" << std::endl;

    //compile time errors
    //std::cout << "Hello World!" << std::endl missing comma
    
    //runtime error
    7/0; //wtf is even this
    //only makes problems if we use it
    /*
    
    /home/vasco-debian/Desktop/DEV/Versioned/Personal/Critical-Systems-Software-Learning/01_C_Language/learning_C++/04-Errors/main.cpp:10:6: warning: division by zero is undefined [-Wdivision-by-zero]
   10 |     7/0; //wtf is even this
      |      ^~
    /home/vasco-debian/Desktop/DEV/Versioned/Personal/Critical-Systems-Software-Learning/01_C_Language/learning_C++/04-Errors/main.cpp:10:6: warning: expression result unused [-Wunused-value]
   10 |     7/0; //wtf is even this
      |     
    
    */
    return 0;
}