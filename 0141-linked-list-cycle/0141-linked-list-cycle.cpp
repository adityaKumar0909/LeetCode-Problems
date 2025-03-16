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
    bool hasCycle(ListNode* head) {

        ListNode* p = head;
        if(p==NULL) return false;
        ListNode* q = head->next;

        if (q == NULL)
            return false;

        while (q != NULL && p!=q) {
            p = p->next;
            q = q->next;
            if (q != NULL)
                q = q->next;
        }

        if(p==q) return true;
        else return false;
    }
};