/*
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 */

class Solution {
public:
    bool isValidSequence(const vector<char> &elements) {
        map<char, bool> used;
        if (elements.size() != 9) {
            return false;
        }
        for (size_t i = 0;i < elements.size(); i++) {
            if (!isdigit(elements[i]) && elements[i] != '.') {
                return false;
            }
            if (isdigit(elements[i]) && used[elements[i]]) {
                return false;
            }
            used[elements[i]] = true;
        }
        return true;
    }
    
    vector<char> getIthRow(const vector<vector<char> > &board, const int idx) {
        vector<char> candidates;
        for (int i = 0; i < 9; i++) {
            candidates.push_back(board[idx][i]);
        }
        return candidates;
    }
    
    vector<char> getIthColumn(const vector<vector<char> > &board, const int idx) {
        vector<char> candidates;
        for (int i = 0; i < 9; i++) {
            candidates.push_back(board[i][idx]);
        }
        return candidates;
    }
    
    vector<char> getIthSquare(const vector<vector<char> > &board, const int idx) {
        vector<char> candidates;
        int base_x = (idx / 3) * 3;
        int base_y = (idx % 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                candidates.push_back(board[base_x+i][base_y+j]);
            }
        }
        return candidates;
    }
    
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<char> candidates;
        for (size_t i = 0; i < 9; i++) {
            candidates = getIthRow(board, i);
            if (!isValidSequence(candidates)) {
                return false;
            }
        }
        for (size_t i = 0; i < 9; i++) {
            candidates = getIthColumn(board, i);
            if (!isValidSequence(candidates)) {
                return false;
            }
        }
        for (size_t i = 0; i < 9; i++) {
            candidates = getIthSquare(board, i);
            if (!isValidSequence(candidates)) {
                return false;
            }
        }
        return true;
    }
};
