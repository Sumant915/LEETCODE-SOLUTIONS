class Solution {
public:
   int find(vector<int>&stones,int target,int index){
    int start=index+1,end=stones.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(stones[mid]==target){
            return mid;
        }
        else if(stones[mid]<target) start=mid+1;
        else end=mid-1;
    }
    return -1;
   }
    bool solve(int index,vector<int>&stones,int jump,vector<vector<int>>&dp){
        if(index>stones.size()) return false;
        if(index==stones.size()-1) return true;
        if(dp[index][jump]!=-1) return dp[index][jump];
        int i=find(stones,stones[index]+jump-1,index);
        int j=find(stones,stones[index]+jump,index);
        int k=find(stones,stones[index]+jump+1,index);
        if(i!=-1 && solve(i,stones,jump-1,dp)) return dp[index][jump]=true;
        if(j!=-1 && solve(j,stones,jump,dp)) return dp[index][jump]=true;
        if(k!=-1 && solve(k,stones,jump+1,dp)) return dp[index][jump]=true;
        return dp[index][jump]=false;
    }
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size() + 1, -1));
        return solve(1, stones, 1,dp);
    }
};