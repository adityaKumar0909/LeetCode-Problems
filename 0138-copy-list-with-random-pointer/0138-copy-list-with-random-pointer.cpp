/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //Adding duplicated nodes
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            
            temp = newNode->next;

        }

        //Adding random of these nodes
        temp=head;
        while(temp){
        if(temp->random){
            temp->next->random = temp->random->next;
        }
        temp= temp->next->next;
        }

        //Seperate original and copied lists
        Node* dummy = new Node(0);
        Node* newLL = dummy;
        temp = head;
        while(temp){
        newLL->next = temp->next;
        newLL = newLL->next;
        temp->next = newLL->next;
        temp=temp->next;

        }

        return dummy->next;

    }
};