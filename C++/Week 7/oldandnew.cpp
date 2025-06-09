#include <iostream>
#include <cstdlib>

/* Week 7 Ex: Demonstrate old vs uniform initialization. */

int main() {
    //Traditional/Old Initialization
    int myAge = 20;
    //Explicit Initialization
    int anotherAge(30);
    int defaultsToZero(0); //Initializes to 0 but looks like a function (something about that in the video)
    int uniformAge{40}; //So here comes uniform initialization
    int newAndImproved{};

    std::cout << "This is my age: " << myAge << std::endl;
    std::cout << "This is another age: " << anotherAge << std::endl;
    std::cout << "Should be 0 (not-uniform): " << defaultsToZero << std::endl;
    std::cout << "Uniform use: " << uniformAge << std::endl;
    std::cout << "New and improved 0 (uniform): " << newAndImproved << std::endl;
}