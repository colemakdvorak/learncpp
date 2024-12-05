#include <iostream>
#include <limits>

void print(int x) {
	std::cout << x << '\n';
}

void print_num() {
    std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;
	std::cout << "You entered '" << c << "', which has ASCII code " << static_cast<int>(c) << ".\n";
}


int main() {
    // Weak typing at work
    char example {'a'};
    char example_num {97};

    std::cout << example << " and " << example_num << '\n';

    // cout queueing behavior
    std::cout << "Input a keyboard character: \n"; // assume the user enters "abcd" (without quotes)
    char ch{};
    std::cin >> ch; // input multiple characters
    std::cout << "You entered: " << ch << '\n';

    // the buffered ones are used instead of asking for additional input.
    // >> operator probably asks for user input if the buffer is in an empty state.
    std::cin >> ch;
    std::cout << "You entered: " << ch << '\n';

    // IMO, atrocious (although understandable)
    while (std::cin.get(ch) && ch != '\n');
    
    std::cout << "Input a keyboard character: \n";
    std::cin >> ch; // input multiple characters separated by whitespace
    std::cout << "You entered: " << ch << '\n';
    std::cin.get(ch);
    std::cout << "You entered: " << ch << '\n';
    std::cin.get(ch); // .get does not ignore whitespace
    std::cout << "You entered: " << ch << '\n';
    while (std::cin.get(ch) && ch != '\n');

    // Beware of multicharacter literals
    // std::cout << '!/n'; Compiler catches the error

    // Explicit casting
    print(static_cast<int>(3.14));
    print_num();
    return 0;
}
