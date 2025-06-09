#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <set>
#include <vector>


struct ClassInfo {
    double overallAvg;
    std::vector<double> grades;
};

//typedef std::unordered_map<std::string, ClassInfo>;

class Student {
    private:
        std::string name_;
        std::unordered_map <std::string, ClassInfo> classes_; 

        
    public:
        //Constructors
        Student();
        ~Student();
        
        Student(std::string aName);

        //Accessors
        std::string getName() const;
        std::set<std::string> getClasses() const; 
        double getAvgClassGrade(std::string aClass) const;
        double getOverallAvg() const;

        //Modifiers
        void addClass(std::string aClass);
        void addClassGrade(std::string aClass, double aGrade);
};
#endif