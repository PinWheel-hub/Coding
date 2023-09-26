/*
最小栈 medium
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
实现 MinStack 类:
MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
*/
using namespace std;
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<math.h>
#include<queue>
#include<stack>
#include<functional>

class MinStack {
private:
    vector<int> s, s_min;
public:
    MinStack() {
        s = {};
        s_min.push_back(INT_MAX);
    }
    
    void push(int val) {
        s.push_back(val);
        if(val < s_min.back()) {
            s_min.push_back(val);
        }
        else {
            s_min.push_back(s_min.back());
        }
    }
    
    void pop() {
        s.pop_back();
        s_min.pop_back();
    }
    
    int top() {
        return s.back();
    }
    
    int getMin() {
        return s_min.back();
    }
};

int main()
{
    vector<vector<int>> nums = {{1, 2}};
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
	system("pause");
}


