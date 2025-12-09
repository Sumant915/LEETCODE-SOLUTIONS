class Solution {
public:
    void combination(int index,vector<int>& candidates,int target,vector<vector<int>>&   result,  vector<int>ans){
      if(index==candidates.size() || target<0){
        return;
      }
      if(target==0) {
        result.push_back(ans);
        return ;
      }
      //same index
      ans.push_back(candidates[index]);
      combination(index,candidates,target-candidates[index],result,ans);
      ans.pop_back();
      //move to next index
      combination(index+1,candidates,target,result,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>ans;
        combination(0,candidates,target,result,ans);
        return result;
    }
};