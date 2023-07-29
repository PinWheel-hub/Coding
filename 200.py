from typing import List, Optional
import sys

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        result = 0
        for i, row in enumerate(grid):
            for j, ele in enumerate(row):
                if ele == "1":
                    self.dfs(grid, i, j)
                    result += 1
        return result
    def dfs(self, grid, i, j):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] != "1":
            return
        grid[i][j] = '2'
        self.dfs(grid, i - 1, j)
        self.dfs(grid, i + 1, j)
        self.dfs(grid, i, j - 1)
        self.dfs(grid, i, j + 1)

if __name__ == '__main__':
    grid = [["1","1","1","1","0"],
            ["1","1","0","1","0"],
            ["1","1","0","0","0"],
            ["0","0","0","0","0"]]
    sol = Solution()
    print(sol.numIslands(grid))