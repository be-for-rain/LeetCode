/*
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 * Sol:
 *		string addition / high precision addition
 *		convert strings to int vectors
 *		calculate the result without carry
 *		set carry and change result to normal form 
 */
class Solution {
public:
    int getIntFromChar(char ch) {
        return (int)(ch - '0');
    }
    
    int getCharFromInt(int digit) {
        return (char)(digit + '0');
    }
    
    string getStringFromIntVector(const vector<int> &digits) {
        string number_string = "";
        for (auto rit = digits.crbegin(); rit != digits.crend(); ++rit)
            number_string.push_back(getCharFromInt(*rit));
        return number_string;
    }

    void stringToIntVector(string str, vector<int> &digits) {
        for (auto rit = str.crbegin(); rit != str.crend(); ++rit) {
            digits.push_back(getIntFromChar(*rit));
        }
    }
    
    void setCarryToNormalFormNumber(vector<int> &digits, int base) {
        digits.push_back(0);
        for (size_t i = 0; i < digits.size(); i++) {
            int current_number = digits[i];
            digits[i] = current_number % base;
            digits[i+1] += current_number / base;
        }
    }
    
    void removeRedundantZeroBit(vector<int> &digits) {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
    }
    
    void addVector(const vector<int> &addend_1, const vector<int> &addend_2, vector<int> &result) {
        int max_addends_size = max(addend_1.size(), addend_2.size()); 
        result.resize(max_addends_size + 1, 0);
        for (size_t i = 0; i < max_addends_size; i++) {
            if (i < addend_1.size())
                result[i] += addend_1[i];
            if (i < addend_2.size())
                result[i] += addend_2[i];
        }
        setCarryToNormalFormNumber(result, 2);
        removeRedundantZeroBit(result);
    }

    string addBinary(string a, string b) {
        vector<int> addend_1, addend_2, result;
        stringToIntVector(a, addend_1);
        stringToIntVector(b, addend_2);
        addVector(addend_1, addend_2, result);
        return getStringFromIntVector(result);
    }
};
