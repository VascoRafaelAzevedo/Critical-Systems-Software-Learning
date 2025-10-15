#include <iostream>

int main() {


    int *p {new int {1}};

    delete p;
    p = nullptr;
    delete p;
    std::cout << "All well, banging booming" << std::endl;
    delete p; //isto dá erro e crash, não se pode dar 2 delete seguidos, mas posso usar delete se estiver nullptr
    std::cout << "All well, banging booming" << std::endl;

    return 0;

}