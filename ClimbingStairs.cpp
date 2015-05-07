/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */
//Fibonacci
class Solution {
public:
    int f(int n, int x, int y) {
        if (n <= 0) {
            return x;
        }
        f(n-1, y, x+y);
    }

    int climbStairs(int n) {
        return f(n-1, 1, 2);
    }
};
