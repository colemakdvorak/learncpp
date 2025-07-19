#include <iostream>

// Notes: Shows how to use the inline keyword for functions. Suggests to the compiler to replace calls with the function body.

inline int min(int x, int y) // inline: suggests inlining, allows multiple definitions across files
{
    return (x < y) ? x : y;
}

int main()
{
    // Demo: calling the inline min function
    std::cout << min(5, 6) << '\n';
    std::cout << min(3, 2) << '\n';
    return 0;
}
