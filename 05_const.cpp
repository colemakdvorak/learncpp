#include <iostream>

const int constant_return() {
    return -1;
}

int main() {
    const double gravity {9.8};
    int const side {4}; // legal but not preferred.
    int test {constant_return()}; // Does const get casted to non-const? It should and it does.
    volatile int random {9}; // qualifier that indicates potential change at any time.
    std::cout << constant_return() << '\n';

    // literal constant suffixes
    std::cout << 5 << '\n';
    std::cout << 5L << '\n';
    std::cout << 5u << '\n';
    return 0;
}
