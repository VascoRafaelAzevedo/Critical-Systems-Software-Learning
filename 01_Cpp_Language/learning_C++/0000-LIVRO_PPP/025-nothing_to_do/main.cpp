#include <iostream>
#include <random>

int main() {
    int unit = 1;
    int balance = 100000;
    long spins = 5'000'000;

    int betRed = unit;
    int betBlack = unit;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1); // 0 = Red, 1 = Black

    for (long i = 0; i < spins; ++i) {
        int result = dist(gen); 
        bool redWins = (result == 0);

        std::cout << "Spin " << i 
                  << ": Red bet=" << betRed 
                  << " Black bet=" << betBlack 
                  << " -> Result: " << (redWins ? "Red" : "Black");

        // Update balance
        if (redWins) {
            balance += betRed;    // win red
            balance -= betBlack;  // lose black
            betRed = unit;        // reset winning side
            betBlack *= 2;        // double losing side
        } else {
            balance += betBlack;  // win black
            balance -= betRed;    // lose red
            betBlack = unit;      // reset winning side
            betRed *= 2;          // double losing side
        }

        std::cout << " | New balance = " << balance << "\n";

        // Optional: stop if bets explode
        if (betRed > balance || betBlack > balance) {
            std::cout << "Bets too large, stopping simulation.\n";
            break;
        }
    }

    return 0;
}
