from typing import List
import sys

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        row_dic = {}
        col_dic = {}
        for i, row in enumerate(matrix):
            for j, ele in enumerate(row):
                if ele == 0:
                    row_dic[i] = True
                    col_dic[j] = True
        for row in row_dic:
            for col, _ in enumerate(matrix[0]):
                matrix[row][col] = 0
        for col in col_dic:
            for row, _ in enumerate(matrix):
                matrix[row][col] = 0


if __name__ == '__main__':
    matrix = [[1,1,1],[1,0,1],[1,1,1]]
    sol = Solution()
    sol.setZeroes(matrix)
    print(matrix)