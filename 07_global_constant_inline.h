#ifndef CONSTANTS_H
#define CONSTANTS_H

// Notes: Namespace for global constants. Keeps things organized and avoids name clashes.

// Define your own namespace to hold constants
namespace constants
{
    // Global constants have internal linkage by default (unless inline/extern)
    constexpr double pi { 3.14159 };           // classic pi
    constexpr double avogadro { 6.0221413e23 }; // Avogadro's number
    constexpr double myGravity { 9.2 };        // m/s^2 -- gravity is light on this planet
    // ... other related constants
}
#endif
