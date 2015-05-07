/*
 * Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 *
 * Return all such possible sentences.
 *
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 *
 * A solution is ["cats and dog", "cat sand dog"].
 */
class Solution {
public:
    void constructNext(string s, unordered_set<string> &dict, vector<vector<bool>> &next){
        vector<bool> can_break(s.length(), false);  //s.[i, s.length()-1] can be broken into words? 
        
        for (int i = s.length()-1; i >= 0; i--) {
            if (i == s.length()-1 || can_break[i+1]) {
                for (int j = 0; j <= i; j++) {
                    string word = s.substr(j, i-j+1);
                    if (dict.find(word) != dict.end()) {
                        can_break[j] = true;
                        next[j][i] = true;
                    }
                }
            }
        }
    }
    
    void search(string s, int start, unordered_set<string> &dict, vector<vector<bool>> &next, vector<string> &allpaths, string path) {
        if (start == s.length()) {
            if (path.size())
                path.pop_back();//reove redundant whitespace
            allpaths.push_back(path);
            return;
        }
        for (int end = start; end < s.length(); end++) {
            if (next[start][end]) {
                string str = s.substr(start, end-start+1);
                search(s, end+1, dict, next, allpaths, path+str+" ");
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> allpaths;
        vector<bool> tmp(s.length(), false);
        vector<vector<bool>> next(s.length(), tmp);//record path, the successive node of dp
        constructNext(s, dict, next);
        search(s, 0, dict, next, allpaths, "");
        return allpaths;
    }
};
