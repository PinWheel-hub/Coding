import numpy as np

def LR_minibatch(x, y, num_steps, lr):
    w, b = np.zeros(x.shape[1]), 0
    for t in range(num_steps):
        batch_index = np.random.choice(x.shape[0], 100) # batch_size: 100
        batch_x, batch_y = x[batch_index], y[batch_index]
        errors = sigmoid(np.dot(batch_x, w) + b)
        grad_w = np.matmul(batch_x.T, errors)
        grad_b = np.sum(errors)
        w = w - lr * grad_w
        b = b - lr * grad_b 
    return w, b

def sigmoid(x):
    return 1.0 / (1 + np.exp(-x))
def max_likelihood(x, y, w, b):
    pos, neg = np.where(y==1), np.where(y==0)
    pos_sum = np.sum(np.log(sigmoid(np.dot(x[pos], w) + b)))
    neg_sum = np.sum(np.log(1-sigmoid(np.dot(x[neg], w) + b)))
    return pos_sum + neg_sum