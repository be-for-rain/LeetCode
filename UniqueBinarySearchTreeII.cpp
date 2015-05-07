/*
 * Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 *
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 *
 *    1         3     3      2      1
 *        \       /     /      / \      \
 *             3     2     1      1   3      2
 *                 /     /       \                 \
 *                    2     1         2                 3
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
    vector<TreeNode *>generate(int left, int right) {
        vector<TreeNode *>ans;
        if (left > right) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = left; i <= right; i++) {
            vector<TreeNode *> lans = generate(left, i-1);
            vector<TreeNode *> rans = generate(i+1, right);
            for (int j = 0; j < lans.size(); j++) {
                for (int k = 0; k < rans.size(); k++) {
                    TreeNode *node = new TreeNode(i);
                    node->left = lans[j];
                    node->right = rans[k];
                    ans.push_back(node);
                }
            }
        }
        return ans;
    }

    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
};
