class Solution {
  public:
    void dfs(int node, int parent, int& timer, vector<int> adj[], vector<int>& vis, vector<int>& disc, vector<int>& low, vector<int>& ap) {
        vis[node]=1;
        disc[node] = low[node] = timer++;
        int child=0;
        
        for(auto nbr: adj[node]) {
            if(nbr == parent) continue;
            
            if(!vis[nbr]) {
                dfs(nbr, node, timer, adj, vis, disc, low, ap);
                low[node] = min(low[node], low[nbr]);
                
                if(low[nbr] >= disc[node] && parent != -1) {
                    ap[node] = 1;
                }
                child++;
            }
            else {
                
                low[node] = min(low[node], disc[nbr]);
            }
        }
        if(parent == -1 && child > 1)
            ap[node] = 1;
    }
    
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> vis(V,0);
        vector<int> ap(V,0);
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        
        int timer=0;
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, -1, timer, adj, vis, disc, low, ap);
            }
        }
        
        vector<int> ans;
        
        for(int i=0; i<V; i++) {
            if(ap[i] == 1) ans.push_back(i);
        }
        
        if(ans.size() == 0) return {-1};
        
        return ans;
    }
};
