#include <iostream>
#include "02_multifile_sep.h"

// Compilation practice. Check tasks.json file.
// int getInteger();

int main()
{
	int x{ getInteger() };
	int y{ getInteger() };

	std::cout << x << " + " << y << " is " << add(x,y) << '\n';
	return 0;
}
