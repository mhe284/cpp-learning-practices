#include <cstdlib>
#include <iostream>
#include <algorithm>

/* Week 2 Ex: Reverse an array of integers. */

int main() {
    const int size = 6;
    int nums[size] = {1,2,3,4,5,6};

    std::cout << "Original Array: " << std::endl;
    for (int i=0; i < size; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    int* ptr1 = &nums[0];
    int* ptr2 = &nums[size-1];

    while (ptr1 <= ptr2) {
        //Using value, reference, and pointers
        int heldnum = *ptr1; 
        *ptr1 = *ptr2;
        *ptr2 = heldnum;
        // Could also just use this: std::swap(*ptr1, *ptr2);
        if (&ptr1 == &ptr2) {
            break;
        }
        ptr1++;
        ptr2--;
    }

    std::cout << "Reversed array: " << std::endl;
    for (int j = 0; j < size; j++) {
        std::cout << nums[j] << " ";
    }
    std::cout << std::endl;
}