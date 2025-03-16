class Node {

public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head = NULL;

    MyLinkedList() {}

    int get(int index) {

        Node* p = head;
        for (int i = 0; i < index; i++) {
            // we couldnt reach to that index as p is NULL before that
            if (!p)
                return -1;
            p = p->next;
        }

        return p ? p->val : -1;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        if (head == NULL) {
            head = temp;
            return;
        }
        temp->next = head;
        head = temp;
    }

    void addAtTail(int val) {

        Node* temp = new Node(val);
        if (!head) {
            head = temp;
            return;
        }

        Node* q = head;
        while (q->next) {
            q = q->next;
        }
        q->next = temp;
    }

    void addAtIndex(int index, int val) {

        Node* temp = new Node(val);

        // if index = 0
        if (index == 0) {
            temp->next = head;
            head = temp;
            return;
        }

        Node* q = head;

        for (int i = 0; i < index - 1; i++) {
            if (!q)
                return;
            q = q->next;
        }

        if (!q)
            return;

        temp->next = q->next;
        q->next = temp;
    }

    void deleteAtIndex(int index) {

        if (!head)
            return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* q = head;

        for (int i = 0; i < index - 1; i++) {
            if (!q || !q->next)
                return;
            q = q->next;
        }

           if (!q->next) return;
           
        Node* temp = q->next;
        q->next = q->next->next;
        delete temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */