// main.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "stack.h"

using namespace std;

// Simple check if string is a number
bool isNumber(string str) {
    // Check if first char is digit or negative sign followed by digit
    if (isdigit(str[0]) || (str[0] == '-' && str.length() > 1 && isdigit(str[1]))) {
        return true;
    }
    return false;
}

double evaluateRPN(string expression) 
{
    Stack myStack; 
    stringstream ss(expression);
    string token;

    // Read each part of the expression
    while (ss >> token) {
        // If it's a number, add it to stack
        if (isNumber(token)) {
            myStack.push(stod(token));
        } 
        // If it's an operator, do the math
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Need two numbers to do math
            if (myStack.size() < 2) {
                cout << "Not enough numbers!\n";
                return nan("");
            }
            
            // Get the numbers
            double num2 = myStack.pop();  // Second number
            double num1 = myStack.pop();  // First number
            
            // Do the math based on the operator
            if (token == "+") {
                myStack.push(num1 + num2);
            }
            else if (token == "-") {
                myStack.push(num1 - num2);
            }
            else if (token == "*") {
                myStack.push(num1 * num2);
            }
            else if (token == "/") {
                // Check for divide by zero
                if (num2 == 0) {
                    cout << "Can't divide by zero!\n";
                    return nan("");
                }
                myStack.push(num1 / num2);
            }
        } 
        else {
            cout << "Invalid input: " << token << endl;
            return nan("");
        }
    }

    // Make sure we have exactly one answer
    if (myStack.size() != 1) {
        cout << "Expression not complete!\n";
        return nan("");
    }

    return myStack.pop();
}

// Test different cases
void test() 
{
    cout << "Testing RPN calculator:\n";
    
    // Test basic math
    cout << "3 4 + = " << evaluateRPN("3 4 +") << endl;
    cout << "10 5 - = " << evaluateRPN("10 5 -") << endl;
    cout << "3 4 * = " << evaluateRPN("3 4 *") << endl;
    cout << "15 3 / = " << evaluateRPN("15 3 /") << endl;
    
    // Test harder problems
    cout << "3 4 + 5 6 - * = " << evaluateRPN("3 4 + 5 6 - *") << endl;
    cout << "7 5 + 1 42 / + = " << evaluateRPN("7 5 + 1 42 / +") << endl;
    
    // Test errors
    cout << "Bad expression: " << evaluateRPN("3 4 + -") << endl;
    cout << "Divide by zero: " << evaluateRPN("5 0 /") << endl;
}

int main(int argc, char *argv[]) 
{

        string expr;
        cout << "Enter RPN expression: ";
        getline(cin, expr);
        double answer = evaluateRPN(expr);
        if (!isnan(answer)) {
            cout << expr << " = " << answer << endl;
        }
    return 0;
}
