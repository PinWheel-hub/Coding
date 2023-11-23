import torch
import torch.nn as nn

class Net(nn.Module):
    def __init__(self):
        super(Net, self).__init__()
        self.s = nn.Sigmoid()
    def forward(self, x):
        return x * self.s(x)
    

net = Net()
a = torch.randn([2, 2])
print(a, net(a))