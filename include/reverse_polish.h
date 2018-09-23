#ifndef REVERSE_POLISH_H
#define REVERSE_POLISH_H

#include <vector>
#include <cmath>
#include <string>
#include "expression_parser.h"

class ReversePolish {
 public:
    static double evaluate(std::string str);
};

#endif
