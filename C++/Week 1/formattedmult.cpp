#include <iostream>
#include <cstdlib>
#include <iomanip> 

/* Week 1 Ex: Display a formatted multiplication table. */
class Solution {
    private: 
    int countDigits(int aNum) {
        int count = 0;
        while (aNum > 0) {
            aNum /= 10;
            count++;
        }
        return count;
    }

    public:
    void printTable(int aSize) {

        //Figure out the largest number digit for spacing
        int largestCount = countDigits(aSize * aSize); 

        //Top numbers
        std::cout << "    |";
        for (int i = 1; i <= aSize; ++i) {
            std::cout << std::setw(largestCount + 1) << i;
            if (i == aSize) {
                std::cout << "\n";
            }
        }

        //Top border line 
        std::cout << "-----";
        for (int i = 1; i <= aSize; ++i) {
            std::cout << std::string(largestCount + 1, '-');
        }
        std::cout << "\n";

        // Print table rows
        for (int i = 1; i <= aSize; ++i) {
            std::cout << std::setw(3) << i << " |";
            for (int j = 1; j <= aSize; ++j) {
                std::cout << std::setw(largestCount + 1) << i * j;
            }
            std::cout << std::endl;
        }
    }
};
int main() {
    int size = 0;

    std::cout << "Enter the size of the multiplication table: ";
    if (!(std::cin >> size) || size <= 0) {
        std::cerr << "Invalid input.\n";
        return EXIT_FAILURE;
    }

    Solution solObj; 
    solObj.printTable(size);

    return 0;
}