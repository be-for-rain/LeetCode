/*
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 *
 */
//[ATTENTION!!] int/int will get int!!   should be (double)int/int

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int ans = 0;
        for (size_t i = 0; i < points.size(); i++) {
            map<double, int> slope_cnt;
            int subans = 0;
            int same_cnt = 0;
            int vertical_cnt = 0;
            for (size_t j = 0; j < points.size(); j++) {
                    if (points[j].x == points[i].x) {
                        if (points[j].y == points[i].y) {   //same point
                            same_cnt++;
                        } else {    // different point on a vertial line
                            vertical_cnt++;
                            subans = max(subans, vertical_cnt);
                        }
                    } else {    //has a slope
                        double slope = (double)(points[j].y-points[i].y) / (points[j].x-points[i].x);
                        //[ATTENTION!!] int/int will get int!!   should be (double)int/int
                        if (slope_cnt.find(slope) == slope_cnt.end()) {
                            slope_cnt[slope] = 1;
                        } else {
                            slope_cnt[slope]++;
                        }
                        subans = max(subans, slope_cnt[slope]);
                    }
            }
            ans = max(ans, subans+same_cnt);
        }
        return ans;
    }
};
