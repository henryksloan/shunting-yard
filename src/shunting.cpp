#include <iostream>
#include <vector>
#include "expression_parser.h"
#include "reverse_polish.h"

int main(int argc, char **argv) {
    std::string str;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, str);
    std::cout << ReversePolish::evaluate(str) << '\n';

    return 0;
}
