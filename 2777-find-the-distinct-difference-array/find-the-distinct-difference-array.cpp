class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_set<int>s;
        vector<int>prefix(nums.size());
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            prefix[i]=s.size();
        }
        vector<int>suffix(nums.size());
        s.clear();
        for(int i=nums.size()-1;i>=0;i--){
            suffix[i]=s.size();
            s.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            prefix[i]=prefix[i]-suffix[i];
        }
        return prefix;
    }
};