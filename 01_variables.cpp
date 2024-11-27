#include <iostream>

int main () {
    // multiple allocation
    int x, y, z;
    [[maybe_unused]] double a,b,c;
    //int e{5};

    // assignment and printing
    x = 42;
    std::cout << x << '\n';

    x = 7;
    std::cout << x << '\n';

    // initialization options
    int width_empty;

    // trad
    int width_copy = 42;    // copy
    int width_direct (42);  // direct

    // modern
    int width_direct_list {42}; // direct listing
    int width_value_init {};    // value initialization

    // tldr; direct list is the only method that disallows implicit conversion.

    // testing
    std::cout <<
        width_empty << '\n' <<
        width_copy << '\n' <<
        width_direct << '\n' <<
        width_direct_list << '\n' <<
        width_value_init << '\n';

    // Interesting to observe that empty spits out garbage value whereas value initialization fills in a default value.
    
    return x; // technically not wrong?
}
