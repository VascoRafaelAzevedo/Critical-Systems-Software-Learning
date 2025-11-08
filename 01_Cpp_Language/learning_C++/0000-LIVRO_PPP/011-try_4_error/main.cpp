#include <iostream>

int area(int a, int b)
{
    return 1;
}

int main()
{

    int s1 = area(7, 2); // error: ) missing
    int s2 = area(7, 2); // error: ; missing
    int s3 = area(7, 2); // error: Int (with a capitalized ’i’) is not a type
    int s4 = area(7, 2);

//    int x0 = arena(7, 2); // error: undeclared function
//    int x1 = area(7);     // error: wrong number of arguments
//   int x2 = area("seven", 2);

    int x4 = area(10,-7);      // OK: but what is a rectangle with a width of minus 7?
    int x5 = area(10.7, 9.3);  // OK: but calls area(10,9)
    char x6 = area(100, 9999); // OK: but truncates the result
}