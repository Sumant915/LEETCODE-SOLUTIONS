class Solution {
public:
   void subsequence(vector<int>&nums,int index,int size,vector<int>temp,vector<vector<int>>&ans){
    if(index==size){
        ans.push_back(temp);
        return ;
    }
    //NO
    subsequence(nums,index+1,size,temp,ans);
    //yes
    temp.push_back(nums[index]);
    subsequence(nums,index+1,size,temp,ans);
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        subsequence(nums,0,nums.size(),temp,ans);
        return ans;
    }
};