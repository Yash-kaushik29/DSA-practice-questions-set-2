class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> dis(V,INT_MAX);
        vector<int> parent(V,-1);
        vector<bool> visited(V,false);
        
        dis[0] = 0;
        
        // find the smallest value in dis
        for(int i=0;i<V;i++){
            int mini = INT_MAX;
            int u;
            for(int j=0;j<V;j++){
               if(dis[j]<mini && visited[j] == false){
                   u = j;
                   mini = dis[j];
               }
            }
            visited[u] = true;
            
            // traverse all neighbours
            for(int k=0;k<adj[u].size();k++){
                int v = adj[u][k][0];
                int w = adj[u][k][1];
                if(visited[v] == false && dis[v]>w){
                    dis[v] = w;
                    parent[v] = u;
                }
            }
        }
        int mst = 0;
        for(int i=1;i<V;i++){
            mst+=dis[i];
        }
        return mst;
        
    }
};
