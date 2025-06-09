#include <cstdlib>
#include <map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iterator>

/* Week 3 Ex: Word frequency counter using map. */

void changeFormat(std::string &aWord) {
    std::string newWord;
    char* ptr = &aWord[0];

    while (*ptr != '\0') {
        //If it's an alphabet char
        if (std::isalpha(*(ptr))) {
            char alphabet = std::tolower(*ptr);
            newWord += alphabet;
            ptr++;
            continue;

        }
        //If it's punctuation
        else {
            //Remove only ending punctuation by checking null term
            if (*(ptr + 1) == '\0') {
                ptr++;
                continue;
            }

            //Add punctuation and move on
            else {
                //Only add if it's an apostrophe
                if ((*ptr) == '\'') {
                    newWord += '\'';
                    ptr++;
                }

                else {
                    ptr++;
                }
            }

        }

    }

    aWord = newWord;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Invalid number of inputs.\n";
        exit(1);
    }
    //Attempts to open input file stream
    std::ifstream in_str(argv[1]);

    if (!in_str.good()) {
        std::cerr << "Unable to open " << argv[1] << " txt...\n";
        exit(1);
    }


    std::map<std::string, int> wordMap;

    //While the file isn't finished being read through
    while (!in_str.eof()) {
        std::string word;
        in_str >> word;
        changeFormat(word);

        //Add to map for frequency count
        wordMap[word] += 1;
    }

    std::cout << "What word do you want to check the frequency of in: " << argv[1] << "?\n";
    std::string input;
    std::cin >> input;

    changeFormat(input);

    std::map<std::string, int>::iterator mapIt = wordMap.find(input);
    if (mapIt != wordMap.end()) {
        if (mapIt->second == 1) {
            std::cout << "The word: " << mapIt->first << " appeared " << mapIt->second << " time.\n";
        }
        else {
            std::cout << "The word: " << mapIt->first << " appeared " << mapIt->second << " amount of times.\n";
        }
    }
    else {
        std::cout << "This word was not found.\n";
    }

}