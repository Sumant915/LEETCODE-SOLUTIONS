
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        int ans=0;
        for(int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                if(grid[i][j]==0 || visited[i][j]) continue;
                long long currsum=0;
                queue<pair<int,int>>q;
                q.push({i,j});
                visited[i][j]=true;
                while(!q.empty()){
                    int real_i=q.front().first;
                    int real_j=q.front().second;
                    q.pop();
                    currsum += grid[real_i][real_j];
                    // up
                    if (real_i-1>=0 &&
                        grid[real_i - 1][real_j]!= 0 &&
                        !visited[real_i - 1][real_j]){
                        visited[real_i - 1][real_j]=true;
                        q.push({real_i - 1, real_j});
                    }
                    // Down
                    if (real_i + 1 < r &&
                        grid[real_i + 1][real_j] != 0 &&
                        !visited[real_i + 1][real_j]) {
                        visited[real_i + 1][real_j] = true;
                        q.push({real_i + 1, real_j});
                    }
                    // Left
                    if (real_j - 1 >= 0 &&
                        grid[real_i][real_j - 1] != 0 &&
                        !visited[real_i][real_j - 1]) {
                        visited[real_i][real_j - 1] = true;
                        q.push({real_i, real_j - 1});
                    }
                    // Right
                    if (real_j + 1 < c &&
                        grid[real_i][real_j + 1] != 0 &&
                        !visited[real_i][real_j + 1]) {
                        visited[real_i][real_j + 1] = true;
                        q.push({real_i, real_j + 1});
                    }
                }
                if (currsum % k == 0)
                    ans++;
            }
        }

        return ans;
    }
};
