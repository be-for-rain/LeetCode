/*
 * Given a string S and a string T, count the number of distinct subsequences of T in S.
 *
 * A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 *
 * Return 3.
 */
class Solution {
public:
    int numDistinct(string S, string T) {
        if (T.length() == 0) {
            return 0;
        }
        vector<int> tmp(T.length()+1, 0);
        vector<vector<int>> f(2, tmp);  //original f[i][j] - until S[0..i], T[0..j], numDistinct
        f[0][0] = f[1][0] = 1;
        int flag = 0;
        for (int i = 1; i <= S.length(); i++, flag = 1-flag) {
            for (int j = 1; j <= T.length(); j++) {
                f[flag][j] = f[1-flag][j];
                if (S[i-1] == T[j-1]) {
                    f[flag][j] += f[1-flag][j-1];
                }
            }
        }
        return f[1-flag][T.length()];
    }
};
