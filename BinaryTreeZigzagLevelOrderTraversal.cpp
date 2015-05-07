/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *        / \
 *          9  20
 *              /  \
 *                 15   7
 *                 return its zigzag level order traversal as:
 *                 [
 *                   [3],
 *                     [20,9],
 *                       [15,7]
 *                       ]
 *  
 *
 *  Sol :
 *		[step 0] do level order travesal
 *		[step 1] reverse the vector of odd level -- reverse(ans[i].begin(), ans[i].end());
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == NULL) {
            return ans;
        }
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode*, int> cur = q.front();
            q.pop();
            TreeNode *node = cur.first;
            int depth = cur.second;
            ans.resize(depth+1);
            ans[depth].push_back(node->val);
            if (node->left) {
                q.push(make_pair(node->left, depth+1));
            }
            if (node->right) {
                q.push(make_pair(node->right, depth+1));
            }
         }
        //do zig-zag
        for (vector<vector<int> >::size_type i = 1; i < ans.size(); i += 2) {
            reverse(ans[i].begin(), ans[i].end());
        } 
    }
};
