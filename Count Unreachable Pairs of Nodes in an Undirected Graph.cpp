class Solution {
public:
    int dfs(int node, vector<int>& vis, vector<int> adj[]) {

        vis[node]=1;
        int ans=1;

        for(auto adjacent: adj[node]) {
            if(!vis[adjacent]) {
                ans+=dfs(adjacent, vis, adj);
            }
        }

        return ans;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<int> adj[n];
        vector<int> vis(n,0);

        for(auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> components;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                int c = dfs(i, vis, adj);
                components.push_back(c); 
            }
        }

        long long size = 0;
        long long res = 0;

        for(int i=0; i<components.size(); i++) {
            size+=components[i];
            res+=(n-size)*components[i];
        }

        return res;
    }
};
