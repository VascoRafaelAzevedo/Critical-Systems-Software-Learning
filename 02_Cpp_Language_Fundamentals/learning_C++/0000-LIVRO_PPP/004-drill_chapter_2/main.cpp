#include <iostream>

int main() {
    std::cout << "Please the first name of the pearson you want to write to: " << std::endl;
    std::string first_name;
    std::cin >> first_name;

    std::cout << "Please the first name of the friend you want to know about: " << std::endl;
    std::string friend_name;
    std::cin >> friend_name;

    std::cout << "Please the new age of yout friend: " << std::endl;
    int friend_age;
    std::cin >> friend_age;
    if (friend_age < 0 || friend_age > 110)
    {
        std::cout << "Your are kidding stop.\n";
        return 0;

    }
    

    std::cout << "Dear " << first_name << ",\n";
    std::cout << "  How are you? I am fine. I miss you.\n";
    std::cout << "  Tell me please about what you have been doing, you don't write me often.\n";
    std::cout << "  Have you seen " << friend_name << ", I haven't seen him in a long time.\n";
    std::cout << "  I hear you just had a birthday and you are " << friend_age <<" years old.\n";

    return 0;
}