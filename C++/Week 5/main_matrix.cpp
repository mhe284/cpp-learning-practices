#include <iostream>
#include <cassert>
#include "Matrix.h"

/* Week 5 Ex: Create a Matrix class with proper copy and destructor. */
/* Week 5 Ex: Add move semantics and test std::move. */

int main() {
    // Default constructor
    Matrix m1;
    assert(m1.num_rows() == 0 && m1.num_cols() == 0);

    // Copy constructor
    Matrix m2(3,4,0);
    assert(m2.num_rows() == 3 && m2.num_cols() == 4);

    Matrix m2_copy(m2);
    assert(m2_copy.num_rows() == 3 && m2_copy.num_cols() == 4);
    m2_copy.set(1,1,27);
    double d0;
    assert(m2.get(1,1,d0));
    assert(d0 == 0.0);
    assert(m2_copy.get(1,1,d0));
    assert(d0 == 27);

    // Equality and Inequality
    Matrix m3;
    assert(m1 == m3);
    assert(m1 != m2);

    // Printing
    std::cout << "Empty matrix:" << std::endl;
    std::cout << m1 << std::endl;

    std::cout << "Zeroed 3x4 matrix:" << std::endl;
    std::cout << m2 << std::endl;

    std::cout << "One after the other:" << std::endl;
    std::cout << m1 << m2 << std::endl;

    // Set & get
    Matrix m5(4,4,2);
    Matrix m6(4,4,12);
    assert(m6.set(2,1,7));
    assert(m6.set(3,3,11));
    double d1;
    assert(m6.get(2,1,d1));
    assert(d1 == 7);

    // Addition
    std::cout << "Adding m5 and m6:" << std::endl;
    std::cout << m5 << m6 << std::endl;

    Matrix m7;
    m7 = m5;
    Matrix m8(m5);
    assert(m7 == m8);

    assert(m7.add(m6));
    std::cout << "The result of m5 + m6:" << std::endl;
    std::cout << m7 << std::endl;

    double* r1 = nullptr;
    r1 = m7.get_row(2);
    assert(r1[0] == 14 && r1[1] == 9);
    delete [] r1;

    // More matrix tests
    Matrix m9(3,3,0); 
    m9.set(0,0,1); 
    m9.set(0,1,2);
    m9.set(0,2,3);
    m9.set(1,0,4);
    m9.set(1,1,5);
    m9.set(1,2,6);
    m9.set(2,0,7);
    m9.set(2,1,8);
    m9.set(2,2,9); 
    std::cout << "3x3 matrix filled and set:" << std::endl;
    m9.print(); 

    std::cout << std::endl; 

    Matrix m10(m9); 
    std::cout << "Copy of previous matrix:" << std::endl; 
    m10.print();

    std::cout << std::endl;

    // Assignment Operator
    Matrix m11(2,2,0); 
    m11.set(0,0,1);
    m11.set(0,1,2);
    m11.set(1,0,3);
    m11.set(1,1,4); 
    std::cout << "2x2 matrix before assignment:" << std::endl; 
    m11.print(); 

    Matrix m12(2,3,0);
    m12.set(0,0,4);
    m12.set(0,1,16);
    m12.set(0,2,25);
    m12.set(1,0,14);
    m12.set(1,1,3.4);
    m12.set(1,2,3.64159); 

    std::cout << std::endl;

    std::cout << "2x3 matrix to assign from:" << std::endl;
    m12.print(); 

    std::cout << std::endl; 

    std::cout << "2x2 matrix after assignment:" << std::endl;
    m11 = m12; 
    m11.print();

    std::cout << std::endl;

    // Move Constructor Test
    Matrix m13(2, 2, 5.0);
    m13.set(0, 1, 10.0);
    std::cout << "Original m13 before move:" << std::endl;
    m13.print();

    Matrix m14(std::move(m13)); // Move constructor
    std::cout << "m14 after move construction from m13:" << std::endl;
    m14.print();
    std::cout << "m13 after being moved-from (should be empty):" << std::endl;
    m13.print();

    // Move Assignment Test
    Matrix m15(2, 2, 1.0);
    m15.set(1, 1, 9.0);
    std::cout << "Original m15 before move assignment:" << std::endl;
    m15.print();

    m15 = std::move(m14); // Move assignment
    std::cout << "m15 after move assignment from m14:" << std::endl;
    m15.print();
    std::cout << "m14 after being moved-from (should be empty):" << std::endl;
    m14.print();

    std::cout << "Completed all matrix tests." << std::endl;
    return 0;
}