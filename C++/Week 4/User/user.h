#ifndef USER_H
#define USER_H
#include <cstdlib>
#include <iostream>

class User {
    private:
        std::string name_;
        std::string password_;
    public:
        User();
        ~User();

        std::pair<bool, std::string> validatePW();
        void addUser(std::string aUsername);
        void addPW(std::string aPassword);


};

#endif