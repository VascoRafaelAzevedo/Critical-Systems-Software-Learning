#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <vector>

class Point {
public:
  int x;
  int y;
};

std::ostream &operator<<(std::ostream &os, const Point &p) {
  return os << "X: " << p.x << " Y: " << p.y;
}

std::istream &operator>>(std::istream &is, Point &p) {
  std::string s1;
  std::string s2;
  is >> s1 >> p.x >> s2 >> p.y;

  return is;
}

int main() {

  int birth_year{2005};

  std::cout << "HEX: \tab" << std::hex << birth_year << std::endl;
  std::cout << "DEC: \tab" << std::dec << birth_year << std::endl;
  std::cout << "OCT: \tab" << std::oct << birth_year << std::endl;

  int age{20};

  std::cout << "AGE: " << std::dec << age << std::endl;

  int a{}, b{}, c{}, d{};
  std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
  std::cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

  float f{1234567.89};
  std::cout << f << '\n';
  std::cout << std::fixed << f << '\n';
  std::cout << std::scientific << f << '\n';

  std::vector<Point> original_points;
  original_points.resize(2);
  std::cout << "Please insert two points (x y for each):\n";
  for (int i = 0; i < 2; ++i) {
    Point p;
    std::cin >> p;
    original_points[i] = p;
  }

  for (Point p : original_points) {
    std::cout << p << "\n";
  }

  std::ofstream ofile{"data.txt"};

  for (Point p : original_points) {
    ofile << p << "\n";
  }

    ofile.close();
  std::ifstream ifile{"data.txt"};
  if (!ifile) {
    std::cerr << "failed to open data.txt\n";
    return 1;
  }

  std::vector<Point> processed_points;
  processed_points.resize(2);
  for (Point &p : processed_points) {
    ifile >> p;
  }

  std::cout << "processed points \n";
  for (Point &p : processed_points) {
    std::cout << p << "\n";
  }

  return 0;
}