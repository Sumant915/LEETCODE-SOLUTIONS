class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int end=0,start=0;
        int prefixsum=0;
        while(end<nums.size()){
            prefixsum+=nums[end];
            while(prefixsum>=target && start<=end){
                ans=min(ans,end-start+1);
                prefixsum-=nums[start];
                start++;
            }
            end++;
        }
        return ans==INT_MAX?0:ans;
    }
};