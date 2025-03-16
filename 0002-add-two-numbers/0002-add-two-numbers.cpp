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
    ListNode* head1 = new ListNode(-1);
    ListNode* temp = head1;

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;

        int carry = 0;

        int sum = 0;
        while (p != NULL || q != NULL) {

            int val1 = p == NULL ? 0 : p->val;
            int val2 = q == NULL ? 0 : q->val;

            sum = carry + val1 + val2;
            carry = sum / 10;
            sum = sum % 10;
            temp->next = new ListNode(sum);
            temp = temp->next;

            if(p)p = p->next;
            if(q)q = q->next;
        }
        while (carry > 0) {
           
           
          
            temp->next = new ListNode(carry%10);
            temp = temp->next;
            carry=carry/10;
        }

        return head1->next;
    }
};