#include <iostream>
#include "02_multifile_sep.h"

int add(int a, int b) {
	return a + b;
}

int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}

int readNumber() {
    int num{};
    std::cout << "Input a Number:\n";
    std::cin >> num;
    return num;
}

void writeAnswer(int num) {
    std::cout << "The sum of numbers you've just typed in is: " << num << '\n';
}
