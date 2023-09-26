from rtree import index
from typing import List, Optional
import sys

idx = index.Index()

# 插入一些空间数据，每个数据都有一个唯一的标识符和一个表示范围的矩形（左下角和右上角坐标）
data = [(0, (0, 0, 2, 2)),
        (1, (1, 1, 3, 3)),
        (2, (2, 2, 4, 4)),
        (3, (4, 4, 5, 5))]

for item in data:
    idx.insert(item[0], item[1])

# 执行范围查询
query_area = (1, 1, 3, 3)
result = list(idx.intersection(query_area))
print(range(0, 1, 0.1))
print("查询结果：", result)