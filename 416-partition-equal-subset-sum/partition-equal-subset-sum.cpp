class Solution {
public:
    bool subset(int n,int sum,int target,vector<int>&nums, vector<vector<int>>&dp){
        if(n==0) return sum==target;
        if(sum==target) return 1;
        if(sum>target) return 0;
        if(dp[n][sum]!=-1) return dp[n][sum];
        return dp[n][sum]=subset(n-1,sum+nums[n-1],target,nums,dp)||subset(n-1,sum,target,nums,dp);
    }
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int i:nums){
            totalsum+=i;
        }
        if(totalsum%2) return 0;
        int target=totalsum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,-1));
        return subset(nums.size(),0,target,nums,dp);
    }
};