class Solution {
public:
    vector<int> vis;

    int dfs(vector<vector<int>> &g,int i){

        vis[i]=1;
        int ans=1;
        for(auto &j:g[i]){
            if(!vis[j]){
                ans+=dfs(g,j);
            }
        }
        return ans;
    }


    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<vector<int>> g(n);
        vis=vector<int>(n,0);

        for(auto &i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }

        vector<int> component;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int x=dfs(g,i);
                component.push_back(x);
            }
        }

        long long ans=0;
        long long t=0;

        for(int i=0;i<component.size();i++){
            t+=component[i];
            ans+=(n-t)*component[i];
        }
        return ans;
        
    }
};
