/*
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 *  return [1,3,2].
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
    void traverse(vector<int> &ans, TreeNode *p) {
        if (p == NULL){
            return;
        }
        traverse(ans, p->left);
        ans.push_back(p->val);
        traverse(ans, p->right);
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        traverse(ans, root);
        return ans;
    }
};
