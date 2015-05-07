/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 *
 * Sol:
 *		search each position (DFS)
 *		simulate stack
 *		record how many '(' has already been used & how many '(' is still in stack
 *
 *		the number should be Catanlan number h(n)
 *		h(n) = C(2*n, n) - C(2*n, n+1)
 */

class Solution {
public:
    //cnt--how many '(' has already been used
    //rest--how many '(' is still in stack (hasn't found pair)
    void search(int pos, int n, string cur, int cnt, int rest, vector<string> &ans) {
        if (pos == 2*n) {
            if (rest == 0) {
                ans.push_back(cur);
            }
            return;
        }
        if (rest) {
            search(pos+1, n, cur+')', cnt, rest-1, ans);
        }
        if (cnt < n) {
            search(pos+1, n, cur+'(', cnt+1, rest+1, ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        search(0, n, "", 0, 0, ans);
        return ans;
    }
};

