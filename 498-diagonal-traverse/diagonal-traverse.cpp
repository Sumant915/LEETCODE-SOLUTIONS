class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int>ans;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool rev=true;
        for(int i=0;i<n+m-1;i++){
            if(rev){
                reverse(mp[i].begin(),mp[i].end());
            }
            rev=!rev;
            for(int j=0;j<mp[i].size();j++){
                ans.push_back(mp[i][j]);
            }
        }
        return ans;
    }
};