#include <iostream>
#include <vector>
#include <string>

enum class Month {
  jan = 1,
  feb,
  mar,
  apr,
  may,
  jun,
  jul,
  aug,
  sep,
  oct,
  nov,
  dec

};

int to_int(Month m) { return static_cast<int>(m); }

Month operator++(Month &m) {
  m = (m == Month::dec) ? Month::jan : Month{to_int(m) + 1};
  return m;
}

struct Year {
  int y;
};

class Date {

public:
  Date();
  Date(Year y, Month m, int d);
  Date(Year y);

  int day() const { return d; }
  Month month() const { return m; }
  Year year() const { return y; }
  bool is_valid();

  void setDay(int dd) { d = dd; }
  void setMonth(Month mm) { m = mm; }
  void setYear(Year yy) { y = yy; }

private:
  int d{1};
  Month m{Month::jan};  // Corrigido: usar Month::jan em vez de {1}
  Year y{2001};
};

// Implementar construtores
Date::Date() : d{1}, m{Month::jan}, y{2001} {}

Date::Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd} {}

Date::Date(Year yy) : y{yy}, m{Month::jan}, d{1} {}

// Implementar is_valid (exemplo básico)
bool Date::is_valid() {
  if (d < 1 || d > 31) return false;
  if (to_int(m) < 1 || to_int(m) > 12) return false;
  return true;
}

std::ostream& operator<<(std::ostream& os, Month m)
{
    std::vector<std::string> month_tbl = {"Not a month", "January", "February", "March", "April", "May", "June", "Jully", "August", "September", "October", "November", "December"};
    return os << month_tbl[to_int(m)];
}

// Adicionar operator<< para Date
std::ostream& operator<<(std::ostream& os, const Date& d) {
  return os << d.year().y << "-" << d.month() << "-" << d.day();
}

int main() {
  Date today{Year{2020}, Month::jan, 2};
  std::cout << today << std::endl;
  return 0;
}