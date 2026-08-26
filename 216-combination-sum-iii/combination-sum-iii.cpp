class Solution {
public:
    void findans(int k,int n,vector<int>temp,vector<vector<int>>&ans,int a){
         if(n==0 && k==0){
            ans.push_back(temp);
            return;
         }
         if(n<0 || k<0) return;
         for(int i=a;i<=9;i++){
             if (i > n) break;
            temp.push_back(i);
            findans(k-1,n-i,temp,ans,i+1);
            temp.pop_back();
         }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        findans(k,n,temp,ans,1);
        return ans;
    }
};