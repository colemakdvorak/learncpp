/*
Notes on sharing random number generators across multiple functions/files (summarized for myself):

- Passing a PRNG everywhere (from main, as a function argument) is possible, but gets messy fast—especially if you only need randomness in a few places.
- Making a static local PRNG in every function is overkill, wastes resources, and can lower randomness quality.
- The best solution: define a single global PRNG object (inside a namespace, e.g. Random::mt) and access it anywhere.
  - This is one of the rare exceptions to the "avoid global variables" rule.
- The header-only pattern (see Random.h) uses 'inline' to safely define the RNG and helper functions in a header, so you can #include it in as many files as you want without linker errors.
- The RNG is self-seeded using both the system clock and several values from std::random_device for good randomness.
- Helper functions like Random::get(min, max) make it easy to get random numbers of any type, without managing distributions or the PRNG object yourself.
- If you need a custom distribution, you can use Random::mt directly.
- This keeps code clean, avoids global state headaches, and ensures high-quality, reproducible randomness everywhere.

Usage:
  #include "Random.h"
  int x = Random::get(1, 6); // random int between 1 and 6
  auto y = Random::get<std::size_t>(0, 10u); // random size_t between 0 and 10
  std::uniform_real_distribution dist(0.0, 1.0);
  double z = dist(Random::mt); // custom distribution

See Random.h for details.
*/

#include "08_random.h" // defines Random::mt, Random::get(), and Random::generate()
#include <cstddef> // for std::size_t
#include <iostream>

int main()
{
	// We can call Random::get() to generate random integral values
	// If the two arguments have the same type, the returned value will have that same type.
	std::cout << Random::get(1, 6) << '\n';   // returns int between 1 and 6
	std::cout << Random::get(1u, 6u) << '\n'; // returns unsigned int between 1 and 6

        // In cases where we have two arguments with different types
        // and/or if we want the return type to be different than the argument types
        // We must specify the return type using a template type argument (between the angled brackets)
	// See https://www.learncpp.com/cpp-tutorial/function-template-instantiation/
	std::cout << Random::get<std::size_t>(1, 6u) << '\n'; // returns std::size_t between 1 and 6

	// If we have our own distribution, we can access Random::mt directly

	// Let's create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };
	for (int count{ 1 }; count <= 10; ++count)
	{
		std::cout << die6(Random::mt) << '\t'; // generate a roll of the die here
	}

	std::cout << '\n';

	return 0;
}
