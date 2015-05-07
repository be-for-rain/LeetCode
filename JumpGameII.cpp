/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */
/*
 * Sol:
 *		sort & greedy algorithm
 */
class Solution {
public:
    
    int jump(int A[], int n) {
        int step = 0;
        if (n <= 1) {
            return 0;
        }
        int i = 0;
        for (int pos = 0, max_pos = 0+A[0]; pos+1 < n; step++) {
            pos = max_pos;
            for (; i <= pos && i < n; i++) {
                if (i+A[i] > max_pos) {
                    max_pos = i+A[i];
                }
            }
        }
        return step;
    }
};
