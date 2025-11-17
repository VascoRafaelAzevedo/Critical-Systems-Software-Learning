module;

#include <iostream>

export module Foo;

export class Foo {
private:
    int foo = 0;
public:

    void print_foo(){
        std::cout << foo << std::endl;
    }
    void set_foo(int x) { foo = x; }
    int get_foo() { return foo; }
};