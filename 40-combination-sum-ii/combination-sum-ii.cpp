
class Solution {
public:
void Recursion( int idx  , vector<int>&Curr , vector<vector<int>>&Ans , vector<int>&nums , int Target){

         if( Target == 0 ){
             Ans.push_back(Curr);
             return;
         }

         for( int i = idx ; i < nums.size() ; i++ ){
              
              // Skip Duplicate
              if( i > idx && nums[i] == nums[ i - 1]) continue;

              // 10 > 9 ? Array sorted
              if( nums[i] > Target ) break;

              Curr.push_back(nums[i]);
              Recursion( i + 1 , Curr , Ans , nums , Target - nums[i]);
              Curr.pop_back();
         }
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>>Ans;
        vector<int>Curr;
        
        sort( nums.begin() , nums.end());
        Recursion( 0 , Curr , Ans , nums , target);
        return Ans;
    }
};