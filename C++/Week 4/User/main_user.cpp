#include "user.h"
#include <string>

/* Week 4 Ex: Build a User class with password validation logic. */

int main() {
    std::cout << "Hello! Please enter a username:\n";
    std::string username;
    std::cin >> username;
    User aUser;
    aUser.addUser(username);
    //Clear std::cin
    std::cin.clear();
    std::cin.ignore(1000,'\n');

    bool validPassword = false;

    //Validate password
    while (!validPassword) {
        std::cout << "Please enter a password!\n";
        std::string password;
        std::cin >> password;
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cout << "Entered password: " << password << std::endl;
        aUser.addPW(password);
        std::pair<bool, std::string> result;
        result = aUser.validatePW();
        validPassword = result.first;
        std::cout << result.second;

    } 
    
    
}