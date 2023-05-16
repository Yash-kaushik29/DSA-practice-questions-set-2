class Solution {
  public:
    void DFS(int source, vector<int> adj[], vector<int>& dfs, vector<int>& vis) {
        
        vis[source] = 1;
        dfs.push_back(source);
        
        for(auto nbr: adj[source]) {
            if(!vis[nbr]) {
                DFS(nbr, adj, dfs, vis);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> dfs;
        vector<int> vis(V,0);
        
        DFS(0, adj, dfs, vis);
        
        return dfs;
    }
    }
};
