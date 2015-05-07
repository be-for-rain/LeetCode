/*
 *
 * Given a set of distinct integers, S, return all possible subsets.
 *
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 */

class Solution {
public:
    //to get the two solutions--whether to choose the k-th element of candidate, and store the decision into cur
    void subsetsSub(vector<int> &candidates, int k, vector<int> &cur, vector<vector<int> > &ans) {
        if (k == candidates.size()) {
            ans.push_back(cur);
            return;
        }
        //k-th element not chosen
        subsetsSub(candidates, k+1, cur, ans);
        //k-th element chosen
        cur.push_back(candidates[k]);
        subsetsSub(candidates, k+1, cur, ans);
        cur.pop_back();//remove the last element of cur--candidates[k]
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ans;
        vector<int> cur;
        subsetsSub(S, 0, cur, ans);
        return ans;
    }
};class Solution {
public:
    //to get the two solutions--whether to choose the k-th element of candidate, and store the decision into cur
    void subsetsSub(vector<int> &candidates, int k, vector<int> &cur, vector<vector<int> > &ans) {
        if (k == candidates.size()) {
            ans.push_back(cur);
            return;
        }
        //k-th element not chosen
        subsetsSub(candidates, k+1, cur, ans);
        //k-th element chosen
        cur.push_back(candidates[k]);
        subsetsSub(candidates, k+1, cur, ans);
        cur.pop_back();//remove the last element of cur--candidates[k]
    }
    
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ans;
        vector<int> cur;
        subsetsSub(S, 0, cur, ans);
        return ans;
    }
};
