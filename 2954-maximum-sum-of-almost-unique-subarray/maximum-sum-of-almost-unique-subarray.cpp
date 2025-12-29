class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int>mp;
        long long currsum=0;
        long long  start=0,end=0;
        long long count=m;
        long long sum=0;
        while(end<nums.size()){
            currsum+=nums[end];
            mp[nums[end]]++;
            if(mp[nums[end]]==1) count--;
            while(end-start+1==k){
                  if(count<=0){
                      if(end==k-1){
                        sum=currsum;
                      }
                      else{
                      sum=max(sum,currsum);
                      }
                  }
                  mp[nums[start]]--;
                  if(mp[nums[start]]==0) count++;
                  currsum-=nums[start];
                  start++;
            }
            end++;
        }
        return sum;
    }
};