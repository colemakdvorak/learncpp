#include <bitset>
#include <iostream>

// Notes: Bitwise shift operations with std::bitset.
// Good for learning: binary literals, left/right shift, and how bits move.

int main()
{
    // 0b1100 = 12 in binary, 4 bits wide
    std::bitset<4> x { 0b1100 };

    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1: drops rightmost bit, fills left with 0 (0110)
    std::cout << (x << 1) << '\n'; // shift left by 1: drops leftmost bit, fills right with 0 (1000)

    return 0;
}
