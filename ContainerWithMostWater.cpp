/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 */

class Solution {
public:
    int getArea(int left, int right, const vector<int> &height) {
        return min(height[left], height[right]) * (right-left);
    }
    
    void constructIncreasePos(deque<int> &increase_pos, const vector<int> &height) {
        for (size_t i = 0; i < height.size(); i++) {
            if (increase_pos.empty() || height[i] > height[increase_pos.back()]){
                increase_pos.push_back(i);
            }
        }
    }
    
    void constructDecreasePos(deque<int> &decrease_pos, const vector<int> &height) {
        if (height.size() == 0)
            return;
        for (int i = height.size()-1; i >= 0; i--) {
            if (decrease_pos.empty() || height[i] > height[decrease_pos.back()]) {
                decrease_pos.push_back(i);
            }
        }
    }

    int maxArea(vector<int> &height) {
        int ans = 0;
        deque<int> increase_pos;
        deque<int> decrease_pos;
        constructIncreasePos(increase_pos, height);
        constructDecreasePos(decrease_pos, height);
        for (deque<int>::iterator left = increase_pos.begin(); left != increase_pos.end(); left++) {
            for (deque<int>::iterator right = decrease_pos.begin(); right != decrease_pos.end() && *left < *right; right++) {
                ans = max(ans, getArea(*left, *right, height));
            }
        }
        return ans;
    }
};
