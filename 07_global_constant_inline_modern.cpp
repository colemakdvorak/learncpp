#include "07_global_constant_inline_modern.h" // brings in inline constants (C++17+)

#include <iostream>

// Notes: Uses a global constant (pi) from a namespace, modern C++17+ style (inline in header).

int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    // Use constants::pi from the header (inline, so no .cpp needed)
    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}
