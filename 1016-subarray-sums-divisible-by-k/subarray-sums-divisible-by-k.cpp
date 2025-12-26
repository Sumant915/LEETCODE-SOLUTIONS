class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int total=0;
        int prefixsum=0;
        m[0]=1;
        int r=0;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int r=prefixsum%k;
            if(r<0) r=r+k;
            if(m.count(r)){
                total+=m[r];
                m[r]++;
            }
            else{
                m[r]++;
            }
        }
      return total;
    }
};