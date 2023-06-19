class Solution {
  public:
    vector<int> dijkstra(int a, int b, int n, vector<pair<int, int>> adj[]) {
        vector<int> dist(n+1, 1e9);
        // queue will store {distance of node, node}
        queue<pair<int, int>> q;
        
        dist[a]=0;
        q.push({0,a});
        
        while(!q.empty()) {
            int u = q.front().second;
            q.pop();
            
            for(auto it: adj[u]) {
                int v = it.first;
                int wt = it.second;
                
                if(dist[u]+wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    q.push({dist[v], v});
                }
            }
        }
        return dist;
    }
  
    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        vector<pair<int, int>> adj[n+1];
        vector<vector<int>> curved;
        
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            int cwt = edge[3];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
            curved.push_back({u,v,cwt});
        }
        
        vector<int> dist1 = dijkstra(a, b, n, adj);
        vector<int> dist2 = dijkstra(b, a, n, adj);
        
        int ans = dist1[b];
        
        for(int i=0; i<m; i++) {
            int u = curved[i][0];
            int v = curved[i][1];
            int cwt = curved[i][2];
            
            ans = min(ans, dist1[u] + cwt + dist2[v]);
            ans = min(ans, dist1[v] + cwt + dist2[u]);
        }
        
        return ans < 1e9 ? ans : -1;
    }
};
