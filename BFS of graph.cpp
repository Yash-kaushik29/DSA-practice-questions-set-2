class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> bfs;
        queue<int> q;
        vector<int> vis(V,0); 
        
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            bfs.push_back(front);
            
            for(int i=0; i<adj[front].size(); i++) {
                
                int neighbour = adj[front][i];
                if(!vis[neighbour]) {
                    q.push(neighbour);
                    vis[neighbour] =1;
                }
            }
        }
        
        return bfs;
    }
};
