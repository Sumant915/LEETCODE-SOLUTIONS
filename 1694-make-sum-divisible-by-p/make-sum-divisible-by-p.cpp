class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum=0;
        for(int x:nums) sum+=x;
        
        int ans = INT_MAX;
        
        map<long long,int> mp;
        int n=nums.size();
        int r = sum % p;
        if(r==0) return 0;
        mp[0] = -1; 
        long long prefix=0;
        for(int i=0;i<n;i++) {
            prefix=(prefix+nums[i])%p;
            int want=(prefix-r+p)%p;
            if(mp.count(want))
                ans=min(ans,i-mp[want]);
            mp[prefix]=i;
        }
        
        return ans == n ? -1 : ans;
    }
};