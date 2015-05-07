/*
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 *
 * Sol:
 *		Binary Search
 */

class Solution {
public:
    int binSearchMin(int A[], int st, int ed, int target) {
        if (st == ed) 
            return -1;
        int mid = (st+ed) / 2;
        if (A[mid] == target && (mid == 0 || A[mid] > A[mid-1]))
            return mid;
        if (A[mid] >= target) 
            return binSearchMin(A, st, mid, target);
        else
            return binSearchMin(A, mid+1, ed, target);
    }
    
    int binSearchMax(int A[], int st, int ed, int target) {
        if (st == ed) 
            return -1;
        int mid = (st+ed) / 2;
        if (A[mid] == target && (mid == ed-1 || A[mid] < A[mid+1]))
            return mid;
        if (A[mid] > target) 
            return binSearchMax(A, st, mid, target);
        else
            return binSearchMax(A, mid+1, ed, target);
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans;
        ans.push_back(binSearchMin(A, 0, n, target));
        ans.push_back(binSearchMax(A, 0, n, target));
        return ans;
    }
};
