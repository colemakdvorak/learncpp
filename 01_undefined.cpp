#include <iostream>

// Example of UB / implementation defined behavior
int main() {
    std::cout << sizeof(int) << std::endl; // Yea I guess.
    2*4;
    return 0;
}
