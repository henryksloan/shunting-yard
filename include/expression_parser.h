#ifndef EXPRESSION_PARSER_H
#define EXPRESSION_PARSER_H

#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <utility>
#include <iostream>

// A pure static class defining functions for parsing mathematical expressions into RPN
class ExpressionParser {
 public:
    // Parses a given mathematical expression
    static std::vector<std::string> parse_string(std::string str);
	static bool is_number(std::string str);

 private:
    // Enforce pure static by privatizing contructor
    ExpressionParser() {}

    // Tokenizes string into operators and arbitrary-digit numbers
	static std::vector<std::string> tokenize(const std::string str);

    // Map each operator to a pair (presedence, right associativity)
    const static std::map<char, std::pair<int, bool>> ops;
};

#endif
