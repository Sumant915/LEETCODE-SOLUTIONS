class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixsum=0;
        unordered_map<int,int>m;
        // prefixsum index 
        m[0]=-1;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int r=prefixsum%k;
            if(m.count(r)){
                if(i-m[r]>1) return true;
            }
            else{
                m[r]=i;
            }
        }
        return false;
    }
};