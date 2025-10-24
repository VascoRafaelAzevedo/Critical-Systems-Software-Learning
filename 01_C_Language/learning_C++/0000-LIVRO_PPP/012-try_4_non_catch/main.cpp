#include <iostream>
using namespace std;
void error(string s1, string s2)
{

    throw runtime_error{s1 + s2};
}

int main()
{

    cout << "hello 1\n";

    try
    {
        error("error", "caught");
    }
    catch (exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    cout << "hello 2\n";
    error("error", " not caught");
    cout << "hello 3\n";
    
    return 0;
}