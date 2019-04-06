/**
 * 21. Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res;
        ListNode* cur;
        bool flag = true;
        while(l1 && l2){
            if(l1->val <= l2->val){
                if(flag){
                    res = l1;
                    cur = res;
                    flag = false;
                }else{
                    cur->next = l1;
                    cur = l1;
                }
                l1 = l1->next;
            }else{
                /* code */
                if(flag){
                    res = l2;
                    cur = res;
                    flag = false;
                }else{
                    cur->next = l2;
                    cur = l2;
                }
                l2 = l2->next;
            }
            
        }
        while(l1){
            cur->next = l1;
            cur = l1;
            l1 = l1->next;
        }
        while(l2){
            cur->next = l2;
            cur = l2;
            l2 = l2->next;
        }

        return res;
    }
};

int main(){
    ListNode node1_1(1);
    ListNode node1_2(2);
    ListNode node1_3(4);
    node1_1.next = &node1_2;
    node1_2.next = &node1_3;

    ListNode node2_1(1);
    ListNode node2_2(3);
    ListNode node2_3(4);
    node2_1.next = &node2_2;
    node2_2.next = &node2_3;


    Solution s;
    ListNode* result;
    result = s.mergeTwoLists(&node1_1, &node2_1);

    while(result){
        cout << result->val << "->";
        result = result->next;
    }
    cout << "NULL" << endl;
    return 0;
}