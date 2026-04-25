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
private:
    void insertNodesInBetween(Node *head) {
        Node *temp = head;
        while(temp) {
            Node *nextNode = temp->next;
            Node *copy = new Node(temp->val);
            
            temp->next = copy;
            copy->next = nextNode;

            temp = temp->next->next;
        }
    }

    void connectRandomNotes(Node *head) {
        Node *temp = head;
        while(temp) {
            if(temp->random) {
                temp->next->random = temp->random->next;                
            }
            temp = temp->next->next;
        }
    }

    Node *getCopiedList(Node *head) {
        Node *temp = head;
        Node *d = new Node(-1);
        Node *res = d;
        while(temp) {
            res->next = temp->next;
            res = res->next;

            temp->next = res->next;
            temp = temp->next;
        }

        return d->next;
    }
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;

        insertNodesInBetween(head);
        connectRandomNotes(head);
        return getCopiedList(head);
    }
};
