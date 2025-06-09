#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

/* Week 3 Ex: Check if two strings are anagrams. */

bool checkAnagram( std::unordered_map<char, int> gMap1, std::unordered_map<char, int> gMap2) {
    for(std::unordered_map<char, int>::iterator mapIt = gMap1.begin();
        mapIt != gMap1.end(); ++mapIt) {
    
        char key = mapIt->first;
        int value = mapIt->second;

        if (gMap2.find(key) == gMap2.end()) {
            return false;
        }

        //Key exists in second map
        else {
            //Must have same # of occurrences
            if ((gMap2[key]) == (gMap2[key])) {
                continue;
            }

            else {
                return false;
            }
        }
    }
    return true;
}

void populateMap(std::unordered_map<char, int>& givenMap,const std::string& givenWord) {
    for (int i=0; i < givenWord.size(); i++) {
        givenMap[givenWord[i]] += 1;
    }
}

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

int main() {
    std::cout << "Type in two words to check if they're an anagram.\n";
    std::string str1, str2;
    std::cin >> str1 >> str2;
    changeFormat(str1);
    changeFormat(str2);

    if (str1.size() != str2.size()) {
        std::cerr << "Not an anagram.\n";
        exit(1);
    }

    std::unordered_map<char, int> word1;
    std::unordered_map<char, int> word2;

    populateMap(word1, str1);
    populateMap(word2, str2);

    if (checkAnagram(word1, word2)) {
        std::cout << "It's an anagram!\n";
    }

    else {
        std::cout << "It's not an anagram.\n";
    }

}