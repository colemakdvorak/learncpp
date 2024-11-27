#include <iostream>

int main(){
    int x{42}, y{0}, z{-12};
    // std::cout is buffered
    // std::endl forces the buffer to flush (vs \n)
    std::cout << x << std::endl;
    std::cout << "Write a number \n";
    std::cin >> y >> x >> z;
    std::cout << y << x << z;

    // If character extraction fails then a value of 0 is assigned to a variable
    // and cin fails all subsequent inputs until it has been explicitly cleared.

    // C++ requires an external library to allow non-enter ending inputs.
    // pdcures, FXTUI, cpp-terminal etc.
    return 0;
}
