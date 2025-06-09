#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

/* Week 10 Ex: Implement a generic max() function. */

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "max(3, 7): " << max(3, 7) << std::endl;
    std::cout << "max(2.5, 1.9): " << max(2.5, 1.9) << std::endl;
    std::cout << "max('a', 'z'): " << max('a', 'z') << std::endl;
    std::cout << "max(std::string(\"cat\"), std::string(\"dog\")): "
              << max(std::string("cat"), std::string("dog")) << std::endl;
}