class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> prefixsum(r, vector<int>(c));
        vector<vector<int>> answer(r, vector<int>(c));

        // prefix sum
        for(int i = 0; i < r; i++) {
            int prefix = 0;
            for(int j = 0; j < c; j++) {
                prefix += mat[i][j];
                prefixsum[i][j] = prefix;
            }
        }

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {

                int rl = max(0, i - k);
                int ru = min(r - 1, i + k);
                int cl = max(0, j - k);
                int cu = min(c - 1, j + k);

                int sum = 0;

                for(int m = rl; m <= ru; m++) {
                    int rowsum = prefixsum[m][cu];

                    if(cl > 0) {
                        rowsum -= prefixsum[m][cl - 1];
                    }

                    sum += rowsum;
                }

                answer[i][j] = sum;
            }
        }

        return answer;
    }
};