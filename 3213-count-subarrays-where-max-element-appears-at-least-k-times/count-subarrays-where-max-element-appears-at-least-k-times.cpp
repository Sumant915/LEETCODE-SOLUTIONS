class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxele=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>maxele){
                maxele=nums[i];
            }
        }
        int start=0,end=0;
        long long ans=0,count=0;
        while(end<nums.size()){
            if(nums[end]==maxele){
                count++;
            }
            while(count==k ){
                ans+=(nums.size()-end);
                if(nums[start]==maxele){
                    count--;
                }
                start++;
            }
            end++;
        }
    return ans;
    }
};