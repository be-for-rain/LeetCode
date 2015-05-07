/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 */
class Solution {
public:
    //ensure x >= 0
    int reverse(int x) {
        int ans = 0;
        while (x) {
            ans = ans * 10 + x%10;
            x /= 10;
        }
        return ans;
    }
    
    bool isPalindrome(int x) {
        if (x < 0) 
            return false;
        int y = reverse(x);
        return x == y;
    }
};
