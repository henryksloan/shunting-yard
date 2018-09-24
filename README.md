# shunting-yard
A lightweight implementation of the shunting yard algorithm of mathematical expression parsing, as well as Reverse Polish Notation (RPN) parsing.

According to [Wikipedia](https://en.wikipedia.org/wiki/Shunting-yard_algorithm):
> In computer science, the shunting-yard algorithm is a method for parsing mathematical expressions specified in infix notation. It can produce either a postfix notation string, also known as Reverse Polish notation (RPN), or an abstract syntax tree (AST). The algorithm was invented by Edsger Dijkstra and named the "shunting yard" algorithm because its operation resembles that of a railroad shunting yard. Dijkstra first described the Shunting Yard Algorithm in the Mathematisch Centrum report MR 34/61.

This implementation is enabled to output and evaluate RPN expressions containing parentheses, floating point numbers with double precision, and basic arithmetic operations (^, *, /, +, -).

## Building
Running the makefile will generate an executable in the `bin/` directory.
```
make
```

## To do
* Ensure compliance with, and create tests according to the specifications of [Mozilla's calculator test suite](https://mozilla.github.io/calculator/test/).
* Implement the parsing of function notation, i.e. `sin(3.14)`
* Implement common functions, such as trigonometric functions and logarithms
* Allow the usage of common mathematical constants such as pi and e
### Long term
* Implement symbolic reading and equations
