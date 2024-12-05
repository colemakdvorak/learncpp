#include <iostream>
#include <iomanip> // for setprecision
#include <limits> 

int main() {
    std::cout << std::boolalpha; // cout settings
    std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';
    
    int a {5};
    double b {5.0};
    float c {5.0f}; 
    double d{5.0f}; // watch out

    // Printing. Auto-formatting.
    std::cout << 5.0 << '\n';
	std::cout << 6.7f << '\n';
	std::cout << 9876543.21 << '\n';

    // Print formatting.
    std::cout << std::setprecision(16);
    std::cout << 0.366666666666666666666666666666666666666666666666666666666666666666f << '\n';
    std::cout << 0.366666666666666666666666666666666666666666666666666666666666666666 << '\n';

    // Typical floating point operation / formatting behavior
    double e{0.1};
    double sum{0.0};
    std::cout << e << '\n'; // use default cout precision of 6
    std::cout << std::setprecision(17);
    std::cout << e << '\n';
    for(int i = 0; i < 10; i++)
        sum += e;
    std::cout << sum << '\n';

    return 0;
}
