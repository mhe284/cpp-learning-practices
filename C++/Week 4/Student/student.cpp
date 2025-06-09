#include "student.h"

//Constructors

Student::Student() {
    name_ = "unknown";
    //Maybe change to -1 and don't count when doing overall avgs... * * *
    classes_["English"] = ClassInfo{0.0,{}};
    classes_["Math"] = ClassInfo{0.0,{}};
}

Student::Student(std::string aName) {
    name_ = aName;
    classes_["English"] = ClassInfo{0.0,{}};
    classes_["Math"] = ClassInfo{0.0,{}};
}

Student::~Student() {

}

//Accessors

std::string Student::getName() const {
    //Not safe
    return name_;
}

std::set<std::string> Student::getClasses() const {
    std::set<std::string> classesList;
    for (const std::pair<std::string, ClassInfo>& keyVal : classes_) {
        classesList.insert(keyVal.first);
    }
    return classesList;
}

double Student::getAvgClassGrade(std::string aClass) const {
    std::unordered_map<std::string, ClassInfo>::const_iterator mapIt = classes_.find(aClass);
    if (mapIt == classes_.end()) {
        return -1;
    }

    else {
        ClassInfo givenClass = mapIt->second;
        return givenClass.overallAvg;
    }
}

double Student::getOverallAvg() const {
    int numClasses = 0;
    double totalAvgs = 0.0;
    for (const std::pair<std::string, ClassInfo>& keyVal : classes_) {
        numClasses += 1;
        ClassInfo aClass = keyVal.second;
        double anAvg = aClass.overallAvg;
        totalAvgs += anAvg;
    }
    return totalAvgs / numClasses;
}

//Modifiers

void Student::addClass(std::string aClass) {
    classes_[aClass] = {0.0,{}};
}

void Student::addClassGrade(std::string aClass, double aGrade) {
    ClassInfo& classInfo = classes_[aClass];
    (classInfo.grades).push_back(aGrade);
    std::vector<double> allGrades = (classInfo.grades);
    double total = 0;
    for (double grade : allGrades) {
        total += grade;
    }
    double result = total / allGrades.size();
    classInfo.overallAvg = result;
}