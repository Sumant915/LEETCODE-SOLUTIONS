class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch National Flag algorithm
        int n = nums.size();
        int left = 0, mid = 0, right = n - 1;
        
        while(mid <= right){
            if(nums[mid] == 1) {
                mid++;
            }
            else if(nums[mid] == 2) {
                swap(nums[right], nums[mid]);
                right--;
            }
            else { // nums[mid] == 0
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            }
        }
    }
};