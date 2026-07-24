class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int i:nums){
            totalsum+=i;
        }
        if(totalsum%2) return 0;
        int target=totalsum/2;
        vector<int>curr(target+1,0);
        curr[0]=1;
        for(int i=1;i<nums.size()+1;i++){
            for(int j=target;j>=0;j--){
                if(j-nums[i-1]>=0){
                    curr[j]=curr[j]||curr[j-nums[i-1]];
                }
            }
        }
        return curr[target];
    }
};