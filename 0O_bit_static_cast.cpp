#include <bitset>
#include <cstdint>
#include <iostream>

// Notes: Bitwise ops on uint8_t, static_cast to control type, and bitset for visualization.

int main()
{
    // 0b00001111 = 15 in binary, 8 bits wide
    std::uint8_t c { 0b00001111 };

    // static_cast to uint8_t: ensures result is 8 bits, avoids promotion to int
    std::cout << std::bitset<32>(static_cast<std::uint8_t>(~c)) << '\n';     // correct: prints 00000000000000000000000011110000
    std::cout << std::bitset<32>(static_cast<std::uint8_t>(c << 6)) << '\n'; // correct: prints 0000000000000000000011000000

    // Assigning result of bitwise ops to uint8_t: static_cast is safe, no warning
    std::uint8_t cneg { static_cast<std::uint8_t>(~c) };                     // compiles
    c = static_cast<std::uint8_t>(~c);                                       // no warning

    return 0;
}
