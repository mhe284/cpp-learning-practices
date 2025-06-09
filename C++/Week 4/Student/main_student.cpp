#include <cstdlib>
#include <iostream>
#include <string>
#include "student.h"

/* Week 4 Ex: Define a Student class with average grade calculation. */

int main() {
    Student student1("Emily");
    student1.addClassGrade("English",90);
    student1.addClassGrade("English",80);
    student1.addClassGrade("English",95);
    student1.addClassGrade("Math", 65);
    student1.addClassGrade("Math", 55);
    student1.addClassGrade("Math", 93);

    double englishGrade = student1.getAvgClassGrade("English");
    std::cout << student1.getName() << " has an English Overall Avg Grade of: " << englishGrade << "\n";
    double mathGrade = student1.getAvgClassGrade("Math");
    std::cout << student1.getName() << " has a Math Overall Avg Grade of: " << mathGrade << "\n";
    double overallAvg = student1.getOverallAvg();
    std::cout << student1.getName() << " has an Overall Avg of: " << overallAvg << "\n";
    
}