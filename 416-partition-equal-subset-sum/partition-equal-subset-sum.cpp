class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(int i:nums){
            totalsum+=i;
        }
        if(totalsum%2) return 0;
        int target=totalsum/2;
        vector<int>prev(target+1,0);
        
        for(int i=1;i<nums.size()+1;i++){
           prev[0]=1;
           vector<int>curr(target+1,0);
           curr[0]=1;
            for(int j=1;j<target+1;j++){
                if(j-nums[i-1]>=0){
                    curr[j]=prev[j]||prev[j-nums[i-1]];
                }
                else{
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return prev[target];
    }
};