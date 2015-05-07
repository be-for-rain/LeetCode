/*
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 */
class Solution {
public:
    void search(int x, int n, int &ansnum) {
        static vector<bool> colExist(n, false);
        static vector<bool> toUpRightExist(n+n, false);
        static vector<bool> toDownRightExist(n+n, false);

        if (x == n) {
            ansnum++;
            return;
        }
        for (int y = 0; y < n; y++) {
            if (!colExist[y] && !toUpRightExist[x+y] && !toDownRightExist[x-y+n]) {
                colExist[y] = true;
                toUpRightExist[x+y] = true;
                toDownRightExist[x-y+n] = true;
                
                search(x+1, n, ansnum);
                
                colExist[y] = false;
                toUpRightExist[x+y] = false;
                toDownRightExist[x-y+n] = false;
            }
        }
    }


    int totalNQueens(int n) {
        int ansnum = 0;
        search(0, n, ansnum);
        return ansnum;
    }
};
