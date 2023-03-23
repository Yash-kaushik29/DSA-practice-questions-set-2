class Solution {
    void dfs(int i, vector<int> adj[], vector<bool>& vis) {
        vis[i]=1;

        for(auto it: adj[i]) {
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }
    
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        vector<int> adj[n];
        int m=edge.size();

        if(m < n-1) return -1;

        for(int i=0; i<m; i++) {
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }

        vector<bool> vis(n,0);
        int c=0;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                c++;
                dfs(i, adj, vis);
            }
        }

        return c-1;
    }
};
