/*
 * There are N children standing in a line. Each child is assigned a rating value.
 *
 * You are giving candies to these children subjected to the following requirements:
 *
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */
class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> left(ratings.size(), 1), right(ratings.size(), 1);
        for (size_t i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                left[i] = left[i-1]+1;
            } 
        }
        for (int i = ratings.size()-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                right[i] = right[i+1]+1;
            }
        }
        int sum = 0;
        for (size_t i = 0; i < ratings.size(); i++) {
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};
