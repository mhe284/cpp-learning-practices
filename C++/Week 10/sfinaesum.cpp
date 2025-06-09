#include <iostream>
#include <type_traits>

/* Week 10 Ex: Write a sum() function with SFINAE to restrict to arithmetic types. */

template<typename T>
typename std::enable_if<std::is_arithmetic<T>::value, void>::type
printType(T t) {
    //For integral
    if (is_i) {
        std::cout << "Type is an an arithmetic type.\n";

    }
    //For floating number
    else if (std::is_floating_point<T>::value) {
        std::cout << "Type is a floating point.\n";
    }

    else {
        std::cout << "T is not an arithmetic or floating point type.\n";
    }

}
int main() {
    int num1 = 10;
    float num2 = 3.2f;
    double num3 = 32.50;
    bool happy = true;
    char char1 = 'm';
    const std::string greeting = "hello";
    printType(num1);
    printType(num2);
    printType(num3);
    printType(happy);
    printType(char1);
    printType(greeting);

}