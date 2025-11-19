#include <iostream>

void copy(int *f1, int *e1, int *f2) {
    while (f1 != e1) {
        *f2 = *f1;
        f1++;
        f2++;
    }
    return;
}

int main() {
    const int size {5};
    int f1[size] = {1,2,3,4,5};
    int f2[size];

    int* e1 = f1 + size;

    copy(f1, e1, f2);

    for (int i = 0; i <  5; i++) {
        std::cout << f2[i] << std::endl;
    }


    return 0; }