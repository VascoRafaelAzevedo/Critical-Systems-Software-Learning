#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

int main() {

    std::map<std::string, int> words;

    for (std::string s; std::cin >> s;) {
        if (!s.compare("end")) { break; }
        auto t0 = std::chrono::system_clock::now();
        words[s]++;
        auto t1 = std::chrono::system_clock::now();
        std::cout << "time to add in RB tree: " << t1 - t0 << std::endl;
    }

    auto t0 = std::chrono::system_clock::now();
    for (const std::pair<std::string, int> &p : words) {
        std::cout << p.first << ": " << p.second << '\n';
    }
    auto t1 = std::chrono::system_clock::now();
    std::cout << "time to add in RB tree: " << t1 - t0 << std::endl;

    auto t2 = std::chrono::system_clock::now();

    // structured binding the pair, I dont know why but structured binding is FASTER
    for (const auto &[key, value] : words)
        std::cout << key << ": " << value << '\n';

    auto t3 = std::chrono::system_clock::now();
    std::cout << "time to add in RB tree: " << t3 - t2 << std::endl;


    //UNORDERED
    


    std::unordered_map<std::string, int> words2;

    for (std::string s; std::cin >> s;) {
        auto ta0 = std::chrono::system_clock::now();
        words2[s]++;
        auto ta1 = std::chrono::system_clock::now();
        std::cout << "time to add in RB tree: " << ta1 - ta0 << std::endl;
    }

    auto ta0 = std::chrono::system_clock::now();
    for (const std::pair<std::string, int> &p : words2) {
        std::cout << p.first << ": " << p.second << '\n';
    }
    auto ta1 = std::chrono::system_clock::now();
    std::cout << "time to add in RB tree: " << ta1 - ta0 << std::endl;

    auto ta2 = std::chrono::system_clock::now();

    // structured binding the pair, I dont know why but structured binding is FASTER
    for (const auto &[key, value] : words2)
        std::cout << key << ": " << value << '\n';

    auto ta3 = std::chrono::system_clock::now();
    std::cout << "time to add in RB tree: " << ta3 - ta2 << std::endl;

    return 0;
}