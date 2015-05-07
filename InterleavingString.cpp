/*
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 *
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 */
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<bool> tmp(s2.length()+1, false);
        vector<vector<bool>> f(s1.length()+1, tmp);
        if (s3.length() != s1.length()+s2.length()) {
            return false;
        }
        f[0][0] = true;
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                f[i][j] = f[i][j] || (i>0 && f[i-1][j] && s3[i+j-1]==s1[i-1]);
                f[i][j] = f[i][j] || (j>0 && f[i][j-1] && s3[i+j-1]==s2[j-1]);
            }
        }
        return f[s1.length()][s2.length()];
        
    }
};
