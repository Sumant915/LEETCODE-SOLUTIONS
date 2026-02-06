class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int profit=0;
        int min=nums[0];
        for(int i=1;i<nums.size();i++){
               if(nums[i]<min){
                min=nums[i];
               }
               else{
                profit=max(profit,nums[i]-min);
               }
        }
        return profit;
    }
};