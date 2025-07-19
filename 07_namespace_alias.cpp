#include <iostream>

// Notes: Namespace aliasing—lets you create a shortcut or versioned name for a namespace.

namespace Foo::Goo
{
}

namespace V2
{
    int add(int x, int y)
    {
        return x + y;
    }
}

int main()
{
    // Namespace alias: Active now refers to V2 (could swap to another version easily)
    namespace Active = V2;

    std::cout << Active::add(1, 2) << '\n'; // Can use Active::add instead of V2::add

    return 0;
}
