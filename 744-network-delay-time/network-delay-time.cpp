class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int weight = times[i][2];

            adj[u-1].push_back({v-1, weight}); 
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0; 

        q.push({0, k-1});

        vector<int> visited(n, 0);

        while(!q.empty()){
            int node = q.top().second;
            int weight = q.top().first;
            q.pop();

            if(visited[node]) continue;
            visited[node] = 1;

            for(int j = 0; j < adj[node].size(); j++){
                int neighbour = adj[node][j].first;
                int wt = adj[node][j].second;

                if(dist[node] + wt < dist[neighbour]){
                    dist[neighbour] = dist[node] + wt;
                    q.push({dist[neighbour], neighbour});
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};