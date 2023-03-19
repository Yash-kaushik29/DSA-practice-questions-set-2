// Using BFS(Kahn's Algorithm)

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> indegree(V,0);
	    
	    for(int i=0; i<V; i++) {
	        for(auto j: adj[i]) {
	            indegree[j]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++) {
	        if(indegree[i] == 0)
	          q.push(i);
	    }
	    
	    vector<int> ans;
	    
	    while(!q.empty()) {
	        int front=q.front();
	        q.pop();
	        
	        ans.push_back(front);
	        
	        for(auto neighbour: adj[front]) {
	            indegree[neighbour]--;
	            if(indegree[neighbour] == 0)
	                q.push(neighbour);
	        }
	    }
	    
	    return ans;
	}
};

// Using DFS

class Solution
{
	public:
	void topoSort(int i, stack<int>& s, vector<bool>& vis, vector<int> adj[]) {
	    vis[i]=1;
	    
	    for(auto neighbour: adj[i]) {
	        if(!vis[neighbour]) {
	            topoSort(neighbour, s, vis, adj);
	        }
	    }
	    
	    s.push(i);
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> vis(V,0);
	    stack<int> s;
	    
	    for(int i=0; i<V; i++) {
	        if(!vis[i]) {
	            topoSort(i, s, vis, adj);
	        }
	    }
	    
	    vector<int> ans;
	    
	    while(!s.empty()) {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};
