/*
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 */

class Solution {
public:
    void ignoreWhitespaces(const char *&s) {
        while (*s == ' ') {
            s++;
        }
    }
    
    void readSign(const char *&s) {
        if (*s == '+' || *s == '-') {
            s++;
        }
    }
    
    bool readDigits(const char *&s) {
        bool is_digits = isdigit(*s);
        while (isdigit(*s)) {
            s++;
        }
        return is_digits;
    }
    
    bool readFloat(const char *&s) {
        //"1." ".1" - legal
        readSign(s);
        bool flag = readDigits(s);
        if (*s == '.') {
            s++;
            flag |= readDigits(s);
        }
        return flag;
    }
    
    bool isNumber(const char *s) {
        ignoreWhitespaces(s);
        if (!readFloat(s)) {
            return false;
        }
        if (*s == 'e') {
            s++;
            readSign(s);
            if (!readDigits(s)) {
                return false;
            }
        }
        ignoreWhitespaces(s);
        return *s == '\0';
    }
};
