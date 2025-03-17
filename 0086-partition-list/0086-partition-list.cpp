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
    ListNode* partition(ListNode* head, int x) {

        if (!head)
            return NULL;

        ListNode* sHead = new ListNode(0);
        ListNode* bHead = new ListNode(0);
        ListNode *small = sHead, *big = bHead;

        ListNode* temp = head;
        while (temp) {
            if (temp->val < x) {
                small->next = temp;
                small = small->next;
            } else {
                big->next = temp;
                big = big->next;
            }

            temp = temp->next;
        }

        big->next = NULL;
        small->next = bHead->next;

        ListNode* newHead = sHead->next;
        delete sHead;
        delete bHead;
        return newHead;
    }
};