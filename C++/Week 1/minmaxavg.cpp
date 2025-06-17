#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

/* Week 1 Ex: Read a list of numbers and compute min, max, average. */
class Solution {
    public:
    static std::tuple<int, int, int> minMaxAvg(std::string givenInput) {
        std::vector<int> allnumbers;
        std::string number;
        int average = 0;
        for (char c : givenInput) {
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
        std::tuple<int,int,int> result = std::make_tuple(allnumbers[0], allnumbers[allnumbers.size()-1], average/allnumbers.size());
        return result;
    }
};

int main() {
    std::cout << "Please input a list of numbers in the format: #,#,#,#,#,#. \n";
    std::string input;
    std::getline (std::cin, input);
    std::tuple<int,int, int> result = Solution::minMaxAvg(input);
    std::cout << "Min: " << std::get<0>(result) << "\n";
    std::cout << "Max: " << std::get<1>(result) << "\n";
    std::cout << "Avg: " << std::get<2>(result) << "\n";

}