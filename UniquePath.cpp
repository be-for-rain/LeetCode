/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int > > f(m+1);
        for (size_t i = 0; i < m+1; i++) {
            f[i].resize(n+1, 0);
        }
        f[0][0] = 1;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                f[i+1][j] += f[i][j];
                f[i][j+1] += f[i][j];
            }
        }
        return f[m-1][n-1];
    }
};
