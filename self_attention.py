import torch
import torch.nn as nn
import math

class Attention_block(nn.Module):
    def __init__(self, channels, num_heads=4):
        super().__init__()
        assert(channels % num_heads == 0)
        self.channels = channels
        self.num_heads = num_heads
        self.num_head_channels = channels // num_heads
        self.qkv = nn.Conv1d(channels, channels * 3, 1)
        self.ln = nn.LayerNorm(normalized_shape=128)
    def forward(self, x):
        B, C, *spatial = x.shape
        x = x.reshape(B, C, -1)
        _, _, N = x.shape
        qkv = self.qkv(x)
        q, k, v = qkv.reshape(B * self.num_heads, self.num_head_channels * 3, N).split(self.num_head_channels, dim=1)
        scale = 1 / math.sqrt(math.sqrt(self.num_head_channels))
        k = k.permute(0, 2, 1)
        weight = torch.matmul(q * scale, k * scale)
        weight = torch.softmax(weight, dim=-1)
        v = torch.matmul(weight, v)
        v = v.reshape(B, -1, N)
        v = v.permute(0, 2, 1)
        x = x.permute(0, 2, 1)
        out = self.ln(x + v).permute(0, 2, 1)
        out = out.reshape(B, C, *spatial)
        return out

attn = Attention_block(128)
x = torch.randn((1, 128, 32, 32))
print(attn(x).shape)