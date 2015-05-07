/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *      [1],
 *          [1,1],
 *             [1,2,1],
 *               [1,3,3,1],
 *                [1,4,6,4,1]
 *                ]
 */


class Solution {
	public:
		vector<vector<int> > generate(int numRows) {
			vector<vector<int> > ans(numRows);
			for (size_t i = 0; i < numRows; i++) {
				ans[i].resize(i+1, 0);
			}
			if (numRows)
				ans[0][0] = 1;
			for (size_t i = 0; i+1 < numRows; i++) {
				for (size_t j = 0; j <= i; j++) {
					ans[i+1][j] += ans[i][j];
					ans[i+1][j+1] += ans[i][j];
				}
			}
			return ans;
		}
};
