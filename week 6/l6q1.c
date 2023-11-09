


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int performOperation(char operation, int operand1, int operand2) {
    switch(operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0;
    }
}

int evaluatePrefixExpression(string expression) {
    stack<int> operandStack;
    
    for (int i = expression.length() - 1; i >= 0; i--) {
        char currentChar = expression[i];
        
        if (isOperator(currentChar)) {
            int operand1 = operandStack.top();
            operandStack.pop();
            
            int operand2 = operandStack.top();
            operandStack.pop();
            
            int result = performOperation(currentChar, operand1, operand2);
            operandStack.push(result);
        } else {
            int operand = currentChar - '0';
            operandStack.push(operand);
        }
    }
    
    return operandStack.top();
}

int main() {
    string prefixExpression = "*+234";
    int result = evaluatePrefixExpression(prefixExpression);
    
    count << "Result: " << result << end;
    
    return 0;
}






























