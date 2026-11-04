class Solution {
public:
    bool fun(int idx,vector<int>&nums,vector<int>&dp){
        if(idx==nums.size()-1) {
            return 1;
        }
        if(dp[idx]!=-1) return dp[idx];
        if(idx>=nums.size()) return 0;
        for(int i=1;i<=nums[idx];i++){
            if(idx+i<nums.size()){
                if(fun(idx+i,nums,dp)) return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return fun(0,nums,dp);
    }
};