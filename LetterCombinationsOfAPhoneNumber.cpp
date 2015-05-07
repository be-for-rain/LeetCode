/*
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 */

class Solution {
public:
    const string letter_map[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    
    void search(string digits, int pos, string current_ans, vector<string> &answer_set) {
        if (pos == digits.length()) {
            answer_set.push_back(current_ans);
            return;
        }
        int digit = digits[pos] - '0';
        for (size_t i = 0; i < letter_map[digit].length(); i++) {
            search(digits, pos+1, current_ans+letter_map[digit][i], answer_set);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> answer_set;
        search(digits, 0, "", answer_set);
        return answer_set;
    }
};
