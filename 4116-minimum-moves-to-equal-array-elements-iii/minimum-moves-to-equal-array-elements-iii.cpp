class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>max_val) max_val=nums[i];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=max_val-nums[i];
        }
        return ans;
    }
};