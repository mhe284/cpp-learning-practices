#include <cstdlib>
#include <iostream>

/* Week 2 Ex: Implement a custom version of strlen. */

class Solution {
    public:
    int customStrLen(std::string aString) {
        int count = 0;
        char* ptr = &aString[0];
        while (*ptr != '\0') {
            count++;
            ptr++;
        }
        return count;
    }

};

int main () {
    Solution solObj;
    char word1[] = "hello";
    char word2[] = "another word: BLAM! BLAM!";
    int size1 = solObj.customStrLen(word1);
    std::cout << "Size of the word " << word1 << " is: " << size1 << std::endl;
    int size2 = solObj.customStrLen(word2);
    std::cout << "Size of the word " << word2 << " is: " << size2 << std::endl;
    std::cout << "Strlen of the word " << word2<< " is: " << strlen(word2) << std::endl;
}