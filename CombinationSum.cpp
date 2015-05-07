/*
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 *
 * Sol:
 *		recursion
 */

class Solution {
public:
    bool foundCombinationSum(vector<int> &candidates, vector<int>::reverse_iterator st_it, int target, vector<vector<int> > &ans) {
        if (target == 0) {
            return true;
        }
        if (target < 0) {
            return false;
        }
        bool found = false;
        for (vector<int>::reverse_iterator it = st_it; it != candidates.rend(); ++it) {
            vector<vector<int> > subans;
            if (foundCombinationSum(candidates, it, target-(*it), subans)) {
                found = true;
                if (subans.size() == 0) {
                    subans.resize(1);
                }
                for (int i = 0; i < subans.size(); ++i) {
                    subans[i].push_back(*it);
                    ans.push_back(subans[i]);
                }
            }
        }
        return found;
    }    
        
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        foundCombinationSum(candidates, candidates.rbegin(), target, ans);
        return ans;
    }
};
