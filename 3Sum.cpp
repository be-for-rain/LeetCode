/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 *     For example, given array S = {-1 0 1 2 -1 -4},
 *
 *         A solution set is:
 *             (-1, 0, 1)
 *                 (-1, -1, 2)
 */

class Solution {
public:
    int getSum(const vector<int> &numbers) {
        int sum = 0;
        for (size_t i = 0; i < numbers.size(); i++) {
            sum += numbers[i];
        }
        return sum;
    }

    void search(int pos, vector<int> &candidates, const vector<int> &num, vector<vector<int> > &ans) {
        if (candidates.size() == 3) {
            if (getSum(candidates) == 0)
                ans.push_back(candidates);
            return;
        }
        for (size_t i = pos; i < num.size(); i++) {
            if (i == pos || num[i] != num[i-1]) {
                candidates.push_back(num[i]);
                search(i+1, candidates, num, ans);
                candidates.pop_back();
            }
        }
    }

    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        vector<int> candidates;
        sort(num.begin(), num.end());
        search(0, candidates, num, ans);
        return ans;
    }
};
