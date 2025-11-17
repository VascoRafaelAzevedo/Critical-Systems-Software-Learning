#include <iostream>
#include <vector>
#include <algorithm>

const int GET_FLOATING{10 * 10 * 10 * 10};
const int FLOATING_DIGITS{4};

std::vector<char> getDigits(float number)
{
    std::vector<char> digits;

    int get_digits = number * GET_FLOATING;
    while (get_digits > 0)
    {
        int d = get_digits % 10;
        get_digits = get_digits / 10;

        digits.push_back(d);
    }
    if ((digits.size() - FLOATING_DIGITS) % 2 != 0)
    {
        digits.push_back(0);
    }

    std::reverse(digits.begin(), digits.end());
    return digits;
}

int main()
{
    float number{};
    std::cout << "Please insert a number to obtain its square:" << std::endl;
    std::cin >> number;

    std::vector<char> digits = getDigits(number);

    for (char c : digits)
    {
       std::cout << (int) c << "\n";
    }

    
    
    
    return 0;
}