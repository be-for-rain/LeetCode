/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *                            / \
 *                                        4   8
 *                                                   /   / \
 *                                                             11  13  4
 *                                                                      /  \    / \
 *                                                                              7    2  5   1
 *                                                                              return
 *                                                                              [
 *                                                                                 [5,4,11,2],
 *                                                                                    [5,8,4,5]
 *                                                                                    ]
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > helpPathSum(TreeNode *root, int sum) {
       vector<vector<int> > ans;
       if (root == NULL) {
           return ans;
       }
       if (!root->left && !root->right && (sum == root->val)) {
           ans.resize(1);
           ans[0].push_back(root->val);
           return ans;
       }
       vector<vector<int> > left_paths = helpPathSum(root->left, sum-root->val);
       vector<vector<int> > right_paths = helpPathSum(root->right, sum-root->val);
       ans.insert(ans.end(), left_paths.begin(), left_paths.end());
       ans.insert(ans.end(), right_paths.begin(), right_paths.end());
       for (vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it) {
           it->push_back(root->val);
       }
       return ans;
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans = helpPathSum(root, sum);
        for (vector<vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it) {
            reverse(it->begin(), it->end());
        }
        return ans;
    }
};
