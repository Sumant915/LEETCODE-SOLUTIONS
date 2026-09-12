class Solution {
public:
    int longestpalindromicsubseqence(string &s,int l,int r,vector<vector<int>>&dp){
        if(l>r) return 0;
        if(l==r) return 1;
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]){
            return dp[l][r]=2+longestpalindromicsubseqence(s,l+1,r-1,dp);
        }
        else{
            return dp[l][r]=max(longestpalindromicsubseqence(s,l+1,r,dp),longestpalindromicsubseqence(s,l,r-1,dp));
        }
    }
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return s.size()-longestpalindromicsubseqence(s,0,s.size()-1,dp);
    }
};