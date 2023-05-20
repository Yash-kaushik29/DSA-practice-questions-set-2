class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;

    double DFS(string src, string dest, unordered_set<string>& vis) {
        if(adj.find(src) == adj.end()) return -1;
        if(src == dest) return 1;

        vis.insert(src);

        for(auto nbr: adj[src]) {
            if(vis.find(nbr.first) != vis.end()) continue;

            double val = DFS(nbr.first, dest, vis);
            if(val != -1) {
                return val*nbr.second;
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = equations.size();

        for(int i=0; i<n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];

            adj[a].push_back({b, value});
            adj[b].push_back({a, 1/value});
        }

        vector<double> ans;
        for(auto query: queries) {
            unordered_set<string> vis;
            ans.push_back(DFS(query[0], query[1], vis));
        }
        return ans;
    }
};
