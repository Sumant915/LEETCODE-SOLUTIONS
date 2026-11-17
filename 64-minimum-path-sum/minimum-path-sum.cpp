class Solution {
public:
    int fun(int m,int n,vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=m || j>=n) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        int right=fun(m,n,grid,i+1,j,dp);
        // sum-=grid[i][j];
        int down=fun(m,n,grid,i,j+1,dp);
        return dp[i][j]=grid[i][j]+min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        // int ans=INT_MAX;
        // int sum=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m,n,grid,0,0,dp);
    }
};