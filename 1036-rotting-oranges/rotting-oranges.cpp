class Solution {
public:
    int r,c;
    int row[4]={-1,1,0,0};
    int col[4]={0,0,1,-1};

    bool valid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        r=grid.size();
        c=grid[0].size();

        queue<pair<int,int>>q;
        int fresh = 0;  // 🔹 added

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
                else if(grid[i][j]==1){
                    fresh++;   // 🔹 added
                }
            }
        }

        if(fresh==0) return 0;  // 🔹 added

        int timer=0;

        while(!q.empty()){
            int n=q.size();
            bool spread = false;  // 🔹 added

            while(n--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int ni = i + row[k];
                    int nj = j + col[k];

                    if(valid(ni,nj) && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push(make_pair(ni,nj));
                        fresh--;           // 🔹 added
                        spread = true;     // 🔹 added
                    }
                }
            }

            if(spread) timer++;  // 🔹 moved here
        }

        if(fresh>0) return -1;  // 🔹 better condition

        return timer;
    }
};