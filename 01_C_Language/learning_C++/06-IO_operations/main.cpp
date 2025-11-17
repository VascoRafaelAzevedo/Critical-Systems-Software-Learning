#include <iostream>

int main() {

    std::string name;
    int age;

    /*
    std::cout << "Hello World!" << std::endl; // normal
    std::cerr << "Hello ERROR!" << std::endl; // error output
    std::clog << "Hello log!" << std::endl; // log output
    */

    // std::cout << "Insert Name and Age:" << std::endl;
    // std::cin >> name >> age;


    // std::cout << "Hello " << name << "you are " << age << std::endl;
    //if input is: Vasco Azevedo
    //only vasco is stored in the name and age is stored as 0 (std::cin) only reads until a space


    //grab with spaces
    std::string full_name;
    int age2;


    std::cout << "Enter name and age: " << std::endl;

    std::getline(std::cin, full_name);


    std::cin >> age2;

    std::cout << "Hello " << full_name << " you are " << age2 << std::endl;

    //this code generates a funny problem, std::cin >> age reads the number and leaves the \n new line character in the buffer


    return 0;
}