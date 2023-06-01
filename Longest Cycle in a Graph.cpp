class Solution {
public:
    void topo(int i, vector<vector<int>>& adj, vector<int> &vis, stack<int> &st){
	vis[i]=1;

        for(auto nbr: adj[i]) {
            if(!vis[nbr]) {
                topo(nbr, adj, vis, st);
            }
        }
        st.push(i);
	}

    void dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &temp){
        vis[i]=1;
        temp.push_back(i);

        for(auto nbr: adj[i]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, vis, temp);
            }
        }
    }

    int kosaraju(int n, vector<vector<int>>& adj) {
        int ans=0;
        stack<int> st;
        vector<int> vis(n,0);

        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                topo(i, adj, vis, st);
            }
        }

        vector<int> adjRev[n];
        for(int i=0; i<n; i++) {
            vis[i]=0;

            for(auto nbr: adj[i]) {
                adjRev[nbr].push_back(i);
            }
        }

        while(!st.empty()) {
            int top = st.top();
            st.pop();

            if(vis[top] == 0) {
                vector<int> temp;
                dfs(top, adjRev, vis, temp);

                if(temp.size() > ans) {
                    ans=temp.size();
                }
            }
        }
        return ans;
    }

    int longestCycle(vector<int>& a) {

        int n=a.size();
        vector<vector<int>> adj(n);

        for(int i=0; i<n; i++) {
            if(a[i] >= 0)
             adj[i].push_back(a[i]);
        }

        int cyclesize=kosaraju(n, adj);
        
        return cyclesize > 1 ? cyclesize : -1; 
    }
};
