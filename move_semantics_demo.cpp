/*
========================================
Rvalue References & Move Semantics
========================================
- Rvalue references (T&&) allow us to bind to temporary (rvalue) objects.
- Move semantics enable efficient transfer of resources (no deep copy).
- Used to implement move constructors and move assignment operators.
*/

#include <iostream>
#include <vector>
#include <utility>  // for std::move

using namespace std;

class Buffer {
public:
    Buffer(size_t size) : size(size), data(new int[size]) {
        cout << "Constructed: Allocated " << size << " ints\n";
    }

    ~Buffer() {
        delete[] data;
        cout << "Destructed: Freed " << size << " ints\n";
    }

    // Copy constructor
    Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
        std::copy(other.data, other.data + other.size, data);
        cout << "Copy constructed\n";
    }

    // Copy assignment
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + other.size, data);
            cout << "Copy assigned\n";
        }
        return *this;
    }

    // Move constructor
    Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {
        other.data = nullptr;
        other.size = 0;
        cout << "Move constructed\n";
    }

    // Move assignment
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;

            size = other.size;
            data = other.data;

            other.data = nullptr;
            other.size = 0;
            cout << "Move assigned\n";
        }
        return *this;
    }

    void fill(int value) {
        for (size_t i = 0; i < size; ++i)
            data[i] = value;
    }

    void printFirst() const {
        if (data && size > 0)
            cout << "First element: " << data[0] << "\n";
        else
            cout << "Buffer is empty\n";
    }

private:
    size_t size;
    int* data;
};

// Function that takes by value - triggers copy or move
void processBuffer(Buffer b) {
    cout << "Processing buffer...\n";
    b.printFirst();
}

int main() {
    cout << "\n=== Copy vs Move Demo ===\n";

    Buffer buf1(5);
    buf1.fill(42);
    cout << "\n--- Passing lvalue (copy) ---\n";
    processBuffer(buf1);  // Triggers copy

    cout << "\n--- Passing rvalue (move) ---\n";
    processBuffer(Buffer(10));  // Triggers move

    cout << "\n--- Using std::move to force move ---\n";
    processBuffer(std::move(buf1));  // Move from lvalue

    cout << "\n--- Move assignment ---\n";
    Buffer buf2(3);
    buf2 = Buffer(8);  // Move assignment

    return 0;
}

/*
==========================
Interview Highlights:
==========================
- Copy constructor/assignment makes deep copy (slow for large resources).
- Move constructor/assignment transfers ownership (fast).
- Use `std::move()` to explicitly cast lvalue to rvalue.
- Rule of Five: If your class manages a resource, define or delete all of:
  1. Destructor
  2. Copy constructor
  3. Copy assignment
  4. Move constructor
  5. Move assignment
- STL containers (like vector) use move semantics internally for performance.
*/
