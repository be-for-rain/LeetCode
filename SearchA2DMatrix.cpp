/*
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 *
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 *
 * Consider the following matrix:
 *
 * [
 *   [1,   3,  5,  7],
 *     [10, 11, 16, 20],
 *       [23, 30, 34, 50]
 *       ]
 *       Given target = 3, return true.
 */
class Solution {
public:
    int locateRow(vector<vector<int> > &matrix, int target) {
        int left = 0, right = matrix.size()-1;
        while (left < right) {
            int mid = (left + right+1) / 2;
            if (matrix[mid].front() > target) {
                right = mid-1;
            } else {
                left = mid;
            }
        }
        if (matrix[left].front() <= target && matrix[left].back() >= target) {
            return left;
        }
        return -1;
    }

    bool inRow(vector<int> &num, int target) {
        int left = 0, right = num.size()-1;
        while (left < right) {
            int mid = (left+right) / 2;
            if (num[mid] < target) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        return num[left]==target;
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int row = locateRow(matrix, target);
        return row != -1 && inRow(matrix[row], target);
    }
};
