class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void DFS(int source, int V, vector<int> adj[], vector<int>& dfs, vector<int>& vis) {
        
        vis[source]=1;
        dfs.push_back(source);
        
        for(int i=0; i<adj[source].size(); i++) {
            int neighbour = adj[source][i];
            
            if(!vis[neighbour]) {
                DFS(neighbour, V, adj, dfs, vis);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> dfs;
        vector<int> vis(V,0);
        
        DFS(0, V, adj, dfs, vis);
        
        return dfs;
    }
};
