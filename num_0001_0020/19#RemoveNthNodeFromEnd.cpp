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
    ListNode* list = NULL;
    ListNode* head = list;
    for(int i = 0; i < 5; i++){
        list->val = i;
        ListNode* Nex = list->next;
        list = Nex;
    }

    ListNode* temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    

    return 0;
}