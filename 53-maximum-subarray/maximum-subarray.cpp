class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0;
        int ans=INT_MIN;
        int sum=0;
        while(i<nums.size()){
            sum+=nums[i];
            ans=max(sum,ans);
            if(sum<0) sum=0;
            i++;
        }
        return ans;
    }
};