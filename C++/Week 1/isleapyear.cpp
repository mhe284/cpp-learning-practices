#include <cstdlib>
#include <iostream>
#include <string>

/* Week 2 Ex: Determine if a given year is a leap year. */

class Solution {
    public:
    static bool isLeapYear(const int aYear) {
        //If it's a century year
        if (aYear % 100 == 0) {
            return ( aYear % 400 == 0 ? true : false);
        }
        else {
            return ( aYear % 4 == 0 ? true: false);
        }
    }
};


int main() {
    std::cout << "Please insert a year: " << "\n";
    std::string year;
    std::getline(std::cin, year);
    int num = std::stoi(year);

    if (Solution::isLeapYear(num)) {
        std::cout << year << " is a Leap Year!\n";
    }

    else {
        std::cout << year << " is NOT a Leap Year!\n";
    }

}