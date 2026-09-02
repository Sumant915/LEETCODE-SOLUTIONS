class Solution {
public:
    int findans(int index,int n,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(index>=n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy==1){
            return dp[index][buy]=max(-prices[index]+findans(index+1,n,0,prices,dp),
            findans(index+1,n,1,prices,dp));
        }
        else{
            return dp[index][buy]= max(prices[index]+findans(index+2,n,1,prices,dp),
            findans(index+1,n,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return findans(0,n,1,prices,dp);
    }
};