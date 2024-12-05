#include <iostream>
#include <cstdint>
#include <iomanip> 

// compiles due to backwards compatibility
int example(void) {
    int x{};
    std::cin >> x;
    return x;
}

int example_void(int) {
    int x{};
    std::cin >> x;
    return x;
}

int main(){
    std::cout << std::left; // left justify output
    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    // Assume 4 bytes on integer
    int x { 2'147'483'647 };
    unsigned int z {256};
    unsigned int y { z*z*z*(z - 1) + z*z*z - 1 };
    std::cout << std::setw(16) << "value of x: " << x << '\n';
    x = x + 1; // integer overflow, undefined behavior in C++
    std::cout << std::setw(16) << "value of x + 1: " << x << '\n';

    std::cout << std::setw(16) << "value of y: " << y << '\n';
    y = y + 1; // integer overflow for unsigned integers, this behavior is defined
    std::cout << std::setw(16) << "value of y + 1: " << y << '\n';

    std::cout << std::setw(16) << "12 / 5 = " << 12 / 5 << '\n';

    signed int s { -1 };
    unsigned int u { 1 };

    // Casting issue
    if(s < u)
        std::cout << s << " < " << u << '\n';
    else
        std::cout << s << " > " << u << '\n';

    std::int32_t sample {256};
    std::int32_t fixed_width {(sample*(sample-1) + sample - 1)/2};
    std::cout << std::setw(16) << "value of fixed_width: " << fixed_width << '\n';
    fixed_width = fixed_width + 1;
    std::cout << std::setw(16) << "value of fixed_width + 1: " << fixed_width << '\n';

    // Yet another C disaster. int8_t behaves like character unless the system is specifically 8-bit
    std::int8_t acts_like_char {65};
    std::cout << "value of acts_like_char is 65, but when printed: " << acts_like_char << '\n';

    // Most memory efficient and fastest aliases.
    std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";

    int sample_int {0};
    std::size_t size { sizeof(sample_int) }; // size_t type
    std::cout << size << '\n';

    return 0;
}
