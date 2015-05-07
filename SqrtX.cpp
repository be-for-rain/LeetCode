/*
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 */

class Solution {
public:
    bool willOverflow(int a, int b) {
        return b >= INT_MAX / a;
    }
    
    int sqrt(int x) {
        long long left = 0, right = x;
        while (left < right) {
            long long mid = (left + right + 1) / 2;
            if (willOverflow(mid, mid) || mid*mid > x) {
                right = mid-1;
            } else {
                left = mid;
            }
        }
        return left;
    }
};
