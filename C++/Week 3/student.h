#ifndef STUDENT_H
#define STUDENT_H
#include <cstdlib>
#include <iostream>

class Student {
    private:
        std::string name;
        double gpa;

    public:

        Student(); 
        Student(std::string aName, double aGrade);

        //Accessors
        double getGPA() const;
        std::string getName() const;

        static bool hasHighGPA(const Student& s);
        
        //Overload < operator
        bool operator< (const Student& obj) const {
            return gpa < obj.gpa;
        }
};

#endif