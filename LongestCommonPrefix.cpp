/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 */
/*
 * Sol:
 *		sort these strings
 *		the length of the longest common prefix
 *			= min{the length of the longest common prefix of two adjacent strings}
 */

class Solution {
public:
    int getCommonPrefixLength(string a, string b) {
        int len = min(a.length(), b.length());
        for (size_t i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                return i;
            }
        }
        return len;
    }

    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        sort(strs.begin(), strs.end());
        strs.push_back(strs[0]);
        int maxlen = strs[0].length();
        for (size_t i = 1; i < strs.size(); i++) {
            int len = getCommonPrefixLength(strs[i-1], strs[i]);
            if (len < maxlen) {
                maxlen = len;
            }
        }
        return strs[0].substr(0, maxlen);
    }
};
