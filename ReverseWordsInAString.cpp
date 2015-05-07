/*
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 */
class Solution {
public:
    string findNextString(string &s, string::iterator &it) {
        for (; it != s.end() && isspace(*it); it++);
        string str = "";
        for (; it != s.end() && !isspace(*it); it++) {
            str += *it;
        }
        reverse(str.begin(), str.end());
        return str;
    }

    void reverseWords(string &s) {
        string ans;
        for (string::iterator it = s.begin(); it != s.end(); ) {
            string str = findNextString(s, it);
            ans += str + ' ';
        }
        while (ans.length() && isspace(ans.back())) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        s = ans;
    }
};
