#include <iostream>
#include <cstdlib>

int parseValue(){
    int num{};
    std::cout << "Enter an integer\n";
    std::cin >> num;
    return num;
}

int returnThree(){
    return 3;
}

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return -1 * b + a;
}

int divide(int a, int b) {
    return (int) ((double) a / (double) b);
}

int double_num(int a) {
    return 2*a;
}

void what(int) {
    // This is a valid function.
}

void printValue(int num){
    std::cout << num << '\n';
}

// It is illegal to call main in C++ but not so in C.
int main() {
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

    // Macro check
    std::cout   << "EXIT FAILURE MACRO VALUE: " 
                << EXIT_FAILURE << '\n' 
                << "EXIT SUCCESS MACRO VALUE: "
                << EXIT_SUCCESS;
    return 0;
}
