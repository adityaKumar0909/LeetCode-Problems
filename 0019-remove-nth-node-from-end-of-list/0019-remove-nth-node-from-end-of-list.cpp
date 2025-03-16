/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    //Edge case
    if(head == NULL || head->next ==NULL){
        delete head;
        return NULL;
    }     
    
    int totalNodes = 0;
    
    ListNode* temp = head;

    while(temp != NULL){
        totalNodes++;
        temp = temp->next;
    }

    int pos = (totalNodes - n);
    
  
    ListNode* p = head;

     for (int i = 1; i < pos; i++) {
        p = p->next;
    }

    if(pos == 0){
        head = head->next;
    }

    p->next = p->next->next;
    return head;  
    }
};