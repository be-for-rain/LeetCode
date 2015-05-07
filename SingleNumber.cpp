/*
   Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

	Sol:
		since a ^ a = 0, ^ all these int up, the result will equal the single number
*/

class Solution {
	public:
		//since a ^ a = 0, every pair will generate 0
		//so ^ them up, the result will equal the single number 
		int singleNumber(int A[], int n) {
			int ans = 0;
			for (int i = 0; i < n; i++)
				ans ^= A[i];
			return ans;
		}
};
