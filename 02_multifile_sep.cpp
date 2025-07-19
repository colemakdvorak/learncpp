#include <iostream>
#include "02_multifile_sep.h"

// Notes: Function definitions for multi-file project. Implements add, getInteger, readNumber, writeAnswer.

// add: returns sum of a and b
int add(int a, int b) {
	return a + b;
}

// getInteger: prompts user and returns input
int getInteger()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;
	return x;
}

// readNumber: another input function, similar to getInteger
int readNumber() {
    int num{};
    std::cout << "Input a Number:\n";
    std::cin >> num;
    return num;
}

// writeAnswer: prints the sum (or any number) to stdout
void writeAnswer(int num) {
    std::cout << "The sum of numbers you've just typed in is: " << num << '\n';
}
