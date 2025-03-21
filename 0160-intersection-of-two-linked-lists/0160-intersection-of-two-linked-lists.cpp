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

        unordered_set<ListNode*> list;
        ListNode* temp = headA;
        while(temp){
            list.insert(temp);
            temp = temp->next;
        }

        temp = headB;
         while(temp){
            if(list.find(temp)!=list.end())
            return temp;

            temp = temp->next;
        }

        return NULL;

        
    }
};