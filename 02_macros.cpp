#include <iostream>

// Permuting the order has the expected effect.
// #define PRINT_JOE // Replaced with blank space
#define PRINT_JOE PRINT_BOB
#define PRINT_BOB

#define FOO 9 // check line 25

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

#if 0 // How's this different from just commenting out the code?
    std::cout << "Bob\n";
    std::cout << "Steve\n";
#endif

#ifdef FOO // This FOO does not get replaced with 9 because it’s part of another preprocessor directive
    std::cout << FOO << '\n'; // This FOO gets replaced with 9 because it's part of the normal code
#endif

    return 0;
}
