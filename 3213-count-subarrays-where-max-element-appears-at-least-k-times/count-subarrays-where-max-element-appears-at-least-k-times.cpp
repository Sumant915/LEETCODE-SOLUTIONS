class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int start=0,end=0;
        int max=nums[0];
        int count=0;
        long long ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
            }
        }
        while(end<nums.size()){
           if(nums[end]==max) count++;
           while(count==k){
            ans+=nums.size()-end;
            if(nums[start]==max) {
                count--;
            }
            start++;
           }
           end++;
        }
        return ans;
    }
};