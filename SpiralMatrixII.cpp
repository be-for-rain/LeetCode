/*
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 *
 * For example,
 * Given n = 3,
 *
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *   [ 8, 9, 4 ],
 *    [ 7, 6, 5 ]
 *    ]
 */

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        static int dr[] = {0, 1, 0, -1};
        static int dc[] = {1, 0, -1, 0};
        
        vector<vector<int> > matrix(n);
        for (size_t i = 0; i < n; i++) {
            matrix[i].resize(n, 0);
        }
        int pr = 0, pc = 0; //position row/column
        int num = 1;
        for (int len = n-1; len > 0; len -= 2) {
            for (int dir = 0; dir < 4; dir++) {
                for (int j = 0; j < len; j++) {
                    matrix[pr][pc] = num++;
                    pr += dr[dir];
                    pc += dc[dir];
                }
            }
            pr += 1;
            pc += 1;
        }
        if (num <= n*n) {
            matrix[pr][pc] = num;
        }
        return matrix;
    }
};
