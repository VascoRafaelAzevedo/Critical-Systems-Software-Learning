#include <iostream>

class Vector{
    int size;
    int* first;
    int* last;
public:
    Vector(): size{20}, first {new int[20]}, last{first + size}{}
    ~Vector(){delete[] first;}

    Vector(Vector& vec) : size{vec.size}, first{new int[vec.size]}, last{first + vec.size} {
        for (int i = 0; i < vec.size; i++) {
            first[i] = vec[i];
        }
    }

    int& operator[](int index){return first[index];}
    const int& operator[](int index) const{return first[index];}

};


int main() {

    Vector v;

    v[10] = 111;
    std::cout << "V " << v[10] << std::endl;

    Vector vv(v);
    v[10] = 112;
    std::cout << "V " << v[10] << std::endl;
    
    std::cout << "VV " << vv[10] << std::endl;

    return 0;
}