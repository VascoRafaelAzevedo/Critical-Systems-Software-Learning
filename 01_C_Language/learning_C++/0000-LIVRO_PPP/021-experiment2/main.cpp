#include <iostream>
#include <string>

class Foo {
public:
    std::string operator+(Foo x){
        return "hello";
    }
    Foo(int ii) {i = ii;}
private: 
    int i;    
};


int main() {

    Foo x = Foo(1);
    Foo y = Foo(2);
    std::string sum = x + y;

    std::cout << sum << std::endl;

    return 0;
}