#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

// Solves math written in Reverse Polish Notation (RPN)
double evaluateRPN(string expression) {
    Stack stack;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        // If the token is a number, push it to the stack
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            stack.push(stod(token));
        } 
        // If the token is an operator, do the math
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                cerr << "Error: Not enough numbers for \"" << token << "\".\n";
                return 0;
            }

            // Get two numbers from the stack
            double b = stack.pop();
            double a = stack.pop();

            // Do the operation
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
        } 
        // If the token is not valid, show an error
        else {
            cerr << "Error: Invalid token \"" << token << "\".\n";
            return 0;
        }
    }

    // If there’s not one number left, something went wrong
    if (stack.size() != 1) {
        cerr << "Error: Invalid RPN expression.\n";
        return 0;
    }

    // Return the answer
    return stack.pop();
}

int main(int argc, char *argv[]) {
    // Check if the program is run with the right arguments
    if (argc == 3 && string(argv[1]) == "-p") {
        string expression = argv[2];
        double result = evaluateRPN(expression);

        // Show the result
        if (result != 0) {
            cout << expression << " = " << result << endl;
        } else {
            cout << "Failed to evaluate expression.\n";
        }
    } 
    // Tell the user how to run the program
    else {
        cout << "Usage: ./main.out -p \"RPN_EXPRESSION\"\n";
    }

    return 0;
}
