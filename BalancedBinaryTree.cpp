/*
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *
 *
 * Sol:
 *	a balanced subtree means
 *		its left & right subtree is balanced
 *		delta of its left & right depth is within 1
 *	so we can do it recursively
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
    bool isBalanced(TreeNode *node, int &depth) {
        if (node == NULL) {
            return true;
        }
        int left_depth = 0, right_depth = 0;
        if (!isBalanced(node->left, left_depth) || !isBalanced(node->right, right_depth)) {
            return false;
        }
        if (abs(left_depth-right_depth) > 1) {
            return false;
        }
        depth = max(left_depth, right_depth) + 1;
        return true;
    }

    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalanced(root, depth);
    }
};
