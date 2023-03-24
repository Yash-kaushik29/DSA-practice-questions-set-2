class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections){
        vector<vector<pair<int, bool>>> adj(n);
        for(auto i: connections){
           // 0 for outgoing vectors and 1 for incoming vectors
           adj[i[0]].push_back(make_pair(i[1],1));
           adj[i[1]].push_back(make_pair(i[0],0));
        }

        vector<bool> visited(n, 0);  
        int count=0;
        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto i:adj[u]){
                if(visited[i.first] == 0){
                    if(i.second == 1)
                        count++;
                    q.push(i.first);
                    visited[i.first] = 1;
                }
            }
        }
        return count;
    }    
};    
