#include <iostream>

// Notes: Shows why global variables are dangerous—any function can change them, leading to hidden bugs.

int g_mode; // global variable (zero-initialized). Easy to accidentally change from anywhere.

// doSomething changes global state—side effect!
void doSomething()
{
    g_mode = 2; // sets global g_mode to 2
}

int main()
{
    g_mode = 1; // sets the global g_mode (not a local!)

    doSomething(); // changes g_mode behind your back

    // Programmer still expects g_mode to be 1
    // But doSomething changed it to 2!

    if (g_mode == 1)
    {
        std::cout << "No threat detected.\n";
    }
    else
    {
        std::cout << "Launching nuclear missiles...\n";
    }

    return 0;
}
