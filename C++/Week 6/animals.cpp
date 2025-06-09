#include <iostream>
#include <vector>
#include <string>

/* Week 6 Ex: BUild an Animal class with Dog and Cat subclasses. */

class Animal {
public:
    virtual ~Animal() = default;
    virtual std::string speak() const {
        return "Unspecified animal means * Random Noise *.";
    }
    virtual std::string type() const {
        return "Animal";
    }
};

class Dog : public Animal {
public:
    std::string speak() const override {
        return "Woof!";
    }
    std::string type() const override {
        return "Dog";
    }
};

class Cat : public Animal {
public:
    std::string speak() const override {
        return "Meow!";
    }
    std::string type() const override {
        return "Cat";
    }
};

int main() {
    std::vector<Animal*> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());

    for (const Animal* a : animals) {
        std::cout << "The " << a->type() << " says: " << a->speak() << std::endl;
        delete a;
    }
    
    return 0;
}