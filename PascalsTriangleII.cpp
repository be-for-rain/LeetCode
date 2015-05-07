/*
 * Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 */
class Solution {
public:
    int pickSomeOut(int picknum, int totnum) {
    	long long ans = 1;
    	for (int i = picknum+1, j = 1; i <= totnum; i++, j++) {
    		ans *= i;
    		if (j <= totnum-picknum)
    			ans /= j;
    	}
    	return (int)ans;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> seq;
        for (size_t i = 0; i <= rowIndex; i++) {
            seq.push_back(pickSomeOut(i, rowIndex));
        }
        return seq;
    }
};
