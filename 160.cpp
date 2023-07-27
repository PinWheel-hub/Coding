/*
相交链表 哈希表/双指针
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
*/

using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#include<math.h>
#include<queue>
#include<stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> map;
        ListNode *current = headA;
        while(current != NULL) {
            map[current] = true;
            current = current->next;
        }
        current = headB;
        while(current != NULL) {
            if(map.find(current) != map.end()) {
                return current;
            }
            current = current->next;
        }
        return current;
    }
};

void print_listnode(ListNode *head) {
    ListNode *current = head;
    while(current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    ListNode *headC = new ListNode(8);
    headC->next = new ListNode(4);
    headC->next->next = new ListNode(5);

	ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = headC;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headC;

	Solution sol;
	ListNode *head = sol.getIntersectionNode(headA, headB);
	print_listnode(head);
	cout << endl;
	system("pause");
}
