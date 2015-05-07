/*
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = (m+n+1)/2;
        int pa = 0, pb = 0;
        while (k > 1) {
            if (pa+k/2-1 >= m || (pb+k/2-1 < n && A[pa+k/2-1] > B[pb+k/2-1])) {
                pb += k/2;
            } else {
                pa += k/2;
            }
            k -= k/2;
        }
        int ntimes = 2-(m+n)%2;
        double sum = 0;
        for (int k = 0; k < ntimes; k++) {
            if (pb >= n || (pa < m && A[pa] <= B[pb])) {
                sum += A[pa];
                pa++;
            } else {
                sum += B[pb];
                pb++;
            }
        }
        return sum/ntimes;
    }
};
