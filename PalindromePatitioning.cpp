/*
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * For example, given s = "aab",
 */
class Solution {
public:
    bool isPalindrome(string s, int st, int ed){
        for (int i = st, j = ed; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void search(string s, int pos, vector<string> path, vector<vector<string> >&solset) {
        if (pos == s.length()) {
            solset.push_back(path);
            return;
        }
        for (int i = pos; i < s.length(); i++) {
            if (isPalindrome(s, pos, i)) {
                path.push_back(s.substr(pos, i-pos+1));
                search(s, i+1, path, solset);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string> > solset;
        if (s != "") {  
            vector<string> path;
            search(s, 0, path, solset);
        }
        return solset;
    }
};
