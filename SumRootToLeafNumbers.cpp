/*
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * For example,
 *
 *     1
 *        / \
 *          2   3
 *          The root-to-leaf path 1->2 represents the number 12.
 *          The root-to-leaf path 1->3 represents the number 13.
 *
 *          Return the sum = 12 + 13 = 25.
 *
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
    void getSumNumbers(TreeNode *root, int num, int &sum) {
        if (root == NULL) {
            return;
        }
        num = num*10 + root->val;
        if (root->left == NULL && root->right == NULL) {//it's a leaf
            sum += num;
            return;
        }
        getSumNumbers(root->left, num, sum);
        getSumNumbers(root->right, num, sum);
    }
    
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        getSumNumbers(root, 0, sum);
        return sum;
    }
};
