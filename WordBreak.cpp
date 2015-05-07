/*
 * Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 *
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 *
 * Return true because "leetcode" can be segmented as "leet code".
 */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> f(s.length()+1, false); //f[i] ~ [0, i], can wordBreak? 
        f[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) 
                if (f[j]) {
                    string str = s.substr(j, i-j);
                    if (dict.find(str) != dict.end()) {
                        f[i] = true;
                        break;
                    }
                }
        }
        return f[s.length()];
    }
};
