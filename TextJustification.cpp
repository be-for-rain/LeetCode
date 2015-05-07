/*
 * Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
 *
 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra space is inserted between words.
 *
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 *
 * Return the formatted lines as:
 * [
 *    "This    is    an",
 *       "example  of text",
 *          "justification.  "
 *          ]
 *          Note: Each word is guaranteed not to exceed L in length.
 *
 *          click to show corner cases.
 *
 *          Corner Cases:
 *          A line other than the last line might contain only one word. What should you do in this case?
 *          In this case, that line should be left-justified.
 */
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans;
        if (words.empty()) {
            return ans;
        }
        int st = 0;
        while (st < words.size()) {
            int charcnt = 0;
            for (int i = st; i <= words.size() ; i++) {
                if (i < words.size() && charcnt+words[i].length()+i-st <= L) {
                    charcnt += words[i].length();
                } else {
                    int ed = i-1;   //[st, ed]
                    string cur_line = words[st];
                    if (st == ed || i==words.size()) {
                        for (int j = 0; j < ed-st; j++) {
                            cur_line += " " + words[st+1+j];
                        }
                        while (cur_line.length() < L) {
                            cur_line += " ";
                        }
                    } else {
                        int spaces = L - charcnt;
                        string smaller_gap_str = "";
                        for (int j = 0; j < spaces/(ed-st); j++) {
                            smaller_gap_str += ' ';
                        }
                        string bigger_gap_str = smaller_gap_str + ' ';
                        int bigger_gap_cnt = spaces%(ed-st);
                        
                        for (int j = 0; j < bigger_gap_cnt; j++) {
                            cur_line += bigger_gap_str + words[st+1+j];
                        }
                        for (int j = bigger_gap_cnt; j < ed-st; j++) {
                            cur_line += smaller_gap_str + words[st+1+j];
                        }
                    }
                    ans.push_back(cur_line);
                    st = ed+1;
                    break;
                }
            }
        }
        return ans;
    }
};
