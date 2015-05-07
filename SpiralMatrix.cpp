/*
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 *
 * For example,
 * Given the following matrix:
 *
 * [
 *  [ 1, 2, 3 ],
 *   [ 4, 5, 6 ],
 *    [ 7, 8, 9 ]
 *    ]
 *    You should return [1,2,3,6,9,8,7,4,5].
 */
class Solution {
public:
    const int dr[4] = {0, 1, 0, -1};
    const int dc[4] = {1, 0, -1, 0};
    
    void readSquare(vector<int> &seq, vector<vector<int> > &matrix, int pr, int pc, vector<int> &len) {
        int maxsize = matrix.size() * matrix[0].size();
        if (len[0] == 1 && len[1] == 1) {
            seq.push_back(matrix[pr][pc]);
            return;
        }
        for (int dir = 0; dir < 4; dir++) {
            for (int i = 0; i+1 < len[dir] && seq.size() < maxsize; i++) {
                seq.push_back(matrix[pr][pc]);
                pr += dr[dir];
                pc += dc[dir];
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> seq;
        vector<int> len(4);
        if (matrix.empty()) {
            return seq;
        }
        len[1] = len[3] = matrix.size();
        len[0] = len[2] = matrix[0].size();
        int maxsize = matrix.size() * matrix[0].size();
        for (size_t i = 0; seq.size() < maxsize; i++) {
            readSquare(seq, matrix, i, i, len);
            for (int j = 0; j < 4; j++) {
                len[j] -= 2;
            }
        }
        return seq;
    }
};
