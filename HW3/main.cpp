#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "stack.h"

using namespace std;

bool isNumber(const string& str) {
    try {
        size_t pos;
        stod(str, &pos);
        return pos == str.length();
    }
    catch (...) {
        return false;
    }
}

double evaluateRPN(string expression) 
{
    Stack stack;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isNumber(token)) {
            stack.push(stod(token));
        } 
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                cerr << "Error: Not enough operands for '" << token << "' operation.\n";
                return nan("");
            }
            double b = stack.pop();
            double a = stack.pop();
            
            if (token == "+") stack.push(a + b);
            else if (token == "-") stack.push(a - b);
            else if (token == "*") stack.push(a * b);
            else if (token == "/") {
                if (b == 0) {
                    cerr << "Error: Division by zero.\n";
                    return nan("");
                }
                stack.push(a / b);
            }
        } 
        else {
            cerr << "Error: Invalid token '" << token << "'.\n";
            return nan("");
        }
    }

    if (stack.size() != 1) {
        cerr << "Error: Invalid expression.\n";
        return nan("");
    }

    return stack.pop();
}

void test() 
{
    cout << "\nRunning tests:" << endl;
    
    // Basic operations
    cout << "3 4 + = " << fixed << setprecision(4) << evaluateRPN("3 4 +") << endl;
    cout << "10 5 - = " << evaluateRPN("10 5 -") << endl;
    cout << "3 4 * = " << evaluateRPN("3 4 *") << endl;
    cout << "15 3 / = " << evaluateRPN("15 3 /") << endl;
    
    // Complex expressions
    cout << "3 4 + 5 6 - * = " << evaluateRPN("3 4 + 5 6 - *") << endl;
    cout << "7 5 + 1 42 / + = " << evaluateRPN("7 5 + 1 42 / +") << endl;
    
    // Error cases
    cout << "Testing invalid expression: " << evaluateRPN("3 4 + -") << endl;
    cout << "Testing division by zero: " << evaluateRPN("5 0 /") << endl;
}

int main(int argc, char *argv[]) 
{
    if (argc == 2 && string(argv[1]) == "test") {
        test();
    }
    else if (argc == 3 && string(argv[1]) == "-p") {
        double result = evaluateRPN(argv[2]);
        if (!isnan(result)) {
            cout << argv[2] << " = " << fixed << setprecision(4) << result << endl;
        }
    } 
    else {
        string expression;
        cout << "Enter an RPN expression: ";
        getline(cin, expression);
        double result = evaluateRPN(expression);
        if (!isnan(result)) {
            cout << expression << " = " << fixed << setprecision(4) << result << endl;
        }
    }
    return 0;
}