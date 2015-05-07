/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *        / \
 *          9  20
 *              /  \
 *                 15   7
 *                 return its level order traversal as:
 *                 [
 *                   [3],
 *                     [9,20],
 *                       [15,7]
 *                       ]
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
    vector<vector<int> > levelOrder(TreeNode *root) {
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
        return ans;
    }
};
