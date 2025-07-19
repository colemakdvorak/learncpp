#include <iostream>

// Notes: Nested namespaces using C++17 Foo::Goo syntax. Good for organizing code hierarchically.

namespace Foo::Goo // Goo is a namespace inside the Foo namespace (C++17 style)
{
    // add is in Foo::Goo
    int add(int x, int y)
    {
        return x + y;
    }
}

namespace Foo
{
     void someFcn() {} // This function is in Foo only (not in Foo::Goo)
}

int main()
{
    // Call add from the nested namespace Foo::Goo
    std::cout << Foo::Goo::add(1, 2) << '\n';
    return 0;
}
