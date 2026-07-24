class Solution {
public:
    bool subset(int n,int sum,int totalsum,vector<int>&nums, vector<vector<int>>&dp){
        if(n==0) return sum==totalsum-sum;
        if(sum==totalsum-sum) return 1;
        if(dp[n][sum]!=-1) return dp[n][sum];
        return dp[n][sum]=subset(n-1,sum+nums[n-1],totalsum,nums,dp)||subset(n-1,sum,totalsum,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int i:nums){
            totalsum+=i;
        }
        if(totalsum%2) return 0;
        vector<vector<int>>dp(nums.size()+1,vector<int>(totalsum+1,-1));
        return subset(nums.size(),0,totalsum,nums,dp);
    }
};