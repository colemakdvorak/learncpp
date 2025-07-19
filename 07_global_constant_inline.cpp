#include "07_global_constant_inline.h" // brings in the declaration of constants::pi

#include <iostream>

// Notes: Uses a global constant (pi) from a namespace, pre-C++17 style (not inline).

// This is old style prior to c++17
int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    // Use constants::pi from the header (defined in .cpp)
    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}
