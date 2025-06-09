#include <iostream>
#include <cstdlib>
#include <string>
#include <typeinfo>

/* Week 7 Ex: Replace type declarations with auto and decltype. */

int main() {
    std::string aPotato = "I'm a potato.\n";
    auto aTomato = "I'm a tomato.\n";

    int aType = 0;
    decltype(1000 / 10.17) aDeclaredType = 06.28;

    std::cout << aPotato << " of type " << typeid(aPotato).name() <<  std::endl;  // std::basic_string<char, std::char_...
    std::cout << aTomato << " of type " << typeid(aTomato).name() <<  std::endl;  // const* char
    std::cout << aDeclaredType << " of type " << typeid(aDeclaredType).name() << std::endl; // double
}