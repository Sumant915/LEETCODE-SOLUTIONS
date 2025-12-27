class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        //start=k
        //end=nums.size()-k
        if(k==0) return nums;
        vector<int>ans(nums.size(),-1);
        int start=0,end=0;
        int window_size=2*k+1;
        long long sum=0;
        while(end<nums.size()){
            sum+=nums[end];
            while(end-start+1==window_size ){
                ans[start+k]=sum/window_size;
                sum-=nums[start];
                start++;
            }
            end++;
        }
        return ans;
    }
};