#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/* Week 1 Ex: Read a list of numbers and compute min, max, average. */

int main() {
    std::cout << "Please input a list of numbers in the format: #,#,#,#,#,#. \n";
    std::vector<int> allnumbers;
    std::string input;
    std::getline (std::cin, input);
    std::string number;
    int average = 0;
    for (char c : input) {
        if (isdigit(c)) {
            number += c;
        }

        else {
            int num = std::stoi(number);
            number = "";
            average += num;
            allnumbers.push_back(num);
        }
    }

    std::sort(allnumbers.begin(), allnumbers.end());
    std::cout << "Min:" << allnumbers[0] << " Max:" << allnumbers[allnumbers.size()-1] << " Avg:" << average / allnumbers.size() << std::endl;

}