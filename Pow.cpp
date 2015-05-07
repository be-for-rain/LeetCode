/*
 * Implement pow(x, n).
 */
class Solution {
public:
    double pow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        double ans = 1;
        double coefficient = x;
        for (int num = n; num; num /= 2, coefficient *= coefficient) {
            if (num % 2) {
                if (num >= 0){
                    ans *= coefficient;
                }else{
                    ans /= coefficient;
                }
            }
        }
        return ans;
    }
};
