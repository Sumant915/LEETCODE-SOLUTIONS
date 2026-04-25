class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int c=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target) c+=1;
                else c-=1;
            if(c>0) sum++;
            }
        }
        return sum;
    }
};