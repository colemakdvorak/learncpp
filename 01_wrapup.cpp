#include <iostream>

int main() {
    int x{};
    std::cout << "Input a number\n";
    if(std::cin >> x) {
        std::cout << "Your input number is: " << x << '\n';
        std::cout << "Double this and you get " << 2*x << '\n';
        std::cout << "Triple this and you get " << 3*x << '\n';
    } else {
        std::cout << "Invalid input";
    }
    return 0;
}
