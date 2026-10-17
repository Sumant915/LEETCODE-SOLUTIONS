class Solution {
public:
   int findsum(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
   }
    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>>arr;
        for(int i=0;i<nums.size();i++){
           arr.push_back({findsum(nums[i]), nums[i]});
        }
        sort(arr.begin(),arr.end());
        vector<int>target;
        for(int i=0;i<arr.size();i++){
            target.push_back(arr[i].second);
        }
        unordered_map<int, int> pos;
        for (int i=0;i<nums.size(); i++) {
            pos[target[i]]=i;
        }
        vector<bool>visited(nums.size(),false);
        int swaps=0;
        for(int i=0;i<nums.size();i++){
            if(visited[i] || nums[i]==target[i]) continue;
            int j=i;
            int cyclesize=0;
            while(!visited[j]){
                visited[j]=true;
                cyclesize++;
                j=pos[nums[j]];
            }
            swaps+=cyclesize-1;
        }
        return swaps;
    }
};