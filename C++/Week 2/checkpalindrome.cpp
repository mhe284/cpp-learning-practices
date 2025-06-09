#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>

/* Week 2 Ex: Check if a string is a palindrome. */

void changeFormat(std::string& aWord) {

    std::string withoutSpaces;
    for (int i=0; i < aWord.size(); i++) {
        if (aWord[i] != ' ') {
            char lowered = std::tolower(aWord[i]);
            withoutSpaces += lowered;
        }
    }
    aWord = withoutSpaces;
}

bool checkPalindrome(std::string aWord) {
    char* leftPtr = &aWord[0];
    char* rightPtr = &aWord[aWord.size()-1];

    while (leftPtr <= rightPtr) {
        //Check that they're the same value
        if (*leftPtr != *rightPtr) {
            return false;
        }
        leftPtr++;
        rightPtr--;
    }

    return true;
}

int main() {
    std::cout << "Insert a word to check if it's a palindrome" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    changeFormat(input);
    bool result = checkPalindrome(input);
    
    if (result) { std::cout << "It's a palindrome!\n"; }
    else { std::cout << "Not a palindrome...\n"; }

}