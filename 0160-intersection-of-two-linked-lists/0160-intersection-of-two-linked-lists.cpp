/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        //connect tail of headA to head of LL2 and if they meet it's a common point;

        ListNode* temp = headA;
        while(temp->next){
            temp = temp->next;
        }

        temp->next = headB;

        ListNode* slow = headA;
        ListNode* fast = headA;

        while(fast->next && fast->next->next){
            
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                slow = headA;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                temp->next = NULL;
                return slow;
            }
        }


        temp->next = NULL;
        
        return NULL;



        
    }
};