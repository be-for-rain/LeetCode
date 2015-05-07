/*
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */
/*
 * Attention!! since struct Interval is defined outside the class Solution, its compare function should be defined outside the class Solution as well, or compile error will be encountered
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
    bool cmp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }
    

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> new_intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        if (!intervals.empty()) 
            new_intervals.push_back(Interval(intervals[0].start, intervals[0].start));
        for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); ++it) {
            if (it->start <= (new_intervals.back().end)) {
                if (it->end > new_intervals.back().end) {
                    new_intervals.back().end = it->end;
                }
            } else {
                new_intervals.push_back(*it);
            }
        }
        return new_intervals;
    }
};
