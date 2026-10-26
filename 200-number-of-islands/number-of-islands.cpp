class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        vector<vector<bool>>visited(r,vector<bool>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='0' || visited[i][j]) continue;
                queue<pair<int,int>>q;
                q.push({i,j});
                visited[i][j]=1;
                ans++;
                while(!q.empty()){
                    int m=q.front().first;
                    int n=q.front().second;
                    q.pop();
                    //up
                    if(m-1>=0 && grid[m-1][n]!='0' && visited[m-1][n]==0){
                        visited[m-1][n]=1;
                        q.push({m-1,n});
                    }
                    //down
                     if(m+1<r && grid[m+1][n]!='0' && visited[m+1][n]==0){
                        visited[m+1][n]=1;
                        q.push({m+1,n});
                    }
                    //left
                     if(n-1>=0 && grid[m][n-1]!='0' && visited[m][n-1]==0){
                        visited[m][n-1]=1;
                        q.push({m,n-1});
                    }
                    //right
                     if(n+1<c && grid[m][n+1]!='0' && visited[m][n+1]==0){
                        visited[m][n+1]=1;
                        q.push({m,n+1});
                    }
                }
            }
        }
        return ans;
    }
};