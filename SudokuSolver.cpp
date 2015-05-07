/*
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
 */
class Solution {
public:
    bool ok(vector<vector<char>> &board, int pr, int pc, int num) {
        if ((rows[pr]&(1<<num)) || (cols[pc]&(1<<num)) || (blocks[pr/3][pc/3]&(1<<num))) {
            return false;
        }
        return true;
    }
    
    void set(vector<vector<char>> &board, int pr, int pc, char ch) {
        board[pr][pc] = ch;
        int num = ch-'1';
        rows[pr] |= 1<<num;
        cols[pc] |= 1<<num;
        blocks[pr/3][pc/3] |= 1<<num;
    }
    
    void clear(vector<vector<char>> &board, int pr, int pc) {
        int num = board[pr][pc]-'1';
        rows[pr] ^= 1<<num;
        cols[pc] ^= 1<<num;
        blocks[pr/3][pc/3] ^= 1<<num;
        board[pr][pc] = '.';
    }

    bool search(int pr, int pc, vector<vector<char> >&board) {
        if (pr == 9) {
            return true;
        }
        if (pc == 9) {
            return search(pr+1, 0, board);
        }
        if (board[pr][pc] == '.') {
            for (int i = 0; i < 9; i++) {
                if (ok(board, pr, pc, i)) {
                    set(board, pr, pc, '1'+i);
                    if (search(pr, pc+1, board)) {
                        return true;
                    }
                    clear(board, pr, pc);
                }
            }
            return false;
        } else {
            return search(pr, pc+1, board);
        }
    }

    void solveSudoku(vector<vector<char> > &board) {
        rows.resize(9, 0);
        cols.resize(9, 0);
        vector<int> tmp(3, 0);
        blocks.resize(3, tmp);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    set(board, i, j, board[i][j]);
                }
            }
        }
        search(0, 0, board);
    }
    private:
        vector<int> rows, cols;
        vector<vector<int>> blocks;
};
