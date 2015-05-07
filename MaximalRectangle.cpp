/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 */
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int nrow = matrix.size();
        int ncol = matrix.size() ? matrix[0].size() : 0;
        vector<int> f(ncol+1, 0);
        vector<vector<int>> presum(nrow+1, f);
        for (int i = 1; i <= nrow; i++) {
            for (int j = 1; j <= ncol; j++) {
                int val = matrix[i-1][j-1]-'0';
                presum[i][j] = val+presum[i][j-1]+presum[i-1][j]-presum[i-1][j-1];
            } 
        }
        int maxarea = 0;
        for (int rows = 1; rows <= nrow; rows++) {
            for (int i = rows; i <= nrow; i++) {
                f.clear();
                f.resize(ncol+1, 0);
                for (int j = 1; j <= ncol; j++) {
                    if (presum[i][j]-presum[i-rows][j]-presum[i][j-1]+presum[i-rows][j-1] == rows) {
                        f[j] = f[j-1]+rows;
                        maxarea = max(maxarea, f[j]);
                    }
                }
            }
        }
        return maxarea;
    }
};
