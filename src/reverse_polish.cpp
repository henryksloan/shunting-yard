#include "reverse_polish.h"
#include <iostream>

double ReversePolish::evaluate(std::string str) {
    std::vector<std::string> out = ExpressionParser::parse_string(str);

    std::vector<double> stack;
    while (out.size() > 0) {
        std::string token = out[0];
        if (ExpressionParser::is_number(token)) {
            stack.push_back(std::stod(token));
        }
        else {
            if (token == "~") {
                if (stack.size() < 1) {
                    throw std::invalid_argument(str);
                }
                double a = stack.back();
                stack.pop_back();
                stack.push_back(-a);
                
                out.erase(out.begin());
                continue;
            }

            if (stack.size() < 2) {
                throw std::invalid_argument(str);
            }
            double a = stack.back();
            stack.pop_back();
            double b = stack.back();
            stack.pop_back();
            if (token == "^") {
                stack.push_back(pow(b, a));
            }
            else if (token == "*") {
                stack.push_back(a*b);
            }
            else if (token == "/") {
                stack.push_back(b/a);
            }
            else if (token == "+") {
                stack.push_back(a+b);
            }
            else if (token == "-") {
                stack.push_back(b-a);
            }
        }

        out.erase(out.begin());
    }

    return stack[0];
}
