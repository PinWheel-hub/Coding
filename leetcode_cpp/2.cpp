/*
旋转图像 medium
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
*/
using namespace std;
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<functional>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *ans = new ListNode();
        ListNode *p = ans;
        bool signal = 0;
        while(p1 != nullptr || p2 != nullptr) {
            p->next = new ListNode();
            p = p->next;
            if(p1 == nullptr) {
                p->val = (p2->val + signal) % 10;
                signal = (p2->val + signal) / 10;
                p2 = p2->next;
            }
            else if(p2 == nullptr) {
                p->val = (p1->val + signal) % 10;
                signal = (p1->val + signal) / 10;
                p1 = p1->next;
            }
            else {
                p->val = (p1->val + p2->val + signal) % 10;
                signal = (p1->val + p2->val + signal) / 10;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        if(signal) p->next = new ListNode(1);
        return ans->next;
    }
};

int main()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution sol;
    ListNode *ans = sol.addTwoNumbers(l1, l2);
    ListNode *p = ans;
    while(p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }

	system("pause");
}