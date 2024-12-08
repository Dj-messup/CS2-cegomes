#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

double evaluateRPN(string expression) 
{
    Stack stack;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-' && isdigit(token[1]))) {
            stack.push(stod(token));
        } 
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                cerr << "Error: Not enough operands.\n";
                return nan("");  // Changed from 0 to NaN
            }
            double b = stack.pop();
            double a = stack.pop();
            
            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) {
                    cerr << "Error: Division by zero.\n";
                    return nan("");  // Changed from 0 to NaN
                }
                stack.push(a / b);
            }
        } 
        else {
            cerr << "Error: Invalid token.\n";
            return nan("");  // Changed from 0 to NaN
        }
    }

    if (stack.size() != 1) {
        cerr << "Error: Invalid expression.\n";
        return nan("");  // Changed from 0 to NaN
    }

    return stack.pop();
}

void test() 
{
    cout << "\nRunning tests:" << endl;
    cout << "3 4 + = " << evaluateRPN("3 4 +") << endl;
    cout << "3 4 + 5 6 - * = " << evaluateRPN("3 4 + 5 6 - *") << endl;
    cout << "7 5 + 1 42 / + = " << evaluateRPN("7 5 + 1 42 / +") << endl;
}

int main(int argc, char *argv[]) 
{
    if (argc == 3 && string(argv[1]) == "-p") {
        double result = evaluateRPN(argv[2]);
        if (!isnan(result)) {
            cout << argv[2] << " = " << result << endl;
        }
    } 
    else {
        string expression;
        cout << "Enter an RPN expression: ";
        getline(cin, expression);
        double result = evaluateRPN(expression);
        if (!isnan(result)) {
            cout << expression << " = " << result << endl;
        }
    }
    return 0;
}