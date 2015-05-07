/*
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 */
class Solution {
public:
    void calcFactorial(vector<int> &factorial) {
        factorial[0] = 1;
        int cur = 1;
        for (int i = 1; i < factorial.size(); i++) {
            cur *= i;
            factorial[i] = cur;
        }
    }

    void calcRank(int n, int k, vector<int> &rank, vector<int> &factorial) {
        int x = k;
        for (int i = 0; i < n; i++) {
            rank[i] = x / factorial[n-i-1];
            x %= factorial[n-i-1];
        }
    }
    
    string getPermutationFromRank(vector<int> &rank) {
        for (int i = rank.size()-1; i >= 0; i--) {
            for (int j = i+1; j < rank.size(); j++) {
                if (rank[j] >= rank[i]) {
                    rank[j]++;
                }
            }
        }
        string ans = "";
        for (int i = 0; i < rank.size(); i++) {
            ans += char('1'+rank[i]);
        }
        return ans;
    }


    string getPermutation(int n, int k) {
        k--;    //so the first permutation ranks 0
        vector<int> factorial(n, 0);
        calcFactorial(factorial);
        vector<int> rank(n, 0);//i-th element, rank among [i, n)
        calcRank(n, k, rank, factorial);
        return getPermutationFromRank(rank);
    }
};
