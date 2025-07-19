#include <iostream>
#include <bitset>

// Notes: Playing with std::bitset for bit manipulation and visualization.
// Good for learning: set/flip/reset/test, size/count, boolalpha, and bitset methods.

int main() {
    int foo {5};
    std::cout << foo;
    // std::bitset: easy way to work with and print bits
    std::bitset<8> mybitset{0b0000'0101}; // 0b: binary literal, 8 bits wide

    mybitset.set(3);   // set bit 3 to 1
    mybitset.flip(4);  // flip bit 4 (0->1, 1->0)
    mybitset.reset(4); // reset bit 4 to 0

    std::cout << "All the bits: " << mybitset<< '\n';
    std::cout << "Bit 3 has value: " << mybitset.test(3) << '\n'; // test: check if bit is set
    std::cout << "Bit 4 has value: " << mybitset.test(4) << '\n';

    std::bitset<8> bits{ 0b0000'0000 };
    std::cout << bits.size() << " bits are in the bitset\n";   // size: total bits
    std::cout << bits.count() << " bits are set to true\n";    // count: how many bits are 1

    std::cout << std::boolalpha; // print bools as true/false instead of 1/0
    std::cout << "All bits are true: " << bits.all() << '\n';  // all: true if all bits are 1
    std::cout << "Some bits are true: " << bits.any() << '\n'; // any: true if any bit is 1
    std::cout << "No bits are true: " << bits.none() << '\n';  // none: true if all bits are 0

    return 0;
}
