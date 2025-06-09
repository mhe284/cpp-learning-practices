#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/* Week 3 Ex:Use std::find_if with custom predicates. */

bool moreThanTen(const std::tuple<std::string, int, double>& student) {
    return std::get<1>(student) > 10;
}

int main() {
    std::vector<std::tuple<std::string,int,double>> studentList = {
        {"Alexa", 12, 95.5},
        {"Lexie", 5, 62.3},
        {"Pamela", 30, 88.2}, 
        {"Diana", 7, 85.5}
    }; 

    std::vector<std::tuple<std::string, int, double>>::iterator it = std::find_if(studentList.begin(), studentList.end(), moreThanTen); 
    if (it != studentList.end()) {
        std::cout << "First student with more than 10 projects is: " 
                  << std::get<0>(*it) << " (Number of Projects:"
                  << std::get<1>(*it) << ") (Overall Average of Projects:"
                  << std::get<2>(*it) << ")\n";
    }
    else {
        std::cout << "No student was found with more than 10 projects.\n";
    }


}