#include <iostream>
#include <string>
#include <vector>
template <typename T> struct S {
  private:
    T val;

  public:
    S(T v) : val{v} {}

    T &access();
    const T &access() const;

    void operator=(const T &);
};

template <typename T> // important to put template here so it recgnizes the T
T &S<T>::access() {
    return val;
}

template <typename T> // important to put template here so it recgnizes the T
const T &S<T>::access() const {
    return val;
}

template <typename T> // important to put template here so it recgnizes the T
void S<T>::operator=(const T &rhs) {
    val = rhs;
}

template <typename T> std::istream &operator>>(std::istream &is, std::vector<T> &v) {
    char c;
    is >> c;
    if (c != '{') {
        is.setstate(std::ios::failbit);
        return is;
    }

    char next = is.peek(); // espreita o próximo char (não consome)
    if (next == '}') {
        is >> c;
        return is;
    }

    T value;
    while (true) {
        is >> value;        // lê um valor
        v.push_back(value); // adiciona ao vector

        is >> c; // lê próximo char (deve ser ',' ou '}')
        if (c == '}')
            break;      // terminou
        if (c != ',') { // se não for vírgula, erro
            is.setstate(std::ios::failbit);
            return is;
        }
        // se chegou aqui, c era ',', continua o loop
    }
    return is;
}

// Free function template to read from cin into S<T> objects
template <typename T> void read_val(S<T> &v) { std::cin >> v.access(); }



int main() {

    S<int> i(10);
    S<char> c('a');
    S<double> d(10.2);
    S<std::string> s("hello");
    S<std::vector<int>> v({
        1,
        2,
        3,
        4,
    });

    std::cout << i.access() << std::endl;
    std::cout << c.access() << std::endl;
    std::cout << d.access() << std::endl;
    std::cout << s.access() << std::endl;
    std::cout << v.access()[2] << std::endl;

    std::cout << "\nReading values from cin...\n";
    //  read_val(i);
    //  read_val(c);
    //  read_val(d);
    //  read_val(s);
      read_val(v);

    std::cout << "\nAfter reading:\n";
    std::cout << i.access() << std::endl;
    std::cout << c.access() << std::endl;
    std::cout << d.access() << std::endl;
    std::cout << s.access() << std::endl;

    std::cout << "VEC:\n";

    for (int integ : v.access()) {
        std::cout << integ << std::endl;
    }

    std::cout << "VEC END\n";


    i = 11;
    std::cout << i.access() << std::endl;

    int &x = i.access();
    const int &x2 = i.access();
    std::cout
        << x2
        << std::endl; // should be 11 because is reference to vall const (he cannot  change it)
    x = 2000;
    std::cout << i.access() << std::endl; // should be 2000 because reference was changed by x
    std::cout
        << x2
        << std::endl; // should be 2000 althout being const because qhat it was pointing has changed

    std::cout
        << "TESTING:"
        << std::endl; // should be 2000 althout being const because qhat it was pointing has changed

    return 0;
}