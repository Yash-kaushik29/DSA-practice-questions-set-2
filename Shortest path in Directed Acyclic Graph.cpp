class Solution {
  public:
     void topoSort(int i, vector<pair<int, int>> adj[], vector<bool>& vis, stack<int>& s) {
         vis[i]=1;
         
         for(auto it: adj[i]) {
             if(!vis[it.first]) {
                 topoSort(it.first, adj, vis, s);
             }
         }
         s.push(i);
     }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int> > adj[N];
        for(int i=0; i<M; i++) {
            int u=edges[i][0];
            int v=edges[i][1];
            int d=edges[i][2];
            adj[u].push_back({v,d});
        }
        
        stack<int> s;
        vector<bool> vis(N,0);
        
        for(int i=0; i<N; i++) {
            if(!vis[i]) {
                topoSort(i, adj, vis, s);
            }
        }
        
        vector<int> dis(N,1e9);
        dis[0]=0;
        
        while(!s.empty()) {
            int u = s.top();
            s.pop();
            
            vis[u]=1;
            for(auto it: adj[u]) {
                int v=it.first;
                int d=it.second;
                
                if(dis[u]+d < dis[v]) {
                    dis[v] = dis[u] + d; 
                }
            }
        }
        
        for(int i=0; i<N; i++) {
            if(dis[i]==1e9)
              dis[i]=-1;
        }
        
        return dis;
    }
};
