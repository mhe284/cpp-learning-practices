#include <cstdlib>
#include <iostream>


enum class Example {
    A,B,C
};

/* Week 7 Ex: Use enum class for safe enum usage. */

int main() {
    Example value = Example::B; // Safe, scoped enum usage

    switch (value) {
        case Example::A:
            std::cout << "Safe: Yahho!\n";
            break;
        case Example::B:
            std::cout << "Safe: It's a me\n";
            break;
        case Example::C:
            std::cout << "Safe: I'm cooking!\n";
            break;
        default:
            break;
    }
}