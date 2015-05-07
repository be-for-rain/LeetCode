/*
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 *
 * Would this affect the run-time complexity? How and why?
 *
 * Write a function to determine if a given target is in the array.
 */
class Solution {
public:
    bool search(int *&A, int left, int right, int target) {
        if (left > right) {
            return false;
        }
        if (left == right) {
            return A[left]==target; 
        }
        int mid = (left+right)/2;
        if (A[mid]==target) {
            return true;
        }
        if (A[mid]==A[left] && A[mid]==A[right]) {
            return search(A, left+1, mid-1, target) || search(A, mid+1, right-1, target);
        }
        if (A[mid] >= A[left]) {
            if (A[left] <= target && target <= A[mid]) {
                return search(A, left, mid, target);
            } else {
                return search(A, mid+1, right, target);
            }
        } else {
            if (A[mid] <= target && target <= A[right]) {
                return search(A, mid, right, target);
            } else {
                return search(A, left, mid-1, target);
            }
        }
    } 

    bool search(int A[], int n, int target) {
        return search(A, 0, n-1, target);
    }
};
