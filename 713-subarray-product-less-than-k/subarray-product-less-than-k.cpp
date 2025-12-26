class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        long long start=0,end=0;
        long long product=1;
        long long total=0;
        while(end<nums.size()){
            product=product*nums[end];
            while(product>=k && start<=end){
                product=product/nums[start];
                start++;
            }
            total+=1+(end-start);
            end++;
        }
        return total;
    }
};