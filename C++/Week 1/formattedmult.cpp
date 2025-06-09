#include <iostream>
#include <cstdlib>
#include <iomanip> 

/* Week 1 Ex: Display a formatted multiplication table. */

int main() {
    int size = 0;

    std::cout << "Enter the size of the multiplication table (Max 32): ";
    if (!(std::cin >> size) || size <= 0 || size > 32) {
        std::cerr << "Invalid input.\n";
        return EXIT_FAILURE;
    }

    //Top numbers
    std::cout << "    |";
    for (int i = 1; i <= size; ++i) {
        std::cout << std::setw(4) << i;
    }

    //Top border line 
    std::cout << "\n----";
    for (int i = 1; i <= size; ++i) {
        std::cout << "----";
    }
    std::cout << std::endl;

    // Print table rows
    for (int i = 1; i <= size; ++i) {
        std::cout << std::setw(3) << i << " |";
        for (int j = 1; j <= size; ++j) {
            std::cout << std::setw(4) << i * j;
        }
        std::cout << std::endl;
    }


    return 0;
}