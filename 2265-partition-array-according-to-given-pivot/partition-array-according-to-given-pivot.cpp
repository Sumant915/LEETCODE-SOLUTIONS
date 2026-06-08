class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int count=0;
        int idx=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                count++;
            }
        }
        while(count){
            ans.push_back(pivot);
            count=count-1;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                ans.push_back(nums[i]);
            }
        }
       for(int i=0;i<nums.size();i++){
          nums[i]=ans[i];
        }
        return nums;
    }
};