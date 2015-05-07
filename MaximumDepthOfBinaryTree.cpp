/*
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode *root) {
        queue<pair<TreeNode *, int> > q;
        if (root == NULL)
            return 0;
        q.push(make_pair(root, 1));
        int max_depth = 1;
        while (!q.empty()) {
            pair<TreeNode*, int> cur = q.front();
            q.pop();
            TreeNode *node = cur.first;
            int depth = cur.second;
            max_depth = depth;
            if (node->left) {
                q.push(make_pair(node->left, depth+1));
            }
            if (node->right) {
                q.push(make_pair(node->right, depth+1));
            }
        }
        return max_depth;
    }
};
