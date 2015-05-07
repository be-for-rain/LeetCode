/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return the minimum cuts needed for a palindrome partitioning of s.
 *
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */
class Solution {
public:
    void calcIspalindrome(string s, vector<vector<bool>> &ispalindrome) {
        for (size_t i = 0; i < ispalindrome.size(); i++) {
            ispalindrome[i].resize(s.length(), false);
        }
        for (int i = 0; i < s.length(); i++) {
            ispalindrome[i][i] = true;  //len == 1
            if (i+1 < s.length() && s[i] == s[i+1])   
                ispalindrome[i][i+1] = true;    //len == 2
        }
        for (int len = 3; len <= s.length(); len++) {
            for (int i = 0; i <= s.length()-len; i++) {
                if (s[i] == s[i+len-1] && ispalindrome[i+1][i+len-2]) {
                    ispalindrome[i][i+len-1] = true;
                }
            }
        }
    }
    
    void calcF(string s, vector<int> &f, vector<vector<bool>> &ispalindrome) {
        f[0] = 0;
        for (int i = 0; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) { //len //[j, i)
                if (f[j]+1 < f[i] && ispalindrome[j][i-1]) {
                    f[i] = f[j]+1;
                }
            }
        }
    }
    
    int minCut(string s) {
        vector<int> f(s.length()+1, INT_MAX);//ed) - how many segments -- mincut+1
        vector<vector<bool>> ispalindrome(s.length());
        calcIspalindrome(s, ispalindrome);
        calcF(s, f, ispalindrome);
        return max(0, f[s.length()]-1);
    }
};
