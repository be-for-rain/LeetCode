/*
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 *
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 *
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 *
 * For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */
class Solution {
public:
    inline int reverseKthDigit(int num, int k) {
        return num ^ (1<<k);
    }
    
    bool search(int nbits, vector<int> &path, vector<bool> &used) {
        if (path.size()==1<<nbits) {
            return true;
        }
        int pre = path.back();
        for (int i = 0; i < nbits; i++) {
            int num = reverseKthDigit(pre, i);
            if (!used[num]) {
                used[num] = true;
                path.push_back(num);
                if (search(nbits, path, used)) {
                    return true;
                }
                path.pop_back();
                used[num] = false;
            }
        }
        
    }

    vector<int> grayCode(int n) {
        vector<int> path(1, 0);
        vector<bool> used(1<<n, false);
        used[0] = true;
        search(n, path, used);
        return path;
    }
};
