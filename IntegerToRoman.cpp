/*
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
public:
    char getOffsetRomanDigit(char digit, int offset) {
        static string RomanSeq = "IVXLCDM";
        for (size_t i = 0; i < RomanSeq.size(); i++) {
            if (RomanSeq[i] == digit) {
                return RomanSeq[i+offset];
            }
        }
        return '\0';
    }

    string getRoman(int firstDigit, int nZeros) {
        static string RomanMap[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
        string str = RomanMap[firstDigit];
        int offset = nZeros * 2;
        for (size_t i = 0; i < str.size(); i++) {
            str[i] = getOffsetRomanDigit(str[i], offset);
        }
        return str;
    }

    string getRomanFromInt(vector<int> digits) {
        string str = "";
        for (size_t i = 0; i < digits.size(); i++) {
            str = getRoman(digits[i], i) + str;
        }
        return str;
    }
    
    void intToDigits(int num, vector<int> &intDigits) {
        while (num) {
            intDigits.push_back(num%10);
            num /= 10;
        }
    }

    string intToRoman(int num) {
        vector<int> intDigits;
        intToDigits(num, intDigits);
        return getRomanFromInt(intDigits);
    }
};
