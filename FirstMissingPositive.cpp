/*
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 */

class Solution {
	public:
		int getFirstMissingPositive(int *&A, int n) {
			for (size_t i = 0; i < n; i++) {
				if (A[i] != i+1) {
					return i+1;
				}
			}
			return n+1;
		}

		void place(int pos, int *&A, int n) {
			if (A[pos] <= 0 || A[pos] > n || A[pos] == pos+1) {
				A[pos] = pos+1;
				return;
			}
			int next_pos = A[pos]-1;
			A[pos] = pos+1;
			place(next_pos, A, n);
		}

		void replace(int *&A, int n) {
			for (size_t i = 0; i < n; i++) {
				if (A[i] > 0 && A[i] <= n && A[i] != i+1) {
					int next_pos = A[i]-1;
					A[i] = 0;
					place(next_pos, A, n);
				}
			}
		}

		int firstMissingPositive(int A[], int n) {
			replace(A, n);
			return getFirstMissingPositive(A, n);
		}
};
