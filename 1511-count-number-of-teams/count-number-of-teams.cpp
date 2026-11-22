class Solution {
public:
    int decreasing(int i,int prev,int count,vector<int>&rating,int (&dp)[1001][1001][4]){
        if(count==3) return 1;
        if(i>=rating.size()) return 0;
        if(dp[i][prev+1][count]!=-1) return dp[i][prev+1][count];
        // dont take 
        int nottaken=decreasing(i+1,prev,count,rating,dp);
        //take 
        int taken=0;
        if(prev==-1 || rating[prev]>rating[i]){
            taken=decreasing(i+1,i,count+1,rating,dp);
        }
        return dp[i][prev+1][count]=taken+nottaken;
    }
    int increasing(int i,int prev,int count,vector<int>&rating,int (&dp)[1001][1001][4]){
        if(count==3) return 1;
        if(i>=rating.size()) return 0;
        if(dp[i][prev+1][count]!=-1) return dp[i][prev+1][count];
        // dont take 
        int nottaken=increasing(i+1,prev,count,rating,dp);
        //take 
        int taken=0;
        if(prev==-1 || rating[prev]<rating[i]){
            taken=increasing(i+1,i,count+1,rating,dp);
        }
        return dp[i][prev+1][count]=taken+nottaken;
    }
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        static int dp1[1001][1001][4];
        static int dp2[1001][1001][4];
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        return decreasing(0,-1,0,rating,dp2)+increasing(0,-1,0,rating,dp1);
    }
};