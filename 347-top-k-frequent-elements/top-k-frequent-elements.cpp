class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        //           element frequency
        for(int i=0;i<nums.size();i++){
           mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto &it:mp){
            q.push({it.second,it.first});
            // frequency element
        }
        vector<int>ans;
        while(!q.empty() && k--){
            int frequency=q.top().first;
            int element=q.top().second;
            ans.push_back(element);
            q.pop();
        }
    return ans;
    }
};