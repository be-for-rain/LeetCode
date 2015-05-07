/*
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *
 * Sol:
 *		scan each char of the string
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st = 0;
        int ans = 0;
        vector<int> appeared(256, -1);
        for (int i = 0; i < s.length(); i++) {
            if (appeared[s[i]] != -1) {
                for (int j = st; j < appeared[s[i]]; j++){
                    appeared[s[j]] = -1;
                }
                st = appeared[s[i]] + 1;
            }
            appeared[s[i]] = i;
            ans = max(ans, i+1-st);
        }
        return ans;
    }
};
