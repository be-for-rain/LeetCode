/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0, pre_len = 0;
        for (int i = 0; s[i] != '\0'; ++i) {
            if (isspace(s[i])) {
                if (len) {
                    pre_len = len;
                }
                len = 0;
            } else {
                ++len;
            }
        }
        return len ? len : pre_len;
    }
};
