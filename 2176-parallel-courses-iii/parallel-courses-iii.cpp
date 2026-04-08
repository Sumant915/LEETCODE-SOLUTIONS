class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(int i=0;i<relations.size();i++){
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
            indegree[relations[i][1]-1]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!indegree[i]) q.push(i);
        }
        vector<int>coursetime(n,0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int j=0;j<adj[node].size();j++){
                indegree[adj[node][j]]--;
                if(!indegree[adj[node][j]]){
                    q.push(adj[node][j]);
                }
coursetime[adj[node][j]]=max( coursetime[adj[node][j]],coursetime[node]+time[node]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,coursetime[i]+time[i]);
        }
        return ans;
    }
};