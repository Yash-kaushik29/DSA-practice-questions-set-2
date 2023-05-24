class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> index;

        for(int i=0; i<n; i++) {
            index[arr[i]].push_back(i);
        }
        vector<bool> vis(n, false);
        queue<int> q;

        q.push(0);
        vis[0]=true;
        int steps=0;

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int node = q.front();
                q.pop();

                if(node == n-1) return steps;

                vector<int> next = index[arr[node]];
                next.push_back(node-1);
                next.push_back(node+1);

                for(int j: next) {
                    if(j>=0 && j<n && !vis[j]) {
                        q.push(j);
                        vis[j]=true;
                    }
                }
                // avoid later lookup indicesOfValue arr[i]
                index[arr[node]].clear();
            }
            steps++;
        }
        return -1;
    }
};
