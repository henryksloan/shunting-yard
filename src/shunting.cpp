#include <iostream>
#include <vector>
#include "expression_parser.h"
#include "reverse_polish.h"

int main(int argc, char **argv) {
    std::string str;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, str);

    std::vector<std::string> out = ExpressionParser::parse_string(str);
    std::cout << "Parsed to: ";
    for (auto token : out) {
        std::cout << token << ' ';
    }
    std::cout << '\n';

    std::cout << ReversePolish::evaluate(str) << '\n';

    return 0;
}
