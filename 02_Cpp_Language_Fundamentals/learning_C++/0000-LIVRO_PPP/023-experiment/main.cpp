#include <iostream>

int foo(int i = 123) { return i; }

int main() {

  int num;
  std::cout << "Insert a number" << std::endl;
  std::cin >> num;
  if (num == 0) {
    std::cout << foo() << "\n";
  }else {
    std::cout << foo(num) << "\n";
  }

  return 0;
}