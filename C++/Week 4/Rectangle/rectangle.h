#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <cstdlib>
#include <iostream>

class Rectangle {
    private:
        static int rectangles_;
        double length_;
        double width_;
        double area_;
        double perimeter_;

    public:
        Rectangle();
        ~Rectangle();
        Rectangle(double aLength, double aWidth);

        //Accessors
        static int getRectangles();
        double getLength() const;
        double getWidth() const;
        double getArea() const;
        double getPerimeter() const;

        //Modifiers
        void setLength(double aNum);
        void setWidth(double aNum);

};
#endif