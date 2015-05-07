/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *     1
 *        / \
 *          2   2
 *           / \ / \
 *           3  4 4  3
 *           But the following is not:
 *               1
 *                  / \
 *                    2   2
 *                       \   \
 *                          3    3
 *                          Note:
 *                          Bonus points if you could solve it both recursively and iteratively.
 *
 * Sol:
 *		for a subtree "root"
 *		whether (root->left, root->right) is symmetric depends on whether
 *			(root->left->right, root->right->left) is symmetric
 *			(root->left->left, root->right->right) is symmetric
 *		so we can solve it recursively
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
    bool isTwoSymmetric(TreeNode *a, TreeNode *b) 
    {
        if (a == NULL || b == NULL) {
            return a == b;
        }
        if (a->val != b->val) {
            return false;
        }
        if (!isTwoSymmetric(a->right, b->left) || !isTwoSymmetric(a->left, b->right)) {
            return false;
        }
        return true;
    }
    
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        return isTwoSymmetric(root->left, root->right);
    }
};
