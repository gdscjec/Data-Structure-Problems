
void bfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (abs(i) == abs(j))
                {
                    continue;
                }
                int newr = r + i;
                int newc = c + j;
                if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                    grid[newr][newc] == '1' && vis[newr][newc] == 0)
                {
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && vis[i][j] == 0)
            {
                ans++;
                bfs(i, j, vis, grid);
            }
        }
    }
    return ans;
}
