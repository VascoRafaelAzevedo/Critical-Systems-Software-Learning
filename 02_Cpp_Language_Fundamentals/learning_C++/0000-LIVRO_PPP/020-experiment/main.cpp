#include <iostream>

class Car {
public:
  Car(int w, int d) : wheels{w}, doors{d} {}
  void setWheels(int n) { wheels = n; }
  void setDoors(int n) { doors = n; }

  int getWheels() const { return wheels; }
  int getDoors() const { return doors; }

private:
  int wheels;
  int doors;
};

class Car2 {
public:
  Car2(int w, int d) : wheels{w}, doors{d} {}
  void setWheels(int n) { wheels = n; }
  void setDoors(int n) { doors = n; }

  int getWheels() const { return wheels; }
  int getDoors() const { return doors; }

private:
  int wheels;
  int doors;
};

std::ostream &operator<<(std::ostream &os, const Car &d) {
  return os << d.getWheels() << ' ' << d.getDoors();
}

std::ostream &operator<<(std::ostream &os, const Car2 &d) {
  return os << d.getWheels() << ' ' << d.getDoors();
}


int main() {

  Car c = Car{1, 2};

  std::cout << c << std::endl;

  return 0;
}