class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start=0,end=0;
        int n=nums.size();
        int count=0;
        int curr_prod=1;
        while(end<n){
            curr_prod*=nums[end];
            while(curr_prod>=k && start<=end){
                curr_prod=curr_prod/nums[start];
                start++;
            }
            count+=end-start+1;
            end++;
        }
        return count;
    }
};