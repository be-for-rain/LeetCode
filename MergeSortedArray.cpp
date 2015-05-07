/*
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 *
 * Sol : 
 *		in order to do it in-place, do it downward
 *		choose the max number of A, B(from the tail) to fill in the tail of A
 */

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int pa = m-1, pb = n-1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (pa>=0 && (pb<0 || A[pa] > B[pb])) {
                A[i] = A[pa--];
            } else {
                A[i] = B[pb--];
            }
        }
    }
};
