class Solution {
public:
    int countmaxsubarray(vector<int>&nums,int range){
        int start=0,end=0,count=0;
        while(end<nums.size()){
            if(nums[end]<=range){
                count+=end-start+1;
                end++;
            }
            else{
                end++;
                start=end;
            }
        }
        return count;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return countmaxsubarray(nums,right)-countmaxsubarray(nums,left-1);
    }
};