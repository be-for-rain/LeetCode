/*
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 *
 * Sol :
 *		pick out the legal one while looping`
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (len < 2 || !(A[i] == A[len-1] && A[i] == A[len-2])) {
                A[len++] = A[i];
            }
        }
        return len;
    }
};
