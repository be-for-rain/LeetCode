/*
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 */
class Solution {
public:
    inline int todigit(char ch) {
        return ch-'0';
    }
    
    int numDecodings(string s) {
        if (s=="") {
            return 0;
        }
        vector<int> f(s.length()+1, 0); //ways of decodings, end with i-1 //i)
        f[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            if (s[i-1] != '0')    //decode only one digit
                f[i] += f[i-1];
            if (i > 1) {    //decode two digits together
                int val = todigit(s[i-2])*10+todigit(s[i-1]);
                if (val >= 10 && val <= 26) {
                    f[i] += f[i-2];
                }
            }
        }
        return f[s.length()];
    }
};
