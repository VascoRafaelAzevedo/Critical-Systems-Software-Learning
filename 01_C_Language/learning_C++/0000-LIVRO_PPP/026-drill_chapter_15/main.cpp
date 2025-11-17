#include <iostream>
#include <vector>

void print_array(std::ostream& os, int* a, int n) {
    for (int i = 0; i < n; i++) {
        os << a[i] << " ";
    }
    os << std::endl;
}

void print_vector(std::ostream& os, std::vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << " ";
    }
    os << std::endl;
}

int main() {

    int* array = new int[10];

    for (int i = 0; i < 10; i++) {
       std::cout << array[i] << std::endl;
    }  

    for (int i = 0; i < 10; i++) {
        array[i] = 100 + i;
    }

    print_array(std::cout,  array, 10);

    delete[] array;

    std::vector<int> v(10);
    for (int i = 0; i < 10; i++) {
        v[i] = 100 + i;
    }

    print_vector(std::cout, v);

    int num {7};
    int* p1 = &num;

    std::cout << "Pointer: " << p1 << " Value: " << *p1 << std::endl;

    int* p2 = new int[num];
    p2[0] = 1;
    for (int i  = 1; i < num; i ++) {
        p2[i]= p2[i-1] * 2;
    }

    print_array(std::cout, p2, num);

    int* p3 = p2;
    p2 = p1;
    p2 = p3;

    print_array(std::cout, p1, num);
    print_array(std::cout, p2, num);

    delete[] p1;
    delete[] p2;
    delete[] p3;



    return 0;
}