from typing import List, Optional
import sys

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        visited = {}
        q = []
        for i, row in enumerate(grid):
            for j, num in enumerate(row):
                if num == 2:
                    q.append((i, j))
                    visited[(i, j)] = 0
        def is_valid(i: int, j: int) -> bool:
            return i >= 0 and i < len(grid) and j >= 0 and j < len(grid[0]) and (i, j) not in visited and grid[i][j] > 0
        time = 0
        while len(q) > 0:
            time = visited[q[0]]
            i, j = q[0]
            grid[i][j] = 2
            if is_valid(i - 1, j):
                visited[(i - 1, j)] = time + 1
                q.append((i - 1, j))
            if is_valid(i + 1, j):
                visited[(i + 1, j)] = time + 1
                q.append((i + 1, j))
            if is_valid(i, j - 1):
                visited[(i, j - 1)] = time + 1
                q.append((i, j - 1))
            if is_valid(i, j + 1):
                visited[(i, j + 1)] = time + 1
                q.append((i, j + 1))
            del q[0]
        for row in grid:
            for num in row:
                if num == 1:
                    return -1
        return time

if __name__ == '__main__':
    grid = [[2,1,1],[1,1,0],[0,1,1]]
    sol = Solution()
    print(sol.orangesRotting(grid))
    