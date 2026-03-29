class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // Step 1: compute the minimum of each row
        vector<int> rowMin(m, INT_MAX);

        // Step 2: compute the maximum of each column
        vector<int> colMax(n, INT_MIN);

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        // Step 3: find all elements that are both row min and column max
        vector<int> result;
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) 
                {
                    result.push_back(matrix[i][j]);
                }
            }
        }

        return result;
    }
};