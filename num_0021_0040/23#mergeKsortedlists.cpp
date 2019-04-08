/**
 * 23. Merge k Sorted Lists
 */

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }else if(lists.size() == 1){
            return lists[0];
        }
        else if(lists.size() == 2){
            return mergeTwoLists(lists[0], lists[1]);
        }else{
            ListNode* sum = mergeTwoLists(lists[0], lists[1]);
            for(int i = 2; i < lists.size(); i++){
                sum = mergeTwoLists(sum, lists[i]);
            }
            return sum;
        }
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res;
        ListNode* cur;
        bool flag = true;
        if(l1 == NULL && l2){
            return l2;
        }
        if(l2 == NULL && l1){
            return l1;
        }
        if(l1 == NULL && l1 == NULL){
            return NULL;
        }
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

    ListNode node3_1(2);
    ListNode node3_2(6);
    node3_1.next = &node3_2;

    vector<ListNode*> lists;
    lists.push_back(&node1_1);
    lists.push_back(&node2_1);
    lists.push_back(&node3_1);

    Solution s;
    ListNode* res = s.mergeKLists(lists);

    while(res){
        cout << res->val << "->";
        res = res->next;
    }
    cout << "NULL" << endl;


    return 0;
}