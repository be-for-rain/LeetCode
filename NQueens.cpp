/*
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 *
 *
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 *
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 *
 * [
 *  [".Q..",  // Solution 1
 *    "...Q",
 *      "Q...",
 *        "..Q."],
 *
 *         ["..Q.",  // Solution 2
 *           "Q...",
 *             "...Q",
 *               ".Q.."]
 *               ]
 *
 */
class Solution {
public:
    
    void search(int x, int n, vector<string> &cur, vector<vector<string> > &solset) {
        static vector<bool> colExist(n, false);
        static vector<bool> toUpRightExist(n+n, false);
        static vector<bool> toDownRightExist(n+n, false);

        if (x == n) {
            solset.push_back(cur);
            return;
        }
        for (int y = 0; y < n; y++) {
            if (!colExist[y] && !toUpRightExist[x+y] && !toDownRightExist[x-y+n]) {
                cur[x][y] = 'Q';
                colExist[y] = true;
                toUpRightExist[x+y] = true;
                toDownRightExist[x-y+n] = true;
                
                search(x+1, n, cur, solset);
                
                cur[x][y] = '.';
                colExist[y] = false;
                toUpRightExist[x+y] = false;
                toDownRightExist[x-y+n] = false;
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > solset;
        vector<string> cur(n, "");
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                cur[i] += '.';
            }
        }
        search(0, n, cur, solset);
        return solset;
    }
};
