#include <iostream>

// Notes: constexpr = compile-time constant. Shows what is (and isn't) a constant expression in C++.

// The return value of a non-constexpr function is not a constant expression
int five()
{
    return 5; // Not constexpr: can't guarantee compile-time evaluation
}

int main()
{
    constexpr double gravity { 9.8 }; // ok: 9.8 is a constant expression (literal)
    constexpr int sum { 4 + 5 };      // ok: arithmetic on literals is constexpr
    constexpr int something { sum };  // ok: sum is constexpr, so this is too

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    // constexpr int myAge { age };      // compile error: age is not a constant expression (user input = run-time)
    // constexpr int f { five() };       // compile error: five() isn't constexpr, so can't use here

    return 0;
}
