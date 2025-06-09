#include <iostream>
#include <cstdlib>
#include <string>

/* Week 2 Ex: Swap two variables using value, reference, and pointer. */

void swapByValue(std::string valueA, std::string valueB) {
    std::string temp = valueA;
    valueA = valueB;
    valueB = temp;
}

void swapByReference(std::string& valueA, std::string& valueB) {
    std::string temp = valueA; 
    valueA = valueB;
    valueB = temp;
}

void swapByPointer(std::string* valueA, std::string* valueB) {
    std::string temp = *valueA;
    *valueA = *valueB;
    *valueB = temp;
}


int main() {
    std::string varA = "Monster";
    std::string varB = "Celsius";

    std::cout << "Swapping by value:\n";
    std::cout << "Before:\n";
    std::cout << "VarA: " << varA << "               VarB: " << varB;
    swapByValue(varA, varB);
    std::cout << "\nAfter (Shouldn't have any change.):\n";
    std::cout << "VarA: " << varA << "               VarB: " << varB;

    std::cout << "\n\nSwapping by reference:\n";
    std::cout << "Before:\n";
    std::cout << "VarA: " << varA << "               VarB: " << varB;
    swapByReference(varA, varB);
    std::cout << "\nAfter (Values should be swapped.):\n";
    std::cout << "VarA: " << varA << "               VarB: " << varB;

    std::string* ptrA = &varA;
    std::string* ptrB = &varB;
    std::cout << "\n\nSwapping by pointer:\n";
    std::cout << "Before:\n";
    std::cout << "VarA: " << varA << "               VarB: " << varB;
    swapByPointer(ptrA, ptrB);
    std::cout << "\nAfter (Values should be swapped.):\n";
    std::cout << "VarA: " << varA << "               VarB: " << varB << "\n";
}