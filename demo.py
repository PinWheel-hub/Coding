import numpy as np

# 创建两组特征
group1 = np.random.rand(10, 256, 384)
group2 = np.random.rand(90, 256, 384)
group2 = np.concatenate((group1, group2), axis=0)

# 将每个特征向量展平为一维数组
flat_group1 = group1.reshape(10, -1)
flat_group2 = group2.reshape(100, -1)

# 计算余弦相似度
cosine_similarities = np.dot(flat_group1, flat_group2.T)  # 注意这里的转置
magnitude1 = np.linalg.norm(flat_group1, axis=1, keepdims=True)
magnitude2 = np.linalg.norm(flat_group2, axis=1, keepdims=True)
cosine_similarities /= np.dot(magnitude1, magnitude2.T)

# 打印结果的形状
print("余弦相似度矩阵:", cosine_similarities)