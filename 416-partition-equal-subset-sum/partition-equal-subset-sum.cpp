class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int i:nums){
            totalsum+=i;
        }
        if(totalsum%2) return 0;
        int target=totalsum/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<nums.size()+1;i++){
            dp[i][0]=1;
            for(int j=0;j<target+1;j++){
                if(j-nums[i-1]>=0){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][target];
    }
};