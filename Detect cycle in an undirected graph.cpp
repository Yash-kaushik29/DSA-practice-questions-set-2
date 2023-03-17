// Using Breadth first search(BFS)

class Solution {
  public:
    bool detect(int src,vector<int> adj[],int vis[])
    {
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(parent!=it)
                {
                    return true;
                }
            }
        }    
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis))
                    return true;
            }
        }
        return false;
    }
};

// Using Depth first search(DFS)

class Solution {
  public:
    bool detect(int src, int parent, vector<int> adj[], int vis[])
    {
        vis[src]=1;
        
        for(auto node: adj[src]) {
            if(!vis[node]) {
                if(detect(node, src, adj, vis)) return true;
            }
            
            else if(vis[node] && parent!=node) {
                return true;
            }
        }
            
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,-1,adj,vis))
                    return true;
            }
        }
        return false;
    }
};
