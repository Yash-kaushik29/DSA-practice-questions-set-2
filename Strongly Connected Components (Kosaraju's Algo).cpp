class Solution
{
	public:
	void dfs(int node,vector<int> &vis,vector<vector<int>>& adj,stack<int> &st)
	{
	    vis[node] = 1;
	    for(auto it: adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	void dfs1(int node,vector<int> &vis,vector<int> adjT[])
	{
	    vis[node] = 1;
	    for(auto it: adjT[node])
	    {
	        if(!vis[it])
	        {
	            dfs1(it,vis,adjT);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V,0);
        stack<int> st;
        // Step 1: Stroing the nodes in order of finishing time of traversal
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,st);
            }
        }
        // --------------------------------------------------------------------
        // Step 2: Reverse the graph
        vector<int> adjT[V];
        for(int i=0;i<V;i++)
        {
            vis[i] = 0;
            for(auto it: adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        // ---------------------------
        // Step 3: DFS traversal to find the SCCs
        int scc = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(!vis[node])
            {
                scc++;
                dfs1(node,vis,adjT);
            }
        }
        // -------------------------------------
        return scc;
    }
};
