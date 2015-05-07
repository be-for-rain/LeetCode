/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 *
 * Sol:
 *		find the peak position
 *			binary search
 *			since for the peak, its value must be non-less than the left point
 *			so test the candidate, 
 *			if (A[candidate] < A[left])
 *				search(left, candidate-1);
 *			else
 *				search(candidate, right);
 *
 *			NOTE:
 *				if left+1 == right, then candidate will be left
 *				since A[candidate] >= A[left], the search range will still be [left, right]
 *				so the search boundary condition should be (left+1 >= right)
 *				or infinite loop and runtime error will be encountered
 *
 *		divide the rotated array into two sorted arrays
 *		binary search in these two sorted arrays
 */


class Solution {
	public:
		int locatePeak(int A[], int n, int left, int right) {
			if (left+1 >= right) {  //length = right-left <= 1
				if (A[left] >= A[right])//left == right || A[left] > A[right]
					return left;
				return right;
			}
			int candidate = (left + right) / 2;
			if (A[candidate] < A[left])
				return locatePeak(A, n, left, candidate-1);
			return locatePeak(A, n, candidate, right);
		}

		int locatePeak(int A[], int n) {
			return locatePeak(A, n, 0, n-1);
		}

		int locateInRange(int A[], int n, int target, int left, int right) {
			if (left > right)

				return -1;  //not found
			int candidate = (left + right) / 2;
			if (A[candidate] == target)
				return candidate;
			if (A[candidate] > target)
				return locateInRange(A, n, target, left, right-1);
			return locateInRange(A, n, target, left+1, right);  //A[candidate] < target
		}

		int search(int A[], int n, int target) {
			int peak_pos = locatePeak(A, n);
			int left_pos = locateInRange(A, n, target, 0, peak_pos);
			if (left_pos != -1)
				return left_pos;
			return locateInRange(A, n, target, peak_pos + 1, n-1);    // right_pos
		}
};
