class Solution {
public:
    int findans(int index,int n,int buy,vector<int>&prices,vector<vector<int>>&dp,int fee){
        if(index==n) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy==1){
            return dp[index][buy]=max(-prices[index]+findans(index+1,n,0,prices,dp,fee),
            findans(index+1,n,1,prices,dp,fee));
        }
        else{
            return dp[index][buy]= max(prices[index]-fee+findans(index+1,n,1,prices,dp,fee),
            findans(index+1,n,0,prices,dp,fee));
        }

    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return findans(0,n,1,prices,dp,fee);
    }
};