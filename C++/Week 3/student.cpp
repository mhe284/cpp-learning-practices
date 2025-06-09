#include "student.h"

Student::Student() {
    name = "unknown";
    gpa = 3.0;
}

Student::Student(std::string aName, double aGrade) {
    name = aName;
    gpa = aGrade;
}

double Student::getGPA() const {
    return gpa;
}

std::string Student::getName() const {
    return name;
}

bool Student::hasHighGPA(const Student& s) {
    return (s.getGPA() > 3.0);
}
        