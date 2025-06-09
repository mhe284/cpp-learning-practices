#include <iostream>
#include <cstdlib>

/* Week 10 Ex: Write print(...) function using variadic templates. */

void print() {
    std::cout << std::endl;
}

template<typename T, typename... Args>
void print(const T& first, const Args&... rest) {
    std::cout << first;
    if constexpr (sizeof...(rest) > 0) {
        std::cout << " ";
        print(rest...);
    } 
    //Print a new line if it's the last arg
    else {
        std::cout << std::endl;
    }
}

int main() {
    print("Should be able to,", "PRINT A VARIOUS", "number of ARGS!", 123, 4.56);
    print("This", "is", "a", "test.", "for?", "variadic.", "templates!");
    print(1, 2, 3, 4, 5);
}