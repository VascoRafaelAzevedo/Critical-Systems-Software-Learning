#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct Item {
    std::string name;
    int iid;
    double value;
};

int main() {

    std::ifstream ist{"items.txt"};
    if (!ist) {
        std::cerr << "Error: Could not open items.txt\n";
        return 1;
    }

    std::vector<Item> vi;

    // Read ten items from file
    for (int i = 0; i < 10; ++i) {
        Item item;
        if (ist >> item.name >> item.iid >> item.value) {
            vi.push_back(item);
        } else {
            std::cerr << "Error reading item " << i + 1 << "\n";
            break;
        }
    }

    for (Item i : vi) {
        std::cout << std::setw(5) << "name: " << std::setw(11) << i.name << " iid: " << std::setw(5)
                  << i.iid << " value: " << std::setw(7) << i.value << std::endl;
    }

    std::sort(vi.begin(), vi.end(), [](const Item &a, const Item &b) {
        return a.name < b.name; // Sort by name in ascending order
    });

    std::cout << std::endl;

    for (Item i : vi) {
        std::cout << std::setw(5) << "name: " << std::setw(11) << i.name << " iid: " << std::setw(5)
                  << i.iid << " value: " << std::setw(7) << i.value << std::endl;
    }

    std::sort(vi.begin(), vi.end(), [](const Item &a, const Item &b) {
        return a.iid < b.iid; // Sort by name in ascending order
    });

    std::cout << std::endl;

    for (Item i : vi) {
        std::cout << std::setw(5) << "name: " << std::setw(11) << i.name << " iid: " << std::setw(5)
                  << i.iid << " value: " << std::setw(7) << i.value << std::endl;
    }

    std::sort(vi.begin(), vi.end(), [](const Item &a, const Item &b) {
        return a.value < b.value; // Sort by name in ascending order
    });

    std::cout << std::endl;

    for (Item i : vi) {
        std::cout << std::setw(5) << "name: " << std::setw(11) << i.name << " iid: " << std::setw(5)
                  << i.iid << " value: " << std::setw(7) << i.value << std::endl;
    }

    vi.push_back(Item{"horse shoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});

    for (Item i : vi) {
        std::cout << std::setw(5) << "name: " << std::setw(11) << i.name << " iid: " << std::setw(5)
                  << i.iid << " value: " << std::setw(7) << i.value << std::endl;
    }

    
    return 0;
}