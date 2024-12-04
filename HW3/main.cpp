#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

// Evaluates a Reverse Polish Notation expression
double evaluateRPN(string expression) {
    Stack stack;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        // Check if token is a number (including negative numbers)
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            stack.push(stod(token));
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                cerr << "Error: Not enough numbers for \"" << token << "\".\n";
                return 0;
            }

            // Pop two numbers from the stack
            double b = stack.pop();
            double a = stack.pop();

            // Perform the operation
            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) {
                    cerr << "Error: Division by zero.\n";
                    return 0;
                }
                stack.push(a / b);
            }
        } else {
            cerr << "Error: Invalid token \"" << token << "\".\n";
            return 0;
        }
    }

    if (stack.size() != 1) {
        cerr << "Error: Invalid RPN expression.\n";
        return 0;
    }

    return stack.pop();
}

int main(int argc, char *argv[]) {
    if (argc == 3 && string(argv[1]) == "-p") {
        string expression = argv[2];
        double result = evaluateRPN(expression);

        if (result != 0) {
            cout << expression << " = " << result << endl;
        } else {
            cout << "Failed to evaluate expression.\n";
        }
    } else {
        cout << "Usage: ./main.out -p \"RPN_EXPRESSION\"\n";
    }

    return 0;
}
