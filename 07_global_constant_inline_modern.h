#ifndef CONSTANTS_H
#define CONSTANTS_H

// Notes: Namespace for global constants, using inline constexpr (C++17+). Modern way to share constants across files.

// define your own namespace to hold constants
namespace constants
{
    inline constexpr double pi { 3.14159 };           // classic pi, inline so only one definition needed
    inline constexpr double avogadro { 6.0221413e23 }; // Avogadro's number
    inline constexpr double myGravity { 9.2 };        // m/s^2 -- gravity is light on this planet
    // ... other related constants
}
#endif
