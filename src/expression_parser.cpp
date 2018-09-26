#include "expression_parser.h"

// Map each operator to a pair (presedence, right associativity)
const std::map<char, std::pair<int, bool>> ExpressionParser::ops = {
    {'~', std::pair<int, bool>(5, true)},
    {'^', std::pair<int, bool>(4, true)},
    {'*', std::pair<int, bool>(3, false)}, {'/', std::pair<int, bool>(3, false)},
    {'+', std::pair<int, bool>(2, false)}, {'-', std::pair<int, bool>(2, false)}
};

bool ExpressionParser::is_number(const std::string str) {
    try {
        std::stod(str);
    }
    catch (std::invalid_argument) {
        return false;
    }

    return true;
}

std::vector<std::string> ExpressionParser::tokenize(std::string str) {
    // Remove whitespace
    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());

    // For each character in the string, check if it's a digit or decimal point
    // If so, push it into an accumulator string, thereby concatinating sequential digits
    // Otherwise, push the completed integer if there is one in the string
    // Finally, push the non-numerical character to the token as an operator
    std::string temp = "";
    std::vector<std::string> tokens;
    for (auto c : str) {
        if (isdigit(c) || c == '.') {
            temp += c;
            continue;
        }

        if (temp != "") {
            tokens.push_back(temp);
            temp = "";
        }
        tokens.push_back(std::string(1, c));
    }

    // If there is a number left in the accumulator string, push it
    if (temp != "") {
        tokens.push_back(temp);
    }

    return tokens;
}

std::vector<std::string> ExpressionParser::parse_string(std::string str) {
    std::vector<std::string> tokens = tokenize(str);
    std::vector<std::string> out_queue;
    std::vector<char> op_stack;
    for (int i = 0; i < tokens.size(); i++) {
        std::string token = tokens[i];
        if (is_number(token)) {
            out_queue.push_back(token);
            continue;
        }

        // A '-' is a unary operator if it is the first symbol in the input, or if it immediately follows an operator or left parenthesis
        if (token == "-" &&
            (i == 0
             || (tokens[i-1] == "(")
             || (ExpressionParser::ops.find(tokens[i-1][0]) != ExpressionParser::ops.end()))) {
            token = "~";
        }

        // Handle operators
        if (ExpressionParser::ops.find(token[0]) != ExpressionParser::ops.end()) {
            // If the stack is empty or a unary operator is found, just push it and move on
            if (op_stack.size() == 0 || token == "~") {
                op_stack.push_back(token[0]);
                continue;
            }
            std::pair<int, bool> op = ExpressionParser::ops.at(token[0]);
            char top = op_stack.back();
            // Selectively pop from the operator stack based on precedence
            while ((top != '\0') && (top != '(') &&
                   ((ExpressionParser::ops.at(top).first > op.first)
                || (ExpressionParser::ops.at(top).second && (ExpressionParser::ops.at(top).first == op.first)))) {
                out_queue.push_back(std::string(1, op_stack.back()));
                op_stack.pop_back();
                top = op_stack.back();
            }
            op_stack.push_back(token[0]);
        }

        if (token[0] == '(') {
            op_stack.push_back(token[0]);
        }
        else if (token[0] == ')') {
           char top = op_stack.back();
           while (top != '(') {
               out_queue.push_back(std::string(1, op_stack.back()));
               op_stack.pop_back();
               top = op_stack.back();
           }
           op_stack.pop_back();
        }
    }

    while (!op_stack.empty()) {
        out_queue.push_back(std::string(1, op_stack.back()));
        op_stack.pop_back();
    }

    return out_queue;
}
