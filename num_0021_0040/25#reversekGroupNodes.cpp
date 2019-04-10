/**
 * 25. Reverse Nodes in k-Group
 */

#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode HEAD(0);
        HEAD.next = head;
        ListNode* pre = &HEAD;
        ListNode* front;
        ListNode* rear;
        ListNode* tmp;

        while(pre->next){
            front = pre->next;
            tmp = front;
            head = front;
            for(int i = 1; i < k; i++){
                if(head->next == NULL){
                    return HEAD.next;
                }
                head = head->next;
            }
            rear = head;
            cout << pre->val << "," << front->val << "," << rear->val << endl;
            reverseList(pre, front, rear);
            pre = tmp;
        }

        return HEAD.next;
    }

    // 转置链表
    void reverseList(ListNode* pre, ListNode* front, ListNode* rear){
        ListNode* tmp;
        pre->next = rear->next;
        rear->next = NULL;
        while(front){
            tmp = front->next;
            front->next = pre->next;
            pre->next = front;
            front = tmp;
        }
    }
};

int main(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);
    ListNode node7(7);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;

    Solution s;
    int k = 4;

    ListNode* res = s.reverseKGroup(&node1, k);

    while(res){
        cout << res->val << "->";
        res = res->next;
    }
    cout << "NULL" << endl;

    return 0;
}