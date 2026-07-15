class Solution {
public:
    int climbStairs(int n) {
     if(n<=2) return n;
     vector<int>ans(4);
     ans[1]=1;
     ans[2]=2;
     ans[3]=3;
     for(int i=4;i<=n;i++){
        ans[1]=ans[2];
        ans[2]=ans[3];
        ans[3]=ans[1]+ans[2];
     }
     return ans[3];
    }
};