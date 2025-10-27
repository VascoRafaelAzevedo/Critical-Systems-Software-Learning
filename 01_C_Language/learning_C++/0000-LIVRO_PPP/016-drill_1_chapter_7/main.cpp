#include <iostream>

void swap_v(int a, int b)
{
    int temp;
    temp = a, a = b;
    b = temp;
}

void swap_r(int &a, int &b)
{
    int temp;
    temp = a, a = b;
    b = temp;
}

// void swap_cr(const int& a,const int& b)
//{
//     int temp;
//     temp = a, a=b;
//     b=temp;
// }

int main()
{

    int x = 7;
    int y = 9;
    swap_v(x, y); // replace ? by v, r, or cr
    swap_v(7, 9);

    std::cout << "X: " << x << "\n"; // nao trocou
    std::cout << "Y: " << y << "\n";

    swap_r(x, y); // replace ? by v, r, or cr
    //swap_r(7, 9); //tinha de ser um lvalue e nao está

    std::cout << "X: " << x << "\n"; // trocou
    std::cout << "Y: " << y << "\n";

    return 0;
}