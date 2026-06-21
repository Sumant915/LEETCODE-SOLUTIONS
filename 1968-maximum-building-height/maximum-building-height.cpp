class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        restrictions.push_back({n,n-1});
        sort(restrictions.begin(),restrictions.end());
        // left to right gaya taki restriction wale me height update ho 
        for(int i=1;i<restrictions.size();i++){
              int d=abs(restrictions[i-1][0]-restrictions[i][0]);
              restrictions[i][1]=min(restrictions[i][1],restrictions[i-1][1]+d);
        }
        //right to left
        for(int i=restrictions.size()-2;i>=0;i--){
            int d=abs(restrictions[i+1][0]-restrictions[i][0]);
            restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+d);
        }
        int ans=0;
        for(int i=1;i<restrictions.size();i++){
            int leftpos=restrictions[i-1][0];
            int leftheight=restrictions[i-1][1];
            int currpos=restrictions[i][0];
            int currheight=restrictions[i][1];
            int diff=currpos-leftpos;
            int heightdiff=abs(currheight-leftheight);
            int peak=max(leftheight,currheight)+(diff-heightdiff)/2;
            ans=max(ans,peak);
        }
        return ans;
    }
};