#include <iostream>

bool comparison(int a, int b) {
    return a == b;
}

int main() {
    bool b1 {true};
    bool b2 {false};
    bool b3 {};

    std::cout << b1 << '\n';
    std::cout << !b1 << '\n';
    std::cout << std::boolalpha;
    std::cout << b1 << '\n';
    std::cout << !b1 << '\n';

    bool b{};
    std::cout << "Input a boolean value: \n";
    std::cin >> b;
    std::cout << b << '\n';
    std::cin >> std::boolalpha;
    std::cout << "Try again: \n";
    std::cin >> b;
    std::cout << b << '\n';
    
    std::cout << comparison(4.0,4); // Long story short: C++ is weakly typed, just like C.
}
