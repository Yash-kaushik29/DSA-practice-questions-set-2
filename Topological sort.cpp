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
