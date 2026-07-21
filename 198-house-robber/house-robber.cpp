class Solution {
public:
    int maxrob(int n,vector<int>&nums,vector<int>&dp){
        if(dp[n]!=-1) return dp[n];
        if(n==0) return nums[0];
        if(n==1) return max(nums[0],nums[1]);
        return dp[n]=max(nums[n]+maxrob(n-2,nums,dp),maxrob(n-1,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return maxrob(n-1,nums,dp);
    }
};