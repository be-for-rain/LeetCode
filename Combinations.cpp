/*
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * For example,
 * If n = 4 and k = 2, a solution is:
 *
 * [
 *   [2,4],
 *     [3,4],
 *       [2,3],
 *         [1,2],
 *           [1,3],
 *             [1,4],
 *             ]
 */
class Solution {
public:
    void search(int n, int k, int pos, vector<vector<int>> &solset) {
        static vector<int> path;
        if (k == 0) {
            solset.push_back(path);
            return;
        }
        for (int i = pos; i <= n; i++) {
            path.push_back(i);
            search(n, k-1, i+1, solset);
            path.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> solset;
        search(n, k, 1, solset);
        return solset;
    }
};
