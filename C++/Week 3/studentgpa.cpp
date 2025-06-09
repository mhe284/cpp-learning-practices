#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "student.h"

/* Week 3 Ex: Sort Student objects in a vector by GPA. */
/* Week 3 Ex:Use std::find_if with custom predicates. */

int main() {
    Student student1;
    Student student2("Elizabeth", 3.27);
    Student student3("Ramira", 2.1);
    Student student4("Duckalo", 4.0);
    Student student5("Yamirez", 2.5);

    std::vector<Student> students = {student1, student2, student3, student4, student5};
    std::sort(students.begin(), students.end());

    for (Student s : students) {
        std::cout << s.getName() << " with GPA: " << s.getGPA() << std::endl;
    }

    std::vector<Student>::iterator studentIt = std::find_if(students.begin(), students.end(), Student::hasHighGPA);
    std::string name = studentIt->getName();
    double gpa = studentIt->getGPA();

    std::cout << "Found student : " << name << " with GPA: " << gpa << std::endl;
}