class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int search=target-nums[i];
           if(mp.find(search) != mp.end() && mp[search] != i) {
            return {i, mp[search]};
            }
        }
        return {-1,-1};
    }
};