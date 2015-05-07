/*
 * Given a collection of integers that might contain duplicates, S, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,2], a solution is:
 *
 * [
 *   [2],
 *     [1],
 *       [1,2,2],
 *         [2,2],
 *           [1,2],
 *             []
 *             ]
 */

class Solution {
public:
    void subsetsWithDupSub(vector<int> &candidates, int k, vector<bool> &chosen, vector<vector<int> > &ans) {
        if (k == candidates.size()) {   //an answer found
            vector<int> sol;
            for (int i = 0; i < candidates.size(); i++) {
                if (chosen[i]) 
                    sol.push_back(candidates[i]);
            }
            ans.push_back(sol);
            return;
        }
        //not chosen
        chosen.push_back(false);
        subsetsWithDupSub(candidates, k+1, chosen, ans);
        chosen.pop_back();
        
        //chosen
        //check whether k-th element can be chosen
        if (k > 0 && candidates[k] == candidates[k-1] && !chosen[k-1]) 
            return;
        chosen.push_back(true);
        subsetsWithDupSub(candidates, k+1, chosen, ans);
        chosen.pop_back();
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<bool> chosen;
        vector<vector<int> > ans;
        subsetsWithDupSub(S, 0, chosen, ans);
        return ans;
    }
};
