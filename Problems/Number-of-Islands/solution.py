def numIslands(self, grid):
        def dfs(x, y):
            if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] != '1':
                return
            grid[x][y] = '0'
            for i, j in [(x - 1, y), (x, y - 1), (x + 1, y), (x, y + 1)]:
                dfs(i, j)
        
        if not grid or not grid[0]:
            return 0
        res = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    dfs(i, j)
                    res += 1
        return res
