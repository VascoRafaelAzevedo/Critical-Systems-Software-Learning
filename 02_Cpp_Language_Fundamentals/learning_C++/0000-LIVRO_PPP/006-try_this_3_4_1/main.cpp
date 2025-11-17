#include <iostream>

int main()
{

    double amount{};
    double amount_converted1{};
    double amount_converted2{};
    char type;

    std::cout << "Please insert the currency you have:" << std::endl;
    std::cout << "'k' for kroner" << std::endl;
    std::cout << "'p' for pound" << std::endl;
    std::cout << "'y' for yen" << std::endl;
    std::cin >> type;

    std::cout << "Please insert the amount of money to convert:" << std::endl;
    std::cin >> amount;

    std::cout << "You have: " << amount << type << std::endl;

    if (type == 'k')
    {
        amount_converted1 = amount / 10;
    }
    else if (type == 'p')
    {
        amount_converted1 = amount * 1.3;
    }
    else
    {
        amount_converted1 = amount / 152;
    }

    switch (type)
    {
    case 'k':
        amount_converted2 = amount / 10;
        break;
    case 'p':
        amount_converted2 = amount * 1.3;
    case 'y':
        amount_converted2 = amount / 152;

    default:
        break;
    }

    std::cout << "\n\nYou Have: " << amount_converted1 << " USD" << std::endl;
    std::cout << "\n\nYou Have: " << amount_converted2 << " USD" << std::endl;

    return 0;
}