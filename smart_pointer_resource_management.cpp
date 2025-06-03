/*
===========================
Theory: Smart Pointers
===========================
- Smart pointers (`std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`) manage dynamically allocated memory automatically.
- They help prevent memory leaks and dangling pointers by clearly defining ownership semantics.

Why use them?
- `unique_ptr` has sole ownership; resource is deleted when it goes out of scope.
- `shared_ptr` allows shared ownership; deleted when the last reference is gone.
- `weak_ptr` breaks cyclic references used with shared_ptr.

Interview Q: What is the difference between `unique_ptr` and `shared_ptr`?
A: `unique_ptr` enforces exclusive ownership, can't be copied. `shared_ptr` uses reference counting and can be copied or shared among owners.

Interview Q: Why are smart pointers safer than raw pointers?
A: Smart pointers automatically delete the memory they own, preventing leaks and double deletes.
*/

/* --- CODE EXAMPLE --- */

#include <iostream>
#include <memory>  // for smart pointers

using namespace std;

class MyClass {
public:
    MyClass(int val) : value(val) {
        cout << "MyClass(" << value << ") constructed\n";
    }
    ~MyClass() {
        cout << "MyClass(" << value << ") destroyed\n";
    }
    void display() const {
        cout << "Value: " << value << "\n";
    }
private:
    int value;
};

void uniquePtrDemo() {
    cout << "\n--- unique_ptr Demo ---\n";
    unique_ptr<MyClass> ptr1 = make_unique<MyClass>(10);
    ptr1->display();

    // unique_ptr can't be copied, but can be moved
    unique_ptr<MyClass> ptr2 = move(ptr1);
    if (!ptr1)
        cout << "ptr1 is now null after move\n";
    ptr2->display();
}

void sharedPtrDemo() {
    cout << "\n--- shared_ptr Demo ---\n";
    shared_ptr<MyClass> sp1 = make_shared<MyClass>(20);
    {
        shared_ptr<MyClass> sp2 = sp1;  // shared ownership
        cout << "Use count: " << sp1.use_count() << "\n";
        sp2->display();
    }  // sp2 goes out of scope, use count decreases

    cout << "Use count after inner block: " << sp1.use_count() << "\n";
    sp1->display();
}

int main() {
    uniquePtrDemo();
    sharedPtrDemo();

    return 0;
}

/*
Interview Tip:
- Use `unique_ptr` by default for exclusive ownership.
- Use `shared_ptr` only when multiple owners are genuinely required.
- Avoid raw `new`/`delete` in modern C++ — prefer `make_unique` and `make_shared`.
*/
