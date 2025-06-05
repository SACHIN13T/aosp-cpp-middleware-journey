/*
    STL Containers & Algorithms - Interview Notes

    - STL (Standard Template Library) provides generic containers (vector, map, etc.) and algorithms (for_each, transform, etc.).
    - Containers like vector and map manage memory and provide efficient access and modification.
    - Algorithms work with iterators, making code reusable and expressive.
    - Lambdas allow inline, anonymous functions, making algorithms cleaner and more flexible.

    Common Interview Points:
    - vector: Dynamic array, contiguous memory, fast random access, slow insert/erase except at end.
    - map: Key-value pairs, sorted by key, log(n) lookup, insert, erase.
    - for_each: Applies a function/lambda to each element in a range.
    - transform: Applies a function to a range and writes the result to another range.
    - Lambdas: Useful for custom logic in algorithms, can capture variables by value/reference.

    Example below demonstrates these concepts.
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

int main() {
    // Using std::vector and std::for_each with lambda
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Original numbers: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n << " ";
    });
    std::cout << std::endl;

    // Using std::transform with lambda to square each number
    std::vector<int> squares(numbers.size());
    std::transform(numbers.begin(), numbers.end(), squares.begin(), [](int n) {
        return n * n;
    });

    std::cout << "Squared numbers: ";
    for (const auto& n : squares) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Using std::map and std::for_each with lambda
    std::map<std::string, int> ageMap = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 28}
    };

    std::cout << "Ages:" << std::endl;
    std::for_each(ageMap.begin(), ageMap.end(), [](const std::pair<std::string, int>& entry) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    });

    return 0;
}