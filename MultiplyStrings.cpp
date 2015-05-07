/*
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 *
 * Sol:
 *		convert strings to int vectors	
 *		multiply them without set carry
 *		set carry of the result vector along scaning it
 *
 * Note:
 *		when const vector<int> &... used as a parameter of a function,
 *		when use its iterator, better to use const_iterator, cbegin(), cend()//C++11
 *		for (vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it)
 *		or you'll get a lot of compiling errors at your local computer and will get "required from here" error at LeetCode
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
    
    void setCarryToNormalFormNumber(vector<int> &digits) {
        digits.push_back(0);
        for (size_t i = 0; i < digits.size(); i++) {
            int current_number = digits[i];
            digits[i] = current_number % 10;
            digits[i+1] += current_number / 10;
        }
    }
    
    void removeRedundantZeroBit(vector<int> &digits) {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
    }
    
    void vectorMultiply(const vector<int> &multiplier_1, const vector<int> &multiplier_2, vector<int> &result) {
        result.resize(multiplier_1.size()+multiplier_2.size(), 0);
        for (size_t i = 0; i < multiplier_1.size(); ++i) 
            for (size_t j = 0; j < multiplier_2.size(); ++j)
                result[i+j] += multiplier_1[i] * multiplier_2[j];
        setCarryToNormalFormNumber(result);
        removeRedundantZeroBit(result);
    }

    string multiply(string num1, string num2) {
        vector<int> multiplier_1, multiplier_2, result;
        stringToIntVector(num1, multiplier_1);
        stringToIntVector(num2, multiplier_2);
        vectorMultiply(multiplier_1, multiplier_2, result);
        return getStringFromIntVector(result);
    }
};
