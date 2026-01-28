class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        set<pair<int,int>>s;
        s.insert(make_pair(0,0));
        
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>p;
        
        p.push(make_pair(mat[0][0],make_pair(0,0)));
       
       pair<int,pair<int,int>>element;
       int i,j,ans;
        while(k--){
            element=p.top();
            ans=element.first;
            i=element.second.first;
            j=element.second.second;
            p.pop();
            if(j+1<n && !s.count(make_pair(i,j+1))){
                p.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
                s.insert(make_pair(i,j+1));
            }
            if(i+1<n && !s.count(make_pair(i+1,j))){
                p.push(make_pair(mat[i+1][j],make_pair(i+1,j)));
                s.insert(make_pair(i+1,j));
            }
        }
        return ans;
    }
};