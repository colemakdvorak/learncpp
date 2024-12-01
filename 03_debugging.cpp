#include <iostream>
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

#define ENABLE_DEBUG

int foo() 
{
#ifdef ENABLE_DEBUG
std::cerr << "DEBUG: foo invoked \n";
#endif

    return -1;
}

void printValue(int value) {
    std::cout << value << '\n';
}

int main() 
{
#ifdef ENABLE_DEBUG
std::cerr << "DEBUG: main start \n";
#endif
    plog::init(plog::debug, "Logfile.txt");
    PLOGD << "main() called";
    std::cout << foo() << '\n';
    printValue(10);
    return 0;
}
