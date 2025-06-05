/* 
===========================
Theory: Lambdas in C++
===========================
- Lambdas are anonymous functions that can be defined inline.
- They are often used for algorithms, callbacks, or short-lived operations.
- Syntax: `[capture](parameters) -> return_type { body }`

Capture Modes:
- `[=]` captures variables by value (read-only copy).
- `[&]` captures variables by reference (can modify originals).
- `[this]` captures the current object pointer (for use in member functions).
- `[=, &x]` captures all by value, but `x` by reference.

Mutable Lambdas:
- Add `mutable` to allow modifying captured-by-value variables inside the lambda.

Interview Q: What is a lambda expression in C++?
A: A lambda is a concise way to define an anonymous function object. Useful for short operations, especially in algorithms.

Interview Q: When should I use a lambda?
A: Use lambdas for short, one-time, inline logic like sorting, filtering, or event callbacks.

*/

/* --- CODE EXAMPLE --- */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void basicLambdaDemo() {
    cout << "\n--- Basic Lambda Demo ---\n";

    auto greet = []() { cout << "Hello from lambda!\n"; };
    greet();

    auto add = [](int a, int b) { return a + b; };
    cout << "Add(3, 4): " << add(3, 4) << "\n";
}

void captureModesDemo() {
    cout << "\n--- Capture Modes Demo ---\n";

    int x = 10, y = 20;

    auto byValue = [=]() {
        cout << "Captured by value: x = " << x << ", y = " << y << "\n";
    };

    auto byRef = [&]() {
        x += 5;
        cout << "Captured by reference: x = " << x << "\n";
    };

    byValue();
    byRef();
}

void lambdaInAlgorithm() {
    cout << "\n--- Lambda in Algorithm Demo ---\n";

    vector<int> nums = {1, 5, 3, 9, 7};

    cout << "Original: ";
    for (int n : nums) cout << n << " ";
    cout << "\n";

    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });

    cout << "Sorted descending: ";
    for (int n : nums) cout << n << " ";
    cout << "\n";

    int count = count_if(nums.begin(), nums.end(), [](int val) {
        return val > 5;
    });
    cout << "Count > 5: " << count << "\n";
}

void mutableLambdaDemo() {
    cout << "\n--- Mutable Lambda Demo ---\n";

    int value = 100;

    auto changeCopy = [=]() mutable {
        value += 50;  // modifies internal copy, not original
        cout << "Inside mutable lambda: value = " << value << "\n";
    };

    changeCopy();
    cout << "Outside lambda: value = " << value << "\n";
}

void lambdaAsCallback(function<void()> callback) {
    cout << "\n--- Lambda as Callback Demo ---\n";
    cout << "Inside function before callback\n";
    callback();
    cout << "Inside function after callback\n";
}

int main() {
    basicLambdaDemo();
    captureModesDemo();
    lambdaInAlgorithm();
    mutableLambdaDemo();

    lambdaAsCallback([]() {
        cout << "This is a callback lambda!\n";
    });

    return 0;
}

/*
Interview Tip:
- Prefer lambdas over function objects or verbose callbacks.
- Use `mutable` only when necessary, and understand its side effects.
- Capture by reference with care to avoid dangling references.
- Lambdas are especially powerful with STL algorithms.
*/
