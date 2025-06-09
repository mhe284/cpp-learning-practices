#include "user.h"
#include <string> 

User::User() {
    name_ = "unknown";
    password_ = "default";
}

User::~User() {

}


std::pair<bool, std::string> User::validatePW() {
    bool has_digit = false;
    bool has_alpha = false;
    bool has_special = false;
    std::pair<bool, std::string> response;
    response.first = false;

    //Digit, letter, and special character check
    for (int i=0; i < password_.size(); i++) {
        //If it's an alphabet
        if (isalpha(password_[i])) {
            //std::cout << "Has a letter.\n";
            has_alpha = true;
        }
        //If it's a digit
        else {
            //If it's a special char
            if (isdigit(password_[i])) {
                //std::cout << "Has a number.\n";
                has_digit = true;
            }
            else {
                //std::cout << "Has special.\n";  
                has_special = true;
            }

        }
    }

    if (!has_digit) { response.second += "Must contain a number.\n"; }
    if (!has_alpha) { response.second += "Must contain a letter.\n";}
    if (!has_special) { response.second += "Must contain a special character.\n";}
    if (has_digit && has_alpha && has_special) {response.first = true; response.second = "Great Password!\n";}
    return response;
}

void User::addUser(std::string aUsername) {
    name_ = aUsername;
}

void User::addPW(std::string aPassword) {
    password_ = aPassword;
}
