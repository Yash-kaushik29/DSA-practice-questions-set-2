class Solution {
  public:
    bool cycle(int i, vector<int>& vis, vector<int>& dfsvis, vector<int> adj[]) {
        vis[i]=1;
        dfsvis[i]=1;
        
        for(auto neighbour: adj[i]) {
            
            if(!vis[neighbour]) {
                if(cycle(neighbour, vis, dfsvis, adj)) {
                    return true;
                }
            }
            else if(dfsvis[neighbour]) {
                return true;
            }
        }
        dfsvis[i]=0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> dfsvis(V,0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(cycle(i, vis, dfsvis, adj)) return true;
            }
        }
        
        return false;
    }
};
