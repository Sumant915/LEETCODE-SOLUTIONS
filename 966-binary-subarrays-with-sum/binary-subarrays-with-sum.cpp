class Solution {
public:
    int atleastsubarray(vector<int>&nums,int goal){
          long long start=0,end=0,currsum=0;
          int count=0;
          while(end<nums.size()){
            currsum+=nums[end];
            while(currsum>=goal && start<=end){
                count+=nums.size()-end;
                currsum=currsum-nums[start];
                start++;
            }
            end++;
          }
          return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return atleastsubarray(nums,goal)-atleastsubarray(nums,goal+1);
    }
};