#include <iostream>

int round(double n)
{
    int rounded = (n * 100);

    return rounded;
}

int main()
{

    bool go{true};
    std::string input{};
    double n1{};
    double biggest{};
    std::cout << "Input number: ('|' to exit)" << std::endl;
    std::cin >> input;
    if (input == "|")
        return 0;
    n1 = std::stod(input);

    double latest{n1 + 1};
    double smallest{n1};

    while (go)
    {

        std::cout << "Number: " << n1 << std::endl;
        if (n1 == latest)
        {
            std::cout << "The n is equal to the last one\n";
            std::cout << "Latest: " << latest << std::endl;
        }
        else
        {
            int n1_round{round(n1)};
            int n2_round{round(latest)};
            if (n1_round == n2_round)
            {
                std::cout << "The n is almost equal to the last one\n";
                std::cout << "Latest: " << latest << std::endl;
            }
            else if (n1 > biggest)
            {
                std::cout << "N is the biggest\n";
                std::cout << "Biggest: " << biggest << std::endl;
                biggest = n1;
            }
            else if (n1 < smallest)
            {
                std::cout << "N is the smallest\n";
                std::cout << "Smallest: " << smallest << std::endl;
                smallest = n1;
            }
        }

        latest = n1;
        std::cout << "Input number: ('|' to exit)" << std::endl;    
        std::cin >> input;
        if (input == "|")
            break;
        n1 = std::stod(input);
    }

    std::cout << "Program finished" << std::endl;

    return 0;
}