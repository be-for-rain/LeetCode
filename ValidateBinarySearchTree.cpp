/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
 *
 * Sol:
 *	a valid BST means
 *		its left subtree is a valid BST
 *		the max value of its left subtree < root->val
 *		its right subtree is a valid BST
 *		the min value of its right subtree > root->val
 *	So I use checkBST() to get the min & max value of a subtree, and return whether it's a valid BST
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
    bool checkBST(TreeNode *root, int& min_val, int& max_val) {
        if (root == NULL) {
            return true;
        }
        if (root->val < min_val) {
            min_val = root->val;
        }
        if (root->val > max_val) {
            max_val = root->val;
        }
        if (root->left) {
            int tmp_max_val = root->left->val;
            if (!checkBST(root->left, min_val, tmp_max_val) || tmp_max_val >= root->val) {
                return false;
            }
        }
        if (root->right) {
            int tmp_min_val = root->right->val;
            if (!checkBST(root->right, tmp_min_val, max_val) || tmp_min_val <= root->val) {
                return false;
            }
        }
        return true;
    }

    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        int val1 = root->val, val2 = root->val;
        return checkBST(root, val1, val2);
    }
};
