class Solution {
public:
    void initVal(map<char, int> &val) {
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;
    }
    
    int getIntFromRoman(string s, map<char, int> &val) {
        int ans = 0;
        int pre_val = -100;
        reverse(s.begin(), s.end());
        for (size_t i = 0; i < s.size(); i++) {
            if (val[s[i]] >= pre_val) {
                ans += val[s[i]];
                pre_val = val[s[i]];
            } else {
                ans -= val[s[i]];
            }
        }
        return ans;
    }
    
    int romanToInt(string s) {
        map<char, int> val;
        initVal(val);
        return getIntFromRoman(s, val);
    }
};