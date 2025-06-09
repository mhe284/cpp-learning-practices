#include <iostream>
#include <cstdlib>
#include "rectangle.h"

/* Week 4 Ex: Create a Rectangle class with area and perimeter. */
/* Week 4 Ex: Track number of object instances with a static counter. */

int main() {
    Rectangle aRectangle(3, 4);
    std::cout << "The length of the rectangle is: " << aRectangle.getLength()
    << " and the width is: " << aRectangle.getWidth() << std::endl;
    std::cout << "The area of the rectangle is: " << aRectangle.getArea() << " and the perimeter is: " << aRectangle.getPerimeter() << std::endl;

    Rectangle rect1(2, 1);
    Rectangle rect2(3,1);
    Rectangle rect3(83,20); 

    std::cout << std::endl;
    std::cout << "The total number of rectangles created is: " << Rectangle::getRectangles() << std::endl;
    
}