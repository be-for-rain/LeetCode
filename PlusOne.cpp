/*
 * Given a number represented as an array of digits, plus one to the number.
 *
 * Sol:
 *		first, don't care about carry matter, add one to the last digit
 *		then scan the vector and set carry digits
 *
 * Note:
 *		[order matter]for number 1234, digits = {1, 2, 3, 4}
 *		so I just reverse the whole bit vector at the very beginning and at the end
 */

class Solution {
public:
    void removeRedundantZeroBit(vector<int> &digits) {
        while (digits.size()>1 && digits.back() == 0) //do nothing to exact "0"
            digits.pop_back();
    }
    
    void setCarryToNormalFormNumber(vector<int> &digits) {
        digits.push_back(0);    //for the last carry digit
        for (size_t i = 0; i < digits.size(); i++) {
            int current_number = digits[i];
            digits[i] = current_number % 10;
            digits[i+1] += current_number / 10;
        }
        removeRedundantZeroBit(digits);
    }
    
    void plusWithoutCarry(vector<int> &digits, int addend) {
        digits[0] += addend;
    }

    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        plusWithoutCarry(digits, 1);
        setCarryToNormalFormNumber(digits);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
