#include <iostream>
#include "02_multifile_sep.h"

// Notes: Multi-file project practice. Shows how to declare/define functions in separate files and link them.
// Compilation practice. Check tasks.json file for build steps.
// int getInteger(); // would be needed if not included via header

int main()
{
	// getInteger and add are defined in another file (see 02_multifile_sep.cpp/.h)
	int x{ getInteger() };
	int y{ getInteger() };

	std::cout << x << " + " << y << " is " << add(x,y) << '\n'; // add is also from the other file
	return 0;
}
