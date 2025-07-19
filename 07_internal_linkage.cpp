// Notes: Internal linkage—static, const, and constexpr at global scope. Only visible in this file.

// Internal global variables definitions:
static int g_x;          // static: internal linkage, not visible outside this file (zero-initialized)
static int g_x{ 1 };     // static: internal linkage, initialized

const int g_y { 2 };     // const: internal linkage by default
constexpr int g_y { 3 }; // constexpr: also internal linkage by default

// Internal function definitions:
static int foo() {};     // static: internal linkage for functions too

int main(){
    return 0;
}
