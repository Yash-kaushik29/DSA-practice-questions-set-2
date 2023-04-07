Appproach 1

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int dir_x[4] = {1, -1, 0, 0};
        int dir_y[4] = {0, 0, 1, -1};
        int ans = 0;
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0 || vis[i][j]) 
                    continue;

                int cells = 0; 
                bool enclosed = true;   
                queue<pair<int, int>> q({{i, j}});
                vis[i][j] = true;

                while(!q.empty()) {
                    auto front = q.front();
                    q.pop();
                    cells++;
                    for(int k = 0; k < 4; k++) {

                        int dy = front.first + dir_y[k];
                        int dx = front.second + dir_x[k];
                        if(dx < 0 || dx >= n || dy < 0 || dy >= m) { 
                            enclosed = false;
                            continue;                            
                        }
                        
                        if(vis[dy][dx]) continue;
                        if(grid[dy][dx] == 0) continue;
                        vis[dy][dx] = true;
                        q.push({dy, dx});
                    }
                }
                if(enclosed) 
                    ans += cells;
            }
        }
        return ans;
    }
};

Recursive approach

class Solution {
public:
    void dfs(vector<vector<int>>& a, int i, int j) {
        if (i < 0 || j < 0 || i == a.size() || j == a[i].size() || a[i][j] != 1) return;
        a[i][j] = 0;
        dfs(a, i + 1, j);
        dfs(a, i - 1, j);
        dfs(a, i, j + 1);
        dfs(a, i, j - 1);
    }

    int numEnclaves(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();

        // To make all enclaves connected to edges visited
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || j == 0 || i == n-1 || j == m-1)
                {
                    if(a[i][j] == 1)
                    dfs(a,i,j);
                }
            }
        }

        // To calculate number of unvisited enclaves
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] == 1)
                cnt++;
            }
        }

        return cnt;
    }
};
