Approach 1 : TC: O(m*n), SC: O(m*n)

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int dir_x[4] = {1, -1, 0, 0};
        int dir_y[4] = {0, 0, 1, -1};
        int ans = 0;  
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> vis(m, vector(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(vis[i][j] || grid[i][j] == 1) 
                    continue;

                queue<pair<int, int>> q({{i, j}});
                bool is_closed = true;

                while(!q.empty()) {
                    auto front = q.front();
                    q.pop();

                    for(int k = 0; k < 4; k++) {
                        int dy = front.first + dir_y[k];
                        int dx = front.second + dir_x[k]; 

                        if(dy < 0 || dy >= m || dx < 0 || dx >= n) { 
                            is_closed = false;
                            continue;
                        }

                        if(grid[dy][dx] == 1) continue;

                        if(vis[dy][dx]) continue;
                        
                        vis[dy][dx] = true;
                        q.push({dy, dx});
                    }
                }
                if(is_closed) 
                    ans++;
            }
        }
        return ans;
    }
};



Approach 2: TC: O(m*n), SC: O(1)

class Solution {
public:
    int n , m;
    
    void dfs(vector<vector<int>>& a , int i , int j){
        if(i < 0 || j < 0 || j >= m || i >= n || a[i][j] != 0) return;
        a[i][j] = INT_MIN;
        dfs(a , i - 1 , j);
        dfs(a , i + 1 , j);
        dfs(a , i , j - 1);
        dfs(a , i , j + 1);
    }
    
    int closedIsland(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        
        // DFS for Island at Edges
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                if((j == 0 || i == 0 || j == m-1 || i == n-1) && a[i][j] == 0)
                    dfs(a,i,j);
        
        // DFS to find all other islands
        int count = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                if(a[i][j] == 0){
                    count++;
                    dfs(a,i,j);
                }
        
        return count;
    }
};
