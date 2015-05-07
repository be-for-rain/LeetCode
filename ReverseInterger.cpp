/*
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * click to show spoilers.
 *
 * Have you thought about this?
 * Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 *
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 *
 * Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 *
 * Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
 *
 * Sol:
 *		since I'm preparing for the final exam of Programming II and is reviewing sth about recursion.. I tried to solve this by recursion as well..
 *		by designing a subsidiary function with another parameter about length of the number
 */

class Solution {
public:
    //reverse x whose length is len (10 ^ len = tenPowerLen)
    int helpReverse(int x, int tenPowerLen) {
        if (tenPowerLen == 1) {//len == 0
            return x;
        }
        int tmp = tenPowerLen / 10; // 10 ^ (len-1);
        return helpReverse(x/10, tmp) + x%10 * tmp;
    }

    int reverse(int x) {
        //get the 10 ^ len(x)
        int abs_x = abs(x);
        int tenPowerLen = 1;    //len = 0
        while (tenPowerLen < abs_x) {
            tenPowerLen *= 10;  //len++
        }
        return helpReverse(x, tenPowerLen); 
    }
};
