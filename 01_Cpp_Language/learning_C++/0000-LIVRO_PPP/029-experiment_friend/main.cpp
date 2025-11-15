#include <iostream>
#include <string>


class Car{
    int tires;
    int doors;
    std::string owner;
public:
    Car(int t, int d, std::string o): tires {t}, doors {d}, owner {o} {}
    friend class Printer;
};

class Printer {
public:
    static void printerFunct(Car c){
        std::cout << "Tires: " << c.tires << "\n";
        std::cout << "Doors: " << c.doors << "\n";
        std::cout << "Owner: " << c.owner << "\n";
    }
};




int main() {

    Car c(4,4,"Vasco");

    Printer::printerFunct(c);
    
    

    return 0;
}