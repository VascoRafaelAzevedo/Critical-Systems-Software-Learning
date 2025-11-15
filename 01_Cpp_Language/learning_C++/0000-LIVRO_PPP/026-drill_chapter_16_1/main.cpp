#include <iostream>

void f(int arr[], int n) {
  int la[10];
  for (int i = 0; i < n; i++) {
    la[i] = arr[i];
  }

  for (int a : la) {
    std::cout << a << std::endl;
  }

  int *p = new int[10];
  int *p2 = p;

  for (int i = 0; i < n; i++) {
    *p2 = la[i];
    p2++;
  }

  for (int i = 0; i < n; i++) {
    std::cout << *p << std::endl;
    p++;
  }
  p = p- 10;

  delete[] p;
}

int main() {

  int ga[]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

  f(ga, 10);

  return 0;
}