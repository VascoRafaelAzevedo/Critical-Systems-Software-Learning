#include <iostream>
#include <vector>

int main()
{

    std::vector<std::string> bad_words{"benfica", "sporting"};

    for (std::string word; std::cin >> word;)
    {
        bool bad_word{false};
        for (std::string bad : bad_words)
        {
            if (word == bad)
            {
                bad_word = true;
            }
        }
        if (!bad_word)
        {
            std::cout << word << "\n";
            std::cout << "------------------\n";
        }
        else
        {
            std::cout << "BLEEP\n";
            std::cout << "------------------\n";
        }
    }

    return 0;
}