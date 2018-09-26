#ifndef REVERSE_POLISH_H
#define REVERSE_POLISH_H

#include <vector>
#include <cmath>
#include <string>
#include "expression_parser.h"

// Parses and evaluates infix strings
class ReversePolish {
 public:
    // Parses a given infix notation string to RPN, and evaluate it
    static double evaluate(std::string str);
};

#endif
