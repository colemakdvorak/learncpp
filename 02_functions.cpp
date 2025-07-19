#include <iostream>
#include <cstdlib>

// Notes: Function basics—parameters, return values, void, overloading, unnamed params, and macros.

int parseValue(){
    int num{};
    std::cout << "Enter an integer\n";
    std::cin >> num;
    return num; // returns user input
}

int returnThree(){
    return 3;
}

// add: returns sum of a and b
int add(int a, int b) {
    return a + b;
}

// multiply: returns product
int multiply(int a, int b) {
    return a * b;
}

// subtract: returns a - b (rewritten as -1 * b + a)
int subtract(int a, int b) {
    return -1 * b + a;
}

// divide: integer division, but casts to double for division first
int divide(int a, int b) {
    return (int) ((double) a / (double) b);
}

// double_num: returns 2 * a
int double_num(int a) {
    return 2*a;
}

// unnamed parameter: valid in C++, useful for overloading/templates
void what(int) {
    // This is a valid function.
}

// printValue: prints the value to stdout
void printValue(int num){
    std::cout << num << '\n';
}

// It is illegal to call main in C++ but not so in C.
int main() {
    // Demo: function calls, parameter passing, macro usage
    int a {parseValue()};
    int b {parseValue()};
    printValue(a);
    printValue(b);
    printValue(add(a,b));
    printValue(subtract(a,b));
    printValue(multiply(a,b));
    printValue(divide(a,b));
    printValue(double_num(a));

    // Unnamed parameters are useful for overloading and type templating.
    what(0);

    // Macro check: EXIT_FAILURE and EXIT_SUCCESS are from <cstdlib>
    std::cout   << "EXIT FAILURE MACRO VALUE: " 
                << EXIT_FAILURE << '\n' 
                << "EXIT SUCCESS MACRO VALUE: "
                << EXIT_SUCCESS;
    return 0;
}
