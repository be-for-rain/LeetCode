/*
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 */
class Solution {
public:
    int getLength(int val, unordered_set<int> &nums) {
        if (nums.find(val) == nums.end()) {
            return 0;
        }
        nums.erase(val);
        int left_len = getLength(val-1, nums);
        int right_len = getLength(val+1, nums);
        return left_len+1+right_len;
        
    }

    int longestConsecutive(vector<int> &num) {
        unordered_set<int> nums;
        for (int i = 0; i < num.size(); i++) {
            nums.insert(num[i]);
        }
        int maxlen = 0;
        for (int i = 0; i < num.size(); i++) {
            int len = getLength(num[i], nums);
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};
