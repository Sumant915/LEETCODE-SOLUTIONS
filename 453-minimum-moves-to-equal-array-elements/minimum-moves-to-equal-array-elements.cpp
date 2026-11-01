class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_idx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[min_idx]) min_idx=i;
        }
        int min_val=nums[min_idx];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i!=min_idx){
                ans+=nums[i]-min_val;
            }
        }
        return ans;
    }
};