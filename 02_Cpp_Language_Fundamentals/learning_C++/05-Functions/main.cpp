#include <iostream>

int sum_num(int first, int second){
    int sum = first + second;
    return sum;
}

int multiply(int first, int second){
    int sum = first * second;
    return sum;
}

int main() {
    
    int first_number {1}; //statement
    int second_number {2};

    std::cout << "First Number: " << first_number << std::endl;
    std::cout << "Second Number: " << second_number << std::endl;
    
    int sum = first_number + second_number;

    std::cout << "SUM:" << sum << std::endl;
    
    int sum2 = sum_num(first_number, second_number);
    std::cout << "SUM2:" << sum2 << std::endl;

    int sum3 = sum_num(12, 12312);
    std::cout << "SUM3:" << sum3 << std::endl;


    std::cout << "SUM4:" << sum_num(12, 11) << std::endl;

    std::cout << "MULTIPLICATION:" << multiply(4, 2) << std::endl;

    return 0;
}