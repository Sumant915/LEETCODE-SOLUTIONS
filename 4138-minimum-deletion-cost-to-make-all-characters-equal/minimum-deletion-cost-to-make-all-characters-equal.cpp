class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long>freq(26,0);
        long long total_cost=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']+=cost[i];
            total_cost+=cost[i];
        }
        long long ans=0;
        for(int i=0;i<26;i++){
            ans=max(ans,freq[i]);
        }
        return total_cost-ans;
    }
};