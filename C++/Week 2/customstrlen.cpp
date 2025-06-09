#include <cstdlib>
#include <iostream>

/* Week 2 Ex: Implement a custom version of strlen. */

int customStrLen(std::string aString) {
    int count = 0;
    char* ptr = &aString[0];
    while (*ptr != '\0') {
        count++;
        ptr++;
    }
    return count;
}

int main () {
    char word[] = "hello";
    int size = customStrLen(word);
    std::cout << "Size of the word is: " << size << std::endl;
}