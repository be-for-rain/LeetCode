/*
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 *
 * Solution:
 *		judge its left && right subtrees recursively
 *
 */

/**
 *  Definition for binary tree
 *   struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		bool isSameTree(TreeNode *p, TreeNode *q) {
			if (!p && !q) {
				return true;
			}
			if (p && q) {
				if (!isSameTree(p->left, q->left)) {
					return false;
				}
				if (!isSameTree(p->right, q->right)) {
					return false;
				}
				if (p->val != q->val){
					return false;
				}
				return true;
			}
			return false;
		}
};

