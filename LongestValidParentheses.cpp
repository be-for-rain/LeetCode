/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 *
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        vector<int> f(s.size()+1, 0);
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else { //s[i] == ')'
                if (!stk.empty()) {
                    f[i+1] = f[stk.top()] + i-stk.top()+1;
                    max_len = max(max_len, f[i+1]);
                    stk.pop();
                }
            }
        }
        return max_len;
    }
};
