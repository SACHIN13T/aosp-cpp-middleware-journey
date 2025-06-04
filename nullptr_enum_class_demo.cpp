/*
===========================
Theory: nullptr and enum class
===========================
- `nullptr` is a type-safe null pointer constant introduced in C++11.
- `enum class` (scoped enumeration) avoids name conflicts and enforces strong typing.

Why use them?
- `nullptr` eliminates ambiguity with overloaded functions and improves type safety.
- `enum class` prevents accidental implicit conversions and provides better scoping.

Interview Q: How is `nullptr` better than `NULL`?
A: `nullptr` is of type `std::nullptr_t` and doesn’t convert to integral types, avoiding ambiguity in overload resolution.

Interview Q: How is `enum class` different from a plain enum?
A: `enum class` keeps the enumerators scoped and prevents implicit conversions to int.
*/

/* --- CODE EXAMPLE --- */

#include <iostream>

using namespace std;

void func(int) {
    cout << "Called func(int)\n";
}

void func(char*) {
    cout << "Called func(char*)\n";
}

enum class Color { Red, Green, Blue };

int main() {
    // nullptr demo
    func(nullptr);  // calls func(char*) — nullptr is a pointer, not an int

    // enum class demo
    Color c = Color::Green;
    if (c == Color::Green) {
        cout << "Color is Green\n";
    }

    // Uncommenting the line below would be an error — scoped enum prevents accidental misuse
    // int x = Color::Red; // Error: cannot convert ‘Color’ to ‘int’ automatically

    return 0;
}

/*
Interview Tip:
- Use `nullptr` to avoid overload ambiguity and bugs related to NULL being an integer.
- Use `enum class` when defining enums to improve code safety and clarity.
*/
