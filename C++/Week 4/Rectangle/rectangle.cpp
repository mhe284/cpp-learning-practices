#include "rectangle.h"

int Rectangle::rectangles_ = 0;

Rectangle::Rectangle() {
    rectangles_ += 1;
    length_ = 0;
    width_ = 0;
    area_ = 0;
    perimeter_ = 0;
}

Rectangle::~Rectangle() {

}

Rectangle::Rectangle(double aLength, double aWidth) {
    rectangles_ += 1;
    length_ = aLength;
    width_ = aWidth;
    area_ = length_ * width_;
    perimeter_ = (2 * length_) + (2 * width_);
}

int Rectangle::getRectangles() {
    return rectangles_;
}

double Rectangle::getLength() const {
    return length_;
}

double Rectangle:: getWidth() const {
    return width_;
}


double Rectangle::getArea() const {
    return area_;
}

double Rectangle::getPerimeter() const {
    return perimeter_;
}

void Rectangle::setLength(double aNum) {
    if (aNum <= 0) {
        std::cout << "Invalid length, set to default: 0\n";
        length_ = 0;
    }

    else {
        length_ = aNum;
        //Calc area & perim if width exists
        if (width_ > 0) {
            area_ = length_ * width_;
            perimeter_ = (2 * length_) + (2 * width_);
        }
    }
}

void Rectangle::setWidth(double aNum) {
    if (aNum <= 0) {
        std::cout << "Invalid width, set to default: 0\n";
        width_ = 0;
    }

    else {
        width_ = aNum;
        if (length_ > 0) {
            area_ = length_ * width_; 
            perimeter_ = (2 * length_) + (2 * width_);
        }
    }
}
 