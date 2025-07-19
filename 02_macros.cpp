#include <iostream>

// Notes: Preprocessor macros, #define, #ifdef, #if 0, and macro replacement quirks.

// Permuting the order has the expected effect.
// #define PRINT_JOE // Replaced with blank space

// PRINT_JOE gets replaced with PRINT_BOB, which is then defined (so both are "defined")
#define PRINT_JOE PRINT_BOB
#define PRINT_BOB

#define FOO 9 // Macro: FOO will be replaced with 9 in code, but not in preprocessor directives

int main()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined (via PRINT_BOB)
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

#if 0 // #if 0 disables code at preprocessor level (not just a comment, code is ignored)
    std::cout << "Bob\n";
    std::cout << "Steve\n";
#endif

#ifdef FOO // FOO here is not replaced with 9, since it's in a preprocessor directive
    std::cout << FOO << '\n'; // FOO here is replaced with 9 (normal code)
#endif

    return 0;
}
