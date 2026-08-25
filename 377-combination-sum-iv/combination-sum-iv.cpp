class Solution {
public:
   int totalcombination(int target,vector<int>&nums,vector<int>&dp){
    if(target==0) return 1;
    if(target<0) return 0;
    if(dp[target]!=-1) return dp[target];
    int total=0;
    for(int i=0;i<nums.size();i++){
        total+=totalcombination(target-nums[i],nums,dp);
    }
    return dp[target]=total;
   }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return totalcombination(target,nums,dp);
    }
};