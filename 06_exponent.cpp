#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>

// Notes: Safe integer exponentiation, overflow checks, constexpr, bit tricks, and simple parity check.
// Good for learning: assert, std::numeric_limits, bitwise ops, and why overflow matters.

/*
powerint_safe: integer exponentiation with overflow checks.
- constexpr: can run at compile time if args are known.
- Handles negative bases, checks for overflow, uses exponentiation by squaring.
*/
constexpr std::int64_t powerint_safe(std::int64_t base, int exp) {
    assert(exp >= 0 && "power_intsafe: exponent is negative"); // assert only runs in debug, catches bad input

    if(base == 0)
        return (exp == 0) ? 1 : 0; // 0^0 = 1 by convention

    std::int64_t result {1};
    bool negative {false};

    if(base < 0){
        base = -base;
        negative = exp & 1; // Trick: if exp is odd, result should be negative
    }    

    while(exp > 0) {
        if(exp & 1){
            if(result > std::numeric_limits<std::int64_t>::max() / base) {
                std::cerr << "powerint_safe(): result overflow\n";
                return std::numeric_limits<std::int64_t>::max();
            }
            result *= base;
        }

        exp /= 2; // Exponentiation by squaring: halves exp each loop

        if(exp <= 0)
            break;

        if(base > std::numeric_limits<std::int64_t>::max() / base){
            std::cerr << "powerint_safe(): result overflow\n";
            return std::numeric_limits<std::int64_t>::max();
        }

        base *= base;
    }

    return negative ? -result : result;
}



/*
isEven: checks if a number is even.
- constexpr: can be evaluated at compile time.
- % 2 is the classic way to check parity.
*/
constexpr bool isEven(int number) {
    return number % 2 == 0 ? true : false;
}

int main() {
    // Demo: show powerint_safe in action
    std::cout << powerint_safe(2, 12);

    int user_input {0}; // Uniform initialization, avoids narrowing
    std::cout << "Type a number. I'll check its parity for you \n";
    std::cin >> user_input;
    std::cout << isEven(user_input); // Should print 1 for even, 0 for odd
    return 0;
}
