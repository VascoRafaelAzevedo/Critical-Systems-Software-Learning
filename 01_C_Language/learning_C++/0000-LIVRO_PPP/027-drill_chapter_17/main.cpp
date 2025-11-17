#include <iostream>

class Ptr {
    double *p;

public:
    Ptr(): p{nullptr} {}
    ~Ptr() {delete p;}
    
    explicit Ptr(double d) : p{ new double(d)}{}
    Ptr(const Ptr& pp) : p{pp.p ? new double(*pp.p): nullptr} {}
    Ptr(Ptr&& pp) : p{ pp.p } { pp.p = nullptr; }


    Ptr& operator=(Ptr pp){
        std::cout << "Copy Assignment" << std::endl;
        swap(*this, pp);
        return *this;
    }
    double& operator*(){
        return *p;
    }

    friend void swap(Ptr& a, Ptr& b) {
        using std::swap;
        swap(a.p, b.p);
    }
};


int main() {

    Ptr p(1);

    std::cout << *p << std::endl; 

    Ptr pp = p;

    *p = 2;
    std::cout << *p << std::endl; 

    std::cout << *pp << std::endl; 

    Ptr v;
    v = p;
    std::cout << *v << std::endl; 


    return 0;
}