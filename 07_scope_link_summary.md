# Scope, Duration, and Linkage Summary

This summary covers the key concepts of scope, duration, and linkage in C++. These concepts determine where and how identifiers (variables, functions, types) can be accessed, how long they exist, and whether declarations in different places refer to the same entity.

---

## Scope

- **Scope** determines where an identifier can be accessed in the source code.

**Block (local) scope:**
- Accessible from the point of declaration to the end of the block (including nested blocks).
- Applies to: local variables, function parameters, types (enums, classes) declared inside a block.

**Global scope:**
- Accessible from the point of declaration to the end of the file.
- Applies to: global variables, functions, types declared in a namespace or global scope.

---

## Duration

- **Duration** determines when a variable is created and destroyed.

**Automatic duration:**
- Created at definition, destroyed when the block is exited.
- Applies to: local variables, function parameters.

**Static duration:**
- Created when the program begins, destroyed when it ends.
- Applies to: global variables, static local variables.

**Dynamic duration:**
- Created and destroyed by programmer request (e.g., with `new`/`delete`).
- Applies to: dynamically allocated variables.

---

## Linkage

- **Linkage** determines if declarations in different scopes refer to the same entity.

**No linkage:**
- Each declaration refers to a unique object/function.
- Applies to: local variables, types declared inside a block.

**Internal linkage:**
- Declarations in the same translation unit refer to the same entity.
- Applies to: static global variables, static functions, const global variables, unnamed namespaces.

**External linkage:**
- Declarations in the entire program refer to the same entity.
- Applies to: non-static functions, non-const global variables, extern/inline const global variables, namespaces.

> **Note:** Functions have external linkage by default. Use `static` to make them internal.

---

## Variable Scope, Duration, and Linkage Table

| Type                                 | Example                        | Scope   | Duration   | Linkage   | Notes                        |
|-------------------------------------- |------------------------------- |---------|------------|-----------|----------------------------- |
| Local variable                        | `int x;`                      | Block   | Automatic  | None      |                             |
| Static local variable                 | `static int s_x;`             | Block   | Static     | None      |                             |
| Dynamic local variable                | `int* x { new int{} };`       | Block   | Dynamic    | None      |                             |
| Function parameter                    | `void foo(int x)`             | Block   | Automatic  | None      |                             |
| Internal non-const global variable    | `static int g_x;`             | Global  | Static     | Internal  | Initialized or uninitialized|
| External non-const global variable    | `int g_x;`                    | Global  | Static     | External  | Initialized or uninitialized|
| Inline non-const global variable      | `inline int g_x;`             | Global  | Static     | External  | C++17, initialized or not   |
| Internal constant global variable     | `constexpr int g_x { 1 };`    | Global  | Static     | Internal  | Must be initialized         |
| External constant global variable     | `extern const int g_x { 1 };` | Global  | Static     | External  | Must be initialized         |
| Inline constant global variable       | `inline constexpr int g_x { 1 };` | Global | Static | External  | C++17, must be initialized  |

---

## Forward Declaration Summary

| Type                        | Example                    | Notes                                         |
|-----------------------------|----------------------------|-----------------------------------------------|
| Function forward declaration| `void foo(int x);`         | Prototype only, no function body              |
| Non-const variable forward  | `extern int g_x;`          | Must be uninitialized                         |
| Const variable forward      | `extern const int g_x;`    | Must be uninitialized                         |
| Constexpr variable forward  | `extern constexpr int g_x;`| Not allowed (constexpr can't be forward declared) |

> A `constexpr` variable (implicitly const) can be forward declared as `extern const`. When accessed this way, it's considered `const` (not `constexpr`).

---

## Storage Class Specifiers

- The `static` and `extern` keywords (storage class specifiers) set storage duration and linkage.
- C++ supports 4 active storage class specifiers:

| Specifier      | Meaning                                         | Note                                               |
|----------------|------------------------------------------------|----------------------------------------------------|
| `extern`       | static (or thread_local) duration, external linkage |                                                    |
| `static`       | static (or thread_local) duration, internal linkage |                                                    |
| `thread_local` | thread storage duration                         |                                                    |
| `mutable`      | object can be modified even if class is const   |                                                    |
| `auto`         | automatic duration                              | Deprecated in C++11                                |
| `register`     | automatic duration, hint for register storage   | Deprecated in C++17                                |

---
