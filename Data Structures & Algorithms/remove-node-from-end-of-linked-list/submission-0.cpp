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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }

        if (n == count)
            return head->next;

        int num = count - n;
        temp = head;
        ListNode *prev = nullptr;
        while (num) {
            prev = temp;
            temp = temp->next;
            num--;
        }
        prev->next = prev->next->next;
        return head;

    }
};
