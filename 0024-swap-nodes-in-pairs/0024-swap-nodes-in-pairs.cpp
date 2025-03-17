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
    ListNode* swapPairs(ListNode* head) {
        
        //If empty LL or only has one element then simply return the head
        if(!head || !head->next){
            return head;
        }
        
        //Qeueue 1 for storing odd place nodes
        queue<ListNode*> q1;
        //Queueu 2 for storing even place nodes
        queue<ListNode*> q2;

        
        ListNode* temp = head;
        //Filling both the Qeueus
        while (temp != NULL && temp->next != NULL) {
            q1.push(temp);
            q2.push(temp->next);
            temp = temp->next->next;
        }

        // If there is an odd number of nodes the last node won't be processed so 
        //we have to push it ourself

        if (temp != NULL) {
            q1.push(temp);
        }
        
        //Making head of new linked list
        ListNode* newHead = q2.front();
        q2.pop();
        temp = newHead;
    
        //Link elements of both queues alternatively 
       

        while(!q1.empty() || !q2.empty()){
        
        //Linking element from Queue1
        if(!q1.empty()){
        temp->next = q1.front();
        q1.pop();
        temp = temp->next;
        }

        //Linking element from Queue2
        if(!q2.empty()){
        temp->next = q2.front();
        q2.pop();
        temp = temp->next;
        }

        }

        //After linking is done . End the final node with a NULL 
        if(temp!=NULL)
        temp->next = NULL;

        return newHead;


    }
};