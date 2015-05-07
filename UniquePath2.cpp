/*
 * Follow up for "Unique Paths":
 *
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 *
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 *
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 *
 * [
 *   [0,0,0],
 *     [0,1,0],
 *       [0,0,0]
 *       ]
 *       The total number of unique paths is 2.
 *
 *       Note: m and n will be at most 100.
 */

class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
			size_t m = obstacleGrid.size();
			size_t n = m ? obstacleGrid[0].size() : 0;
			if (m == 0 || n == 0) {
				return 0;
			}
			vector<vector<int > > f(m+1);
			for (size_t i = 0; i < m+1; i++) {
				f[i].resize(n+1, 0);
			}
			f[0][0] = 1;
			for (size_t i = 0; i < m; i++) {
				for (size_t j = 0; j < n; j++) {
					if (obstacleGrid[i][j]) {
						f[i][j] = 0;
					}
					f[i+1][j] += f[i][j];
					f[i][j+1] += f[i][j];
				}
			}
			return f[m-1][n-1];

		}
};
