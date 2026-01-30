class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int prefixsum=0;
        m[0]=1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            if(m.count(prefixsum-k)){
                count+=m[prefixsum-k];
                m[prefixsum]++;
            }
            else{
                m[prefixsum]++;
            }
        }
        return count;
    }
};