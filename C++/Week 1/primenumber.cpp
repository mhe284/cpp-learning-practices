#include <cstdlib>
#include <iostream>

/* Week 1 Ex: Print prime numbers between 1 and 100 */
class Solution {
    public: 
    static bool isPrime(const int& n) {
        for (int i=2; i < n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    constexpr int MAX_PRIME = 100;
    int aNum = 1;
    
    std::cout << "Enter the size of the multiplication table (Max 32): ";
    if (!(std::cin >> aNum) || aNum < 1 ) {
        std::cerr << "Invalid input. Please enter a positive integer.\n";
        return EXIT_FAILURE;
    }

    while (aNum < MAX_PRIME) {
        //Check if it's a prime number
        if (Solution::isPrime(aNum)) {
            std::cout << aNum << std::endl;
        }
        aNum++;
    }
}