#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

/* Week 9 Ex: Protect a counter with mutex in a multithreaded program. */

int counter = 0;
std::mutex counterMutex;

void incrementCounter(int times) {
    for (int i = 0; i < times; ++i) {
        counterMutex.lock();
        ++counter;
        counterMutex.unlock();
    }
}

int main() {
    const int numThreads = 4;
    const int incrementsPerThread = 100;
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(std::thread(incrementCounter, incrementsPerThread));
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}