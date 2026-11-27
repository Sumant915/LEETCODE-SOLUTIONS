class Solution {
public:
    int fun(vector<int>&costs,int j,vector<int>&dp){
        if(j<=0) return 0;
        if(dp[j-1]!=-1) return dp[j-1];
        int p=INT_MAX,q=INT_MAX,r=INT_MAX;
        if(j>=1){
             p=costs[j-1]+1+fun(costs,j-1,dp);
        }
        if(j>=2){
            q=costs[j-1]+4+fun(costs,j-2,dp);
        }
        if(j>=3){ 
             r=costs[j-1]+9+fun(costs,j-3,dp);
        }
        return dp[j-1]=min(p,min(q,r));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n,-1);
        return fun(costs,n,dp);
    }
};