class Solution
{
    bool isBridgeFlag=false;
	
    void dfs(int node, int& timer, int parent, vector<int>& disc, vector<int>& low,
                   vector<bool>& vis, vector<int> adj[], int c, int d) {
        vis[node] = true;
        low[node] = disc[node] = timer++;
        
        for(auto nbr: adj[node]) {
            if(nbr == parent) {
                continue;
            }
            if(!vis[nbr]) {
                dfs(nbr, timer, node, disc, low, vis, adj, c, d);
                low[node] = min(low[node], low[nbr]);
                
                if(low[nbr] > disc[node]) {
                    if((nbr==c && node==d) || (nbr==d && node==c)) {
                        isBridgeFlag = true;
                    }
                }
            }
            else {
                low[node] = min(low[node], low[nbr]);
            }
        }
    }
	public:
    
    int isBridge(int V, vector<int> adj[], int c, int d) {
        
        vector<int> disc(V,-1);
        vector<int> low(V,-1);
        vector<bool> vis(V,false);
        int timer=0;
        
        for(int i=0;i<V;i++){
            if(vis[i]){
                continue;
            }
            dfs(i, timer, -1, disc, low, vis, adj, c, d);
        }
        
        return isBridgeFlag;  
    }
};
