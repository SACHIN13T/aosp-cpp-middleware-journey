#include <iostream>
#include <fstream>
#include <string>

class FileHandler {
public:
    FileHandler(const std::string& filename)
        : file(filename, std::ios::out)
    {
        if (file.is_open()) {
            std::cout << "File opened: " << filename << std::endl;
        } else {
            std::cerr << "Failed to open file: " << filename << std::endl;
        }
    }

    void write(const std::string& text) {
        if (file.is_open()) {
            file << text << std::endl;
        }
    }

    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed." << std::endl;
        }
    }

private:
    std::ofstream file;
};

class DynamicArray {
public:
    DynamicArray(size_t size)
        : size(size), data(new int[size])
    {
        std::cout << "Allocated array of size " << size << std::endl;
    }

    int& operator[](size_t index) {
        return data[index];
    }

    ~DynamicArray() {
        delete[] data;
        std::cout << "Array memory released." << std::endl;
    }

private:
    size_t size;
    int* data;
};

int main() {
    {
        FileHandler fh("example.txt");
        fh.write("Hello, RAII in C++!");
    } // FileHandler destructor called here

    {
        DynamicArray arr(5);
        for (size_t i = 0; i < 5; ++i) {
            arr[i] = static_cast<int>(i * i);
        }
        for (size_t i = 0; i < 5; ++i) {
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        }
    } // DynamicArray destructor called here

    return 0;
}