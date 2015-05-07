/*
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T, return the emtpy string "".
 *
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */
class Solution {
public:
    string minWindow(string S, string T) {
        string ans = "";
        int minlen = INT_MAX, found_cnt = 0, st = 0;
        vector<int> need(256, 0), found(256, 0);
        
        for (int i = 0; i < T.length(); i++) {
            need[T[i]]++;
        }
        for (int i = 0; i < S.length(); i++) {
            if (found[S[i]] < need[S[i]]) {
                found_cnt++;
            }
            found[S[i]]++;
            if (found_cnt == T.length()) {
                for ( ; found[S[st]] > need[S[st]]; st++) {
                    found[S[st]]--;
                }
                if (i-st+1 < minlen) {
                    minlen = i-st+1;
                    ans = S.substr(st, minlen);
                }
            }
        }    
        return ans;
    }
};
