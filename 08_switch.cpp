/*
Notes

- In a switch statement, you can declare variables before the first case label, but you can't initialize them there.
  - e.g. 'int a;' is allowed, but 'int b{5};' is not.
- You can declare variables inside a case, but it's bad practice because their scope can be confusing.
- Initializing a variable inside a case is only allowed if that case is the last one (no subsequent cases).
  - Otherwise, the compiler will complain, since the variable could be skipped by jumping to another case.
- If you need to declare and initialize variables in a case, it's safest to use a block:
    case 1: {
        int x = 5;
        // ...
        break;
    }
- Variables declared before the first case label are in scope for all cases, so be careful with naming and initialization.
- Assignments (not declarations) are always allowed in any case.

Summary:  
Declare variables before the switch or inside a block within a case if you need initialization. Avoid declaring variables directly in cases unless you know what you're doing.

*/

#include <iostream>
int main(){
    switch (1)
    {
        int a; // okay: definition is allowed before the case labels
        int b{ 5 }; // illegal: initialization is not allowed before the case labels

    case 1:
        int y; // okay but bad practice: definition is allowed within a case
        y = 4; // okay: assignment is allowed
        break;

    case 2:
        int z{ 4 }; // illegal: initialization is not allowed if subsequent cases exist
        y = 5; // okay: y was declared above, so we can use it here too
        break;

    case 3:
        break;
    }
}
