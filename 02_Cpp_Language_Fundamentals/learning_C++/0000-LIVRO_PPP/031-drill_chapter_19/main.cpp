#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

template <std::input_iterator Iter1, typename Iter2>
    requires std::output_iterator<Iter2, std::iter_value_t<Iter1>>
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2) {
    for (; f1 != e1; ++f1) {
        *f2 = *f1;
        ++f2;
    }
    return f2;
}

int main() {

    std::array<int, 10> array{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int> vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::list<int> list{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::array<int, 10> array2 = array;
    std::vector<int> vector2 = vector;
    std::list<int> list2 = list;

    for (int i : array2) {
        i = i + 2;
    }

    for (int i : vector2) {
        i = i + 3;
    }

    for (int i : list2) {
        i = i + 5;
    }

    copy(array.begin(), array.end(), vector2.begin());

    copy(list.begin(), list.end(), array2.begin());

    auto p = std::find(vector2.begin(), vector2.end(), 3);

    if (p == vector.end()) {
        std::cout << "There is nothing" << std::endl;
    } else {
        std::cout << "At index: " << *p << std::endl;
    }

    auto pp = std::find(list.begin(), list.end(), 27);

    if (pp == list.end()) {
        std::cout << "There is nothing" << std::endl;
    } else {
        std::cout << "At index: " << *pp << std::endl;
    }

    return 0;
}