#include <iostream>

int five()
{
    return 5;
}

int pass(const int x) // x is a runtime constant
{
    return x;
}

int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y; // can only execute at runtime

    return y;      // return value only known at runtime
}

int main()
{
    // The following are non-constants:
    [[maybe_unused]] int a { 5 };

    // The following are compile-time constants:
    [[maybe_unused]] const int b { 5 };
    [[maybe_unused]] const double c { 1.2 };
    [[maybe_unused]] const int d { b };       // b is a compile-time constant

    // The following are runtime constants:
    [[maybe_unused]] const int e { a };       // a is non-const
    [[maybe_unused]] const int f { e };       // e is a runtime constant
    [[maybe_unused]] const int g { five() };  // return value isn't known until runtime
    [[maybe_unused]] const int h { pass(5) }; // return value isn't known until runtime

    // Literals can be used in constant expressions
    5;                           // constant expression
    1.2;                         // constant expression
    "Hello world!";              // constant expression

    // Most operators that have constant expression operands can be used in constant expressions
    5 + 6;                       // constant expression
    1.2 * 3.4;                   // constant expression
    8 - 5.6;                     // constant expression (even though operands have different types)
    sizeof(int) + 1;             // constant expression (sizeof can be determined at compile-time)

    // Calls to non-constexpr functions can only be used in runtime expressions
    getNumber();                 // runtime expression
    five();                      // runtime expression (even though return value is constant expression)

    // Operators without constant expression operands can only be used in runtime expressions
    std::cout << 5;              // runtime expression (std::cout isn't a constant expression operand)


    return 0;
}
