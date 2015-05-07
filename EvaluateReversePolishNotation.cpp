/*
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *     ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 *
 *
 * Sol:
 *		use a stack to store the operands(numbers)
 *		each time an operator encountered, pop out the two topmost operands, calculate their result with operator, push back the result into stack
 *
 *	Notes:
 *		1,when judging whether a string represents an operator, should judge whether its length == 1 first ———— str[0] == '-' also holds for negative numbers
 *		2. the topmost int is the SECOND operand!!
 */
class Solution {
public:
    bool isOperator(string str) {
        if (str.length() != 1)  //attention!! for negative numbers, str[0] is '-' as well!!
            return false;
        char ch = str[0];
        return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');    
    }
    
    int calc(int a, int b, char op) {
        if (op == '+')
            return a+b;
        if (op == '-')
            return a-b;
        if (op == '*')
            return a*b;
        if (op == '/')
            return a/b;
    }
    
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
            if (isOperator(*it)) {
                int num_b = stk.top();  //pay attention to the order!! the top element should be the second operand!
                stk.pop();
                int num_a = stk.top();
                int result = calc(num_a, num_b, (*it)[0]);
                stk.top() = result;
            } else {
                stk.push(atoi(it->c_str()));
            }
        }
        return stk.top();
    }
};
