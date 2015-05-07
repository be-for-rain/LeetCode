/*
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 * Sol:
 *	a valid BST means its inorder traversal is a sorted array
 *	so traverse and check it on the fly
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
    bool checkTraverse(TreeNode *root, TreeNode *&pre) {
        if (root == NULL) {
            return true;
        }
        if (!checkTraverse(root->left, pre)) {
            return false;
        }
        if (pre && root->val <= pre->val) {
            return false;
        }
        pre = root;
        if (!checkTraverse(root->right, pre)) {
            return false;
        }
        return true;
    }
    
    bool isValidBST(TreeNode *root) {
        TreeNode *tmp = NULL;
        return checkTraverse(root, tmp);    
    }
};
