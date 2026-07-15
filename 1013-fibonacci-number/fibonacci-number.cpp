class Solution {
public:
    void findfibo(int n,vector<int>&ans){
        for(int i=2;i<=n;i++){
            ans[i]=ans[i-1]+ans[i-2];
        }
    }
    int fib(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        vector<int>ans(n+1,-1);
        ans[0]=0;
        ans[1]=1;
        findfibo(n,ans);
        return ans[n];
    }
};