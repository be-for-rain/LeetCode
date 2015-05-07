/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 * Sol:
 *		DP with memoization
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
    
    bool isWellParenthesed(string s, int st, int ed, vector<vector<int> > &f) {
        if (f[st][ed]) {    //searched before
            return f[st][ed] == 1;
        }
        if (st == ed) {
            f[st][ed] = 1;
            return true;
        }
        if ((st > ed) || ((ed-st)%2 == 1)) {
            f[st][ed] = -1;
            return false;
        }
        if (isPair(s[st], s[ed-1]) && isWellParenthesed(s, st+1, ed-1, f)) {
            f[st][ed] = 1;
            return true;
        }
        for (int i = st+2; i < ed-1; i++) {
            if (isWellParenthesed(s, st, i, f) && isWellParenthesed(s, i, ed, f)) {
                f[st][ed] = 1;
                return true;
            }
        }
        f[st][ed] = -1;
        return false;
    }
    
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }
        vector<vector<int> > f(s.size()+1);
        for (vector<vector<int> >::iterator it = f.begin(); it != f.end(); ++it) {
            it->resize(s.size()+1);
        }
        return isWellParenthesed(s, 0, s.size(), f);
    }
};
