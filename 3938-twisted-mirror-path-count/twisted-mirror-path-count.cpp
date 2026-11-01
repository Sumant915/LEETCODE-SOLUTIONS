class Solution {
public:
  int totalpaths(int r,int c,vector<vector<int>>&grid,int dir,vector<vector<vector<int>>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0 || r==n || c<0 || c==m){
            return 0;
        }
        if(r==n-1 && c==m-1){
            return 1;
        }
        if(dp[r][c][dir]!=-1) return dp[r][c][dir];
        if(grid[r][c]==1){
            if (dir==0) {
                return dp[r][c][dir]=totalpaths(r,c+1,grid,1,dp);
            }
            else {
                return dp[r][c][dir]=totalpaths(r+1,c,grid,0,dp);
            }
            return 0;
        }
        //right
        int right=totalpaths(r,c+1,grid,1,dp);
        //down
        int down=totalpaths(r+1,c,grid,0,dp);
        return dp[r][c][dir]=(right+down)%1000000007;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
        return totalpaths(0,0,grid,0,dp);
    }
};