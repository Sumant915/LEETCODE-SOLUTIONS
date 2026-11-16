class Solution {
public:
    int fun(int m,int n,int i,int j,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid){
        if(i<0 || j<0 || i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(obstacleGrid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) {
            return 1;
        }
        int down=fun(m,n,i+1,j,dp,obstacleGrid);
        int right=fun(m,n,i,j+1,dp,obstacleGrid);
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m,n,0,0,dp,obstacleGrid);
    }
};