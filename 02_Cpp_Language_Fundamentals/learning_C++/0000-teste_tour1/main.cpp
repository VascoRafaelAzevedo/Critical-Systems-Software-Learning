#include <iostream>

using namespace std;

int main() {

    cout << "Hello, World!" << endl;


    for (int64_t i {0} ; i < 10000000000; i++)
    {
        int *arr = new int[10000000]; //usa a ram toda
        cout << i;
    }

    cout << "finished";
    
    

    return 0;
}