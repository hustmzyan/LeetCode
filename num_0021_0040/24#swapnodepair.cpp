/**
 * 24. Swap Nodes in Pairs
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = head;
        ListNode* cur = head;
        ListNode* nex;
        while(cur && cur->next){
            nex = cur->next;
            if(pre == head){
                head = nex;
            }else{
                pre->next = nex;
            }
            cur->next = nex->next;
            nex->next = cur;

            pre = cur;
            if(cur->next){
                cur = cur->next;
            }else{
                return head;
            }
        }
        return head;


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

    ListNode* res = s.swapPairs(&node1);

    while(res){
        cout << res->val << "->";
        res = res->next;
    }
    cout << "NULL" << endl;

    return 0;
}