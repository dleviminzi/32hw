#include <iostream>
#include <cassert>
#include <string>
#include <stack>
#include "Map.h"

void pfix_upd1(std::stack<char> op_stack, std::string& postfix);
void pfix_upd2(std::stack<char> op_stack, std::string& postfix);
bool ind_range(std::string str, int ind, int prev, int lower, int upper);


int evaluate(std::string infix, const Map& values, std::string& postfix, 
        int& result) {

    // initialize return value and count '(' and ')'
    int r_value(0);
    int open_p(0), close_p(0), operands(0), operators(0);

    // initialize postfix and operator stack to empty
    std::stack<char> op_stack;
    postfix = "";

    //check if infix is empty
    if (infix.length() == 0) r_value = 1;

    // converting infix to postfix form 
    char ch;
    for (int i(0); i < infix.length(); i++) {
        ch = infix[i];
        switch(ch) {
            case 'a' ... 'z':
                if (!values.contains(ch)) r_value = 2;
                if (ind_range(infix, i, 1, 96, 123)) r_value = 1;
                if (infix[i-1] == ' ' && ind_range(infix, i, 2, 96, 123))
                    r_value = 1;
                if (infix[i-1] == ')') r_value = 1;
                postfix += ch;
                operands++;
                break;
            case '(':
                if (ind_range(infix, i, 1, 96, 123)) r_value = 1;
                open_p++;
                op_stack.push(ch);
                break;
            case ')':
                close_p++;
                while(op_stack.top() != '(') {
                    postfix += op_stack.top();
                    op_stack.pop();
                }
                op_stack.pop();
                break;
            case '+':
                if (ind_range(infix, i, 1, 41, 48)) r_value = 1;
                if (ind_range(infix, i, 1, 39, 42)) r_value = 1;
                pfix_upd1(op_stack, postfix);
                op_stack.push(ch);
                operators++;
                break;
            case '-':
                if (ind_range(infix, i, 1, 41, 48)) r_value = 1;
                if (ind_range(infix, i, 1, 39, 42)) r_value = 1;
                pfix_upd1(op_stack, postfix);
                op_stack.push(ch);
                operators++;
                break;
            case '*':
                if (ind_range(infix, i, 1, 41, 48)) r_value = 1;
                if (ind_range(infix, i, 1, 39, 42)) r_value = 1;
                pfix_upd2(op_stack, postfix);
                op_stack.push(ch);
                operators++;
                break;
            case '/':
                if (ind_range(infix, i, 1, 41, 48)) r_value = 1;
                if (ind_range(infix, i, 1, 39, 42)) r_value = 1;
                pfix_upd2(op_stack, postfix);
                op_stack.push(ch);
                operators++;
                break;
            case ' ':
                break;
            default:
                r_value = 1;
                break;
        }
    }

    // move through remaining contents of the stack
    while (!op_stack.empty()) {
        postfix += op_stack.top();
        op_stack.pop();
    }

    // checking if #'(' = #')'
    if(open_p != close_p) r_value = 1;

    // checking
    if (operands == 1 && operators > 0) r_value = 1;
    if (operands == 0 && operators == 0) r_value = 1;

    // evaluating the postfix expression
    std::stack<int> opd_stack;
    int operand2;
    int operand1;
    int res_op;
    for(char i : postfix) {
        if (r_value != 0) break;
        if(!(i > 41 && i < 48)) {
            int char_val(0);
            values.get(i, char_val);
            opd_stack.push(char_val);
        }
        else {
            operand2 = opd_stack.top();
            opd_stack.pop();
            operand1 = opd_stack.top();
            opd_stack.pop();
            switch (i) {
                case '*':
                    res_op = (operand1*operand2);
                    opd_stack.push(res_op);
                    break;
                case '/':
                    if (operand2 == 0) {
                        r_value = 3;
                        break;
                    }
                    res_op = (operand1/operand2);
                    opd_stack.push(res_op);
                    break;
                case '+':
                    res_op = (operand1 + operand2);
                    opd_stack.push(res_op);
                    break;
                case '-':
                    res_op = (operand1 - operand2);
                    opd_stack.push(res_op);
                    break;
            }
        }
    }

    // getting result value if applicable and returning appropriate out
    if (r_value == 0) result = opd_stack.top();
    return r_value;
}

void pfix_upd1(std::stack<char> op_stack, std::string& postfix) {
    while(!op_stack.empty() && op_stack.top() != '(' && 
            !(op_stack.top() == '*' || op_stack.top() == '/')) {
        postfix += op_stack.top();
        op_stack.pop();
    }
}

void pfix_upd2(std::stack<char> op_stack, std::string& postfix) {
    while(!op_stack.empty() && op_stack.top() != '(' && 
            (op_stack.top() == '*' || op_stack.top() == '/')) {
        postfix += op_stack.top();
        op_stack.pop();
    }
}


bool ind_range(std::string str, int ind, int prev, int lower, int upper) {
    bool result(false);
    if (str[ind-prev] > lower && str[ind-prev] < upper) result=true;
    return result;
}
