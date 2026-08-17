class Solution {
public:
    int mincoins(vector<int>& coins, int n, int amount, vector<vector<int>>&dp) {
        if (amount == 0)
            return 0;
        if (n == 0 || amount < 0)
            return 1e9;
        if(dp[n][amount]!=-1) return dp[n][amount];
        int notTake = mincoins(coins, n - 1, amount,dp);
        int take =1+ mincoins(coins, n, amount - coins[n - 1],dp);
        return dp[n][amount]=min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans = mincoins(coins, n, amount,dp);
        return ans >= 1e9? -1 : ans;
    }
};