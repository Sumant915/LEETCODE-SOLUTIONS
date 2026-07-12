class Solution {
public:
    int maxArea(vector<int>& nums) {
       int i=0;
       int j=nums.size()-1;
       int maxwater=0;
       int ans=0;
       while(i<=j){
            if(nums [i]<nums[j]){
               ans=nums[i]*(j-i);
               i++;
            }
            else{
            ans=nums[j]*(j-i);
               j--;
            }
          maxwater=max(maxwater,ans);
       }
    return maxwater;
    }
};