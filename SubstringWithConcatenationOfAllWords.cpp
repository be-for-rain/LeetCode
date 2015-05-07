/*
 * You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
 *
 * For example, given:
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
 */
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        map<string, int> need;
        int len = L.size() ? L[0].length() : 0;
        vector<int> st;
        for (int i = 0; i < len; i++) {
            st.push_back(i);
        }
        vector<map<string,int>> found(len);
        vector<int> found_cnt(len, 0);
        
        for (int i = 0; i < L.size(); i++) {
            if (need.find(L[i]) == need.end()) {
                need[L[i]] = 1;
                for (int j = 0; j < len; j++) {
                    found[j][L[i]] = 0;
                }
            } else {
                need[L[i]]++;
            }
        }

        for (int i = 0; i+len <= S.length(); i++) {
            string str = S.substr(i, len);
            int k = i%len;
            if (found[k][str] < need[str]) {
                found_cnt[k]++;
            }
            found[k][str]++;
            if (found_cnt[k] == L.size()) {
                for (; st[k]+len <= S.length(); st[k]+=len) {
                    string ss = S.substr(st[k], len);
                    if (need.find(ss) == need.end() || found[k][ss] <= need[ss]) {
                        break;
                    }
                    found[k][ss]--;
                }
                if (i - st[k]+len == L.size()*len) {
                    ans.push_back(st[k]);
                }
            }
        }
        return ans;
    }
};
