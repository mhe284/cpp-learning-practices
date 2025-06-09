#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/* Week 8 Ex: Use lambda in std::sort to sort by custom field. */

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35}
    };

    // Sort by age using a lambda
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.age < b.age;
    });

    for (const auto& person : people) {
        std::cout << person.name << ": " << person.age << std::endl;
    }
}