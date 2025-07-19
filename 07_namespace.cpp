#include <iostream>

// Notes: Namespaces let you group functions/variables to avoid name collisions. Useful for organizing code.

namespace Foo // define a namespace named Foo
{
    // doSomething in Foo: adds two numbers
    int doSomething(int x, int y)
    {
        return x + y;
    }
}

namespace Goo // define a namespace named Goo
{
    // doSomething in Goo: subtracts two numbers
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    // Use the doSomething() from Foo and Goo explicitly
    std::cout << Foo::doSomething(4, 3) << '\n'; // calls Foo::doSomething (4 + 3)
    std::cout << Goo::doSomething(4, 3) << '\n'; // calls Goo::doSomething (4 - 3)
    return 0;
}
