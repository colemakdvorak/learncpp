#include <iostream>
#include <random>

/*
Notes on Mersenne Twister, seeding, and random number generation (summarized for myself):

- The Mersenne Twister (std::mt19937) has a huge internal state: 19937 bits (624 32-bit ints or 312 64-bit ints).
- std::mt19937 allocates 624 integers; std::mt19937_64 allocates 312.
- The type used is std::uint_fast32_t, which could be 32 or 64 bits depending on the platform. If it's 64 bits, std::mt19937 uses 624 64-bit ints (double the memory needed!).
- If I seed std::mt19937 with just a single int (like from the clock or std::random_device), I'm underseeding it—only 1 value for 624 slots. The library tries to fill the rest, but it's not truly random. This can lead to poor-quality random numbers. (Fun fact: with a single 32-bit seed, the first output can never be 42!)
- To improve this, use std::seed_seq. It takes as many random values as I have, and generates enough to fill the PRNG's state. More random data = better results.
- In this file, I use 8 values from std::random_device to seed std::seed_seq, which is a good minimum. Using 624 values is possible but slow and can exhaust the system's entropy pool.
- Other sources for seed data: clock, thread id, function addresses, user id, process id, etc. (see randutils.hpp for more ideas).
- Alternative: use a PRNG with a smaller state (e.g., 64 or 128 bits) if I don't need the full power of Mersenne Twister.

Warming up PRNGs:
- If a PRNG is underseeded, the first few outputs may be low quality. "Warming up" means discarding the first N outputs (hundreds or thousands) to mix the state.
- std::seed_seq does a warmup for std::mt19937, so I don't need to do it manually.

Debugging with random numbers:
- Randomized programs can be hard to debug because bugs may not always show up.
- For debugging, seed the PRNG with a fixed value (e.g., 5) so the program behaves the same every run. If the bug doesn't show, try a different seed.
- Once fixed, go back to normal random seeding.

Random FAQ:
- If I get the same sequence every run, I probably forgot to seed the PRNG or used a fixed seed.
- If I get the same number every time, I'm probably reseeding or recreating the PRNG for each random number (don't do that!).
*/

int main()
{
	std::random_device rd{};
	// Using 8 values from std::random_device to seed std::seed_seq.
	// This helps avoid underseeding the Mersenne Twister (see notes above).
	std::seed_seq ss{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
	std::mt19937 mt{ ss }; // std::seed_seq also "warms up" the PRNG for us.

	// Reusable random number generator for uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // (C++14: std::uniform_int_distribution<> die6{ 1, 6 };)

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << die6(mt) << '\t'; // generate a roll of the die here

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}

	return 0;
}
