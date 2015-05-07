/*
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 *
 * For example,
 * Given board =
 *
 * [
 *   ["ABCE"],
 *     ["SFCS"],
 *       ["ADEE"]
 *       ]
 *       word = "ABCCED", -> returns true,
 *       word = "SEE", -> returns true,
 *       word = "ABCB", -> returns false.
 */
class Solution {
public:
    bool search(vector<vector<char>> &board, int pr, int pc, string word, int pos, vector<vector<bool>>&visited) {
        static int dr[] = {1, 0, -1, 0};
        static int dc[] = {0, 1, 0, -1};
        if (pos == word.length()) {
            return true;
        }
        if (pr < 0 || pr >= board.size() || pc < 0 || pc >= board[0].size() || visited[pr][pc] || board[pr][pc] != word[pos]) {
            return false;
        }
        visited[pr][pc] = true;
        for (int i = 0; i < 4; i++) {
            if (search(board, pr+dr[i], pc+dc[i], word, pos+1, visited)) {
                visited[pr][pc] = false;
                return true;
            }
        }
        visited[pr][pc] = false;
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0) {
            return word=="";
        }
        vector<bool> tmp(board[0].size(), false);
        vector<vector<bool>> visited(board.size(), tmp);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (search(board, i, j, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
