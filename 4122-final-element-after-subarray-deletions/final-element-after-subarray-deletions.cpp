class Solution {
public:
    int finalElement(vector<int>& nums) {
        int m=nums.size();
        return max(nums[0],nums[m-1]);
    }
};