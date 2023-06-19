class Solution{
  public:
    int dfs(int node, vector<int> adj[], vector<int>& vis, int& ans) {
        if(vis[node]) return 0;
        vis[node]=1;
        
        int select=0;
        for(auto nbr: adj[node]) {
            if(!vis[nbr] && !dfs(nbr, adj, vis, ans)) {
                select=1;
            }
        }
        
        if(select) ans++;
        return select;
    }
  
    int countVertex(int N, vector<vector<int>>edges){
        vector<int> vis(N+1,0);
        vector<int> adj[N+1];
        
        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int ans=0;
        dfs(1, adj, vis, ans);
        return ans;
    }
};
