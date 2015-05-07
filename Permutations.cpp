/*
 * Given a collection of numbers, return all possible permutations.
 *
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 *
 */
class Solution {
public:
    void permuteSub(vector<int> &num, int k, vector<vector<int> > &ans) {
        if (k == num.size()) {
            ans.push_back(num);
            return;
        }
        for (int i = k; i < num.size(); i++) {
            swap(num[i], num[k]);
            permuteSub(num, k+1, ans);
            swap(num[i], num[k]);
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ans;
        permuteSub(num, 0, ans);
        return ans;
    }
};
