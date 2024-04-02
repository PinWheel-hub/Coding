import numpy as np

def conv2d(input, kernel, stride=1, padding=0):
    out_c, k_in_c, k_h, k_w = kernel.shape
    in_c, in_h, in_w = input.shape

    assert in_c == k_in_c

    out_h = (in_h + 2 * padding - k_h) // stride + 1
    out_w = (in_w + 2 * padding - k_w) // stride + 1
    
    output = np.zeros((out_c, out_h, out_w))

    if padding > 0:
        input_padded = np.zeros((in_c, in_h + 2 * padding, in_w + 2 * padding))
        input_padded[:, padding: -padding, padding: -padding] = input
    else:
        input_padded = input

    for i in range(out_h):
        for j in range(out_w):
            for m in range(out_c):
                for n in range(in_c):
                    output[m, i, j] += np.sum(kernel[m, n] * input_padded[n, i * stride : i * stride + k_h, j * stride : j * stride + k_w])
    return output

input = np.random.rand(3, 224, 224)
kernel = np.random.rand(4, 3, 3, 3) 
print(conv2d(input, kernel).shape)               