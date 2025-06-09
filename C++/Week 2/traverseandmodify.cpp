#include <cstdlib>
#include <iostream>

/* Week 2 Ex: Traverse and modify an array using pointers */

int main() {
    constexpr int arraySize = 5;
    int arr[arraySize] = {1,2,3,4,5};

    std::cout << "Previous Array:\n";
    for (int i=0; i < arraySize; i++) {
        std::cout << arr[i] << " "; 
    }

    //Doubles each element in the array
    int* arrPtr = &arr[0];
    while (arrPtr != &arr[arraySize]) {
        *arrPtr *=  2; 
        ++arrPtr;
    }

    std::cout << "\nModified Array:\n";
    for (int i=0; i < arraySize; i++) {
        std::cout << arr[i] << " "; 
    }

    std::cout << std::endl;

}