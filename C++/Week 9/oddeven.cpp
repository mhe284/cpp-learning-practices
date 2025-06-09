#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <string>

/* Week 9 Ex: Start two threads to print even and odd numbers. */

std::mutex printMutex;

void printOdd(std::vector<int> givenNums) {
    for (int n : givenNums) {
        if ((n % 2) != 0) {
            printMutex.lock();
            std::cout << "Printing odd: " << n << std::endl;
            printMutex.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

void printEven(std::vector<int> givenNums) {
    for (int n : givenNums) {
        if ((n % 2) == 0) {
            printMutex.lock();
            std::cout << "Printing even: " << n << std::endl;
            printMutex.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

int main() {
    std::vector<int> numbers = {1,2,3,4,5,6,7,8,9,10};
    std::thread odd(printOdd, numbers);
    std::thread even(printEven, numbers);
    odd.join();
    even.join();
}