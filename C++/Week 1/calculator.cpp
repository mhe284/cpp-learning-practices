#include <cstdlib>
#include <iostream>

/* Week 1 Ex: Implement a calculator for basic arithmetic operations. */

int main() {
    std::cout << "First number:\n";
    int num1 = 0;
    std::cin >> num1; 
    if (std::cin.fail()) { std::cout << "Invalid input.\n"; return EXIT_FAILURE; }

    //Clear std::cin
    std::cin.clear();
    std::cin.ignore(1000,'\n');

    std::cout << "Second number:\n";
    int num2 = 0;
    std::cin >> num2;
    if (std::cin.fail()) { std::cout << "Invalid input.\n"; return EXIT_FAILURE; }

    std::cin.clear();
    std::cin.ignore(1000,'\n');
    

    std::cout << "What operation would you like to perform? (Please input: '+', '-','*','/','%')" << std::endl;
    char operation;
    std::cin >> operation;

    switch(operation) {
        default: 
            std::cout << "Invalid operation.\n";
            break;
        case '+':
            std::cout << "Result: " << num1 + num2 << "\n";
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << "\n";
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << "\n";
            break;
        case '/': 
            std::cout << "Result: " << num1 / num2 << "\n";
            break;
        case '%': 
            std::cout << "Result: " << num1 % num2 << "\n";
            break;
    }

}