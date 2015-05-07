/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 * Sol:
 *		use stack
 *		push each char, if it is a pair of the top element of the stack, pop them out
 *		if the string is valid parenthesed, the stack should be empty
 */

class Solution {
public:
    bool isPair(char a, char b) {
        if (a == '(' && b == ')'){
            return true;
        }
        if (a == '{' && b == '}') {
            return true;
        }
        if (a == '[' && b == ']') {
            return true;
        }
        return false;
    }

    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (!stk.empty() && isPair(stk.top(), s[i])) {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};
