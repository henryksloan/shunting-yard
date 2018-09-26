#include <iostream>
#include <vector>
#include "expression_parser.h"
#include "reverse_polish.h"

int main(int argc, char **argv) {
    std::string str;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, str);

    try {
        std::cout << ReversePolish::evaluate(str) << '\n';
    }
    catch (const std::invalid_argument &e){
        std::cout << '\'' << str << "\' is not a valid mathematical expression";
    }

    return 0;
}
