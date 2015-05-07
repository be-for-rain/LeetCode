/*
 * Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 *
 * For example:
 * Given "25525511135",
 *
 * return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */
class Solution {
public:
    string toString(vector<string> &vec) {
        string str = "";
        for (size_t i = 0; i < vec.size(); i++) {
            str += vec[i];
            if (i+1 < vec.size()) {
                str += '.';
            }
        }
        return str;
    }

    void search(string s, int pos, vector<string> &allpaths) {
        static vector<string> path;
        if (path.size() == 4) {
            if (pos == s.length()) {
                allpaths.push_back(toString(path));
            }
            return;
        }
        if (s[pos] == '0') {
            path.push_back("0");
            search(s, pos+1, allpaths);
            path.pop_back();
            return;
        }
        int val = 0;
        string curstr = "";
        for (int i = pos; i < s.length(); i++) {
            val = val*10 + s[i]-'0';
            curstr += s[i];
            if (val > 255) {
               break;
            }
            path.push_back(curstr);
            search(s, i+1, allpaths);
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> allpaths;
        if (s.length() <= 12) {
            search(s, 0, allpaths);
        }
        return allpaths;
    }
};
