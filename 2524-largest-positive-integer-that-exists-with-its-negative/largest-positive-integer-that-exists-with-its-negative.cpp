class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=-1;
        for (int i=0;i<nums.size();i++){
            int value=nums[i];
            if(value>0){
                m[value]+=1;
            }
        }
        for (int i=0;i<nums.size();i++){
            int value=nums[i];
            if(value<0){
                if(m.count(abs(value))){
                    ans=max(ans,abs(value));
                }
            }
        }
        return ans;
    }
};