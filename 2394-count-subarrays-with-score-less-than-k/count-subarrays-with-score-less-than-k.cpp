class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum=0;
        int start=0,end=0;
        long long total=0;
        while(end<nums.size()){
            sum+=nums[end];
            long long score=sum*(end-start+1);
            while(score>=k && start<=end){
                sum=sum-nums[start];
                start++;
                score=sum*(end-start+1);
            }
            total+=1+(end-start);
            end++;
        }
        return total;
    }
};