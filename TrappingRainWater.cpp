/*
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */

class Solution {
	public:
		int getWaterBetween(const vector<int> &height, const vector<int> &presum, int left_pos, int right_pos) {
			int nonwater_area = presum[right_pos-1] - presum[left_pos];//(left_pos, right_pos)
			int water_level = min(height[left_pos], height[right_pos]);
			return water_level * (right_pos - left_pos - 1) - nonwater_area;
		}

		int getWaterTrapped(const vector<int> &height, const vector<int> &presum, const vector<int> &right_pair_pos) {
			int water = 0;
			int left_pos = 0;
			while (left_pos+1 < height.size()) {//[ATTENTION!!] height.size() is unsigned! left_pos < height.size()-1 will lead to runtime error when height.size() == 0
				water += getWaterBetween(height, presum, left_pos, right_pair_pos[left_pos]);
				left_pos = right_pair_pos[left_pos];
			}
			return water;
		}

		void arrayToVector(int A[], int n, vector<int> &height) {
			for (int i = 0; i < n; i++)
				height[i] = A[i];
		}

		void calcRightPairPos(const vector<int> &height, vector<int> &right_pair_pos) {
			stack<int> stk;
			for (size_t i = 0; i < height.size(); i++) {
				while (!stk.empty() && height[stk.top()] <= height[i]) {
					right_pair_pos[stk.top()] = i;
					stk.pop();
				}
				if (!stk.empty()) {
					right_pair_pos[stk.top()] = i;
				} 
				stk.push(i);
			}
		}

		void calcHeightPresum(const vector<int> &height, vector<int> &presum) {
			if (height.size() > 0) 
				presum[0] = height[0];
			for (size_t i = 1; i < height.size(); i++)
				presum[i] = presum[i-1] + height[i];
		}


		int trap(int A[], int n) {
			vector<int> height(n, 0), presum(n, 0), right_pair_pos(n, 0);
			arrayToVector(A, n, height);
			calcRightPairPos(height, right_pair_pos);
			calcHeightPresum(height, presum);
			return getWaterTrapped(height, presum, right_pair_pos);
		}
};
