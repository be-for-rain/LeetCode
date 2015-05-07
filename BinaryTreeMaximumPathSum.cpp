/*
 * Given a binary tree, find the maximum path sum.
 *
 * The path may start and end at any node in the tree.
 */


/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
	public:
		int maxPathSum(TreeNode *root, int &max_sum) {
			if (root == NULL) {
				max_sum = 0;
				return INT_MIN;
			}
			int left_max, right_max;//left_max_sum
			int left_ans = maxPathSum(root->left, left_max);
			int right_ans = maxPathSum(root->right, right_max);
			max_sum = max(0, max(left_max, right_max))+root->val;
			return max(max_sum, max(max(left_ans, right_ans), left_max+root->val+right_max));

		}

		int maxPathSum(TreeNode *root) {
			int max_sum = INT_MIN;
			return maxPathSum(root, max_sum);
		}
};
