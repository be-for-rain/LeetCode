/*
 * Given an array of integers, every element appears three times except for one. Find that single one.
 *
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
class Solution {
public:
    int singleNumber(int A[], int n) {
        int max_time = 3;
        vector<int> num(n, 0);
        num[0] = ~0;
        for (int i = 0; i < n; i++) {
            int all_num_or = 0;
            for (int j = max_time-1; j > 0; j--) {
                num[j] &= ~(A[i] & num[j]);
                num[j] ^= A[i] & num[j-1];
                all_num_or ^= num[j];
            }
            num[0] = ~all_num_or;
        }
        return num[1];
    }
};
