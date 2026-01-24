class Solution {
public:
    int minPairSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int start=0,end=nums.size()-1;
       int ans=INT_MIN;
       while(start<end){
        ans=max(ans,nums[start]+nums[end]);
        start++;
        end--;
       }
       return ans;
    }
};