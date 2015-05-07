/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 */
class Solution {
public:
    string getStringFromNum(int num) {
        string ans = "";
        while (num) {
            ans += (char)('0'+num%10);
            num /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string getNextString(string s) {
        string ans = "";
        char ch;
        int cnt = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (i != s.length() && (i == 0 || s[i] == s[i-1])) {
                cnt++;
            } else {
                string tmp = getStringFromNum(cnt);
                ans += tmp;
                ans += s[i-1];
                cnt = 1;
            }
        }
        return ans;
    }

    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; i++) {
            str = getNextString(str);
        }
        return str;
    }
};
