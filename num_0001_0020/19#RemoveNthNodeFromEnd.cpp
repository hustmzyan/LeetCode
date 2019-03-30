/**
 * 19. Remove Nth Node From End of List
 * Given a linked list, remove the n-th node from the end of list and return its head.
 */

/**
 * Definition for singly-linked list.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto** slow = &head;
        auto* fast = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        while(fast != NULL){
            slow = &((*slow)->next);
            fast = fast->next;
        }
        auto* cur = *slow;
        *slow = cur->next;
        delete cur;
        return head;
    }
};

int main(){
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    int n = 2;

    Solution s;

    ListNode* res = NULL;
    res = s.removeNthFromEnd(&node1, n);

    while(res){
        cout << res->val;
        if(res->next){
            cout << "->";
        }
        res = res->next;
    }
    
    cout << endl;

    return 0;
}