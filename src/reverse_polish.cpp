#include "reverse_polish.h"
#include <iostream>

double ReversePolish::evaluate(std::string str) {
    std::vector<std::string> out = ExpressionParser::parse_string(str);
    for (auto token : out) {
        std::cout << token << ' ';
    }
    std::cout << '\n';

    std::vector<double> stack;
    while (out.size() > 0) {
        std::cout << "stack: ";
        for (int s : stack) {
            std::cout << s << ' ';
        }
        std::cout << '\n';
        std::string token = out[0];
        if (ExpressionParser::is_number(token)) {
            stack.push_back(std::stod(token));
        }
        else {
            double a = stack.back();
            stack.pop_back();
            double b = stack.back();
            stack.pop_back();
            if (token == "^") {
                stack.push_back(pow(a, b));
            }
            else if (token == "*") {
                stack.push_back(a*b);
            }
            else if (token == "/") {
                stack.push_back(a/b);
            }
            else if (token == "+") {
                stack.push_back(a+b);
            }
            else if (token == "-") {
                stack.push_back(a-b);
            }
        }

        out.erase(out.begin());
    }

    return stack[0];
}
