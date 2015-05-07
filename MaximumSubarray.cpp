/*
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 *
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 */
class Solution {
public:
    int maxSubArray(int A[], int n) {
        vector<int> f(n);//end with i, the max sub array sum
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (i > 0 && f[i-1] > 0) {
                f[i] = f[i-1]+A[i];
            } else {
                f[i] = A[i];
            }
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
