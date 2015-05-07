/*
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 * [
 *      [2],
 *          [3,4],
 *             [6,5,7],
 *               [4,1,8,3]
 *               ]
 *               The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 *               Note:
 *               Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 *
 *
 */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) {
            return INT_MAX;
        }
        int max_row_id = triangle.size()-1;
        vector<vector<int> > f(triangle.size());
        for (size_t i = 0; i < f.size(); i++) {
            f[i].resize(triangle[i].size(), INT_MAX);
        }
        f[0][0] = triangle[0][0];
        for (size_t i = 0; i+1 < triangle.size(); i++) {
            for (size_t j = 0; j < triangle[i].size(); j++) {
                f[i+1][j] = min(f[i][j]+triangle[i+1][j], f[i+1][j]);
                f[i+1][j+1] = min(f[i][j]+triangle[i+1][j+1], f[i+1][j+1]);
            }
        }
        int min_path_sum = f[max_row_id][0];
        for (size_t i = 1; i < triangle[max_row_id].size(); i++) {
            min_path_sum = min(min_path_sum, f[max_row_id][i]);
        }
        return min_path_sum;
    }
};
