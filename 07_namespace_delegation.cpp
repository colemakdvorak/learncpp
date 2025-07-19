#include <iostream>

// Notes: Shows how to resolve function names between global and namespace scope using :: (scope resolution).

void print() // this print() lives in the global namespace
{
	std::cout << " there\n";
}

namespace Foo
{
	void print() // this print() lives in the Foo namespace
	{
		std::cout << "Hello";
	}

	void printHelloThere()
	{
		print();   // calls print() in Foo namespace (Foo::print)
		::print(); // calls print() in global namespace (the :: means "global")
	}
}

int main()
{
	// Calls Foo::printHelloThere, which calls both Foo::print and ::print
	Foo::printHelloThere();

	return 0;
}
