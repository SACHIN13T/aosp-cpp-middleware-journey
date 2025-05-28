/*
===========================
Theory: auto and decltype
===========================

- `auto` lets the compiler infer the variable type.
- `decltype` queries the type of an expression at compile time.

Why use them?
- `auto` simplifies code and reduces repetition.
- `decltype` helps write generic code and templates.

Interview Q: What's the difference between `auto` and `decltype`?
A: `auto` deduces the type from initializer; `decltype` gives the type of any expression without evaluating it.

*/

/* --- CODE EXAMPLE --- */

#include <iostream>

using namespace std;

int foo() { return 42; }

int main() {
    auto a = 10;         // int
    decltype(a) b = 20;  // same type as a

    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "foo() returns: " << foo() << "\n";

    return 0;
}

/*
Interview Tip:
- When asked about `auto` and `decltype`, emphasize how they improve readability and enable generic programming.
- Give a small example to demonstrate each.
*/
