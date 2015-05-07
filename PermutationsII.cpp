/*
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 */
class Solution {
public:
    void search(vector<int> &num, int pos, vector<vector<int> > &ans) {
        static vector<bool> used(num.size(), false);
        static vector<int> path;
        if (pos == num.size()) {
            ans.push_back(path);
            return;
        }
        int pre = -1;
        for (int i = 0; i < num.size(); i++) {
            if (!used[i]) {
                if (pre == -1 || num[i] != num[pre]) {
                    used[i] = true;
                    path.push_back(num[i]);
                    search(num, pos+1, ans);
                    path.pop_back();
                    used[i] = false;
                }
                pre = i;
            }
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > ans;
        search(num, 0, ans);
        return ans;
    }
};
