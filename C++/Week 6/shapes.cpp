#include <iostream>
#include <string>
#include <cmath>
#include <vector>

/* Week 6 Ex: Implement a polymorphic Shape class hierarchy. */
/* Week 6 Ex: Store derived class objects in a vector and call virtual functions. */
/* Week 6 Ex: Use override and observe correct/incorrect overrides. */

constexpr double PI = 3.14159265358979323846;

class Shape {
public:
    virtual ~Shape() = default;
    virtual int amtEdges() const {
        std::cout << "Unknown number of edges.\n";
        return -1;
    }
    virtual std::string alwaysEven() const {
        return "Unknown if always even.\n";
    }

    virtual double calcArea() const {
        std::cout << "Unspecified Shape, unable to calculate area.\n";
        return -1;
    }

};

class Rectangle : public Shape {
protected:
    double width_;
    double height_;
public:
    Rectangle(double width, double height) {
        width_ = width;
        height_ = height;
    }

    int amtEdges() const override {
        return 4;
    }
    std::string alwaysEven() const override {
        return "Rectangles don't always have even sides.\n";
    }
    double calcArea() const override {
        return width_ * height_;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {
        width_ = side;
        height_ = side;
    }
    std::string alwaysEven() const override {
        return "Squares always have even sides.\n";
    }
    double calcArea() const override {
        return width_ *  width_;
    }
};

class Circle : public Shape {
protected:
    double radius_;
public:
    Circle(double radius) {
        radius_ = radius;
    }
    int amtEdges() const override {
        return 0;
    }
    std::string alwaysEven() const override {
        return "Circles have no edges.\n";
    }
    double calcArea() const override {
        return PI * radius_ * radius_ ;
    }

};

class Triangle: public Shape {
    protected:
        double base_, height_;
    public: 
    Triangle(double base, double height) {
        base_ = base;
        height_ = height; 
    }
    int amtEdges() const override {
        return 3;
    }

    std::string alwaysEven() const override {
        return "Triangles don't always have even sides.\n";
    }

    double calcArea() const override {
        return 0.5 * base_ * height_;
    }
};

int main() {
     std::vector<Shape*> shapes;
    shapes.push_back(new Square(4.0));
    shapes.push_back(new Rectangle(3.0, 5.0));
    shapes.push_back(new Circle(2.0));
    shapes.push_back(new Triangle(6.0, 2.0));

    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "Shape " << i+1 << " has: " << shapes[i]->amtEdges() << " edges.\n";
        std::cout << shapes[i]->alwaysEven();
        std::cout << "Area: " << shapes[i]->calcArea() << std::endl;
        std::cout << std::endl;
        delete shapes[i];
    }
    return 0;
}