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
private:
    ListNode *reverseLinkedList(ListNode *head) {
        ListNode *temp = head;
        ListNode *prev = nullptr;
        while(temp) {
            ListNode *nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast-> next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        fast = reverseLinkedList(fast);
        slow->next = nullptr;
        slow = head;

        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        while(slow && fast){
            temp->next = slow;
            slow = slow->next;
            temp = temp->next;
            temp->next = fast;
            fast = fast->next;
            temp = temp->next;
        }
        while(slow) {
            temp->next = slow;
            slow = slow->next;
            temp = temp->next;
        }
        head = dummy->next;
    }
};
