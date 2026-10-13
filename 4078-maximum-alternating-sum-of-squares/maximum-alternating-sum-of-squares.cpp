class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int idx=n/2;
        long long sum1=0;
        for(int i=idx;i<n;i++){
            sum1=sum1+(nums[i]*nums[i]);
        }
        long long sum2=0;
        for(int i=0;i<idx;i++){
            sum2=sum2+(nums[i]*nums[i]);
        }
        return sum1-sum2;
    }
};