#include <iostream>
#include "BigUint.cpp"


int main () {
    string firstNum;
    string secondNum;
    string command;

    std::cin >> firstNum >> command >> secondNum;

    std::cout << firstNum << " " << command << " " << secondNum << " = ";

    if (command == "-")
        std::cout << (BigUint(firstNum) - BigUint(secondNum)).toString() << std::endl;

    else if (command == "x")
        std::cout << (BigUint(firstNum) * BigUint(secondNum)).toString() << std::endl;

    return 0;
}
