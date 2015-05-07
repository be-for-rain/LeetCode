class Solution {
public:
    int getOrderedPairStartPos(vector<int> &num) {
        for (int i = num.size()-1; i > 0; i--) {
            if (num[i-1] < num[i]) {
                return i-1;
            } 
        }
        return -1;
    }

    void nextPermutation(vector<int> &num) {
        int st = getOrderedPairStartPos(num);
        if (st == -1) {
            reverse(num.begin(), num.end());
        } else {
            int candidate = st+1;
            for (int i = st+1; i < num.size() && num[st] < num[i]; i++) {
                candidate = i;
            }
            swap(num[st], num[candidate]);
            sort(num.begin()+st+1, num.end());
        }
    }
};