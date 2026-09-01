class Solution {
public:
   int findans(int index,int n,int buy,int transaction,vector<int>&prices, vector<vector<vector<int>>>&dp){
        if(index==n || transaction==0) return 0;
        if(dp[index][buy][transaction]!=-1) return dp[index][buy][transaction];
        if(buy==1){
            return dp[index][buy][transaction]=max(-prices[index]+findans(index+1,n,0,transaction,prices,dp),
            findans(index+1,n,1,transaction,prices,dp));
        }
        else{
            return dp[index][buy][transaction]= max(prices[index]+findans(index+1,n,1,transaction-1,prices,dp),
            findans(index+1,n,0,transaction,prices,dp));
        }

    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return findans(0,n,1,k,prices,dp);
    }
};