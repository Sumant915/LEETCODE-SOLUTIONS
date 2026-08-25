class Solution {
public:
    void findans(int n,vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int>temp){
        if(n==0){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return ;
        temp.push_back(candidates[n-1]);
        findans(n,candidates,target-candidates[n-1],ans,temp);
        temp.pop_back();
        findans(n-1,candidates,target,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        findans(candidates.size(),candidates,target,ans,temp);
        return ans;
    }
};