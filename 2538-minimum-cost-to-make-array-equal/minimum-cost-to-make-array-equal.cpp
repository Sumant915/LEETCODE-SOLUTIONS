class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int,int>>arr;
        long long  totalcost=0;
        for(int i=0;i<nums.size();i++){
             arr.push_back({nums[i], cost[i]});
             totalcost+=cost[i];
        }
        sort(arr.begin(),arr.end());
        int n=nums.size();
        long long sum=0;
        long long  target=0;
        for(auto &p:arr){
            sum+=p.second;
            if(sum*2>=totalcost){
                target=p.first;
                break;
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=1LL*abs(nums[i]-target)*cost[i];
        }
        return ans;
    }
};