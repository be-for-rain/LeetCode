/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 */
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int> > f(grid);
        for (int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0) {
                    if (j > 0) {   //i==0, j > 0
                        f[i][j] += f[i][j-1];
                    }
                } else {
                    if (j == 0) {//i>0, j==0
                        f[i][j] += f[i-1][j];
                    } else {//i>0, j>0
                        f[i][j] += min(f[i][j-1], f[i-1][j]);
                    }
                }
            }
        return f.back().back();
    }
};
